#include "keyboard4x4.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Inicializa o teclado matricial 4x4.
 * 
 * Esta função configura os pinos GPIO das linhas e colunas do teclado matricial.
 * Também inicializa os pinos das linhas como saídas e os pinos das colunas como entradas.
 * A estrutura `keyboard4x4` é alocada e retornada para uso posterior.
 *
 * @param columns  Um vetor de 4 pinos representando as colunas do teclado.
 * @param rows     Um vetor de 4 pinos representando as linhas do teclado.
 * @param keyboard_values  Um vetor de 16 caracteres, representando o mapeamento de teclas.
 * 
 * @return Um ponteiro para a estrutura `keyboard4x4` inicializada, ou NULL em caso de falha na alocação de memória.
 */
keyboard4x4 *keyboard_init(uint columns[4], uint rows[4], char keyboard_values[16]) {
    // Aloca memória para a estrutura do teclado
    keyboard4x4 *keyboard = malloc(sizeof(keyboard4x4));
    if (!keyboard) {
        return NULL; // Falha na alocação de memória, retorna NULL
    }

    // Atribui os ponteiros para as colunas, linhas e mapeamento das teclas
    keyboard->columns = columns;
    keyboard->rows = rows;
    keyboard->KEY_MAP = keyboard_values;

    // Inicializa os pinos GPIO das linhas e colunas
    for (uint i = 0; i < 4; i++) {
        gpio_init(rows[i]);          // Inicializa o pino da linha
        gpio_init(columns[i]);       // Inicializa o pino da coluna
        gpio_set_dir(rows[i], GPIO_OUT);  // Define as linhas como saídas
        gpio_set_dir(columns[i], GPIO_IN); // Define as colunas como entradas
        gpio_put(rows[i], HIGH);     // Coloca as linhas em nível HIGH
        gpio_pull_up(columns[i]);    // Ativa o resistor pull-up nas colunas
    }

    return keyboard; // Retorna o ponteiro para a estrutura do teclado inicializada
}

/**
 * @brief Obtém a tecla pressionada no teclado matricial.
 * 
 * Esta função verifica se algum botão foi pressionado no teclado 4x4.
 * Ela ativa uma linha de cada vez, verifica as colunas e retorna a tecla correspondente.
 *
 * @param keyboard  Ponteiro para a estrutura `keyboard4x4`, contendo as colunas, linhas e mapeamento das teclas.
 * 
 * @return O caractere correspondente à tecla pressionada, ou '\0' se nenhuma tecla for pressionada.
 */
char keyboard_get_pressed_key(const keyboard4x4 *keyboard) {
    // Loop para verificar cada linha
    for (uint i = 0; i < 4; i++) {
        gpio_put(keyboard->rows[i], LOW);  // Ativa a linha, colocando-a em nível LOW
        // Verifica as colunas para detectar qual tecla foi pressionada
        for (uint j = 0; j < 4; j++) {
            if (!gpio_get(keyboard->columns[j])) { // Se a coluna estiver em nível LOW, significa que a tecla foi pressionada
                gpio_put(keyboard->rows[i], HIGH); // Restaura a linha para HIGH
                return keyboard->KEY_MAP[i * 4 + j]; // Retorna a tecla correspondente ao mapeamento
            }
        }
        gpio_put(keyboard->rows[i], HIGH); // Desativa a linha, colocando-a de volta em HIGH
    }
    return '\0'; // Se nenhuma tecla foi pressionada, retorna '\0'
}
