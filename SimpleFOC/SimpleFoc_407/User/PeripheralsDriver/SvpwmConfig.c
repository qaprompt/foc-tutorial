#include "SvpwmConfig.h"
#include "Svpwm.h"
#include "TIM3.h"
#include "TIM4.h"
#include "ADC1.h"
#include "math.h"
#include "main.h"
#include "arm_math.h"

#include "TLE5012BConfig.h"
#include "MotorGPIO.h"
#include "Timer.h"


#include "stdio.h"
#include "SEGGER_RTT.h"
#include "SEGGER_RTT_Conf.h"



//声明一个SVPWM对象
SVPWM_EXPORT(gMotor1,100.0f,12.0f,
                SetTIM3Channel1HighLeaveTime_us,
                SetTIM3Channel2HighLeaveTime_us,
                SetTIM3Channel3HighLeaveTime_us)


SVPWM_EXPORT(gMotor2,100.0f,12.0f,
                SetTIM4Channel1HighLeaveTime_us,
                SetTIM4Channel2HighLeaveTime_us,
                SetTIM4Channel3HighLeaveTime_us)





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
** Function name:       Motor1SvpwmGenerate
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
** Function name:       GetMotor1SVPWMSector
** Descriptions:        获取电机1的扇区
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
uint8_t GetMotor1SVPWMSector(void)
{
    return GetSVPWMSector(&gMotor1);
}
/*************************************************************
** Function name:       GetMotor2SVPWMSector
** Descriptions:        获取电机2的扇区
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
uint8_t GetMotor2SVPWMSector(void)
{
    return GetSVPWMSector(&gMotor2);
}




