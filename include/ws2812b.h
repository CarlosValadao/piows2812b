#ifndef WS2812B_H
#define WS2812B_H

#include <stdint.h>
#include "hardware/pio.h"

#define WS2812B_PIN 7
#define RED         0
#define GREEN       1
#define BLUE        2
#define YELLOW      3
#define PURPLE      4
#define WHITE       5
#define BLUE_MARINE 6


/** 
 * @file ws2812b.h
 * @brief Este arquivo contém declarações de funções e definições relacionadas
 *        ao dispositivo WS2812B conectado ao pino GPIO do raspebrry pi pico w,
 *        na forma de matriz 5x5 (25 elementos).
 *       
 *        ***************
 *        *** ATENCAO ***
 *        ***************
 *       Todos os plots nesta matriz é feito em um quadrado 3x3
 *       posições onde se encontra o #
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

typedef struct {
    PIO pio;
    uint state_machine_id;
    uint8_t out_pin;
} ws2812b_t;

typedef struct {
    uint8_t *pattern;
    uint8_t intensity;
    uint8_t color;
    bool is_flipped;
} led_shape_t;

ws2812b_t *init_ws2812b(PIO pio, uint8_t pin);
void ws2812b_draw(const ws2812b_t *ws, const led_shape_t *shape);
void ws2812b_turn_off_all(const ws2812b_t *ws);
void send_ws2812b_data(PIO pio, uint sm, uint32_t data);

#endif // WS2812B