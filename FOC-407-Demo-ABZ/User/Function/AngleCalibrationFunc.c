#include "AngleCalibrationFunc.h"
//系统
#include "main.h"
//电机1使能引脚
#include "Motor1GPIO.h"
//电机1SVPWM生成
#include "Motor1SvpwmConfig.h"
//电机1磁编码器
#include "Motor1TIM2Encoder.h"
//Motor1PWM生成定时器
#include "Motor1TIM1PWM.h"

//电机2使能引脚
#include "Motor2GPIO.h"
//电机2SVPWM生成
#include "Motor2SvpwmConfig.h"
//电机2磁编码器
#include "Motor2TIM4Encoder.h"
//Motor2PWM生成定时器
#include "Motor2TIM3PWM.h"


//打印
#include "stdio.h"
#include "SEGGER_RTT.h"
#include "SEGGER_RTT_Conf.h"

/*************************************************************
** Function name:       Motor1AngleCalibration
** Descriptions:        电机一角度校准
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor1AngleCalibration(void)
{
	//1.使能电机
	Motor1SetEnable(1);
	//2.电机旋转至a轴
	SetMotor1ChannelAHighLeaveTime_us(80);
	SetMotor1ChannelBHighLeaveTime_us(40);
	SetMotor1ChannelCHighLeaveTime_us(40);
	HAL_Delay(500);
	//3.角度校准
	for (uint8_t i = 0; i < 10; i++) {
		HAL_Delay(10);
		Motor1TIM2EncoderReset();
	}
	//4.电机失能
	SetMotor1ChannelAHighLeaveTime_us(0);
	SetMotor1ChannelBHighLeaveTime_us(0);
	SetMotor1ChannelCHighLeaveTime_us(0);
	//Motor1SetEnable(0);
}


/*************************************************************
** Function name:       Motor2AngleCalibration
** Descriptions:        电机二角度校准
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor2AngleCalibration(void)
{
	//1.使能电机
	Motor2SetEnable(1);
	//2.电机旋转至a轴
	SetMotor2ChannelAHighLeaveTime_us(80);
	SetMotor2ChannelBHighLeaveTime_us(40);
	SetMotor2ChannelCHighLeaveTime_us(40);
	HAL_Delay(500);
	//3.角度校准
	for (uint8_t i = 0; i < 10; i++) {
		Motor2TIM4EncoderReset();
		HAL_Delay(10);
	}
	

	//4.电机失能
	SetMotor2ChannelAHighLeaveTime_us(0);
	SetMotor2ChannelBHighLeaveTime_us(0);
	SetMotor2ChannelCHighLeaveTime_us(0);
	//Motor2SetEnable(0);
}


/*************************************************************
** Function name:      AngleCalibrationFunc_Init
** Descriptions:       编码器角度校准
** Input parameters:   none
** Output parameters:  none
** Returned value:     none
** Created by:         none
** Created date:       none
*************************************************************/
void AngleCalibrationFunc_Init(void)
{
    Motor1AngleCalibration();
	Motor2AngleCalibration();
}




