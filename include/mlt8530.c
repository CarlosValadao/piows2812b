#include <stdio.h>
#include "mlt8530.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/timer.h"

#define BUZZER_FREQUENCY 500

static void buzzer_set_frequency(uint gpio, uint frequency)
{
    // Obter o slice do PWM para o GPIO
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    // Configurar a frequência
    uint32_t clock_freq = 125000000; // Frequência do clock (125 MHz no Pico)
    uint32_t divider = clock_freq / (frequency * 65536); // Divisor para a frequência desejada
    if (divider < 1)
        divider = 1; // Evitar divisão menor que 1
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, divider); // Configurar o divisor do clock
    pwm_init(slice_num, &config, true); // Iniciar o PWM
    // Configurar a duty cycle (50% para som contínuo)
    pwm_set_gpio_level(gpio, 32768); // Meio do ciclo (50%)
}

void buzzer_init(uint buzzer_pin){
    gpio_init(buzzer_pin);
    gpio_set_dir(buzzer_pin, GPIO_OUT);
    // Configurar o GPIO para PWM
    gpio_set_function(buzzer_pin, GPIO_FUNC_PWM); 
}

void buzzer_beep(uint buzzer_pin, uint duration){
    buzzer_set_frequency(buzzer_pin, BUZZER_FREQUENCY);
    sleep_ms(duration);
    pwm_set_gpio_level(buzzer_pin, 0);
 }
