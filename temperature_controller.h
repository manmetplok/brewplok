#ifndef TEMPERATURECONTROLLER_H
#define TEMPERATURECONTROLLER_H
#include "temperature_sensor.h"
#include <map>
#include "proto/gen/session.pb.h"
#include "data.h"

class TemperatureController : public QObject
{
public:
    TemperatureController(SensorModel*, Data*);
    ~TemperatureController();
    void Start();
private:
    SensorModel* m_model;
    Data * m_data;
    std::map<std::string,std::shared_ptr<Session>> sessions;


};

#endif // TEMPERATURECONTROLLER_H
