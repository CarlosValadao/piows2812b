#ifndef KEYBOARD4X4_H
#define KEYBOARD4X4_H

#include "pico/stdlib.h"

#define HIGH 1  /**< Define o valor lógico alto (1) */
#define LOW  0   /**< Define o valor lógico baixo (0) */

/** 
 * @file keyboard4x4.h
 * @brief Este arquivo contém declarações de funções e definições relacionadas a um
 *        teclado matricial 4x4 conectado ao pino GPIO.
 *
 * Este arquivo fornece funções para inicializar um teclado matricial 4x4 e 
 * para capturar a tecla pressionada a partir de uma matriz de GPIOs conectados.
 * Ele também define a estrutura usada para representar o teclado 4x4.
 *
 * @author Carlos Valadao
 * @date 17/01/2025
 */

/**
 * @brief Estrutura que representa o teclado matricial 4x4.
 * 
 * Esta estrutura contém:
 * - `columns`: Um ponteiro para os pinos de colunas do teclado.
 * - `rows`: Um ponteiro para os pinos de linhas do teclado.
 * - `KEY_MAP`: Um ponteiro para a tabela de mapeamento das teclas.
 */
typedef struct {
    uint *columns;   /**< Ponteiro para os pinos das colunas */
    uint *rows;      /**< Ponteiro para os pinos das linhas */
    char *KEY_MAP;   /**< Ponteiro para o mapeamento das teclas (valores de 0 a 9 e A-Z) */
} keyboard4x4;

/**
 * @brief Inicializa o teclado matricial 4x4.
 * 
 * Esta função configura os pinos GPIO das linhas e colunas e mapeia as teclas
 * para o teclado 4x4. Ela também aloca a estrutura `keyboard4x4` e inicializa
 * os valores passados para as colunas, linhas e mapeamento das teclas.
 *
 * @param columns  Um vetor de 4 pinos representando as colunas do teclado.
 * @param rows     Um vetor de 4 pinos representando as linhas do teclado.
 * @param keyboard_values  Um vetor de 16 caracteres, representando o mapeamento de teclas.
 * 
 * @return Um ponteiro para a estrutura `keyboard4x4` inicializada.
 */
keyboard4x4 *keyboard_init(uint columns[4], uint rows[4], char keyboard_values[16]);

/**
 * @brief Obtém a tecla pressionada no teclado matricial.
 * 
 * Esta função verifica se alguma tecla foi pressionada e retorna a tecla correspondente
 * de acordo com o mapeamento fornecido durante a inicialização do teclado. 
 * Caso nenhuma tecla seja pressionada, a função retornará um valor padrão (por exemplo, '\0').
 *
 * @param keyboard  Ponteiro para a estrutura `keyboard4x4` que contém o teclado.
 * 
 * @return O caractere correspondente à tecla pressionada, ou '\0' se nenhuma tecla estiver pressionada.
 */
char keyboard_get_pressed_key(keyboard4x4 const *keyboard);

#endif
