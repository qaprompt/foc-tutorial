#include "PerDriverMain.h"
#include "main.h"

#include "SvpwmConfig.h"
#include "Timer.h"
#include "FOCConfig.h"
#include "DRV8301Config.h"
#include "SpeedPIDConfig.h"
#include "PositionPIDConfig.h"
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
	HAL_Delay(2000);
	//DRV8301Config_Init();//FUCK I Can NOT Commit With DRV8301
	FOCConfig_Init();
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
int debugFlag = 0;
void PerDriverMain_Loop(void)
{
	//打印调试信息
	RUN_BY_LIMIT_BLOCK(5,
		//FOCConfig_Printf();
		SpeedPIDConfig_Printf();
		PositionPIDConfig_Printf();
	)
	
	//改变转速
	RUN_BY_LIMIT_BLOCK(4000,
		if (debugFlag == 0) {
			debugFlag = 1;
			//SetTarIDIQ(0,20);
			//SetSpeedPIDConfigTarSpeed(10.0f);
			SetPositionPIDConfigTarPosition(90.0);
		} else if (debugFlag == 1){
			debugFlag = 0;
			//SetTarIDIQ(0,-20);
			//SetSpeedPIDConfigTarSpeed(5.0f);
			SetPositionPIDConfigTarPosition(90.0);
		}
	)
	//位置闭环
	PositionPIDConfig_Loop();
	//速度闭环
	SpeedPIDConfig_Loop();
	
}


