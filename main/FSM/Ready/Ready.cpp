#include "Ready.hpp"
#include "LineFollower.hpp"
#include "esp_log.h"

Ready::Ready() {}

Ready::~Ready() {}

void Ready::Enter() {
    ESP_LOGI("[FSM]", "Entered Ready state");
}

void Ready::Update() {
  
}

void Ready::Exit() {
}