#ifndef MOTOR_HPP
#define MOTOR_HPP
#include "driver/gpio.h"
#include "driver/ledc.h"

class Motor {
  public:
    enum Nivel{
      LOW = 0,
      HIGH = 8191,
    };

    Motor();
    Motor(gpio_num_t pin_forward, gpio_num_t pin_backward, gpio_num_t en, 
        ledc_channel_t channel_forward, 
        ledc_channel_t channel_backward);  
    ~Motor(); // Destructor

    void Init();
    void Stop();  
    void SetDuty(int speed);


  private:
    // Configurações do PWM 
    gpio_num_t pin_forward, pin_backward, en; // GPIO pin number
    ledc_channel_t channel_forward, channel_backward;
    ledc_mode_t speed_mode;
    ledc_timer_t timer_sel;
    uint32_t duty;
    int hpoint;
};

#endif // MOTOR_HPP