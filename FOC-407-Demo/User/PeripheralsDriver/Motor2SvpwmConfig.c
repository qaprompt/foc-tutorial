#include "Motor2SvpwmConfig.h"
//SVPWM框架
#include "Svpwm.h"
//Motor2PWM生成定时器
#include "Motor2TIM3PWM.h"
//打印
#include "stdio.h"
#include "SEGGER_RTT.h"
#include "SEGGER_RTT_Conf.h"



//声明一个SVPWM对象
SVPWM_EXPORT(gMotor2,100.0f,12.0f,
                SetMotor2ChannelAHighLeaveTime_us,
                SetMotor2ChannelBHighLeaveTime_us,
                SetMotor2ChannelCHighLeaveTime_us)
/*************************************************************
** Function name:       Motor2SvpwmGenerate
** Descriptions:        电机一SVPWM生成
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor2SvpwmGenerate(float uα,float uβ)
{
    SvpwmContorol(&gMotor2,uα,uβ);
}
/*************************************************************
** Function name:       GetMotor2SVPWMSector
** Descriptions:        获取电机1的扇区
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
uint8_t Motor2GetSVPWMSector(void)
{
    return GetSVPWMSector(&gMotor2);
}




