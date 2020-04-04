#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H
#include <QAbstractListModel>
#include <QStringList>
#include "proto/gen/session.pb.h"
#include <QDateTime>

class TemperatureSensor
{
public:
    TemperatureSensor(const QString &address);

    QString name() const;
    QString address() const;
    double target_temp() const;
    float current_temp() const;
    void current_temp(float);
    void session(std::shared_ptr<Session>);
    QVariantMap history() const;

private:
    QString m_name;
    QString m_address;
    std::shared_ptr<Session> m_session;
    double m_target_temp;
    float m_current_temp;
};

class SensorModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum SensorRoles {
        NameRole = Qt::UserRole +1,
        AddressRole,
        TargetTempRole,
        CurrentTempRole,
        History,
    };
    SensorModel(QObject *parent = 0);
    QVariant getHistory(int index) const;
    void addSensor(const TemperatureSensor &sensor);
    void setCurrentTemp(std::string index, float temp);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QList<TemperatureSensor> sensors();
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<TemperatureSensor> m_sensors;
};
#endif // TEMPERATURESENSOR_H
