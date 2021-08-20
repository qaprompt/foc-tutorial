/***********************************************************************
* @file KeyConfig
* Description:
*
**********************************************************************
* File name:      KeyConfig.h
* Date:           2021-08-19
* Version:        V1.0
* Author          liuxiang
* @history:
* V1.0 创建文件
***********************************************************************/
#ifndef __KeyConfig_H__
#define __KeyConfig_H__
#include "stdint.h"

enum {
    KEYCONFIG_UP_STATUS = 0,                  //弹起状态
    KEYCONFIG_DOWN_STATUS,                    //按下状态
    KEYCONFIG_IDLE_EVENT,                     //空闲事件
    KEYCONFIG_SHORT_EVENT,                    //短按弹起事件
    KEYCONFIG_LONG_EVENT,                     //长按弹起事件
    KEYCONFIG_LONG_TIMEOUT_EVENT,             //长按超时事件
};

void KeyConfig_Init(void);
void KeyConfig_Loop(void);
uint8_t ReadUPKeyStatus(void);
uint8_t ReadUPKeyEvent(void);
uint8_t ReadDownKeyStatus(void);
uint8_t ReadDownKeyEvent(void);


#endif //__KeyConfig_H__



