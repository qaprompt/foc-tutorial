#include "PositionPIDConfig.h"

#include "PositionPID.h"
#include "SpeedPIDConfig.h"
#include "TIM3Encoder.h"

#define P_OUTMAX  100
#define P_KP  0.045f
#define P_KI  0.0f
#define P_KD  0.018f


float GetMotorPosition(void)
{ 
    return GetTimer3EncoderAngle()  -  180;
}

void SetMotorPosition(float position)
{
    SetSpeedPIDConfigTarSpeed(position);
}

POSITION_PID_CONTROL_EXPORT(gPositionPID,0.005,P_OUTMAX,GetMotorPosition,SetMotorPosition)




/*************************************************************
** Function name:       PositionPIDConfig_Init
** Descriptions:        位置PID初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void PositionPIDConfig_Init(void)
{
    SetPositionPIDEnable(&gPositionPID,1);
    SetPositionPIDParams(&gPositionPID,P_KP,P_KI,P_KD);
    SetPositionPIDTar(&gPositionPID,0.0f);
}

/*************************************************************
** Function name:       PositionPIDConfig_Init
** Descriptions:        位置PID初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetPositionPIDConfigTarPosition(float tarPosition)
{
    SetPositionPIDTar(&gPositionPID,tarPosition);
}

/*************************************************************
** Function name:       PositionPIDConfig_Init
** Descriptions:        位置PID初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void PositionPIDConfig_Loop(void)
{
    PositionPIDCycle(&gPositionPID);
}
/*************************************************************
** Function name:       PositionPIDConfig_Printf
** Descriptions:        位置PID信息打印
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void PositionPIDConfig_Printf(void)
{
	PositionPIDPrintf(&gPositionPID);
}





