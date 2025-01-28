#include "ws2812b_motion.h"


static void fliplr(uint8_t *matrix) {
    uint8_t temp;
    temp = matrix[5];
    matrix[5] = matrix[9]; matrix[9] = temp;
    temp = matrix[6];
    matrix[6] = matrix[8]; matrix[8] = temp;
    temp = matrix[15];
    matrix[15] = matrix[19]; matrix[19] = temp;
    temp = matrix[16];
    matrix[16] = matrix[18]; matrix[18] = temp;
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


void ws2812b_motion_spin(const uint8_t *glyph, const uint8_t color, const uint8_t intensity)
{
    return;
}

void ws2812b_motion_sway(const uint8_t *glyph, const uint8_t color, const uint8_t intensity)
{
    return;
}

void ws2812b_motion_bounce(const uint8_t *glyph, const uint8_t color, const uint8_t intensity)
{
    return;
}

void ws2812b_motion_shift_left(const uint8_t *glyph, const uint8_t color, const uint8_t intensity)
{
    uint8_t i;
    fliplr(glyph);
    for(i = 0; i < 5; i++) left_shift(&(glyph[5 * i]));
    fliplr(glyph);
}

void ws2812b_motion_shift_right(const uint8_t *glyph, const uint8_t color, const uint8_t intensity)
{
    uint8_t i;
    fliplr(glyph);
    for(i = 0; i < 5; i++) right_shift(&(glyph[5 * i]));
    fliplr(glyph);
}

void ws2812b_motion_shift_up(const uint8_t *glyph, const uint8_t color, const uint8_t intensity)
{
    uint8_t i;
    fliplr(glyph);
    transpose(glyph);
    for(i = 0; i < 5; i++) left_shift(&(glyph[5 * i]));
    transpose(glyph);
    fliplr(glyph);
}

void ws2812b_motion_shift_down(const uint8_t *glyph, const uint8_t color, const uint8_t intensity)
{
    uint8_t i;
    fliplr(glyph);
    transpose(glyph);
    for(i = 0; i < 5; i++) right_shift(&(glyph[5 * i]));
    transpose(glyph);
    fliplr(glyph);
}

void ws2812b_motion_zoom(const uint8_t *glyph, const uint8_t color, const uint8_t intensity)
{
    return;
}

void ws2812b_motion_contract(const uint8_t *glyph, const uint8_t color, const uint8_t intensity)
{
    return;
}

void ws2812b_motion_pulse(const uint8_t *glyph, const uint8_t color, const uint8_t intensity)
{
    return;
}
