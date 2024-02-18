#include "Stopping.hpp"
#include "LineFollower.hpp"
#include "esp_log.h"

Stopping::Stopping() {}

Stopping::~Stopping() {}

void Stopping::Enter() {
    ESP_LOGI("[FSM]", "Entered Stopping state");
}

void Stopping::Update() {
  
}

void Stopping::Exit() {
}