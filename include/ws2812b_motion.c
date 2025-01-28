#include "ws2812b_motion.h"
#include <string.h>
#include <stdlib.h>


static void fliplr(uint8_t *glyph) {
    uint8_t temp;
    temp = glyph[5];
    glyph[5] = glyph[9]; glyph[9] = temp;
    temp = glyph[6];
    glyph[6] = glyph[8]; glyph[8] = temp;
    temp = glyph[15];
    glyph[15] = glyph[19]; glyph[19] = temp;
    temp = glyph[16];
    glyph[16] = glyph[18]; glyph[18] = temp;
}

static void right_shift(uint8_t *arr)
{
    uint8_t i;
    for(i = 4; i > 0; i--) arr[i] = arr[i-1];
    arr[0] = 0;
}

static void left_shift(uint8_t *arr)
{
    uint8_t i;
    for(i = 0; i < 4; i++) arr[i] = arr[i+1];
    arr[4] = 0;
}

// realiza a transposta de arr, sendo ele um array
// de 25 posicoes (5x5)
static void transpose(uint8_t *arr)
{
    uint8_t temp;
    uint8_t i;
    uint8_t j;
    for(i = 0; i < 5; i++)
    {
        for(j=i+1; j < 5; j++)
        {
            temp = arr[i * 5 + j];
            arr[i * 5 + j] = arr[j * 5 + i];
            arr[j * 5 + i] = temp;
        }
    }
}


void ws2812b_motion_spin(uint8_t *glyph)
{
    return;
}

void ws2812b_motion_sway(uint8_t *glyph)
{
    return;
}

void ws2812b_motion_bounce(uint8_t *glyph)
{
    return;
}

void ws2812b_motion_shift_left(uint8_t *glyph, uint8_t *shifted_glyph)
{
    uint8_t i;
    memcpy(shifted_glyph, glyph, 25 * sizeof(uint8_t));
    fliplr(shifted_glyph);
    for(i = 0; i < 5; i++) left_shift(&(shifted_glyph[5 * i]));
    fliplr(shifted_glyph);
}

void ws2812b_motion_shift_right(uint8_t *glyph, uint8_t *shifted_glyph)
{
    uint8_t i;
    memcpy(shifted_glyph, glyph, 25 * sizeof(uint8_t));
    fliplr(shifted_glyph);
    for(i = 0; i < 5; i++) right_shift(&(shifted_glyph[5 * i]));
    fliplr(shifted_glyph);
}

void ws2812b_motion_shift_up(uint8_t *glyph, uint8_t *shifted_glyph)
{
    uint8_t i;
    memcpy(shifted_glyph, glyph, 25 * sizeof(uint8_t));
    fliplr(shifted_glyph);
    transpose(shifted_glyph);
    for(i = 0; i < 5; i++) left_shift(&(shifted_glyph[5 * i]));
    transpose(shifted_glyph);
    fliplr(shifted_glyph);
}

void ws2812b_motion_shift_down(uint8_t *glyph, uint8_t *shifted_glyph)
{
    uint8_t i;
    memcpy(shifted_glyph, glyph, 25 * sizeof(uint8_t));
    fliplr(shifted_glyph);
    transpose(shifted_glyph);
    for(i = 0; i < 5; i++) right_shift(&(shifted_glyph[5 * i]));
    transpose(shifted_glyph);
    fliplr(shifted_glyph);
}

void ws2812b_motion_zoom(uint8_t *glyph)
{
    return;
}

void ws2812b_motion_contract(uint8_t *glyph)
{
    return;
}

void ws2812b_motion_pulse(uint8_t *glyph)
{
    return;
}