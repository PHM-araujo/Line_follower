#ifndef ENCODER_HPP
#define ENCODER_HPP

#include "driver/gpio.h"

class Encoder {
public:
    Encoder(gpio_num_t pinA, gpio_num_t pinB);
    float get_distancia_percorrida();
    float get_velocidade();

private:
    const float METROS_POR_PASSO = 0.01; // Exemplo de constante para a conversão de passos para metros
    gpio_num_t pinA_;
    gpio_num_t pinB_;
    int passos_;
    int ultimo_estado_;
    unsigned long ultimo_tempo_;
};

#endif // ENCODER_HPP





/*
#ifndef ENCODER_HPP
#define ENCODER_HPP

#include <driver/gpio.h>
#include <driver/timer.h>

class Encoder {
public:
    Encoder(gpio_num_t pinA, gpio_num_t pinB); // Construtor

    double get_distancia_percorrida(); // Método para obter a distância percorrida
    double get_velocidade(); // Método para obter a velocidade

private:
    gpio_num_t _pinA, _pinB; // Pinos do encoder
    volatile int _passos; // Passos do encoder
    timer_group_t _timer_group; // Grupo de timer para o ESP32
    timer_idx_t _timer_idx; // Índice do timer para o ESP32

    static void IRAM_ATTR isr_handler(void* arg); // ISR para lidar com as interrupções do encoder
    void processa_passos(); // Método para processar os passos do encoder
};

#endif // ENCODER_HPP



*/

/*#include "Encoder.hpp"

Encoder::Encoder(gpio_num_t pinA, gpio_num_t pinB) : _pinA(pinA), _pinB(pinB), _passos(0) {
    // Configuração dos pinos GPIO e ISR
    gpio_set_direction(_pinA, GPIO_MODE_INPUT);
    gpio_set_direction(_pinB, GPIO_MODE_INPUT);
    gpio_set_intr_type(_pinA, GPIO_INTR_ANYEDGE);
    gpio_set_intr_type(_pinB, GPIO_INTR_ANYEDGE);
    gpio_isr_handler_add(_pinA, isr_handler, (void*) this);
    gpio_isr_handler_add(_pinB, isr_handler, (void*) this);

    // Configuração do timer
    _timer_group = TIMER_GROUP_0;
    _timer_idx = TIMER_0;
    timer_config_t config = {
        .alarm_en = false,
        .counter_en = true,
        .intr_type = TIMER_INTR_LEVEL,
        .counter_dir = TIMER_COUNT_UP,
        .auto_reload = false,
        .divider = 80
    };
    timer_init(_timer_group, _timer_idx, &config);
    timer_start(_timer_group, _timer_idx);
}

double Encoder::get_distancia_percorrida() {
    const double CONSTANTE = 0.01; // Ajuste esta constante para o seu encoder específico
    return _passos * CONSTANTE;
}

double Encoder::get_velocidade() {
    double tempo;
    timer_get_counter_time_sec(_timer_group, _timer_idx, &tempo);
    double distancia = get_distancia_percorrida();
    return distancia / tempo;
}

void IRAM_ATTR Encoder::isr_handler(void* arg) {
    static_cast<Encoder*>(arg)->processa_passos();
}

void Encoder::processa_passos() {
    int MSB = gpio_get_level(_pinA);
    int LSB = gpio_get_level(_pinB);
    int encoded = (MSB << 1) | LSB;
    int sum = (lastEncoded << 2) | encoded;

    if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) _passos--;
    if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) _passos++;

    lastEncoded = encoded;
}
*/