#include "ws2812b_motion.h"
#include "ws2812b.h"
#include "ws2812b_definitions.h"
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include <string.h>
#include <stdlib.h>

static void rotate_clockwise_matrix_90_deg(uint8_t matrix[25]) {
    uint8_t temp[25];

    // Transposta e inversão em um único passo no array unidimensional
    for (uint8_t i = 0; i < 5; i++) {
        for (uint8_t j = 0; j < 5; j++) {
            temp[j * 5 + (5 - 1 - i)] = matrix[i * 5 + j];
        }
    }

    // Copiar o resultado para o array original
    for (uint8_t i = 0; i < 25; i++) {
        matrix[i] = temp[i];
    }
}


void rotate_clockwise_90_deg_glyph(ws2812b_t *ws, uint8_t *glyph, uint8_t color, uint8_t intensity)
{
    uint8_t k;
    uint8_t *aux_glyph = malloc(sizeof(uint8_t) * 25);
    //uint8_t *temp_glyph = malloc(sizeof(uint8_t) * 25);
    memcpy(aux_glyph, glyph, sizeof(uint8_t) * 25);
    for(k = 0; k < 4; k++)
    {
        ws2812b_draw(ws, aux_glyph, color, intensity);
        rotate_clockwise_matrix_90_deg(aux_glyph);
        //memcpy(aux_glyph, temp_glyph, sizeof(uint8_t) * 25);
        sleep_ms(500);
    }
    //free(temp_glyph);
    free(aux_glyph);
}


bool static has_right_side_colision(uint8_t *glyph)
{
    return (glyph[4] || glyph[9] || glyph[14] || glyph[19] || glyph[24]) ? true : false;
}


bool static has_left_side_colision(uint8_t *glyph)
{
    return (glyph[0] || glyph[5] || glyph[10] || glyph[15] || glyph[20]) ? true : false;
}

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


void ws2812b_motion_left_colision(ws2812b_t *ws, uint8_t *glyph, uint8_t color, uint8_t intensity)
{
    uint8_t k;
    uint8_t *aux_glyph = malloc(25 * sizeof(uint8_t));
    uint8_t *temp_glyph = malloc(25 * sizeof(uint8_t));
    memcpy(aux_glyph, glyph, 25 * sizeof(uint8_t));
    while(!has_left_side_colision(aux_glyph))
    {
        ws2812b_motion_shift_left(aux_glyph, temp_glyph);
        ws2812b_draw(ws, aux_glyph, color, intensity);
        memcpy(aux_glyph, temp_glyph, sizeof(uint8_t) * 25);
        sleep_ms(500);
    }
    for(k = 0; k < 3; k++)
    {
        ws2812b_motion_shift_right(aux_glyph, temp_glyph);
        ws2812b_draw(ws, aux_glyph, color, intensity);
        memcpy(aux_glyph, temp_glyph, sizeof(uint8_t) * 25);
        sleep_ms(500);
    }
    ws2812b_motion_shift_left(aux_glyph, temp_glyph);
    ws2812b_draw(ws, aux_glyph, color, intensity);
    memcpy(aux_glyph, temp_glyph, sizeof(uint8_t) * 25);
    sleep_ms(500);
    ws2812b_motion_shift_left(aux_glyph, temp_glyph);
    free(aux_glyph);
    free(temp_glyph);
}

void ws2812b_motion_spin(ws2812b_t *ws, uint8_t color, uint8_t intensity)
{
    uint8_t k;
    for(k = 0; k < 16; k++)
    {
        ws2812b_draw(ws, spins[k], color, intensity);
        sleep_ms(250);
    }
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

uint8_t *ws2812b_motion_pulse(ws2812b_t *ws, uint8_t *glyph)
{
    const uint8_t *heart_glyphs[] = { HEART_SMALL, HEART_MEDIUM, HEART_LARGE };
    uint8_t size_index = 0;
    int8_t direction = 1; // 1: crescente, -1: decrescente
    uint8_t k = 8;
    while (k--)
    {
        // Atualiza o size_index
        size_index += direction;
        if (size_index == 2 || size_index == 0) direction *= -1; // Inverte a direção

        // Atualiza o glyph
        for (uint8_t i = 0; i < 25; i++) glyph[i] = heart_glyphs[size_index][i];

        //transpose(glyph);
        //fliplr(glyph);
        ws2812b_draw(ws, glyph, RED, 1);

        sleep_ms(300);
    }

    return glyph;
}

void ws2812b_motion_slide_left(ws2812b_t *ws, uint8_t *glyph, uint8_t color, uint8_t intensity)
{
    uint8_t i;
    uint8_t *shifted_glyph = malloc(25 * sizeof(uint8_t));
    uint8_t *aux_glyph = malloc(25 * sizeof(uint8_t));
    memcpy(aux_glyph, glyph, 25 * sizeof(uint8_t));
    ws2812b_draw(ws, glyph, color, intensity);
    sleep_ms(500);
    //ws2812b_turn_off_all(ws);
    sleep_ms(50);
    for(i = 0; i < 4; i++)
    {
        ws2812b_motion_shift_left(aux_glyph, shifted_glyph);
        ws2812b_draw(ws, shifted_glyph, color, intensity);
        memcpy(aux_glyph, shifted_glyph, 25 * sizeof(uint8_t));
        sleep_ms(500);
        //ws2812b_turn_off_all(ws);
        sleep_ms(50);
    }
    sleep_ms(20);
    ws2812b_draw(ws, glyph, color, intensity);
    sleep_ms(200);
    free(shifted_glyph);
    free(aux_glyph);
}

void ws2812b_motion_slide_right(ws2812b_t *ws, uint8_t *glyph, uint8_t color, uint8_t intensity)
{
    uint8_t i;
    uint8_t *shifted_glyph = malloc(25 * sizeof(uint8_t));
    uint8_t *aux_glyph = malloc(25 * sizeof(uint8_t));
    memcpy(aux_glyph, glyph, 25 * sizeof(uint8_t));
    ws2812b_draw(ws, glyph, color, intensity);
    sleep_ms(500);
    //ws2812b_turn_off_all(ws);
    sleep_ms(50);
    for(i = 0; i < 4; i++)
    {
        ws2812b_motion_shift_right(aux_glyph, shifted_glyph);
        ws2812b_draw(ws, shifted_glyph, color, intensity);
        memcpy(aux_glyph, shifted_glyph, 25 * sizeof(uint8_t));
        sleep_ms(500);
        //ws2812b_turn_off_all(ws);
        sleep_ms(50);
    }
    sleep_ms(20);
    ws2812b_draw(ws, glyph, color, intensity);
    sleep_ms(200);
    free(shifted_glyph);
    free(aux_glyph);
}

void ws2812b_motion_slide_up(ws2812b_t *ws, uint8_t *glyph, uint8_t color, uint8_t intensity)
{
    uint8_t i;
    uint8_t *shifted_glyph = malloc(25 * sizeof(uint8_t));
    uint8_t *aux_glyph = malloc(25 * sizeof(uint8_t));
    memcpy(aux_glyph, glyph, 25 * sizeof(uint8_t));
    ws2812b_draw(ws, glyph, color, intensity);
    sleep_ms(500);
    //ws2812b_turn_off_all(ws);
    sleep_ms(50);
    for(i = 0; i < 4; i++)
    {
        ws2812b_motion_shift_up(aux_glyph, shifted_glyph);
        ws2812b_draw(ws, shifted_glyph, color, intensity);
        memcpy(aux_glyph, shifted_glyph, 25 * sizeof(uint8_t));
        sleep_ms(500);
        //ws2812b_turn_off_all(ws);
        sleep_ms(50);
    }
    sleep_ms(20);
    ws2812b_draw(ws, glyph, color, intensity);
    sleep_ms(200);
    free(shifted_glyph);
    free(aux_glyph);
}

void ws2812b_motion_slide_down(ws2812b_t *ws, uint8_t *glyph, uint8_t color, uint8_t intensity)
{
    uint8_t i;
    uint8_t *shifted_glyph = malloc(25 * sizeof(uint8_t));
    uint8_t *aux_glyph = malloc(25 * sizeof(uint8_t));
    memcpy(aux_glyph, glyph, 25 * sizeof(uint8_t));
    ws2812b_draw(ws, glyph, color, intensity);
    sleep_ms(500);
    //ws2812b_turn_off_all(ws);
    sleep_ms(50);
    for(i = 0; i < 4; i++)
    {
        ws2812b_motion_shift_down(aux_glyph, shifted_glyph);
        ws2812b_draw(ws, shifted_glyph, color, intensity);
        memcpy(aux_glyph, shifted_glyph, 25 * sizeof(uint8_t));
        sleep_ms(500);
        //ws2812b_turn_off_all(ws);
        sleep_ms(50);
    }
    sleep_ms(20);
    ws2812b_draw(ws, glyph, color, intensity);
    sleep_ms(200);
    free(shifted_glyph);
    free(aux_glyph);
}