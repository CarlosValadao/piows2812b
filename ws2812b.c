#include "ws2812b.h"
#include <stdlib.h>
#include <string.h>
#include "pio_matrix.pio.h" // Inclua o programa PIO aqui

void ws2812b_init(ws2812b_t *ws2812b, int num_pixels) {
    ws2812b->num_pixels = num_pixels;
    ws2812b->buffer = (uint32_t *)malloc(num_pixels * sizeof(uint32_t));
    if (ws2812b->buffer) {
        memset(ws2812b->buffer, 0, num_pixels * sizeof(uint32_t)); // Inicializa o buffer
    }
}

void ws2812b_update(const ws2812b_t *ws2812b) {
    PIO pio = pio0;
    uint sm = 0; // Ajuste para o state machine correto

    for (int i = 0; i < ws2812b->num_pixels; i++) {
        pio_sm_put_blocking(pio, sm, ws2812b->buffer[i]);
    }
}

void ws2812b_motion_shift_left(const ws2812b_t *ws2812b_ptr) {
    uint32_t first_pixel = ws2812b_ptr->buffer[0];

    for (int i = 0; i < ws2812b_ptr->num_pixels - 1; i++) {
        ws2812b_ptr->buffer[i] = ws2812b_ptr->buffer[i + 1];
    }
    ws2812b_ptr->buffer[ws2812b_ptr->num_pixels - 1] = first_pixel;
}
