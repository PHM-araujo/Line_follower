#include "Motor.hpp"
#include "esp_log.h"

/**
 * @brief Default Constructor
*/
Motor::Motor() {
  pin_forward = GPIO_NUM_0;
  pin_backward = GPIO_NUM_0;
  en = GPIO_NUM_0;
  channel_forward = LEDC_CHANNEL_0;
  channel_backward = LEDC_CHANNEL_1;
  speed_mode = LEDC_HIGH_SPEED_MODE;
  timer_sel = LEDC_TIMER_0;
  duty = 0;
  hpoint = 0;
}
/**
 * @brief Constructor
 * 
 * @param pin_in_1 GPIO pin number
 * @param pin_in_2 GPIO pin number
 * @param direcao Direção do motor
*/
Motor::Motor(gpio_num_t pin_forward, gpio_num_t pin_backward, gpio_num_t en, 
        ledc_channel_t channel_forward, 
        ledc_channel_t channel_backward) {
  
    this->pin_forward = pin_forward;
    this->pin_backward = pin_backward;
    this->en = en;

    this->channel_forward = channel_forward;
    this->channel_backward = channel_backward;
    speed_mode = LEDC_HIGH_SPEED_MODE;
    timer_sel = LEDC_TIMER_0;
    duty = 0;
    hpoint = 0;
}

/**
 * @brief Destructor
*/
Motor::~Motor() {
  Stop();
}

/**
 * @brief Method to initialize the motor
*/
void Motor::Init() {
    gpio_set_direction(pin_forward, GPIO_MODE_OUTPUT);
    gpio_set_direction(pin_backward, GPIO_MODE_OUTPUT);
    gpio_set_direction(en, GPIO_MODE_OUTPUT);
    gpio_set_level(en, 1);  // Enable the motor

    // Incializa o Timer usado pelo PWM como frequencia e resolução do PWM
    ledc_timer_config_t ledc_timer = {
        .speed_mode = LEDC_HIGH_SPEED_MODE,     // timer mode
        .duty_resolution = LEDC_TIMER_13_BIT,   // resolution of PWM duty
        .timer_num = LEDC_TIMER_0,              // timer index
        .freq_hz = 5000,                        // frequency of PWM signal
        .clk_cfg = LEDC_AUTO_CLK                // Auto select the source clock
    };

    ledc_timer_config(&ledc_timer);

    // Inicializa os canais do PWM
    ledc_channel_config_t ledc_channel_forward = {
      .gpio_num   = pin_forward,
      .speed_mode = speed_mode,
      .channel    = channel_forward,
      .intr_type  = LEDC_INTR_DISABLE,
      .timer_sel  = timer_sel,
      .duty       = duty,
      .hpoint     = hpoint,
      .flags      = 0,
    };
    ledc_channel_config(&ledc_channel_forward);

    ledc_channel_config_t ledc_channel_backward = {
      .gpio_num   = pin_backward,
      .speed_mode = speed_mode,
      .channel    = channel_backward,
      .intr_type  = LEDC_INTR_DISABLE,
      .timer_sel  = timer_sel,
      .duty       = duty,
      .hpoint     = hpoint,
      .flags      = 0 
    };
    ledc_channel_config(&ledc_channel_backward);

    // Initialize fade service.
    ledc_fade_func_install(0);
}

/**
 * @brief Aciona o freio do motor
*/
void Motor::Stop() {
  // Set the duty cycle for the forward and backward channels
  ledc_set_duty(speed_mode, channel_forward, HIGH);
  ledc_update_duty(speed_mode, channel_forward);

  ledc_set_duty(speed_mode, channel_backward, HIGH);
  ledc_update_duty(speed_mode, channel_backward);
}

/**
 * @brief Set the duty cycle for the motor
 * 
 * @param duty Duty cycle
 * 
 * @note The duty cycle is a value between 0 and +/-8191
 * @note The direction is determined by the sign of the duty cycle
*/
void Motor::SetDuty(int duty) {
    // Set the duty cycle for the forward and backward channels
    ledc_set_duty(speed_mode, channel_forward, duty >= 0 ? duty : 0);
    ledc_update_duty(speed_mode, channel_forward);

    ledc_set_duty(speed_mode, channel_backward, duty >= 0 ? 0 : -1*duty);
    ledc_update_duty(speed_mode, channel_backward);
}