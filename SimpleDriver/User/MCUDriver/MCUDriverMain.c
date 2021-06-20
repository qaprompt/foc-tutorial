#include "MCUDriverMain.h"
#include "main.h"

#include "TIM1PWM.h"
#include "TIM3Encoder.h"
#include "timer.h"
#include "MotorGPIO.h"
#include "GPIONVIC.h"
//系统电源
#include "ADC2.h"
//通讯
#include "CAN1.h"
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
	TIM1_Init();
	TimerEncoderInit();
	ADC2_Init();
	CAN_Init();
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
//	 RUN_BY_LIMIT_BLOCK(20,
//	 	printf("1:%d\r\n",GetTimer3EncoderCnt());
//	 	printf("2:%f\r\n",GetTimer3EncoderAngle());
//	 )
	RUN_BY_LIMIT_BLOCK(500,
		CAN_Test();
	)
	RUN_BY_LIMIT_BLOCK(100,
		printf("1:%d\r\n",GetADC2Channel10Value());
	)
}


