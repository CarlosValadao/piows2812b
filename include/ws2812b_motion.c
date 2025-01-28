#include "ws2812b_motion.h"
#include "ws2812b_definitions.h"


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


uint8_t *ws2812b_motion_spin(uint8_t *glyph)
{
    return;
}

uint8_t *ws2812b_motion_sway(uint8_t *glyph)
{
    return;
}

uint8_t *ws2812b_motion_bounce(uint8_t *glyph)
{
    return;
}

uint8_t *ws2812b_motion_shift_left(uint8_t *glyph)
{
    uint8_t i;
    uint8_t flipped_glyph[5];
    fliplr(glyph);
    for(i = 0; i < 5; i++) left_shift(&(glyph[5 * i]));
    fliplr(glyph);
}

uint8_t *ws2812b_motion_shift_right(uint8_t *glyph)
{
    uint8_t i;
    fliplr(glyph);
    for(i = 0; i < 5; i++) right_shift(&(glyph[5 * i]));
    fliplr(glyph);
}

uint8_t *ws2812b_motion_shift_up(uint8_t *glyph)
{
    uint8_t i;
    fliplr(glyph);
    transpose(glyph);
    for(i = 0; i < 5; i++) left_shift(&(glyph[5 * i]));
    transpose(glyph);
    fliplr(glyph);
}

uint8_t *ws2812b_motion_shift_down(uint8_t *glyph)
{
    uint8_t i;
    fliplr(glyph);
    transpose(glyph);
    for(i = 0; i < 5; i++) right_shift(&(glyph[5 * i]));
    transpose(glyph);
    fliplr(glyph);
}

uint8_t *ws2812b_motion_zoom(uint8_t *glyph)
{
    return;
}

uint8_t *ws2812b_motion_contract(uint8_t *glyph)
{
    return;
}

uint8_t *ws2812b_motion_pulse(uint8_t *glyph)
{
    const uint8_t *heart_glyphs[] = {HEART_SMALL, HEART_MEDIUM, HEART_LARGE};
    uint8_t size_index = 0;
    int8_t direction = 1; // 1: crescente, -1: decrescente

    while (1)
    {
        // Atualiza o size_index
        size_index += direction;
        if (size_index == 2 || size_index == 0) direction *= -1; // Inverte a direção

        // Atualiza o glyph
        for (uint8_t i = 0; i < 25; i++) glyph[i] = heart_glyphs[size_index][i];

        //transpose(glyph);
        //fliplr(glyph);

        sleep_ms(100);
    }

    return glyph;
}