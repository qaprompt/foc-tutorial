/***********************************************************************
* @file Motor1SpeedPIDConfig
* Description:
*
**********************************************************************
* File name:      Motor1SpeedPIDConfig.h
* Date:           2021-03-24
* Version:        V1.0
* Author          liuxiang
* @history:
* V1.0 创建文件
***********************************************************************/
#ifndef __Motor1SpeedPIDConfig_H__
#define __Motor1SpeedPIDConfig_H__
#include "stdint.h"


void Motor1SpeedPIDConfig_Init(void);
void Motor1SpeedPIDConfigSetTar(float tarSpeed);
float Motor1SpeedPIDConfigGetPre(void);
void Motor1SpeedPIDConfig_Loop(void);
void Motor1SpeedPIDConfig_Printf(void);


#endif //__Motor1SpeedPIDConfig_H__



