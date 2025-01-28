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
        0, 1, 0, 1, 0,
        0, 1, 0, 1, 0,
        0, 1, 0, 1, 0,
        0, 1, 1, 1, 0
    };

static const uint8_t ONE_GLYPH[] =  { // 1
        0, 0, 1, 0, 0,
        0, 1, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 0, 1, 0, 0,
        0, 1, 1, 1, 0
    };

static const uint8_t TWO_GLYPH[] =  { // 2
        0, 1, 1, 1, 0,
        0, 0, 0, 1, 0,
        0, 1, 1, 1, 0,
        0, 1, 0, 0, 0,
        0, 1, 1, 1, 0
    };

static const uint8_t THREE_GLYPH[] =  { // 3
        0, 1, 1, 1, 0,
        0, 0, 0, 1, 0,
        0, 1, 1, 1, 0,
        0, 0, 0, 1, 0,
        0, 1, 1, 1, 0
    };

static const uint8_t FOUR_GLYPH[] =  { // 4
        0, 1, 0, 1, 0,
        0, 1, 0, 1, 0,
        0, 1, 1, 1, 0,
        0, 0, 0, 1, 0,
        0, 0, 0, 1, 0
    };

static const uint8_t FIVE_GLYPH[] =  { // 5
        0, 1, 1, 1, 0,
        0, 1, 0, 0, 0,
        0, 1, 1, 1, 0,
        0, 0, 0, 1, 0,
        0, 1, 1, 1, 0
    };

static const uint8_t SIX_GLYPH[] =   { // 6
        0, 1, 1, 1, 0,
        0, 1, 0, 0, 0,
        0, 1, 1, 1, 0,
        0, 1, 0, 1, 0,
        0, 1, 1, 1, 0
    };

static const uint8_t SEVEN_GLYPH[] =   { // 7
        0, 1, 1, 1, 0,
        0, 0, 0, 1, 0,
        0, 0, 1, 0, 0,
        0, 1, 0, 0, 0,
        0, 1, 0, 0, 0
    };

static const uint8_t EIGHT_GLYPH[] =   { // 8
        0, 1, 1, 1, 0,
        0, 1, 0, 1, 0,
        0, 1, 1, 1, 0,
        0, 1, 0, 1, 0,
        0, 1, 1, 1, 0
    };

static const uint8_t NINE_GLYPH[] =   { // 9
        0, 1, 1, 1, 0,
        0, 1, 0, 1, 0,
        0, 1, 1, 1, 0,
        0, 0, 0, 1, 0,
        0, 1, 1, 1, 0
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

#endif // WS2812B_DEFINITIONS_H