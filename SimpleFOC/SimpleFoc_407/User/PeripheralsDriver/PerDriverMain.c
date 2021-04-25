#include "PerDriverMain.h"

#include "LEDConfig.h"
#include "SvpwmConfig.h"
#include "FOCConfig.h"

#include "SpeedPIDConfig.h"
#include "PositionPIDConfig.h"

#include "Timer.h"
#include "main.h"
/*************************************************************
** Function name:      PerDriverMain_Init
** Descriptions:       外设初始化
** Input parameters:   none
** Output parameters:  none
** Returned value:     none
** Created by:         none
** Created date:       none
*************************************************************/
void PerDriverMain_Init(void)
{
	LEDConfig_Init();
	Motor2FOCConfig_Init();
	SpeedPIDConfig_Init();
	PositionPIDConfig_Init();
}

/*************************************************************
** Function name:      PerDriverMain_Loop
** Descriptions:       外设循环
** Input parameters:   none
** Output parameters:  none
** Returned value:     none
** Created by:         none
** Created date:       none
*************************************************************/
uint8_t currentflag;
uint8_t speedflag;
uint8_t positionflag;
int16_t angle = 180;
void PerDriverMain_Loop(void)
{
	//打印调试信息
	RUN_BY_LIMIT_BLOCK(1,
		//Motor2FOCConfig_Printf();
		//SpeedPIDConfig_Printf();
		PositionPIDConfig_Printf();
	)
	//电流环调试
//	RUN_BY_LIMIT_BLOCK(2000,
//		if (currentflag == 0) {
//			Motor2SetTarIDIQ(0.0,0.03);
//			currentflag = 1;
//		} else {
//			Motor2SetTarIDIQ(0.0,0.05);
//			currentflag = 0;
//		}
//	)
//	//速度环调试
//	RUN_BY_LIMIT_BLOCK(4000,
//		if (speedflag == 0) {
//			SetSpeedPIDConfigTarSpeed(5);
//			speedflag = 1;
//		} else {
//			SetSpeedPIDConfigTarSpeed(2);
//			speedflag = 0;
//		}
//	)
//	//位置环调试
//	RUN_BY_LIMIT_BLOCK(2000,
//		if (positionflag == 0) {
//			SetPositionPIDConfigTarPosition(90);
//			positionflag = 1;
//		} else {
//			SetPositionPIDConfigTarPosition(180);
//			positionflag = 0;
//		}
//	)	
	//位置环调试
	RUN_BY_LIMIT_BLOCK(1000,
		angle += 6;
		if(angle >= 360) {
			angle = 0;
		}
		SetPositionPIDConfigTarPosition(180 - angle);
	)	
	
	LEDConfig_Loop();
	SpeedPIDConfig_Loop();
	PositionPIDConfig_Loop();
}
