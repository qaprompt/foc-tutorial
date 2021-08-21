/***********************************************************************
* @file GUIInputEvent
* Description:
*
**********************************************************************
* File name:      GUIInputEvent.h
* Date:           2021-08-20
* Version:        V1.0
* Author          liuxiang
* @history:
* V1.0 创建文件
***********************************************************************/
#ifndef __GUIInputEvent_H__
#define __GUIInputEvent_H__
#include "stdint.h"


void GUIInputEvent(void);

uint8_t ISKeyUP(void);
uint8_t ISKeyDown(void);
uint8_t ISKeyExit(void);
uint8_t ISKeyOK(void);



#endif //__GUIInputEvent_H__

