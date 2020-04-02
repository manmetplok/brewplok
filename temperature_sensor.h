#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H
#include <QAbstractListModel>
#include <QStringList>


class TemperatureSensor
{
public:
    TemperatureSensor(const QString &address);

    QString name() const;
    QString address() const;
    double target_temp() const;
    float current_temp() const;
    void current_temp(float);

private:
    QString m_name;
    QString m_address;
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
        CurrentTempRole
    };
    SensorModel(QObject *parent = 0);

    void addSensor(const TemperatureSensor &sensor);
    void setCurrentTemp(int index, float temp);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<TemperatureSensor> m_sensors;
};
#endif // TEMPERATURESENSOR_H
