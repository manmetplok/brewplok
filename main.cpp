#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "temperature_sensor.h"
#include "DS18B20.h"

int main(int argc, char *argv[])
{


    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);
    DS18B20 sens1("28-00000b385bb3");
    auto temp = sens1.getTemp();
//    auto temp = 12.3f;
    SensorModel model;
    TemperatureSensor sensorMod("28-00000b385bb3");
    sensorMod.current_temp(temp);
    model.addSensor(sensorMod);
    model.addSensor(TemperatureSensor("0x002"));
    model.addSensor(TemperatureSensor("0x003"));


    QQmlApplicationEngine engine;


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    QQmlContext *context = engine.rootContext();
    context->setContextProperty("sensorModel", &model);
    engine.load(url);

    return app.exec();
}
