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
#include "include/ws2812b_motion.h"

//arquivo .pio
#include "build/pio_matrix.pio.h"

//número de LEDs
#define NUM_PIXELS 25

//pino de saída
#define OUT_PIN 7

//botão de interupção
const uint button_0 = 5;


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
    double r = 0.0, b = 0.0 , g = 0.0;

    //coloca a frequência de clock para 128 MHz, facilitando a divisão pelo clock
    ok = set_sys_clock_khz(128000, false);

    // Inicializa todos os códigos stdio padrão que estão ligados ao binário.
    stdio_init_all();

    printf("iniciando a transmissão PIO");
    if (ok) printf("clock set to %ld\n", clock_get_hz(clk_sys));

    //configurações da PIO
    uint offset = pio_add_program(pio, &pio_matrix_program);
    uint sm = pio_claim_unused_sm(pio, true);
    pio_matrix_program_init(pio, sm, offset, OUT_PIN);

    //inicializar o botão de interrupção - GPIO5
    gpio_init(button_0);
    gpio_set_dir(button_0, GPIO_IN);
    gpio_pull_up(button_0);

    //interrupção da gpio habilitada
    gpio_set_irq_enabled_with_callback(button_0, GPIO_IRQ_EDGE_FALL, 1, & gpio_irq_handler);

    //Definição dos pinos do teclado
    uint columns[4] = {16, 18, 19, 20};
    uint rows[4] = {21, 22, 26, 27};
    char KEY_MAP[16] = {
        '1', '2', '3', 'A',
        '4', '5', '6', 'B',
        '7', '8', '9', 'C',
        '*', '0', '#', 'D'
    };

    keyboard4x4 *keyboard = keyboard_init(columns, rows, KEY_MAP);
    char key = '\0';

    while (true) {
        sleep_ms(500);
        /*printf("\nfrequencia de clock %ld\r\n", clock_get_hz(clk_sys));*/

        //Obter a tecla pressionada
        key = keyboard_get_pressed_key(keyboard);

        //Se a tecla não for nula, imprime a tecla pressionada
        if (key != '\0') {
            printf("Tecla pressionada: %c\n", key);
            //Executa a função de acordo à tecla pressionada
            if (key == '6') {
                printf("Chamando ws2812b_motion_pulse\n");
                ws2812b_motion_pulse(pio, sm);
                printf("ws2812b_motion_pulse chamada\n");
            }
        }
    }
}
