#include "data.h"

void Data::setValue(QString sensor, int64_t time,  float temp){
    m_sensor = sensor;
    m_wValue.setX(time);
    m_wValue.setY(temp);
    printf("temp: %f",temp);
    emit wValueChanged();
}

void Data::sensor(QString sensor) {
    m_sensor = sensor;
    emit wSensorChanged();
}


Data::Data(QObject *parent):QObject(parent){

}
