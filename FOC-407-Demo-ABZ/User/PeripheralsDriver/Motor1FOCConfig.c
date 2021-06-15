#include "Motor1FOCConfig.h"
//FOC框架
#include "Foc.h"
//电机使能引脚
#include "Motor1GPIO.h"
//电机1SVPWM生成
#include "Motor1SvpwmConfig.h"
//电机1磁编码器
#include "Motor1TIM2Encoder.h"
//电机1电流采集
#include "Motor1ADC1.h"

#define AD_TO_CURRENT 0.00032

#define M1_OUTMAX  12.0f * 0.577f
#define M1_KP  0.018f
#define M1_KI  0.018f
#define M1_KD  0.0f


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
	*ua = GetMotor1ADC1PhaseXValue(0) * AD_TO_CURRENT * 1.5;
	*ub = GetMotor1ADC1PhaseXValue(1) * AD_TO_CURRENT * 1.5;
	*uc = GetMotor1ADC1PhaseXValue(2) * AD_TO_CURRENT * 1.5;

}
//声明FOC对象
FOC_EXPORT(gMotor1FOC,7.0f,3,Motor1SetEnable,Motor1TIM2EncoderGetAngle,Motor1GetSVPWMSector,GetMotor1PreCurrent,Motor1SvpwmGenerate)

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
** Function name:       Motor1GetPreIDIQ
** Descriptions:        获取电机1实际电流
** Input parameters:    None
** Output parameters:   None
** Returned value:      Q轴实际电流
** Remarks:             None
*************************************************************/
float Motor1GetPreIDIQ(void)
{
	return GetPreIQ(&gMotor1FOC);
}
/*************************************************************
** Function name:       GetMotor1Angle
** Descriptions:        获取电机1机械角度
** Input parameters:    None
** Output parameters:   None
** Returned value:      电机2机械角度
** Remarks:             None
*************************************************************/
float Motor1GetAngle(void)
{
	return GetFocAngle(&gMotor1FOC);
}
