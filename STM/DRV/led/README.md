
## Usage Example

### Basic LED Control

```c
#include "led_drv_minimal.h"

static void my_led_write(bool state)
{
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, state ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

static void my_led_toggle(void)
{
    HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}

static bool my_led_read(void)
{
    return HAL_GPIO_ReadPin(LED_GPIO_Port, LED_Pin) == GPIO_PIN_SET;
}

int main(void) 
{
    led_t my_led;
    
    led_init(&my_led, my_led_write, my_led_toggle, my_led_read);
    
    led_on(&my_led);      // Turn on
    
    while(1)
    {
        led_toggle(&my_led);
        HAL_Delay(500);
    }
}
