#ifndef MLT8530_H
#define MLT8530_H

#include "pico/stdlib.h"

/** 
 * @file rgb.h
 * @brief Este arquivo contém declarações de funções e definições relacionadas a um
 *        buzzer conectado aos pinos GPIO
 *
 * @author Carlos Valadao
 * @date 17/01/2025
 */

static void buzzer_set_frequency(uint buzzer_pin, uint frequency);
void buzzer_init(uint buzzer_pin);
void buzzer_beep(uint buzzer_pin, uint duration);

#endif
