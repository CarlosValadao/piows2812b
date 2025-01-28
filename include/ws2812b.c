#include "ws2812b.h"
#include "hardware/clocks.h"
#include "pio_matrix.pio.h"
#include <stdlib.h>

// flip the 5x5 matrix (to draw) on ws2812b
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

static uint32_t ws2812b_compose_led_value(uint8_t color, uint8_t intensity)
{
    uint32_t composite_value;
    uint8_t intensity_value = (intensity*255)/100;
    switch (color)
    {
    case RED:
        composite_value = intensity_value << 16;
        break;
    case GREEN:
        composite_value = intensity_value << 24;
        break;
    case BLUE:
        composite_value = intensity_value << 8;
        break;
    case YELLOW:
        intensity_value /= 2u;
        composite_value = ((intensity_value << 16) | (intensity_value << 24));
        break;
    case PURPLE:
        intensity_value /= 2u;
        composite_value = ((intensity_value << 8) | (intensity_value << 16));
        break;
    case WHITE:
        intensity_value /= 3u;
        composite_value = ((intensity_value << 24) | (intensity_value << 16) | (intensity_value << 8));
        break;
    case BLUE_MARINE:
        intensity_value /= 2u;
        composite_value = ((intensity_value << 24) | (intensity_value << 8));
        break;
    default:
        composite_value = 0; // cor não reconhecida
        break;
    }
    return composite_value;
}


void ws2812b_draw(const ws2812b_t *ws, const uint8_t *glyph, const uint8_t color, const uint8_t intensity)
{
    uint8_t i;
    uint32_t composite_value;
    for(i = 0; i < 25; i++) {
        if(glyph[24-i] == 1) {
            composite_value = ws2812b_compose_led_value(color, intensity);
            send_ws2812b_data(ws->pio, ws->state_machine_id, composite_value);
        }
        else send_ws2812b_data(ws->pio, ws->state_machine_id, 0);
    }
}


void ws2812b_turn_off_all(const ws2812b_t *ws)
{
    uint8_t i;
    for(i = 0; i > 25; i++) send_ws2812b_data(ws->pio, ws->state_machine_id, 0);
}

void send_ws2812b_data(PIO pio, uint sm, uint32_t data)
{
    pio_sm_put_blocking(pio, sm, data);
}

ws2812b_t *init_ws2812b(PIO pio, uint8_t pin)
{
    ws2812b_t *ws = malloc(sizeof(ws2812b_t));
    //configurações da PIO
    uint offset = pio_add_program(pio, &pio_matrix_program);
    uint sm = pio_claim_unused_sm(pio, true);

    pio_sm_config c = pio_matrix_program_get_default_config(offset);

    // Set pin to be part of set output group, i.e. set by set instruction
    sm_config_set_set_pins(&c, pin, 1);

    // Attach pio to the GPIO
    pio_gpio_init(pio, pin);

    // Set pin direction to output at the PIO
    pio_sm_set_consecutive_pindirs(pio, sm, pin, 1, true);

    // Set pio clock to 8MHz, giving 10 cycles per LED binary digit
    float div = clock_get_hz(clk_sys) / 8000000.0;
    sm_config_set_clkdiv(&c, div);

    // Give all the FIFO space to TX (not using RX)
    sm_config_set_fifo_join(&c, PIO_FIFO_JOIN_TX);

    // Shift to the left, use autopull, next pull threshold 24 bits
    sm_config_set_out_shift(&c, false, true, 24);

    // Set sticky-- continue to drive value from last set/out.  Other stuff off.
    sm_config_set_out_special(&c, true, false, false);

    // Load configuration, and jump to the start of the program
    pio_sm_init(pio, sm, offset, &c);
    
    // enable this pio state machine
    pio_sm_set_enabled(pio, sm, true);

    // inicialização ws2812b_t
    ws->out_pin = pin;
    ws->state_machine_id = sm;
    ws->pio = pio;
    return ws;
}

void prepare_glyph(uint8_t *glyph)
{
    fliplr(glyph);
}