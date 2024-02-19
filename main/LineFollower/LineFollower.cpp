#include "LineFollower.hpp"
#include "defines.hpp"

// Framework includes
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

State* LineFollower::current_state = nullptr;
/**
 * @brief: Default constructor
*/
LineFollower::LineFollower(){
    ESP_LOGI("[ROBOT]", "Called constructor");

    // Pin configuration
    motor_left = Motor(PWM_1_ESQ, PWM_2_ESQ, EN_ESQ, LEDC_CHANNEL_0, LEDC_CHANNEL_1);
    motor_right = Motor(PWM_1_DIR, PWM_2_DIR, EN_DIR, LEDC_CHANNEL_2, LEDC_CHANNEL_3);
}
/**
 * @brief: Default destructor
*/
LineFollower::~LineFollower(){
    ESP_LOGI("[ROBOT]", "Called destructor");
    delete current_state;
}
/**
 * @brief Responsible for changing the current state
 * @param new_state new state to be set
*/
void LineFollower::TransitionTo(State *new_state) {
    ESP_LOGI("[FSM]", "TrasitionTo new state");
    if (current_state == new_state) {
        return;
    }
    // if there is a current state (=! nullptr)
    if (current_state) {
        current_state->Exit();
        delete current_state;
    }

    current_state = new_state;

    // if there is a new state (=! nullptr)
    if (new_state) {
        new_state->SetLineFollower(this);
        new_state->Enter();
    }
}
/**
 * @brief: Update the current state
*/
void LineFollower::UpdateStateRoutine(void *pvParameters) {
    ESP_LOGI("[FSM]", "Routine to update the state");

    while(1){
        current_state->Update();
    }
}
/**
 * @brief: Initialize the subsystems
*/
void LineFollower::InitSubsystems(){
    ESP_LOGI("[ROBOT]", "Initializing subsystems");
    motor_left.Init();
    motor_right.Init();
}
/**
 * @brief: Test the motors
*/
void LineFollower::TestMotors(){
    ESP_LOGI("[ROBOT]", "Testing motors");
    motor_left.SetDuty(8191);
    motor_right.SetDuty(8191);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    motor_left.SetDuty(0);
    motor_right.SetDuty(0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    motor_left.SetDuty(-8191);
    motor_right.SetDuty(-8191);
    vTaskDelay(5000 / portTICK_PERIOD_MS);
    motor_left.SetDuty(0);
    motor_right.SetDuty(0);
}