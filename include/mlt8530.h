#ifndef MLT8530_H
#define MLT8530_H

#include "pico/stdlib.h"

/** 
 * @file mlt8530.h
 * @brief Este arquivo contém declarações de funções e definições relacionadas ao
 *        controle de um buzzer passivo MLT8530 conectado aos pinos GPIO do Raspberry Pi Pico.
 *
 * O código permite a inicialização e o acionamento do buzzer passivo para emitir sons com 
 * frequências e durações específicas, configurando os pinos GPIO para gerar o sinal necessário.
 *
 * @author Carlos Valadao
 * @date 17/01/2025
 */

// Define o pino GPIO onde o buzzer está conectado
#define BUZZER_PIN 13 /**< Pino GPIO 13 onde o buzzer está conectado */

// Macros para facilitar a inicialização e o acionamento do buzzer com o pino padrão
#define buzzer_beep_default(duration, frequency) buzzer_beep(BUZZER_PIN, duration, frequency) /**< Macro que chama a função buzzer_beep com o pino padrão */
#define buzzer_init_default() buzzer_init(BUZZER_PIN) /**< Macro que chama a função buzzer_init com o pino padrão */

/**
 * @brief Inicializa o buzzer passivo conectado ao pino GPIO especificado.
 * 
 * Esta função configura o pino GPIO onde o buzzer está conectado para operar com
 * a frequência de pulso adequada para emitir som. O pino é configurado como saída
 * e o sinal de controle é gerado para ativar o buzzer.
 * 
 * @param buzzer_pin O pino GPIO onde o buzzer está conectado.
 */
void buzzer_init(uint8_t buzzer_pin);

/**
 * @brief Emite um beep no buzzer passivo com a duração e frequência especificadas.
 * 
 * Esta função gera um sinal de controle para o buzzer passivo, fazendo-o emitir
 * um som com a frequência e a duração passadas como parâmetros. A frequência
 * determina o tom do som e a duração especifica quanto tempo o buzzer irá emitir
 * o som.
 * 
 * @param buzzer_pin O pino GPIO onde o buzzer está conectado.
 * @param duration A duração do beep, em milissegundos.
 * @param frequency A frequência do beep, em Hertz (Hz).
 */
void buzzer_beep(uint8_t buzzer_pin, uint16_t duration, uint16_t frequency);

#endif // MLT8530_H
