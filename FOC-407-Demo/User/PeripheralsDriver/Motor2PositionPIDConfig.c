#include "Motor2PositionPIDConfig.h"
//位置PID
#include "PositionPID.h"
//电机2速度闭环
#include "Motor2SpeedPIDConfig.h"
//电机2电流闭环
#include "Motor2FOCConfig.h"

#define M2_POSITION_KP  0.08f
#define M2_POSITION_KI  0.000f
#define M2_POSITION_KD  0.08f



float Motor2GetPosition(void)
{ 
    return Motor2GetAngle() -  180;
}

void Motor2SetPosition(float position)
{
    Motor2SpeedPIDConfigSetTar(position);
}

POSITION_PID_CONTROL_EXPORT(gMotor2PositionPID,0.005,50.0,Motor2GetPosition,Motor2SetPosition)




/*************************************************************
** Function name:       Motor2PositionPIDConfig_Init
** Descriptions:        位置PID初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor2PositionPIDConfig_Init(void)
{
    SetPositionPIDEnable(&gMotor2PositionPID,1);
    SetPositionPIDParams(&gMotor2PositionPID,M2_POSITION_KP,M2_POSITION_KI,M2_POSITION_KD);
    SetPositionPIDTar(&gMotor2PositionPID,0.0f);
}

/*************************************************************
** Function name:       Motor2SetPositionPIDConfigTar
** Descriptions:        设置目标位置
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor2PositionPIDConfigSetTar(float tarPosition)
{
    SetPositionPIDTar(&gMotor2PositionPID,tarPosition);
}

/*************************************************************
** Function name:       Motor2PositionPIDConfig_Init
** Descriptions:        位置PID初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor2PositionPIDConfig_Loop(void)
{
    PositionPIDCycle(&gMotor2PositionPID);
}
/*************************************************************
** Function name:       Motor2PositionPIDConfig_Printf
** Descriptions:        位置PID信息打印
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor2PositionPIDConfig_Printf(void)
{
	PositionPIDPrintf(&gMotor2PositionPID);
}





