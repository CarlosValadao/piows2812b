#ifndef KEYBOARD4X4_H
#define KEYBOARD4X4_H

#include "pico/stdlib.h"

#define HIGH 1
#define LOW  0

/** 
 * @file keyboard4x4.h
 * @brief Este arquivo contém declarações de funções e definições relacionadas a um
 *        teclado matricial 4x4 conectado ao pino GPIO
 *
 * @author Carlos Valadao
 * @date 17/01/2025
 */

typedef struct {
    uint *columns;
    uint *rows;
    char *KEY_MAP;
} keyboard4x4;

keyboard4x4 *keyboard_init(uint columns[4], uint rows[4], char keyboard_values[16]);
char keyboard_get_pressed_key(keyboard4x4 const *keyboard);

#endif