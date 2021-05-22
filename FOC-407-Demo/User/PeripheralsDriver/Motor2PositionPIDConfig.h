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
#ifndef __Motor2PositionPIDConfig_H__
#define __Motor2PositionPIDConfig_H__
#include "stdint.h"



void Motor2PositionPIDConfig_Init(void);
void Motor2PositionPIDConfigSetTar(float tarPosition);
void Motor2PositionPIDConfig_Loop(void);
void Motor2PositionPIDConfig_Printf(void);

#endif //__Motor2PositionPIDConfig_H__







