#include "ws2812b.h"
#include <string.h>

// Função para mover o padrão de LEDs para a esquerda
void ws2812b_motion_shift_left(const ws2812b_t *ws2812b_ptr) {
    if (!ws2812b_ptr || !ws2812b_ptr->pixels) return;

    uint num_pixels = ws2812b_ptr->num_pixels;

    // Armazena o primeiro LED antes do deslocamento
    uint32_t first_pixel = ws2812b_ptr->pixels[0];

    // Move todos os LEDs para a esquerda
    memmove(&ws2812b_ptr->pixels[0], &ws2812b_ptr->pixels[1], (num_pixels - 1) * sizeof(uint32_t));

    // Reinsere o LED inicial no final
    ws2812b_ptr->pixels[num_pixels - 1] = first_pixel;

    // Atualiza os LEDs fisicamente
    for (uint i = 0; i < num_pixels; i++) {
        send_ws2812b_data(ws2812b_ptr->pio, ws2812b_ptr->state_machine_id, ws2812b_ptr->pixels[i]);
    }
}
