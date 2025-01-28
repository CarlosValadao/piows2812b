#ifndef WS2812B_H
#define WS2812B_H

#include <stdint.h>
#include "hardware/pio.h"

// Definição do pino onde o WS2812B está conectado
#define WS2812B_PIN 7

// Definições de cores
#define RED         0       /**< Representa a cor vermelha */
#define GREEN       1       /**< Representa a cor verde */
#define BLUE        2       /**< Representa a cor azul */
#define YELLOW      3       /**< Representa a cor amarela */
#define PURPLE      4       /**< Representa a cor roxa */
#define WHITE       5       /**< Representa a cor branca */
#define BLUE_MARINE 6       /**< Representa a cor azul marinho */

/** 
 * @file ws2812b.h
 * @brief Este arquivo contém declarações de funções e definições relacionadas
 *        ao controle do dispositivo WS2812B, utilizando o Raspberry Pi Pico W.
 *        O WS2812B é um LED RGB endereçável, e o código controla uma matriz
 *        de 5x5 LEDs (25 LEDs no total).
 * 
 *        ***************
 *        *** ATENÇÃO ***
 *        ***************
 *       Todos os plots nesta matriz são feitos em um quadrado 3x3
 *       posições, onde se encontra o "#". Exemplo de matriz:
 * 
 *           . . . . .
 *           . # # # .
 *           . # # # .
 *           . # # # .
 *           . . . . .   
 * 
 * @author Carlos Valadao
 * @date 23/01/2025
 */

/**
 * @brief Estrutura para representar o WS2812B conectado a um pino GPIO
 * 
 * Esta estrutura contém as informações necessárias para controlar o WS2812B,
 * incluindo o identificador do PIO, o ID da máquina de estados, e o pino de saída
 * para enviar dados para o WS2812B.
 */
typedef struct {
    PIO pio;                /**< Ponteiro para o módulo PIO */
    uint state_machine_id;  /**< ID da máquina de estados associada ao WS2812B */
    uint8_t out_pin;        /**< Pino GPIO utilizado para o WS2812B */
} ws2812b_t;

/**
 * @brief Inicializa o WS2812B no pino especificado.
 * 
 * Esta função configura o PIO e a máquina de estados para controlar o WS2812B.
 * Ela aloca uma estrutura `ws2812b_t` e configura o pino de saída para enviar dados
 * para o WS2812B. O PIO (Programmable I/O) é utilizado para gerar o sinal adequado
 * para controlar os LEDs.
 * 
 * @param pio    O módulo PIO que será utilizado.
 * @param pin    O pino GPIO onde o WS2812B está conectado.
 * 
 * @return Um ponteiro para a estrutura `ws2812b_t` inicializada.
 */
ws2812b_t *init_ws2812b(PIO pio, uint8_t pin);

/**
 * @brief Desenha um padrão de LEDs no WS2812B.
 * 
 * Esta função recebe um "glyph" (um padrão de LEDs em formato de matriz 5x5),
 * a cor e a intensidade dos LEDs, e desenha esse padrão no WS2812B conectado.
 * O padrão de LEDs é enviado via PIO, que irá acionar os LEDs de acordo com o
 * padrão especificado.
 * 
 * @param ws        Ponteiro para a estrutura `ws2812b_t` com o WS2812B configurado.
 * @param glyph     Padrão de LEDs a ser exibido (matriz de 5x5).
 * @param color     Cor dos LEDs, definida por uma das macros de cor (ex. `RED`, `GREEN`).
 * @param intensity Intensidade dos LEDs (de 0 a 100).
 */
void ws2812b_draw(const ws2812b_t *ws, const uint8_t *glyph, const uint8_t color, const uint8_t intensity);

/**
 * @brief Desliga todos os LEDs do WS2812B.
 * 
 * Esta função envia um sinal para desligar todos os LEDs da matriz WS2812B, ou seja,
 * todos os LEDs serão apagados (valores 0).
 * 
 * @param ws Ponteiro para a estrutura `ws2812b_t` com o WS2812B configurado.
 */
void ws2812b_turn_off_all(const ws2812b_t *ws);

/**
 * @brief Envia dados para o WS2812B via PIO.
 * 
 * Esta função é responsável por enviar os dados de controle para o WS2812B usando o
 * PIO. Ela envia um dado codificado para acionar os LEDs de acordo com a cor, intensidade
 * e o padrão especificado.
 * 
 * @param pio  O módulo PIO utilizado para enviar os dados.
 * @param sm   O ID da máquina de estados que será utilizada para enviar os dados.
 * @param data Os dados a serem enviados para o WS2812B (controle dos LEDs).
 */
void send_ws2812b_data(PIO pio, uint sm, uint32_t data);

/**
 * @brief Prepara um glyph para ser enviado para o WS2812B.
 * 
 * Esta função realiza ajustes no padrão de LEDs, preparando-o para ser transmitido.
 * A função pode incluir ajustes na intensidade, controle de brilho ou outras operações
 * necessárias antes de enviar os dados para os LEDs.
 * 
 * @param glyph O padrão de LEDs a ser preparado (matriz de 5x5).
 */
void prepare_glyph(uint8_t *glyph);

#endif // WS2812B_H
