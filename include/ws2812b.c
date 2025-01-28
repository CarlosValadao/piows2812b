#include "ws2812b.h"
#include "hardware/clocks.h"
#include "pio_matrix.pio.h"
#include <stdlib.h>

/**
 * @brief Inverte horizontalmente a matriz 5x5 para ajustar a visualização.
 * 
 * A função `fliplr` troca os valores de algumas posições específicas para inverter
 * a matriz. Esse processo pode ser útil para a correção do layout ou a orientação
 * dos LEDs em uma matriz física.
 * 
 * @param matrix A matriz 5x5 de LEDs a ser invertida.
 */
static void fliplr(uint8_t *matrix) {
    uint8_t temp;
    // Troca as posições das colunas para inverter a matriz horizontalmente
    temp = matrix[5];
    matrix[5] = matrix[9]; matrix[9] = temp;
    temp = matrix[6];
    matrix[6] = matrix[8]; matrix[8] = temp;
    temp = matrix[15];
    matrix[15] = matrix[19]; matrix[19] = temp;
    temp = matrix[16];
    matrix[16] = matrix[18]; matrix[18] = temp;
}

/**
 * @brief Compor o valor final do LED baseado na cor e intensidade.
 * 
 * Esta função gera o valor final que será enviado para o WS2812B, levando em consideração
 * a cor e a intensidade fornecidas. A intensidade é convertida em um valor de 0 a 255,
 * e a cor é mapeada para o valor adequado (R, G, B, etc.).
 * 
 * @param color     A cor desejada (ex. `RED`, `GREEN`, `BLUE`).
 * @param intensity A intensidade do LED, de 0 a 100.
 * 
 * @return O valor final composto para o LED (32 bits).
 */
static uint32_t ws2812b_compose_led_value(uint8_t color, uint8_t intensity)
{
    uint32_t composite_value;
    uint8_t intensity_value = (intensity * 255) / 100;  // Converter intensidade de 0-100 para 0-255
    switch (color)
    {
    case RED:
        composite_value = intensity_value << 16;  // Desloca para a posição correta para o canal vermelho
        break;
    case GREEN:
        composite_value = intensity_value << 24;  // Desloca para a posição correta para o canal verde
        break;
    case BLUE:
        composite_value = intensity_value << 8;   // Desloca para a posição correta para o canal azul
        break;
    case YELLOW:
        intensity_value /= 2u;  // Amarelo é uma mistura de vermelho e verde
        composite_value = ((intensity_value << 16) | (intensity_value << 24));  // Mistura dos canais vermelho e verde
        break;
    case PURPLE:
        intensity_value /= 2u;  // Roxo é uma mistura de azul e vermelho
        composite_value = ((intensity_value << 8) | (intensity_value << 16));  // Mistura dos canais azul e vermelho
        break;
    case WHITE:
        intensity_value /= 2u;  // Branco é uma mistura de todos os canais com intensidade reduzida
        composite_value = ((intensity_value << 24) | (intensity_value << 16) | (intensity_value << 8));  // Mistura de todos os canais
        break;
    case BLUE_MARINE:
        intensity_value /= 2u;  // Azul-marinho é uma mistura de azul e verde
        composite_value = ((intensity_value << 24) | (intensity_value << 8));  // Mistura dos canais azul e verde
        break;
    default:
        composite_value = 0;  // Cor não reconhecida
        break;
    }
    return composite_value;
}

/**
 * @brief Desenha um padrão de LEDs no WS2812B.
 * 
 * Esta função percorre o padrão de LEDs fornecido (glyph) e, para cada LED ativo
 * (representado pelo valor 1), envia um valor composto para o WS2812B, acionando
 * o LED com a cor e intensidade especificadas. Para LEDs apagados (valor 0), envia 0.
 * 
 * @param ws        Ponteiro para a estrutura `ws2812b_t`, que contém as informações do WS2812B.
 * @param glyph     A matriz 5x5 que define o padrão de LEDs a ser exibido.
 * @param color     A cor dos LEDs a serem acionados.
 * @param intensity A intensidade dos LEDs (0 a 100%).
 */
void ws2812b_draw(const ws2812b_t *ws, const uint8_t *glyph, const uint8_t color, const uint8_t intensity)
{
    uint8_t i;
    uint32_t composite_value;
    for (i = 0; i < 25; i++) {
        if (glyph[24 - i] == 1) {  // Percorre os LEDs da matriz, de trás para frente
            composite_value = ws2812b_compose_led_value(color, intensity);  // Gera o valor do LED com a cor e intensidade
            send_ws2812b_data(ws->pio, ws->state_machine_id, composite_value);  // Envia o valor para o WS2812B
        }
        else {
            send_ws2812b_data(ws->pio, ws->state_machine_id, 0);  // Se o LED estiver apagado, envia 0
        }
    }
}

/**
 * @brief Desliga todos os LEDs do WS2812B.
 * 
 * Esta função envia 0 para todos os LEDs da matriz, apagando todos os LEDs
 * conectados ao WS2812B.
 * 
 * @param ws Ponteiro para a estrutura `ws2812b_t`, que contém as informações do WS2812B.
 */
void ws2812b_turn_off_all(const ws2812b_t *ws)
{
    uint8_t i;
    for (i = 0; i < 25; i++) {
        send_ws2812b_data(ws->pio, ws->state_machine_id, 0);  // Envia 0 para cada LED
    }
}

/**
 * @brief Envia dados para o WS2812B via PIO.
 * 
 * Esta função é responsável por enviar um dado para o WS2812B utilizando o módulo PIO
 * do Raspberry Pi Pico. A função `pio_sm_put_blocking` coloca o dado na máquina de estados,
 * acionando o LED correspondente.
 * 
 * @param pio  O módulo PIO a ser utilizado.
 * @param sm   O ID da máquina de estados a ser utilizada.
 * @param data O dado (valor de cor) a ser enviado ao WS2812B.
 */
void send_ws2812b_data(PIO pio, uint sm, uint32_t data)
{
    pio_sm_put_blocking(pio, sm, data);  // Envia o dado para a máquina de estados
}

/**
 * @brief Inicializa o WS2812B no pino especificado.
 * 
 * Esta função configura o PIO e a máquina de estados para controlar o WS2812B. O pino
 * é configurado para enviar dados para o WS2812B, e a configuração do clock é ajustada
 * para 8 MHz, permitindo controlar os LEDs com precisão.
 * 
 * @param pio  O módulo PIO a ser utilizado.
 * @param pin  O pino GPIO onde o WS2812B está conectado.
 * 
 * @return Um ponteiro para a estrutura `ws2812b_t` que contém as informações de controle.
 */
ws2812b_t *init_ws2812b(PIO pio, uint8_t pin)
{
    ws2812b_t *ws = malloc(sizeof(ws2812b_t));  // Aloca memória para a estrutura
    uint offset = pio_add_program(pio, &pio_matrix_program);  // Adiciona o programa PIO
    uint sm = pio_claim_unused_sm(pio, true);  // Requisita uma máquina de estados não utilizada

    // Configuração do PIO para enviar dados para o WS2812B
    pio_sm_config c = pio_matrix_program_get_default_config(offset);
    sm_config_set_set_pins(&c, pin, 1);  // Configura o pino para ser usado para envio de dados

    pio_gpio_init(pio, pin);  // Inicializa o pino GPIO
    pio_sm_set_consecutive_pindirs(pio, sm, pin, 1, true);  // Define o pino como saída

    // Configura o clock do PIO para 8 MHz
    float div = clock_get_hz(clk_sys) / 8000000.0;
    sm_config_set_clkdiv(&c, div);

    sm_config_set_fifo_join(&c, PIO_FIFO_JOIN_TX);  // Apenas transmite dados, não recebe

    sm_config_set_out_shift(&c, false, true, 24);  // Configura o shift de 24 bits para os LEDs

    sm_config_set_out_special(&c, true, false, false);  // Configuração especial para saída

    pio_sm_init(pio, sm, offset, &c);  // Inicializa a máquina de estados com a configuração
    pio_sm_set_enabled(pio, sm, true);  // Ativa a máquina de estados
