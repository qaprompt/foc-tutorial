#include "FOCConfig.h"
#include "MotorGPIO.h"

#include "Foc.h"
#include "SvpwmConfig.h"
#include "TLE5012BConfig.h"
#include "ADC1.h"

#include "stdio.h"
#include "SEGGER_RTT.h"
#include "SEGGER_RTT_Conf.h"

#include "Timer.h"
//#define AD_TO_CURRENT 0.004028
#define AD_TO_CURRENT 0.0008

#define M1_OUTMAX  12.0f * 0.577f
#define M1_KP  0.002f
#define M1_KI  0.002f
#define M1_KD  0.0f


#define M2_OUTMAX  12.0f * 0.577f
#define M2_KP  0.01f
#define M2_KI  0.01f
#define M2_KD  0.0f
/*************************************************************
** Function name:       GetMotor1PreCurrent
** Descriptions:        获取电机1 3相电流值
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void GetMotor1PreCurrent(float *ua,float *ub,float *uc)
{
	*ua = GetADC1ChannelXValue(2) * AD_TO_CURRENT;
	*ub = GetADC1ChannelXValue(1) * AD_TO_CURRENT;
	*uc = GetADC1ChannelXValue(0) * AD_TO_CURRENT;

}
/*************************************************************
** Function name:       GetMotor2PreCurrent
** Descriptions:        获取电机2 3相电流值
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void GetMotor2PreCurrent(float *ua,float *ub,float *uc)
{
	*ua = GetADC1ChannelXValue(0)* AD_TO_CURRENT;
	*ub = GetADC1ChannelXValue(1)* AD_TO_CURRENT;
	*uc = GetADC1ChannelXValue(2)* AD_TO_CURRENT;

}
//声明两个FOC对象
FOC_EXPORT(gMotor1FOC,7.0f,3,SetMotor1Enable,ReadMotor1Angel,GetMotor1SVPWMSector,GetMotor1PreCurrent,Motor1SvpwmGenerate)
FOC_EXPORT(gMotor2FOC,7.0f,3,SetMotor2Enable,ReadMotor2Angel,GetMotor2SVPWMSector,GetMotor2PreCurrent,Motor2SvpwmGenerate)

/*************************************************************
** Function name:       Motor1FOCConfig_Init
** Descriptions:        电机一FOC初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor1FOCConfig_Init(void)
{
	//设置电机1参数
    SetFocEnable(&gMotor1FOC,1);
    SetCurrentPIDParams(&gMotor1FOC,M1_KP,M1_KI,M1_KD,M1_OUTMAX);
	//设置目标电流
	SetCurrentPIDTar(&gMotor1FOC,0,0);
}
/*************************************************************
** Function name:       Motor2FOCConfig_Init
** Descriptions:        电机二FOC初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor2FOCConfig_Init(void)
{
	//设置电机2参数
    SetFocEnable(&gMotor2FOC,1);
    SetCurrentPIDParams(&gMotor2FOC,M2_KP,M2_KI,M2_KD,M2_OUTMAX);
	//设置目标电流
	SetCurrentPIDTar(&gMotor2FOC,0,0);
}
/*************************************************************
** Function name:       Motor1FOCConfig_Printf
** Descriptions:        电机一FOC打印函数
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor1FOCConfig_Printf(void)
{
	FOCPrintf(&gMotor1FOC);
}
/*************************************************************
** Function name:       Motor2FOCConfig_Printf
** Descriptions:        电机二FOC打印函数
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor2FOCConfig_Printf(void)
{
	FOCPrintf(&gMotor2FOC);
}
/*************************************************************
** Function name:       Motor1FocControl
** Descriptions:        电机一FOC控制函数
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor1FocControl(void)
{
	FocContorl(&gMotor1FOC);
}
/*************************************************************
** Function name:       Motor2FocControl
** Descriptions:        电机二FOC控制函数
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor2FocControl(void)
{
	FocContorl(&gMotor2FOC);
}


/*************************************************************
** Function name:       Motor1SetTarIDIQ
** Descriptions:        设置电机1目标电流
** Input parameters:    id：d轴电流单位A
**						iq: q轴电流单位A
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor1SetTarIDIQ(float id,float iq)
{
	SetCurrentPIDTar(&gMotor1FOC,id,iq);
}
/*************************************************************
** Function name:       Motor2SetTarIDIQ
** Descriptions:        设置电机2目标电流
** Input parameters:    id：d轴电流单位A
**						iq: q轴电流单位A
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor2SetTarIDIQ(float id,float iq)
{
	SetCurrentPIDTar(&gMotor2FOC,id,iq);
}


/*************************************************************
** Function name:       GetMotor1Angle
** Descriptions:        获取电机1机械角度
** Input parameters:    None
** Output parameters:   None
** Returned value:      电机2机械角度
** Remarks:             None
*************************************************************/
float GetMotor1Angle(void)
{
	return GetFocAngle(&gMotor1FOC);
}
/*************************************************************
** Function name:       GetMotor2Angle
** Descriptions:        获取电机2机械角度
** Input parameters:    None
** Output parameters:   None
** Returned value:      电机2机械角度
** Remarks:             None
*************************************************************/
float GetMotor2Angle(void)
{
	return GetFocAngle(&gMotor2FOC);
}

