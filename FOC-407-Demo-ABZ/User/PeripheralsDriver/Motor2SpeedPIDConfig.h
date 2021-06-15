/***********************************************************************
* @file Motor2SpeedPIDConfig
* Description:
*
**********************************************************************
* File name:      Motor2SpeedPIDConfig.h
* Date:           2021-03-24
* Version:        V1.0
* Author          liuxiang
* @history:
* V1.0 创建文件
***********************************************************************/
#ifndef __Motor2SpeedPIDConfig_H__
#define __Motor2SpeedPIDConfig_H__
#include "stdint.h"


void Motor2SpeedPIDConfig_Init(void);
void Motor2SpeedPIDConfigSetTar(float tarSpeed);
float Motor2SpeedPIDConfigGetPre(void);
void Motor2SpeedPIDConfig_Loop(void);
void Motor2SpeedPIDConfig_Printf(void);


#endif //__Motor2SpeedPIDConfig_H__



