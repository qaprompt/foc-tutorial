#include "PositionPIDConfig.h"

#include "PositionPID.h"
#include "SpeedPIDConfig.h"
#include "FOCConfig.h"


float GetMotorPosition(void)
{ 
    return GetMotor2Angle() -  180;
}

void SetMotorPosition(float position)
{
    SetSpeedPIDConfigTarSpeed(position);
}

POSITION_PID_CONTROL_EXPORT(gPositionPID,0.005,100.0,GetMotorPosition,SetMotorPosition)




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
    SetPositionPIDParams(&gPositionPID,0.07f,0.0f,0.07f);
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





