#include "MCUDriverMain.h"

#include "Motor1TIM1PWM.h"
#include "Motor2TIM3PWM.h"

//时间调度
#include "Timer.h"
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
    Motor1TIM1_Init();
	Motor2TIM3_Init();
	SetMotor1ChannelAHighLeaveTime_us(50);
    SetMotor1ChannelBHighLeaveTime_us(50);
    SetMotor1ChannelCHighLeaveTime_us(50);
	SetMotor2ChannelAHighLeaveTime_us(50);
    SetMotor2ChannelBHighLeaveTime_us(50);
    SetMotor2ChannelCHighLeaveTime_us(50);
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

