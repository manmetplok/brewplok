#ifndef TEMPERATURECONTROLLER_H
#define TEMPERATURECONTROLLER_H
#include "temperature_sensor.h"

class TemperatureController : public QObject
{
public:
    TemperatureController(SensorModel*);
    ~TemperatureController();
    void Start();
private:
    SensorModel* m_model;


};

#endif // TEMPERATURECONTROLLER_H
