#include <stdio.h>
#include "mlt8530.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/timer.h"

/**
 * @brief Configura a frequência do buzzer usando PWM.
 * 
 * Esta função ajusta a frequência do som emitido pelo buzzer, utilizando o controle de PWM
 * no pino GPIO especificado. A frequência é configurada através de um divisor de clock
 * que define a taxa de geração do sinal.
 * 
 * @param gpio O pino GPIO onde o buzzer está conectado.
 * @param frequency A frequência do som desejada, em Hertz.
 */
static void buzzer_set_frequency(uint8_t gpio, uint16_t frequency)
{
    // Obter o número do slice do PWM associado ao GPIO
    uint slice_num = pwm_gpio_to_slice_num(gpio);

    // Definir a frequência do clock do Raspberry Pi Pico (125 MHz)
    uint32_t clock_freq = 125000000; // Frequência do clock do Pico (125 MHz)

    // Calcular o divisor do clock necessário para atingir a frequência desejada
    uint32_t divider = clock_freq / (frequency * 65536); // Calcula o divisor para a frequência
    if (divider < 1) divider = 1; // Evitar que o divisor seja menor que 1
    else if (divider > 255) divider = 255; // Limitar o divisor a 255 (máximo permitido)

    // Configurar o PWM com o divisor calculado
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, divider); // Configura o divisor do clock para o PWM

    // Iniciar o PWM com a configuração definida
    pwm_init(slice_num, &config, true); // Inicia o PWM no slice correspondente ao GPIO

    // Definir o nível de duty cycle para 50%, gerando um sinal contínuo (som constante)
    pwm_set_gpio_level(gpio, 32768); // Meio ciclo (50% de duty cycle), valor máximo de 65536
}

/**
 * @brief Inicializa o buzzer passivo no pino especificado.
 * 
 * Esta função configura o pino GPIO onde o buzzer está conectado, preparando-o
 * para gerar sinais PWM e ativar o buzzer. O pino é configurado como saída e 
 * é configurado para controlar o PWM.
 * 
 * @param buzzer_pin O pino GPIO onde o buzzer está conectado.
 */
void buzzer_init(uint8_t buzzer_pin){
    // Inicializa o pino GPIO para uso
    gpio_init(buzzer_pin);
    gpio_set_dir(buzzer_pin, GPIO_OUT); // Configura o pino como saída

    // Configura o pino GPIO para usar a funcionalidade de PWM
    gpio_set_function(buzzer_pin, GPIO_FUNC_PWM); // Configura o pino para controle de PWM
}

/**
 * @brief Emite um beep no buzzer com a frequência e duração especificadas.
 * 
 * Esta função gera um sinal PWM no pino do buzzer com a frequência e duração 
 * desejadas, produzindo um som. O som é emitido pelo buzzer durante o tempo 
 * especificado e, em seguida, o sinal é desativado.
 * 
 * @param buzzer_pin O pino GPIO onde o buzzer está conectado.
 * @param duration A duração do beep, em milissegundos.
 * @param frequency A frequência do beep, em Hertz (Hz).
 */
void buzzer_beep(uint8_t buzzer_pin, uint16_t duration, uint16_t frequency){
    // Configura a frequência do buzzer
    buzzer_set_frequency(buzzer_pin, frequency);

    // Aguarda pela duração especificada para o beep
    sleep_ms(duration);

    // Desativa o buzzer após a duração do beep
    pwm_set_gpio_level(buzzer_pin, 0); // Define o nível de PWM como 0 (desliga o buzzer)
}
