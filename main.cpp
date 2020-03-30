#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "temperature_sensor.h"
int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    SensorModel model;
    model.addSensor(TemperatureSensor("0x001"));
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
