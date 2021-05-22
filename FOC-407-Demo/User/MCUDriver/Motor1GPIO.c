#include "Motor1GPIO.h"
#include "main.h"

/*************************************************************
** Function name:       Motor1SetEnable
** Descriptions:        设置电机1使能标志
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor1SetEnable(uint8_t isEnable)
{
    HAL_GPIO_WritePin(M1_Enable_GPIO_Port,M1_Enable_Pin, (GPIO_PinState)isEnable);
}
