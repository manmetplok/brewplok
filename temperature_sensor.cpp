#include "temperature_sensor.h"
#include <string>
TemperatureSensor::TemperatureSensor(const QString &address) : m_address(address)
{

}

QString TemperatureSensor::name() const {
    return m_name;
}

Q_INVOKABLE QString TemperatureSensor::address() const {
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

void TemperatureSensor::session(std::shared_ptr<Session> session){
    m_session = session;
}

Q_INVOKABLE QVariantMap TemperatureSensor::history() const{
    QVariantMap result;
    auto session = m_session.get();

    auto nrOfValues = session->value_size();
    for (int i = 0;  i < nrOfValues ; i++) {
        auto value = session->value(i);
        result.insert(QString::number((session->starttime() + i )), value);
    }
    return result;
}

SensorModel::SensorModel(QObject *parent)
    : QAbstractListModel(parent)
{
}


void SensorModel::setCurrentTemp(std::string sensorName, float temp)
{
//    emit layoutAboutToBeChanged();
    for (auto i = 0; i < m_sensors.length(); i++) {
        auto sensor = m_sensors[i];
        if (sensor.address().compare(QString::fromStdString(sensorName)) == 0) {
            printf("refreshing %s width temp %f\n", sensorName.c_str(), temp);
            m_sensors[i].current_temp(temp);
            QModelIndex topLeft = createIndex(i,0);
            emit dataChanged(topLeft, topLeft);
//            emit dataChanged(topLeft, topLeft, {CurrentTempRole });
        }


    }



//    emit dat();
}

QList<TemperatureSensor> SensorModel::sensors() {
    return m_sensors;
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

QVariant SensorModel::getHistory(int index) const{
    return m_sensors[index].history();
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
    else if (role == History)
        return sensor.history();
    return QVariant();
}

//![0]
QHash<int, QByteArray> SensorModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[AddressRole] = "address";
    roles[CurrentTempRole] = "current";
    roles[History] = "history";
    return roles;
}
