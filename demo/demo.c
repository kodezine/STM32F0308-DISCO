#include <stdbool.h>
#include "demo.h"
#include "main.h"
#include "stm32f0xx_hal.h"
void app_main(void)
{
    HAL_SYSTICK_Config(600000); /* Set 1ms period for the internal systick which enables 1ms standard tick delay for HAL*/
    do
    {
        HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin); /* Toggle pin after some delay */
        HAL_Delay(200);    /* busy wait delay */
    } while (true);
    return;
}

/*
600000 : 100 -> 25ms
600000 : 200 -> 50ms
*/