#include "MCUDriverMain.h"

#include "Motor1TIM1PWM.h"
#include "Motor2TIM3PWM.h"

//时间调度
#include "Timer.h"

//
#include "Uart1.h"
/*************************************************************
** Function name:      MCUDriverMain_Init
** Descriptions:       芯片初始化
** Input parameters:   none
** Output parameters:  none
** Returned value:     none
** Created by:         none
** Created date:       none
*************************************************************/
void MCUDriverMain_Init(void)
{
	uint8_t data = 30;
    Motor1TIM1_Init();
	Motor2TIM3_Init();
	//Uart1_SendData(&data,1);
}

/*************************************************************
** Function name:      MCUDriverMain_Loop
** Descriptions:       芯片循环
** Input parameters:   none
** Output parameters:  none
** Returned value:     none
** Created by:         none
** Created date:       none
*************************************************************/
void MCUDriverMain_Loop(void)
{
	
}

