/***********************************************************************
* @file PositionPIDConfig
* Description:
*
**********************************************************************
* File name:      PositionPIDConfig.h
* Date:           2021-03-31
* Version:        V1.0
* Author          liuxiang
* @history:
* V1.0 创建文件
***********************************************************************/
#ifndef __Motor1PositionPIDConfig_H__
#define __Motor1PositionPIDConfig_H__
#include "stdint.h"



void Motor1PositionPIDConfig_Init(void);
void Motor1PositionPIDConfigSetTar(float tarPosition);
void Motor1PositionPIDConfig_Loop(void);
void Motor1PositionPIDConfig_Printf(void);

#endif //__Motor1PositionPIDConfig_H__







