#ifndef WS2812B_DEFINITIONS_H
#define WS2812B_DEFINITIONS_H

/**
 * @author Carlos Valadao
 * @file ws2812b_definitions.h
 * @brief Definições de padrões para números de 0 a 9 em uma matriz 5x5 de LEDs WS2812B.
 * 
 * Cada número é representado por um array unidimensional de 25 posições (5x5),
 * onde 0 significa LED apagado e 1 significa LED aceso.
 */

static const uint8_t ZERO_GLYPH[] = { // 0
        0, 1, 1, 1, 0,
        0, 1, 0, 1, 0,  // Linha 1 invertida: 0, 1, 0, 1, 0 -> 0, 1, 0, 1, 0
        0, 1, 0, 1, 0,  // Linha 3 invertida: 0, 1, 0, 1, 0 -> 0, 1, 0, 1, 0
        0, 1, 0, 1, 0,
        0, 1, 1, 1, 0
    };

static const uint8_t ONE_GLYPH[] =  { // 1
        0, 0, 1, 0, 0,
        0, 0, 1, 1, 0,  // Linha 1 invertida: 0, 1, 1, 0, 0 -> 0, 0, 1, 1, 0
        0, 0, 1, 0, 0,  // Linha 3 invertida: 0, 0, 1, 0, 0 -> 0, 0, 1, 0, 0
        0, 0, 1, 0, 0,
        0, 1, 1, 1, 0
    };

static const uint8_t TWO_GLYPH[] =  { // 2
        0, 1, 1, 1, 0,
        0, 1, 0, 0, 0,  // Linha 1 invertida: 0, 0, 0, 1, 0 -> 0, 1, 0, 0, 0
        0, 1, 1, 1, 0,  // Linha 3 invertida: 0, 1, 0, 0, 0 -> 0, 0, 0, 1, 0
        0, 0, 0, 1, 0,
        0, 1, 1, 1, 0
    };

static const uint8_t THREE_GLYPH[] =  { // 3
        0, 1, 1, 1, 0,
        0, 1, 0, 0, 0,  // Linha 1 invertida: 0, 0, 0, 1, 0 -> 0, 1, 0, 0, 0
        0, 1, 1, 1, 0,  // Linha 3 invertida: 0, 0, 0, 1, 0 -> 0, 1, 0, 0, 0
        0, 1, 0, 0, 0,
        0, 1, 1, 1, 0
    };

static const uint8_t FOUR_GLYPH[] =  { // 4
        0, 1, 0, 1, 0,
        0, 1, 0, 1, 0,  // Linha 1 invertida: 0, 1, 0, 1, 0 -> 0, 1, 0, 1, 0
        0, 1, 1, 1, 0,  // Linha 3 invertida: 0, 0, 0, 1, 0 -> 0, 1, 1, 0, 0
        0, 1, 0, 0, 0,
        0, 0, 0, 1, 0
    };

static const uint8_t FIVE_GLYPH[] =  { // 5
        0, 1, 1, 1, 0,
        0, 0, 0, 1, 0,  // Linha 1 invertida: 0, 1, 0, 0, 0 -> 0, 0, 0, 1, 0
        0, 1, 1, 1, 0,  // Linha 3 invertida: 0, 0, 0, 1, 0 -> 0, 1, 1, 1, 0
        0, 1, 0, 0, 0,
        0, 1, 1, 1, 0
    };

static const uint8_t SIX_GLYPH[] =   { // 6
        0, 1, 1, 1, 0,
        0, 0, 0, 1, 0,  // Linha 1 invertida: 0, 1, 0, 0, 0 -> 0, 0, 0, 1, 0
        0, 1, 1, 1, 0,  // Linha 3 invertida: 0, 0, 0, 1, 0 -> 0, 1, 1, 1, 0
        0, 1, 0, 1, 0,
        0, 1, 1, 1, 0
    };

static const uint8_t SEVEN_GLYPH[] =   { // 7
        0, 1, 1, 1, 0,
        0, 1, 0, 0, 0,  // Linha 1 invertida: 0, 0, 0, 1, 0 -> 0, 1, 0, 0, 0
        0, 0, 1, 0, 0,  // Linha 3 invertida: 0, 1, 0, 0, 0 -> 0, 0, 1, 0, 0
        0, 0, 0, 1, 0,
        0, 1, 0, 0, 0
    };

static const uint8_t EIGHT_GLYPH[] =   { // 8
        0, 1, 1, 1, 0,
        0, 1, 0, 1, 0,  // Linha 1 invertida: 0, 1, 0, 1, 0 -> 0, 1, 0, 1, 0
        0, 1, 1, 1, 0,  // Linha 3 invertida: 0, 1, 0, 1, 0 -> 0, 1, 1, 1, 0
        0, 1, 0, 1, 0,
        0, 1, 1, 1, 0
    };

static const uint8_t NINE_GLYPH[] =   { // 9
        0, 1, 1, 1, 0,
        0, 1, 0, 1, 0,  // Linha 1 invertida: 0, 1, 0, 1, 0 -> 0, 1, 0, 1, 0
        0, 1, 1, 1, 0,  // Linha 3 invertida: 0, 0, 0, 1, 0 -> 0, 1, 1, 1, 0
        0, 1, 0, 0, 0,
        0, 1, 1, 1, 0
    };

static const uint8_t ALL_LEDS_ON[] = {
    1, 1, 1, 1, 1,
    1, 1, 1, 1, 1,
    1, 1, 1, 1, 1,
    1, 1, 1, 1, 1,
    1, 1, 1, 1, 1
};


static const uint8_t *NUMERIC_GLYPHS[] = {
    ZERO_GLYPH,
    ONE_GLYPH,
    TWO_GLYPH,
    THREE_GLYPH,
    FOUR_GLYPH,
    FIVE_GLYPH,
    SIX_GLYPH,
    SEVEN_GLYPH,
    EIGHT_GLYPH,
    NINE_GLYPH
};

static const uint8_t HEART_SMALL[] = {
    0, 0, 0, 0, 0,
    0, 1, 0, 1, 0,
    0, 1, 1, 1, 0,
    0, 0, 1, 0, 0,
};

static const uint8_t HEART_MEDIUM[] = {
    0, 0, 0, 0, 0,
    0, 1, 0, 1, 0,
    1, 1, 1, 1, 1,
    0, 1, 1, 1, 0,
    0, 0, 1, 0, 0,
};

static const uint8_t HEART_LARGE[] = {
    0, 1, 0, 1, 0,
    1, 1, 1, 1, 1,
    1, 1, 1, 1, 1,
    0, 1, 1, 1, 0,
    0, 0, 1, 0, 0,
};

static const uint8_t *HEART_GLYPHS[] = {
    HEART_SMALL,
    HEART_MEDIUM,
    HEART_LARGE
};

//desenho do motion spin
static const uint8_t spin_1[25] =   {1, 0, 0, 0, 0,
                                     0, 0, 0, 0, 1, 
                                     1, 0, 1, 0, 0,
                                     0, 0, 0, 0, 1,
                                     1, 0, 0, 0, 0};

static const uint8_t spin_2[25] =   {1, 1, 0, 0, 0,
                                     0, 0, 0, 0, 1, 
                                     1, 0, 1, 0, 0,
                                     0, 0, 0, 0, 1,
                                     0, 0, 0, 0, 0};

static const uint8_t spin_3[25] =   {1, 1, 1, 0, 0,
                                     0, 0, 0, 0, 1, 
                                     1, 0, 1, 0, 0,
                                     0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0};

static const uint8_t spin_4[25] =   {1, 1, 1, 1, 0,
                                     0, 0, 0, 0, 1, 
                                     0, 0, 1, 0, 0,
                                     0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0};

static const uint8_t spin_5[25] =   {1, 1, 1, 1, 1,
                                     0, 0, 0, 0, 0, 
                                     0, 0, 1, 0, 0,
                                     0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0};

static const uint8_t spin_6[25] =   {0, 1, 1, 1, 1,
                                     1, 0, 0, 0, 0, 
                                     0, 0, 1, 0, 0,
                                     0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0};

static const uint8_t spin_7[25] =   {0, 0, 1, 1, 1,
                                     1, 0, 0, 0, 0, 
                                     0, 0, 1, 0, 1,
                                     0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0};

static const uint8_t spin_8[25] =   {0, 0, 0, 1, 1,
                                     1, 0, 0, 0, 0, 
                                     0, 0, 1, 0, 1,
                                     1, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0};

static const uint8_t spin_9[25] =   {0, 0, 0, 0, 1,
                                     1, 0, 0, 0, 0, 
                                     0, 0, 1, 0, 1,
                                     1, 0, 0, 0, 0,
                                     0, 0, 0, 0, 1};

static const uint8_t spin_10[25] =  {0, 0, 0, 0, 0,
                                     1, 0, 0, 0, 0, 
                                     0, 0, 1, 0, 1,
                                     1, 0, 0, 0, 0,
                                     0, 0, 0, 1, 1};

static const uint8_t spin_11[25] =  {0, 0, 0, 0, 0,
                                     1, 0, 0, 0, 0, 
                                     0, 0, 1, 0, 1,
                                     1, 0, 0, 0, 0,
                                     0, 0, 1, 1, 1};

static const uint8_t spin_12[25] =  {0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 
                                     0, 0, 1, 0, 0,
                                     1, 0, 0, 0, 0,
                                     0, 1, 1, 1, 1};

static const uint8_t spin_13[25] =  {0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 
                                     0, 0, 1, 0, 0,
                                     1, 0, 0, 0, 0,
                                     1, 1, 1, 1, 1};

static const uint8_t spin_14[25] =  {0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 
                                     0, 0, 1, 0, 0,
                                     0, 0, 0, 0, 1,
                                     1, 1, 1, 1, 0};

static const uint8_t spin_15[25] =  {0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 0, 
                                     1, 0, 1, 0, 0,
                                     0, 0, 0, 0, 1,
                                     1, 1, 1, 0, 0};

static const uint8_t spin_16[25] =  {0, 0, 0, 0, 0,
                                     0, 0, 0, 0, 1, 
                                     1, 0, 1, 0, 0,
                                     0, 0, 0, 0, 1,
                                     1, 1, 0, 0, 0};

static const uint8_t *spins[] = {spin_1, spin_2, spin_3, spin_4, spin_5, spin_6, spin_7, spin_8, 
                       spin_9, spin_10, spin_11, spin_12, spin_13, spin_14, spin_15, spin_16};

#endif // WS2812B_DEFINITIONS_H