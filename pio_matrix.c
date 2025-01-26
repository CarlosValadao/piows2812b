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


//arquivo .pio
#include "pio_matrix.pio.h"

//número de LEDs
#define NUM_PIXELS 25

//pino de saída
#define OUT_PIN 7


//botão de interupção
const uint button_0 = 5;
const uint button_1 = 6;


//rotina da interrupção
static void gpio_irq_handler(uint gpio, uint32_t events){
    printf("Interrupção ocorreu no pino %d, no evento %d\n", gpio, events);
    printf("HABILITANDO O MODO GRAVAÇÃO");
	reset_usb_boot(0,0); //habilita o modo de gravação do microcontrolador
}


//função principal
int main()
{
    

    PIO pio = pio0; 
    bool ok;
    uint16_t i;
    uint32_t valor_led;
    uint8_t *map = NULL;
    ws2812b_t leds;

uint8_t pattern[25] = {
    0, 1, 1, 1, 0,
    0, 1, 0, 1, 0,
    0, 1, 0, 1, 0,
    0, 1, 0, 1, 0,
    0, 1, 1, 1, 0
};

    
    led_shape_t shape = {.pattern = pattern, .color = PURPLE, .intensity = 1, .is_flipped = false};

    ws2812b_t *ws = NULL;

    //coloca a frequência de clock para 128 MHz, facilitando a divisão pelo clock
    ok = set_sys_clock_khz(128000, false);

    // Inicializa todos os códigos stdio padrão que estão ligados ao binário.
    stdio_init_all();

    printf("iniciando a transmissão PIO");
    if (ok) printf("clock set to %ld\n", clock_get_hz(clk_sys));

    //configurações da PIO
    // uint offset = pio_add_program(pio, &pio_matrix_program);
    // uint sm = pio_claim_unused_sm(pio, true);
    // pio_matrix_program_init(pio, sm, offset, OUT_PIN);
    ws = init_ws2812b(pio, OUT_PIN);

    //inicializar o botão de interrupção - GPIO5
    gpio_init(button_0);
    gpio_set_dir(button_0, GPIO_IN);
    gpio_pull_up(button_0);

    gpio_init(button_1);
    gpio_set_dir(button_1, GPIO_IN);
    gpio_pull_up(button_1);

    //interrupção da gpio habilitada
    gpio_set_irq_enabled_with_callback(button_0, GPIO_IRQ_EDGE_FALL, 1, & gpio_irq_handler);
    buzzer_init_default();
    ws2812b_turn_off_all(ws);

    // Inicialização
    PIO pio = pio0;
    ws2812b_t *ws = init_ws2812b(pio, OUT_PIN);

    uint32_t colors[NUM_PIXELS] = {
        0xFF0000, 0x00FF00, 0x0000FF, 0xFFFF00, 0xFF00FF,
        0x00FFFF, 0xFFFFFF, 0x880000, 0x008800, 0x000088,
        0x888800, 0x880088, 0x008888, 0x444444, 0x888888,
        0x220000, 0x002200, 0x000022, 0x222200, 0x220022,
        0x002222, 0x111111, 0x222222, 0x333333, 0x444444
    };

    memcpy(ws->pixels, colors, NUM_PIXELS * sizeof(uint32_t));

    while (true) {
        ws2812b_motion_shift_left(ws); // Move os LEDs para a esquerda
        sleep_ms(500);
    }

    return 0;
    while (true) {
        //buzzer_beep_default(1000, 300);
        //send_ws2812b_data(ws->pio, ws->state_machine_id, 68280);
        //ws2812b_draw(ws, &shape);
        /*for (int i = 0; i < 25; i++) {
            uint8_t physical_index = map[i]; // Usa o mapeamento
            if (pattern[physical_index] == 1) {
                send_ws2812b_data(ws->pio, ws->state_machine_id, 0xFF0000); // Exemplo: vermelho
            } else {
                send_ws2812b_data(ws->pio, ws->state_machine_id, 0x000000); // Desligar LED
            }
        }
        */
        //ws2812b_turn_off_all(ws);
        sleep_ms(500);
        printf("\nfrequeência de clock %ld\r\n", clock_get_hz(clk_sys));
    }
}