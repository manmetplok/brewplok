#include "temperature_controller.h"
#include "rxcpp/rx.hpp"
#include "DS18B20.h"

TemperatureController::TemperatureController(SensorModel* sensorModel)
{
    m_model = sensorModel;
}

void TemperatureController::Start() {
    auto threads = rxcpp::observe_on_event_loop();
    auto current = rxcpp::identity_current_thread();
    auto subscriber = rxcpp::make_subscriber<float>(
            [this](float v){printf("OnNext: %d\n", v);
               m_model->setCurrentTemp(0, v);
    },
            [](){printf("OnCompleted\n");});



    auto values = rxcpp::observable<>::interval(std::chrono::seconds(1));
    values.subscribe_on(threads)
            .map([](int v){DS18B20 reader("28-00000b385bb3"); return reader.getTempMock(); })
        .observe_on(current)
        .subscribe(subscriber);

}
TemperatureController::~TemperatureController() {
printf("Desctruct\n");
}

