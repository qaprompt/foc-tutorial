#include "Motor2SpeedPIDConfig.h"
//速度PID库
#include "SpeedPID.h"
//电机2电流环
#include "Motor2FOCConfig.h"

#define M2_SPEED_KP  0.25f
#define M2_SPEED_KI  0.0008f
#define M2_SPEED_KD  0.0f



float Motor2GetPreSpeed(void)
{
    static float angle = 0.0;
    static float lastAngle = 0.0;
    float speed;
    angle = Motor2GetAngle();
    speed = angle - lastAngle;
    if (speed < -180) {
        speed = speed + 360;
    }
    if (speed > 180) {
        speed = speed - 360;
    }
	lastAngle = angle;
    return speed;
}

void  Motor2SetCurrent(float current)
{
    Motor2SetTarIDIQ(0,current);
}


SPEED_PID_CONTROL_EXPORT(gMotor2SpeedPID,0.002,10,Motor2GetPreSpeed,Motor2SetCurrent)







/*************************************************************
** Function name:       Motor2SpeedPIDConfig_Init
** Descriptions:        电机2速度PID初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor2SpeedPIDConfig_Init(void)
{
    SetSpeedPIDEnable(&gMotor2SpeedPID,1);
    SetSpeedPIDParams(&gMotor2SpeedPID,M2_SPEED_KP,M2_SPEED_KI,M2_SPEED_KD);
    SetSpeedPIDTar(&gMotor2SpeedPID,0.0f);
}

/*************************************************************
** Function name:       Motor2SpeedPIDConfigSetTar
** Descriptions:        电机2速度PID初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor2SpeedPIDConfigSetTar(float tarSpeed)
{
    SetSpeedPIDTar(&gMotor2SpeedPID,tarSpeed);
}

/*************************************************************
** Function name:       Motor2SpeedPIDConfig_Init
** Descriptions:        电机2速度PID初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor2SpeedPIDConfig_Loop(void)
{
    SpeedPIDCycle(&gMotor2SpeedPID);
}
/*************************************************************
** Function name:       Motor2SpeedPIDConfig_Printf
** Descriptions:        电机2速度PID信息打印
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor2SpeedPIDConfig_Printf(void)
{
	SpeedPIDPrintf(&gMotor2SpeedPID);
}







