#ifndef WS2812B_H
#define WS2812B_H

#include <stdint.h>

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
 *       Todos os plots nesta matriz é feito em um retângulo 5x3
 *       posições onde se encontra o #
 * 
 *           . # # # .
 *           . # # # .
 *           . # # # .
 *           . # # # .
 *           . # # # .   
 *
 * @author Carlos Valadao
 * @date 23/01/2025
 */

typedef struct
{
    uint8_t color;
    uint8_t intensity;
    uint8_t *matrix;
} ws2812b_t;


uint32_t ws2812b_compose_led_value(uint8_t color, uint8_t intensity);
void ws2812b_draw(const ws2812b_t *ws2812b_ptr);
void ws2812b_turn_off();

#endif