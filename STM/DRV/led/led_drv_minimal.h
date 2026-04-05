#ifndef LED_DRV_H
#define LED_DRV_H

#include <stdbool.h>

typedef struct
{
    void (*write_pin)(bool state);
    void (*toggle_pin)(void);
    bool (*read_pin)(void);

    bool is_initialized;
    bool current_state;
} led_t;

void led_init(led_t *led,
              void (*write)(bool),
              void (*toggle)(void),
              bool (*read)(void));

void led_on(led_t *led);
void led_off(led_t *led);
void led_toggle(led_t *led);
bool led_is_on(led_t *led);

#endif