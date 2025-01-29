#ifndef WS2812B_MOTION_H
#define WS2812B_MOTION_H

#include "ws2812b.h"
#include <stdint.h>

/** 
 * @file ws2812b_motion.h
 * @brief Este arquivo contém declarações de funções relacionadas à animação
 *        de uma matriz de LEDs WS2812B 5x5, permitindo a movimentação e os efeitos visuais nos LEDs.
 *        
 *        ***************
 *        *** ATENÇÃO ***
 *        ***************
 *       Todos os efeitos nesta matriz são realizados em um quadrado 3x3 de LEDs
 *       (no centro da matriz 5x5), conforme ilustrado abaixo:
 * 
 *           . # # # .
 *           . # # # .
 *           . # # # .
 *           . # # # .
 *           . # # # .   
 * 
 * @author Carlos Valadao
 * @date 23/01/2025
 */

/**
 * @brief Função para girar a matriz de LEDs em um movimento de rotação (spin).
 * 
 * Esta função cria um efeito de rotação (movimento circular) de um glyph de LEDs na matriz WS2812B.
 * 
 * @param ws Ponteiro para a estrutura `ws2812b_t` que contém as configurações do WS2812B.
 * @param color Cor a ser usada na animação (ver constantes como `RED`, `GREEN`, etc.).
 * @param intensity Intensidade da cor nos LEDs, de 0 a 100.
 */
void ws2812b_motion_spin(ws2812b_t *ws, uint8_t color, uint8_t intensity);

/**
 * @brief Função de animação que move o glyph de um lado para o outro (sway).
 * 
 * Esta função cria um efeito de movimento lateral suave no glyph de LEDs.
 * 
 * @param glyph Ponteiro para a matriz de LEDs (glyph) a ser movida.
 */
void ws2812b_motion_sway(uint8_t *glyph);

/**
 * @brief Função que faz o glyph "quicar" na matriz de LEDs (efeito de bounce).
 * 
 * Este efeito faz o glyph "quicar" (rebotar) entre os limites da matriz, como uma bola quicando.
 * 
 * @param glyph Ponteiro para a matriz de LEDs (glyph) a ser movida.
 */
void ws2812b_motion_bounce(uint8_t *glyph);

/**
 * @brief Função que realiza um deslocamento do glyph para a esquerda.
 * 
 * Esta função move a matriz de LEDs (glyph) para a esquerda, criando um efeito de "deslizamento".
 * 
 * @param glyph Ponteiro para a matriz de LEDs (glyph) a ser movida.
 * @param shifted_glyph Ponteiro para a matriz de LEDs onde será armazenada a versão movida.
 */
void ws2812b_motion_shift_left(uint8_t *glyph, uint8_t *shifted_glyph);

/**
 * @brief Função que realiza um deslocamento do glyph para a direita.
 * 
 * Esta função move a matriz de LEDs (glyph) para a direita, criando um efeito de "deslizamento".
 * 
 * @param glyph Ponteiro para a matriz de LEDs (glyph) a ser movida.
 * @param shifted_glyph Ponteiro para a matriz de LEDs onde será armazenada a versão movida.
 */
void ws2812b_motion_shift_right(uint8_t *glyph, uint8_t *shifted_glyph);

/**
 * @brief Função que realiza um deslocamento do glyph para cima.
 * 
 * Esta função move a matriz de LEDs (glyph) para cima, criando um efeito de "deslizamento".
 * 
 * @param glyph Ponteiro para a matriz de LEDs (glyph) a ser movida.
 * @param shifted_glyph Ponteiro para a matriz de LEDs onde será armazenada a versão movida.
 */
void ws2812b_motion_shift_up(uint8_t *glyph, uint8_t *shifted_glyph);

/**
 * @brief Função que realiza um deslocamento do glyph para baixo.
 * 
 * Esta função move a matriz de LEDs (glyph) para baixo, criando um efeito de "deslizamento".
 * 
 * @param glyph Ponteiro para a matriz de LEDs (glyph) a ser movida.
 * @param shifted_glyph Ponteiro para a matriz de LEDs onde será armazenada a versão movida.
 */
void ws2812b_motion_shift_down(uint8_t *glyph, uint8_t *shifted_glyph);

/**
 * @brief Função que aplica um efeito de zoom no glyph de LEDs.
 * 
 * Esta função aplica um efeito de zoom na matriz de LEDs (glyph), ampliando ou diminuindo seu tamanho.
 * 
 * @param glyph Ponteiro para a matriz de LEDs (glyph) a ser ajustada.
 */
void ws2812b_motion_zoom(uint8_t *glyph);

/**
 * @brief Função que aplica um efeito de contração no glyph de LEDs.
 * 
 * Este efeito faz o glyph "encolher" na matriz de LEDs, reduzindo seu tamanho.
 * 
 * @param glyph Ponteiro para a matriz de LEDs (glyph) a ser ajustada.
 */
void ws2812b_motion_contract(uint8_t *glyph);

/**
 * @brief Função que cria um efeito de pulsação (pulso) no glyph de LEDs.
 * 
 * A função alterna o tamanho do glyph (como se ele estivesse pulsando), criando um efeito de expansão e contração.
 * 
 * @param ws Ponteiro para a estrutura `ws2812b_t` que contém as configurações do WS2812B.
 * @param glyph Ponteiro para a matriz de LEDs (glyph) a ser animada.
 * 
 * @return uint8_t* O ponteiro para a matriz de LEDs (glyph) após a animação.
 */
uint8_t *ws2812b_motion_pulse(ws2812b_t *ws, uint8_t *glyph);

/**
 * @brief Função que realiza um movimento de deslizamento do glyph para a esquerda.
 * 
 * O glyph é deslocado para a esquerda na matriz de LEDs, criando um efeito de movimento horizontal.
 * 
 * @param ws Ponteiro para a estrutura `ws2812b_t` que contém as configurações do WS2812B.
 * @param glyph Ponteiro para a matriz de LEDs (glyph) a ser movida.
 * @param color A cor a ser utilizada para o movimento.
 * @param intensity A intensidade da cor nos LEDs.
 */
void ws2812b_motion_slide_left(ws2812b_t *ws, uint8_t *glyph, uint8_t color, uint8_t intensity);

/**
 * @brief Função que realiza um movimento de deslizamento do glyph para a direita.
 * 
 * O glyph é deslocado para a direita na matriz de LEDs, criando um efeito de movimento horizontal.
 * 
 * @param ws Ponteiro para a estrutura `ws2812b_t` que contém as configurações do WS2812B.
 * @param glyph Ponteiro para a matriz de LEDs (glyph) a ser movida.
 * @param color A cor a ser utilizada para o movimento.
 * @param intensity A intensidade da cor nos LEDs.
 */
void ws2812b_motion_slide_right(ws2812b_t *ws, uint8_t *glyph, uint8_t color, uint8_t intensity);

/**
 * @brief Função que realiza um movimento de deslizamento do glyph para cima.
 * 
 * O glyph é deslocado para cima na matriz de LEDs, criando um efeito de movimento vertical.
 * 
 * @param ws Ponteiro para a estrutura `ws2812b_t` que contém as configurações do WS2812B.
 * @param glyph Ponteiro para a matriz de LEDs (glyph) a ser movida.
 * @param color A cor a ser utilizada para o movimento.
 * @param intensity A intensidade da cor nos LEDs.
 */
void ws2812b_motion_slide_up(ws2812b_t *ws, uint8_t *glyph, uint8_t color, uint8_t intensity);

/**
 * @brief Função que realiza um movimento de deslizamento do glyph para baixo.
 * 
 * O glyph é deslocado para baixo na matriz de LEDs, criando um efeito de movimento vertical.
 * 
 * @param ws Ponteiro para a estrutura `ws2812b_t` que contém as configurações do WS2812B.
 * @param glyph Ponteiro para a matriz de LEDs (glyph) a ser movida.
 * @param color A cor a ser utilizada para o movimento.
 * @param intensity A intensidade da cor nos LEDs.
 */
void ws2812b_motion_slide_down(ws2812b_t *ws, uint8_t *glyph, uint8_t color, uint8_t intensity);

/**
 * @brief Função que cria um efeito de colisão à esquerda para o glyph de LEDs.
 * 
 * A animação faz o glyph "colidir" no lado esquerdo da matriz de LEDs, gerando uma reação visual.
 * 
 * @param ws Ponteiro para a estrutura `ws2812b_t` que contém as configurações do WS2812B.
 * @param glyph Ponteiro para a matriz de LEDs (glyph) a ser movida.
 * @param color A cor a ser utilizada para o movimento.
 * @param intensity A intensidade da cor nos LEDs.
 */
void ws2812b_motion_left_colision(ws2812b_t *ws, uint8_t *glyph, uint8_t color, uint8_t intensity);

/**
 * @brief Função que realiza uma rotação do glyph de 90 graus no sentido horário.
 * 
 * O glyph é rotacionado em 90 graus no sentido horário, criando um efeito visual de rotação.
 * 
 * @param ws Ponteiro para a estrutura `ws2812b_t` que contém as configurações do WS2812B.
 * @param glyph Ponteiro para a matriz de LEDs (glyph) a ser movida.
 * @param color A cor a ser utilizada para o movimento.
 * @param intensity A intensidade da cor nos LEDs.
 */
void rotate_clockwise_90_deg_glyph(ws2812b_t *ws, uint8_t *glyph, uint8_t color, uint8_t intensity);

#endif
