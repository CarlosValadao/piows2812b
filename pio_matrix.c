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
    uint k;

    uint8_t glyph[25] = {0}; 

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
       for(k=0;k<10;k++)
       {
        ws2812b_draw(ws, NUMERIC_GLYPHS[k], PURPLE, 1);
        sleep_ms(1500);
        ws2812b_turn_off_all(ws);
        
        sleep_ms(50);
       }
        printf("\nfrequeência de clock %ld\r\n", clock_get_hz(clk_sys));
    }

    return 0;
}
