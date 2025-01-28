#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/adc.h"
#include "pico/bootrom.h"
#include "include/keyboard4x4.h"
#include "include/mlt8530.h"
#include "include/ws2812b.h"
#include "include/ws2812b_definitions.h"
#include "include/ws2812b_motion.h"

//arquivo .pio
#include "pio_matrix.pio.h"

//número de LEDs
#define NUM_PIXELS 25

//pino de saída
#define OUT_PIN 7

#define set_bootsel_mode() reset_usb_boot(0, 0)

//botão de interupção
const uint BUTTON_A = 5;


//rotina da interrupção
static void gpio_irq_handler(uint gpio, uint32_t events){
    printf("Interrupção ocorreu no pino %d, no evento %d\n", gpio, events);
    printf("HABILITANDO O MODO GRAVAÇÃO");
	reset_usb_boot(0,0); //habilita o modo de gravação do microcontrolador
}


int main()
{
    PIO pio = pio0; 
    bool ok;
    uint16_t i;
    uint32_t valor_led;
    uint8_t *map = NULL;
    uint8_t shifted_glyph[25];
    ws2812b_t *ws = NULL;
    char pressed_key = '\0';
    uint8_t temp_glyph[25] = {0};

    uint columns[4] = {21, 20, 19, 18};
    uint rows[4] = {16, 27, 26, 22};
    char KEY_MAP[16] = {
        '1', '2', '3', 'A',
        '4', '5', '6', 'B',
        '7', '8', '9', 'C',
        '*', '0', '#', 'D'
    };

    keyboard4x4 *keyboard;

    keyboard = keyboard_init(columns, rows, KEY_MAP);

    buzzer_init_default();

    ok = set_sys_clock_khz(128000, false);
    stdio_init_all();

    printf("iniciando a transmissão PIO");
    if (ok) printf("clock set to %ld\n", clock_get_hz(clk_sys));

    ws = init_ws2812b(pio, OUT_PIN);

    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);

    uint8_t k;
    //interrupção da gpio habilitada
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, 1, & gpio_irq_handler);
    ws2812b_turn_off_all(ws);
    printf("Iniciando o programa...\n");
    while (true) {
        pressed_key = keyboard_get_pressed_key(keyboard);
        if(pressed_key != '\0')
        {
            switch(pressed_key)
            {
                case '1':
                    ws2812b_motion_slide_left(ws, ONE_GLYPH, GREEN, 100);
                    break;
                case '2':
                    ws2812b_motion_slide_right(ws, TWO_GLYPH, RED, 100);
                    break;
                case '3':
                    ws2812b_motion_slide_up(ws, THREE_GLYPH, YELLOW, 100);
                    break;
                case '4':
                    ws2812b_motion_slide_down(ws, FOUR_GLYPH, PURPLE, 100);
                    break;
                case '5':
                    ws2812b_motion_spin(ws, BLUE_MARINE, 10);
                    break;
                case '6':
                    ws2812b_motion_pulse(ws, temp_glyph);
                    for(k = 0; k < 5; k++)
                    {
                        buzzer_beep_default(500, 2000);
                        sleep_ms(700);
                    }
                    break;
                case '7':
                    ws2812b_motion_left_colision(ws, ONE_GLYPH, PURPLE, 100);
                    break;
                case '8':
                    rotate_clockwise_90_deg_glyph(ws, TWO_GLYPH, YELLOW, 100);
                    break;
                case '9':
                    rotate_clockwise_90_deg_glyph(ws, TWO_GLYPH, YELLOW, 100);
                    break;
                case 'A':
                    ws2812b_turn_off_all(ws);
                    break;
                case 'B':
                    ws2812b_draw(ws, ALL_LEDS_ON, BLUE, 100);
                    sleep_ms(100);
                    break;
                case 'C':
                    ws2812b_draw(ws, ALL_LEDS_ON,  RED, 80);
                    sleep_ms(100);
                    break;
                case 'D':
                    ws2812b_draw(ws, ALL_LEDS_ON, GREEN, 50);
                    sleep_ms(100);
                    break;
                case '#':
                    ws2812b_draw(ws, ALL_LEDS_ON, WHITE, 20);
                    sleep_ms(100);
                    break;
                case '*':
                    set_bootsel_mode();
                    break;
                case '0':
                    ws2812b_motion_slide_left(ws, ALL_LEDS_ON, WHITE, 100);
                    break;
            }
        }

    }
}