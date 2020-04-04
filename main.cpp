#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "temperature_sensor.h"
#include "temperature_controller.h"

#include "data.h"
#include "DS18B20.h"

int main(int argc, char *argv[])
{


    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    SensorModel model;
    TemperatureSensor sensorMod("28-00000b385bb2");
    TemperatureSensor sensorMod2("28-00000b385bb3");


    model.addSensor(sensorMod);
    model.addSensor(sensorMod2);
    Data data;
    TemperatureController controller(&model, &data);
    controller.Start();
    QQmlApplicationEngine engine;


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    QQmlContext *context = engine.rootContext();
    context->setContextProperty("sensorModel", &model);
    context->setContextProperty("graphData", &data);
    engine.load(url);

    return app.exec();
}
