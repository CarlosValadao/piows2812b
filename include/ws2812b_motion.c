#include "ws2812b_motion.h"

void ws2812b_motion_spin(const ws2812b_t *ws2812b_ptr)
{
    return;
}

void ws2812b_motion_sway(const ws2812b_t *ws2812b_ptr)
{
    return;
}

void ws2812b_motion_bounce(const ws2812b_t *ws2812b_ptr)
{
    return;
}

void ws2812b_motion_shift_left(const ws2812b_t *ws2812b_ptr)
{
    return;
}

void ws2812b_motion_shift_right(const ws2812b_t *ws2812b_ptr)
{
    return;
}

void ws2812b_motion_shift_up(const ws2812b_t *ws2812b_ptr)
{
    return;
}

void ws2812b_motion_shift_down(const ws2812b_t *ws2812b_ptr)
{
    return;
}

void ws2812b_motion_zoom(const ws2812b_t *ws2812b_ptr)
{
    return;
}

void ws2812b_motion_contract(const ws2812b_t *ws2812b_ptr)
{
    return;
}

/*########################FUNÇÃO DE PULSAR###########################*/

#define MATRIX_WIDTH 5
#define MATRIX_HEIGHT 5
#define NUM_LEDS 5 * 5

// Matriz de padrões de coração
typedef struct {
    uint8_t r[MATRIX_WIDTH * MATRIX_HEIGHT];
    uint8_t g[MATRIX_WIDTH * MATRIX_HEIGHT];
    uint8_t b[MATRIX_WIDTH * MATRIX_HEIGHT];
} MatrixPattern;

const MatrixPattern heart_patterns[] = {
    {/*Coração pequeno*/
        .r = {
            0, 0, 0, 0, 0,
            0, 0, 255, 0, 0,
            0, 255, 255, 255, 0,
            0, 255, 0, 255, 0,
            0, 0, 0, 0, 0,
        },
        .g = {0},
        .b = {0}
    },
    {/*Coração grande*/
        .r = {
            0, 0, 255, 0, 0,
            0, 255, 255, 255, 0,
            255, 255, 255, 255, 255,
            255, 255, 255, 255, 255,
            0, 255, 0, 255, 0,
        },
        .g = {0},
        .b = {0}
    }
};

static uint32_t rgb_combine(uint8_t r, uint8_t g, uint8_t b)
{
    return (r << 16) | (g << 8) | b;
}

void ws2812b_motion_pulse(PIO pio, int sm)
{
    while(true) {
        //Crescimento do coração
        for (int i = 0; i < sizeof(heart_patterns) / sizeof(MatrixPattern); i++) {
            for (int j = 0; j < NUM_LEDS; j++) {
                uint32_t color = rgb_combine(heart_patterns[i].r[j], heart_patterns[i].g[j], heart_patterns[i].b[j]);
                pio_sm_put_blocking(pio, sm, color);
            }
            sleep_ms(300); 
        }

        //Decrescimento do coração
        for (int i = sizeof(heart_patterns) / sizeof(MatrixPattern) - 1; i >= 0; i--) {
            for (int j = 0; j < NUM_LEDS; j++) {
                uint32_t color = rgb_combine(heart_patterns[i].r[j], heart_patterns[i].g[j], heart_patterns[i].b[j]);
                pio_sm_put_blocking(pio, sm, color);
            }
            sleep_ms(300);
        }
    }
}
