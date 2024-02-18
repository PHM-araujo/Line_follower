#include "LineFollower.hpp"
#include "Starting.hpp"

// FreeRTOS includes
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


LineFollower line_follower;

extern "C" void app_main(void) {
    // Start the state machine
    line_follower.TransitionTo(new Starting());

    // Create the Robot Routines
    xTaskCreate(&LineFollower::UpdateStateRoutine, "UpdateStateRoutine", 2048, NULL, 5, NULL);

    vTaskDelete(NULL);
}
