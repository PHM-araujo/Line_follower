#include "LineFollower.hpp"

// Framework includes
#include "esp_log.h"

State* LineFollower::current_state = nullptr;
/**
 * @brief: Default constructor
*/
LineFollower::LineFollower(){}
/**
 * @brief: Default destructor
*/
LineFollower::~LineFollower(){
    ESP_LOGI("[FSM]", "Called destructor");
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
