#include "Motor1SvpwmConfig.h"
//SVPWM框架
#include "Svpwm.h"
//Motor1PWM生成定时器
#include "Motor1TIM1PWM.h"
//打印
#include "stdio.h"
#include "SEGGER_RTT.h"
#include "SEGGER_RTT_Conf.h"



//声明一个SVPWM对象
SVPWM_EXPORT(gMotor1,100.0f,12.0f,
                SetMotor1ChannelAHighLeaveTime_us,
                SetMotor1ChannelBHighLeaveTime_us,
                SetMotor1ChannelCHighLeaveTime_us)
/*************************************************************
** Function name:       Motor1SvpwmGenerate
** Descriptions:        电机一SVPWM生成
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor1SvpwmGenerate(float uα,float uβ)
{
    SvpwmContorol(&gMotor1,uα,uβ);
}
/*************************************************************
** Function name:       GetMotor1SVPWMSector
** Descriptions:        获取电机1的扇区
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
uint8_t Motor1GetSVPWMSector(void)
{
    return GetSVPWMSector(&gMotor1);
}




