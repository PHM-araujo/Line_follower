#include "Updating.hpp"
#include "LineFollower.hpp"
#include "esp_log.h"

Updating::Updating() {}

Updating::~Updating() {}

void Updating::Enter() {
    ESP_LOGI("[FSM]", "Entered Updating state");
}

void Updating::Update() {
  
}

void Updating::Exit() {
}