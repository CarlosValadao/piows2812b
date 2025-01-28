#ifndef WS2812B_MOTION_H
#define WS2812B_MOTION_H

#include "ws2812b.h"
#include <stdint.h>

/** 
 * @file ws2812b.h
 * @brief Este arquivo contém declarações de funções e definições relacionadas
 *        ao dispositivo WS2812B conectado ao pino GPIO do raspebrry pi pico w,
 *        na forma de matriz 5x5 (25 elementos).
 *        Por meio dessa biblioteca é possível "animar" a matriz RGB LED.
 *          
 *        ***************
 *        *** ATENCAO ***
 *        ***************
 *       Todos os plots nesta matriz é feito em um quadrado 3x3
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

void ws2812b_motion_spin(uint8_t *glyph);
void ws2812b_motion_sway(uint8_t *glyph);
void ws2812b_motion_bounce(uint8_t *glyph);
void ws2812b_motion_shift_left(uint8_t *glyph, uint8_t *shifted_glyph);
void ws2812b_motion_shift_right(uint8_t *glyph, uint8_t *shifted_glyph);
void ws2812b_motion_shift_up(uint8_t *glyph, uint8_t *shifted_glyph);
void ws2812b_motion_shift_down(uint8_t *glyph, uint8_t *shifted_glyph);
void ws2812b_motion_zoom(uint8_t *glyph);
void ws2812b_motion_contract(uint8_t *glyph);
void ws2812b_motion_pulse(uint8_t *glyph);
void ws2812b_motion_slide_left(ws2812b_t *ws, uint8_t *glyph, uint8_t color, uint8_t intensity);
void ws2812b_motion_slide_right(uint8_t *glyph, uint8_t color, uint8_t intensity);
void ws2812b_motion_slide_up(uint8_t *glyph, uint8_t color, uint8_t intensity);
void ws2812b_motion_slide_down(uint8_t *glyph, uint8_t color, uint8_t intensity);

#endif