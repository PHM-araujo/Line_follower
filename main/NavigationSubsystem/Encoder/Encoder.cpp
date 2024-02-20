#include "encoder.hpp"
#include "esp_timer.h"

Encoder::Encoder(gpio_num_t pinA, gpio_num_t pinB) : pinA_(pinA), pinB_(pinB), passos_(0), ultimo_estado_(0), ultimo_tempo_(0) {
    gpio_config_t config;
    config.mode = GPIO_MODE_INPUT;
    config.pull_up_en = GPIO_PULLUP_ENABLE;
    config.pull_down_en = GPIO_PULLDOWN_DISABLE;
    config.intr_type = GPIO_INTR_DISABLE;
    gpio_config(&config);
    gpio_set_level(pinA_, 0); // Pull-up
    gpio_set_level(pinB_, 0); // Pull-up
}

float Encoder::get_distancia_percorrida() {
    return passos_*METROS_POR_PASSO; //vamos multiplicar a quantidade de passos necessaria por uma constante que representa a distancia percorrida por 1 metro, provavelmente será um numero pequeno
    //ex: se 90 passos representam 1 metro, a constante será 1/90
}

float Encoder::get_velocidade() {
    unsigned long tempo_atual = esp_timer_get_time();
    float velocidade;

    // Calcula o tempo desde a última chamada do método get_velocidade
    unsigned long delta_tempo = tempo_atual - ultimo_tempo_;

    // Calcula a velocidade em metros por segundo
    velocidade = (passos_ - ultimo_estado_) / (float)delta_tempo * 1000000; // Converte de microssegundos para segundos

    // Atualiza o estado e o tempo para a próxima chamada
    ultimo_estado_ = passos_;
    ultimo_tempo_ = tempo_atual;

    return velocidade;
}



/*
#include "Encoder.hpp"

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