#include "MCUDriverMain.h"

#include "Motor1TIM1PWM.h"
#include "Motor2TIM3PWM.h"
#include "Motor1TIM2Encoder.h"
#include "Motor2TIM4Encoder.h"
#include "Motor1EncoderNVIC.h"
#include "Motor2EncoderNVIC.h"

//时间调度
#include "Timer.h"

//通讯
#include "Uart1.h"
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
	uint8_t data = 30;
    Motor1TIM1_Init();
	Motor2TIM3_Init();
	Motor1EncoderZ_Init();
	Motor2EncoderZ_Init();
	Motor1TIM2EncoderInit();
	Motor2TIM4EncoderInit();
	//Uart1_SendData(&data,1);
	Uart1_Init();
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
//	RUN_BY_LIMIT_BLOCK(5,
//		printf("3:%f\r\n",Motor1TIM2EncoderGetAngle());
//		printf("4:%f\r\n",Motor2TIM4EncoderGetAngle());
//	)
//	RUN_BY_LIMIT_BLOCK(500,
//		CAN_Test();
//	)
}

