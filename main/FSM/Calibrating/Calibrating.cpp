#include "Calibrating.hpp"
#include "LineFollower.hpp"
#include "esp_log.h"

Calibrating::Calibrating() {}

Calibrating::~Calibrating() {}

void Calibrating::Enter() {
    ESP_LOGI("[FSM]", "Entered Calibrating state");
}

void Calibrating::Update() {
  
}

void Calibrating::Exit() {
}