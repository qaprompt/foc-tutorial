/***********************************************************************
* @file OLEDConfig
* Description:
*
**********************************************************************
* File name:      OLEDConfig.h
* Date:           2021-05-10
* Version:        V1.0
* Author          liuxiang
* @history:
* V1.0 创建文件
***********************************************************************/
#ifndef __OLEDConfig_H__
#define __OLEDConfig_H__
#include "stdint.h"

void OLEDConfig_Init(void);
void OLEDConfigDrawPoint(uint8_t x,uint8_t y,uint8_t status);
uint8_t OLEDConfigGetPoint(uint8_t x,uint8_t y);
void OLEDConfigRefresh(void);
void OLEDConfig_Loop(void);
#endif //__OLEDConfig_H__




