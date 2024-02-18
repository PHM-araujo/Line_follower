#include "Stopped.hpp"
#include "LineFollower.hpp"
#include "esp_log.h"

Stopped::Stopped() {}

Stopped::~Stopped() {}

void Stopped::Enter() {
    ESP_LOGI("[FSM]", "Entered Stopped state");
}

void Stopped::Update() {
  
}

void Stopped::Exit() {
}