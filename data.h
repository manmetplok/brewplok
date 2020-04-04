#ifndef DATA_H
#define DATA_H

#include <QObject>
#include <QPointF>
#include <QTimer>

class Data : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QPointF wValue READ wValue NOTIFY wValueChanged)
    Q_PROPERTY(QString wSensor READ wSensor NOTIFY wSensorChanged)

public:
    Data(QObject *parent=Q_NULLPTR);
    QPointF wValue() const{
        return m_wValue;
    }
    QString wSensor() const{
        return m_sensor;
    }
    void sensor(QString);
    void setValue(QString, int64_t, float );

signals:
    void wValueChanged();
    void wSensorChanged();

private:
    QPointF m_wValue;
    QString m_sensor;
};

#endif // DATA_H
