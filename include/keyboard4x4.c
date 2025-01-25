#include "keyboard4x4.h"
#include <stdlib.h>
#include <stdio.h>


keyboard4x4 *keyboard_init(uint columns[4], uint rows[4], char keyboard_values[16]) {
    keyboard4x4 *keyboard = malloc(sizeof(keyboard4x4));
    if (!keyboard) {
        return NULL; // Falha na alocação
    }
    keyboard->columns = columns;
    keyboard->rows = rows;
    keyboard->KEY_MAP = keyboard_values;
    for (uint i = 0; i < 4; i++) {
        gpio_init(rows[i]);
        gpio_init(columns[i]);
        gpio_set_dir(rows[i], GPIO_OUT); // Linhas como saída
        gpio_set_dir(columns[i], GPIO_IN); // Colunas como entrada
        gpio_put(rows[i], HIGH); // Inicializa as linhas como HIGH
        gpio_pull_up(columns[i]); // Ativa pull-up para as colunas
    }
    return keyboard;
}

char keyboard_get_pressed_key(const keyboard4x4 *keyboard) {
    for (uint i = 0; i < 4; i++) {
        gpio_put(keyboard->rows[i], LOW); // Ativa a linha
        //sleep_ms(15); // Tempo para estabilização
        for (uint j = 0; j < 4; j++) {
            if (!gpio_get(keyboard->columns[j])) { // Verifica LOW (botão pressionado)
                gpio_put(keyboard->rows[i], HIGH); // Restaura a linha
                printf("I -> %u J -> %u\n", i, j);
                return keyboard->KEY_MAP[i * 4 + j];
            }
        }
      gpio_put(keyboard->rows[i], HIGH); // Desativa a linha
    }
    return '\0'; // Nenhuma tecla pressionada
}
