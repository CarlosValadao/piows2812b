#ifndef WS2812B_MOTION_H
#define WS2812B_MOTION_H

#include "ws2812b.h"

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

void ws2812b_motion_spin(const ws2812b_t *ws2812b_ptr);
void ws2812b_motion_sway(const ws2812b_t *ws2812b_ptr);
void ws2812b_motion_bounce(const ws2812b_t *ws2812b_ptr);
void ws2812b_motion_shift_left(const ws2812b_t *ws2812b_ptr);
void ws2812b_motion_shift_right(const ws2812b_t *ws2812b_ptr);
void ws2812b_motion_shift_up(const ws2812b_t *ws2812b_ptr);
void ws2812b_motion_shift_down(const ws2812b_t *ws2812b_ptr);
void ws2812b_motion_zoom(const ws2812b_t *ws2812b_ptr);
void ws2812b_motion_contract(const ws2812b_t *ws2812b_ptr);
void ws2812b_motion_pulse(const ws2812b_t *ws2812b_ptr);

#endif