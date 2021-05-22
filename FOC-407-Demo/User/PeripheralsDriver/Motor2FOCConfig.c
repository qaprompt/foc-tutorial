#include "Motor2FOCConfig.h"
//FOC框架
#include "Foc.h"
//电机使能引脚
#include "Motor2GPIO.h"
//电机2SVPWM生成
#include "Motor2SvpwmConfig.h"
//电机2磁编码器
#include "Motor2TLE5012BConfig.h"
//电机2电流采集
#include "Motor2ADC2.h"

#define AD_TO_CURRENT 0.0008

#define M2_OUTMAX  12.0f * 0.577f
#define M2_KP  0.01f
#define M2_KI  0.01f
#define M2_KD  0.0f


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
	*ua = GetMotor2ADC2PhaseXValue(0) * AD_TO_CURRENT * 1.5;
	*ub = GetMotor2ADC2PhaseXValue(1) * AD_TO_CURRENT * 1.5;
	*uc = GetMotor2ADC2PhaseXValue(2) * AD_TO_CURRENT * 1.5;

}
//声明FOC对象
FOC_EXPORT(gMotor2FOC,7.0f,3,Motor2SetEnable,Motor2TLE5012BReadAngel,Motor2GetSVPWMSector,GetMotor2PreCurrent,Motor2SvpwmGenerate)

/*************************************************************
** Function name:       Motor2FOCConfig_Init
** Descriptions:        电机一FOC初始化
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
** Function name:       Motor2FOCConfig_Printf
** Descriptions:        电机一FOC打印函数
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
** Function name:       Motor2FocControl
** Descriptions:        电机一FOC控制函数
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
** Function name:       GetMotor2Angle
** Descriptions:        获取电机2机械角度
** Input parameters:    None
** Output parameters:   None
** Returned value:      电机2机械角度
** Remarks:             None
*************************************************************/
float Motor2GetAngle(void)
{
	return GetFocAngle(&gMotor2FOC);
}
