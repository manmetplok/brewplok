cmake_minimum_required(VERSION 3.5)

project(brewplok LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(rxcpp REQUIRED)
include_directories(${rxcpp_INCLUDE_DIR})

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Core Quick Charts LinguistTools REQUIRED)
find_package(Protobuf)
set(TS_FILES brewplok_en_150.ts)

if(ANDROID)
    add_library(brewplok SHARED
      main.cpp
      qml.qrc
      ${TS_FILES}
    )
else()
    add_executable(brewplok
      main.cpp
      data.cpp
      temperature_sensor.cpp
      temperature_controller.cpp
      DS18B20.cpp
      proto/gen/session.pb.cc
      qml.qrc
      ${TS_FILES}
    )
endif()

target_compile_definitions(brewplok
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(brewplok
  PRIVATE Qt5::Core Qt5::Quick Qt5::Charts pthread ${Protobuf_LIBRARIES})

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
