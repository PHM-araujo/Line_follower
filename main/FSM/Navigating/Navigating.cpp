#include "Navigating.hpp"
#include "LineFollower.hpp"
#include "esp_log.h"

Navigating::Navigating() {}

Navigating::~Navigating() {}

void Navigating::Enter() {
    ESP_LOGI("[FSM]", "Entered Navigating state");
}

void Navigating::Update() {
  
}

void Navigating::Exit() {
}