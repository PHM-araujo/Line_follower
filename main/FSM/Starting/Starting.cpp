#include "Starting.hpp"
#include "LineFollower.hpp"
#include "esp_log.h"

Starting::Starting() {}

Starting::~Starting() {}

void Starting::Enter() {
    ESP_LOGI("[FSM]", "Entered Starting state");
}

void Starting::Update() {
  
}

void Starting::Exit() {
}