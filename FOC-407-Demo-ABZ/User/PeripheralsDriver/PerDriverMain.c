#include "PerDriverMain.h"
//系统
#include "main.h"
//时间调度
#include "Timer.h"
#include "math.h"
//LED
#include "LEDConfig.h"
//Motor1
#include "Motor1SvpwmConfig.h"
#include "Motor1FOCConfig.h"
#include "Motor1SpeedPIDConfig.h"
#include "Motor1PositionPIDConfig.h"
//Motor2
#include "Motor2SvpwmConfig.h"
#include "Motor2FOCConfig.h"
#include "Motor2SpeedPIDConfig.h"
#include "Motor2PositionPIDConfig.h"
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
	Motor1FOCConfig_Init();
	Motor1SpeedPIDConfig_Init();
	Motor1PositionPIDConfig_Init();
	Motor2FOCConfig_Init();
	Motor2SpeedPIDConfig_Init();
	Motor2PositionPIDConfig_Init();
	
	
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
float angle = 0;
float star = 0.0;
float spre;

int ptar;
float ppre;
void PerDriverMain_Loop(void)
{
	//打印调试信息
	RUN_BY_LIMIT_BLOCK(5,
		//Motor1FOCConfig_Printf();
		//Motor1SpeedPIDConfig_Printf();
		//Motor1PositionPIDConfig_Printf();
		//Motor2FOCConfig_Printf();
		//Motor2SpeedPIDConfig_Printf();
		//Motor2PositionPIDConfig_Printf();

	)
	//电流环调试
//	RUN_BY_LIMIT_BLOCK(2000,
//		if (currentflag == 0) {
//			Motor1SetTarIDIQ(0.1,0.0);
//			//Motor2SetTarIDIQ(0.1,0.1);
//			currentflag = 1;
//		} else {
//			Motor1SetTarIDIQ(0.05,0.00);
//			//Motor2SetTarIDIQ(0.05,0.05);
//			currentflag = 0;
//		}
//	)
//	//速度环调试
//	 RUN_BY_LIMIT_BLOCK(4000,
//	 	if (currentflag == 0) {
//	 		Motor1SpeedPIDConfigSetTar(10);
//	 		//Motor2SpeedPIDConfigSetTar(10);
//	 		currentflag = 1;
//	 	} else {
//	 		Motor1SpeedPIDConfigSetTar(5);
//	 		//Motor2SpeedPIDConfigSetTar(5);
//	 		currentflag = 0;
//	 	}
//	 )
//	//位置环调试
//	RUN_BY_LIMIT_BLOCK(2000,
//		if (currentflag == 0) {
//			Motor1PositionPIDConfigSetTar(90);
//			//Motor2PositionPIDConfigSetTar(90);
//			currentflag = 1;
//		} else {
//			Motor1PositionPIDConfigSetTar(60);
//			//Motor2PositionPIDConfigSetTar(60);
//			currentflag = 0;
//		}
//	)
	//位置环应用-->时钟效果
	RUN_BY_LIMIT_BLOCK(1000,
		angle += 30;
		if(angle >= 360) {
			angle = 0;
		}
		Motor1PositionPIDConfigSetTar(180 - angle);
		Motor2PositionPIDConfigSetTar(180 - angle);
	)
//	//位置环应用-->力反馈
//	RUN_BY_LIMIT_BLOCK(10,
//		float iq;
//		//Motor1PositionPIDConfigSetTar(180 - angle);
//		iq = -Motor2GetPreIDIQ();
//		Motor1SetTarIDIQ(0,iq/5);
//		Motor2PositionPIDConfigSetTar(Motor1GetAngle() -  180);	
//	)
//	//旋转陀螺
//	RUN_BY_LIMIT_BLOCK(50,
//		spre = Motor2SpeedPIDConfigGetPre();
//		printf("1:%f\r\n",spre);
//		if ( fabs(star) < 0.01) {
//			star = spre*2;
//			
//		} 
//		if (fabs(spre) < 0.5) {
//			star = 0;
//		}
//		Motor2SpeedPIDConfigSetTar(star);	
//	)
//	//多档开关
//	RUN_BY_LIMIT_BLOCK(50,
//		ppre = Motor1PositionPIDConfigGetPre();
//		printf("2:%f\r\n",ppre);
//		
//		ptar = ppre / 30;
//		ptar = ptar * 30;
//		printf("3:%d\r\n",ptar);
//		Motor1PositionPIDConfigSetTar(ptar);	
//	)
	LEDConfig_Loop();
	Motor1SpeedPIDConfig_Loop();
	Motor1PositionPIDConfig_Loop();
	Motor2SpeedPIDConfig_Loop();
	Motor2PositionPIDConfig_Loop();
}
