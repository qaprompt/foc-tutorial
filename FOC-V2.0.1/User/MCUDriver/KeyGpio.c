#include "KeyGpio.h"
#include "main.h"



/*************************************************************
** Function name:       ReadKeyUPLeave
** Descriptions:        读取上按键电平
** Input parameters:    None
** Output parameters:   None
** Returned value:      上按键电平
** Remarks:             None
*************************************************************/
uint8_t ReadKeyUPLeave(void)
{
    return HAL_GPIO_ReadPin(KEY_UP_GPIO_Port, KEY_UP_Pin);
}
/*************************************************************
** Function name:       ReadKeyDownLeave
** Descriptions:        读取下按键电平
** Input parameters:    None
** Output parameters:   None
** Returned value:      下按键电平
** Remarks:             None
*************************************************************/
uint8_t ReadKeyDownLeave(void)
{
    return HAL_GPIO_ReadPin(KEY_DOWN_GPIO_Port, KEY_DOWN_Pin);
}

