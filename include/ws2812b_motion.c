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


void ws2812b_motion_spin(led_shape_t *shape)
{
    return;
}

void ws2812b_motion_sway(led_shape_t *shape)
{
    return;
}

void ws2812b_motion_bounce(led_shape_t *shape)
{
    return;
}

void ws2812b_motion_shift_left(led_shape_t *shape)
{
    uint8_t i;
    fliplr(shape->pattern);
    for(i = 0; i < 5; i++) left_shift(&(shape->pattern[5 * i]));
    fliplr(shape->pattern);
}

void ws2812b_motion_shift_right(led_shape_t *shape)
{
    uint8_t i;
    fliplr(shape->pattern);
    for(i = 0; i < 5; i++) right_shift(&(shape->pattern[5 * i]));
    fliplr(shape->pattern);
}

void ws2812b_motion_shift_up(led_shape_t *shape)
{
    uint8_t i;
    fliplr(shape->pattern);
    transpose(shape->pattern);
    for(i = 0; i < 5; i++) left_shift(&(shape->pattern[5 * i]));
    transpose(shape->pattern);
    fliplr(shape->pattern);
}

void ws2812b_motion_shift_down(led_shape_t *shape)
{
    return;
}

void ws2812b_motion_zoom(led_shape_t *shape)
{
    return;
}

void ws2812b_motion_contract(led_shape_t *shape)
{
    return;
}

void ws2812b_motion_pulse(led_shape_t *shape)
{
    return;
}
