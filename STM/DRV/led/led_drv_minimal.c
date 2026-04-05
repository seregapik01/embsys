#include "led_drv_minimal.h"

void led_init(led_t *led,
              void (*write)(bool),
              void (*toggle)(void),
              bool (*read)(void))
{
    led->write_pin = write;
    led->toggle_pin = toggle;
    led->read_pin = read;
    led->is_initialized = true;

    led_off(led);
}

void led_on(led_t *led)
{
    if (!led->is_initialized || !led->write_pin) return;
    led->write_pin(true);
    led->current_state = true;
}

void led_off(led_t *led)
{
    if (!led->is_initialized || !led->write_pin) return;
    led->write_pin(false);
    led->current_state = false;
}

void led_toggle(led_t *led)
{
    if (!led->is_initialized || !led->toggle_pin) return;
    led->toggle_pin();
    if (led->read_pin)
    {
        led->current_state = led->read_pin();
    }
}