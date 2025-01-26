#include "ws2812b_motion.h"


static void right_shift(uint8_t arr[5])
{
    uint8_t i;
    for(i = 4; i >= 0; i--) arr[i] = arr[i-1];
    arr[0] = 0;
}

void ws2812b_motion_spin(led_shape_t *shape)
{
    return;
}

void ws2812b_motion_sway(led_shape_t *shape)
{
    return;
}

void ws2812b_motion_bounce(led_shape_t *shape)
{
    return;
}

void ws2812b_motion_shift_left(led_shape_t *shape)
{
    return;
}

void ws2812b_motion_shift_right(led_shape_t *shape)
{
    return;
}

void ws2812b_motion_shift_up(led_shape_t *shape)
{
    return;
}

void ws2812b_motion_shift_down(led_shape_t *shape)
{
    return;
}

void ws2812b_motion_zoom(led_shape_t *shape)
{
    return;
}

void ws2812b_motion_contract(led_shape_t *shape)
{
    return;
}

void ws2812b_motion_pulse(led_shape_t *shape)
{
    return;
}
