#include "temperature_sensor.h"

TemperatureSensor::TemperatureSensor(const QString &address) : m_address(address)
{

}

QString TemperatureSensor::name() const {
    return m_name;
}

QString TemperatureSensor::address() const {
    return m_address;
}



double TemperatureSensor::target_temp() const {
    return m_target_temp;
}

float TemperatureSensor::current_temp() const {
    return m_current_temp;
}

void TemperatureSensor::current_temp(float temp) {
    m_current_temp = temp;
}

SensorModel::SensorModel(QObject *parent)
    : QAbstractListModel(parent)
{
}


void SensorModel::setCurrentTemp(int index, float temp)
{
    m_sensors[index].current_temp(temp);
    QModelIndex topLeft = createIndex(index,0);
    emit dataChanged(topLeft, topLeft);
}

void SensorModel::addSensor(const TemperatureSensor &sensor)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_sensors << sensor;
    endInsertRows();
}

int SensorModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return m_sensors.count();
}

QVariant SensorModel::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() >= m_sensors.count())
        return QVariant();

    const TemperatureSensor &sensor = m_sensors[index.row()];
    if (role == NameRole)
        return sensor.name();
    else if (role == AddressRole)
        return sensor.address();
    else if (role == CurrentTempRole)
        return sensor.current_temp();
    return QVariant();
}

//![0]
QHash<int, QByteArray> SensorModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[AddressRole] = "address";
    roles[CurrentTempRole] = "current";
    return roles;
}
