#include "Motor1PositionPIDConfig.h"
//位置PID
#include "PositionPID.h"
//电机1速度闭环
#include "Motor1SpeedPIDConfig.h"
//电机1电流闭环
#include "Motor1FOCConfig.h"

#define M1_POSITION_KP  0.08f
#define M1_POSITION_KI  0.000f
#define M1_POSITION_KD  0.08f



float Motor1GetPosition(void)
{ 
    return Motor1GetAngle() -  180;
}

void Motor1SetPosition(float position)
{
    Motor1SpeedPIDConfigSetTar(position);
}

POSITION_PID_CONTROL_EXPORT(gMotor1PositionPID,0.005,100.0,Motor1GetPosition,Motor1SetPosition)




/*************************************************************
** Function name:       Motor1PositionPIDConfig_Init
** Descriptions:        位置PID初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor1PositionPIDConfig_Init(void)
{
    SetPositionPIDEnable(&gMotor1PositionPID,1);
    SetPositionPIDParams(&gMotor1PositionPID,M1_POSITION_KP,M1_POSITION_KI,M1_POSITION_KD);
    SetPositionPIDTar(&gMotor1PositionPID,0.0f);
}

/*************************************************************
** Function name:       Motor1SetPositionPIDConfigTar
** Descriptions:        设置目标位置
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor1PositionPIDConfigSetTar(float tarPosition)
{
    SetPositionPIDTar(&gMotor1PositionPID,tarPosition);
}

/*************************************************************
** Function name:       Motor1PositionPIDConfig_Init
** Descriptions:        位置PID初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor1PositionPIDConfig_Loop(void)
{
    PositionPIDCycle(&gMotor1PositionPID);
}
/*************************************************************
** Function name:       Motor1PositionPIDConfig_Printf
** Descriptions:        位置PID信息打印
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor1PositionPIDConfig_Printf(void)
{
	PositionPIDPrintf(&gMotor1PositionPID);
}





