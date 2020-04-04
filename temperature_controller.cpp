#include "temperature_controller.h"
#include "rxcpp/rx.hpp"
#include "DS18B20.h"
#include "data.h"


TemperatureController::TemperatureController(SensorModel* sensorModel, Data * data)
{
    m_model = sensorModel;
    m_data = data;
    //Record time
    auto now = std::chrono::system_clock::now();
    int64_t epoch = std::chrono::duration_cast<std::chrono::seconds>( now.time_since_epoch()).count();

    for (auto sensor:  sensorModel->sensors()) {
        auto sessionPtr = std::make_shared<Session>();
        auto session = sessionPtr.get();
        session->set_starttime(epoch);

        session->set_sensor(sensor.address().toStdString());
        sessions.insert(std::make_pair(sensor.address().toStdString(), sessionPtr));
        printf("Checking: %s", sessionPtr->DebugString().c_str());
    }
}

void TemperatureController::Start() {
    auto threads = rxcpp::observe_on_event_loop();
    auto current = rxcpp::identity_current_thread();


    auto subscriber = rxcpp::make_subscriber<std::tuple<std::string,float, std::shared_ptr<Session>>>(
                [this](std::tuple<std::string,float, std::shared_ptr<Session>> v){
        auto [sensor, value, session] = v;
                auto startTime  = session->starttime();
                auto now = std::chrono::system_clock::now();
                int64_t epoch = std::chrono::duration_cast<std::chrono::seconds>( now.time_since_epoch()).count();
                auto seconds= epoch - startTime;
                m_data->setValue(QString::fromStdString(sensor), seconds, value);
                m_model->setCurrentTemp(sensor, value);
    },
                [](){printf("OnCompleted\n");});

        auto values = rxcpp::observable<>::interval(std::chrono::seconds(3));
        values.subscribe_on(threads)
                .flat_map([this](int _){
            return rxcpp::observable<>::iterate(this->sessions)
                    .map([](auto s){
                auto [sensor_name, session] = s;
                        DS18B20 reader(sensor_name.c_str());
                        auto newValue = reader.getTempMock();
                        session.get()->add_value(newValue);
                        return std::tuple<std::string, float, std::shared_ptr<Session>>(sensor_name, newValue,session );
            });
            })
                        .observe_on(current)
                        .subscribe(subscriber);
            }

                        TemperatureController::~TemperatureController() {
                    printf("Desctruct\n");
                }

