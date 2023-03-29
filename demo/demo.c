#include <stdbool.h>
#include "demo.h"
#include "main.h"
#include "stm32f0xx_hal.h"

extern UART_HandleTypeDef huart1;

__NO_RETURN void app_main(void)
{
    HAL_SetTickFreq(HAL_TICK_FREQ_1KHZ);
    //HAL_TIM_Base_Start_IT(&htim1);
    do
    {
        HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin); /* Toggle pin after some delay */
        HAL_Delay(20);    /* busy wait delay */
    } while (true);
}

/*
600000 : 100 -> 25ms
600000 : 200 -> 50ms
*/