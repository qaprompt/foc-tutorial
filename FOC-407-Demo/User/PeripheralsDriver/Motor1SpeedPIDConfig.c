#include "Motor1SpeedPIDConfig.h"
//速度PID库
#include "SpeedPID.h"
//电机1电流环
#include "Motor1FOCConfig.h"

#define M1_SPEED_KP  0.08f
#define M1_SPEED_KI  0.001f
#define M1_SPEED_KD  0.0f



float Motor1GetPreSpeed(void)
{
    static float angle = 0.0;
    static float lastAngle = 0.0;
    float speed;
    angle = Motor1GetAngle();
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

void  Motor1SetCurrent(float current)
{
    Motor1SetTarIDIQ(0,current);
}


SPEED_PID_CONTROL_EXPORT(gMotor1SpeedPID,0.002,200,Motor1GetPreSpeed,Motor1SetCurrent)







/*************************************************************
** Function name:       Motor1SpeedPIDConfig_Init
** Descriptions:        电机1速度PID初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor1SpeedPIDConfig_Init(void)
{
    SetSpeedPIDEnable(&gMotor1SpeedPID,1);
    SetSpeedPIDParams(&gMotor1SpeedPID,M1_SPEED_KP,M1_SPEED_KI,M1_SPEED_KD);
    SetSpeedPIDTar(&gMotor1SpeedPID,0.0f);
}

/*************************************************************
** Function name:       Motor1SpeedPIDConfigSetTar
** Descriptions:        电机1速度PID初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor1SpeedPIDConfigSetTar(float tarSpeed)
{
    SetSpeedPIDTar(&gMotor1SpeedPID,tarSpeed);
}

/*************************************************************
** Function name:       Motor1SpeedPIDConfig_Init
** Descriptions:        电机1速度PID初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor1SpeedPIDConfig_Loop(void)
{
    SpeedPIDCycle(&gMotor1SpeedPID);
}
/*************************************************************
** Function name:       Motor1SpeedPIDConfig_Printf
** Descriptions:        电机1速度PID信息打印
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor1SpeedPIDConfig_Printf(void)
{
	SpeedPIDPrintf(&gMotor1SpeedPID);
}







