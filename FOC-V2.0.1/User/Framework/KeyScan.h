/***********************************************************************
* @file KeyScan
* Description:
*
**********************************************************************
* File name:      KeyScan.h
* Date:           2021-08-17
* Version:        V1.0
* Author          liuxiang
* @history:
* V1.0 创建文件
***********************************************************************/
#ifndef __KeyScan_H__
#define __KeyScan_H__
#include "stdint.h"


extern volatile uint32_t gKEY_TimeCNT;

enum {
    KEY_UP_STATUS = 0,                  //弹起状态
    KEY_DOWN_STATUS,                    //按下状态
    KEY_IDLE_EVENT,                     //空闲事件
    KEY_SHORT_EVENT,                    //短按弹起事件
    KEY_LONG_EVENT,                     //长按弹起事件
    KEY_LONG_TIMEOUT_EVENT,             //长按超时事件
};



struct SKey_Struct {
    uint32_t startTime;             //起始时间

    uint8_t event;                  //事件
    uint8_t status;                 //状态

    uint8_t timeOutFlag;            //长按超时标志
    uint8_t effLeave;               //有效电平

    float pressTime;                //按下的时间(单位:秒)
    float shortTime;                //短按时间(单位:秒)
    float longTime;                 //长按时间(单位:秒)
    float cycle;                    //周期
    uint8_t(*GetKeyLeave)(void);    //获取按键电平
};
typedef struct SKey_Struct Key_Struct;
typedef Key_Struct* PKey_Struct;

/*************************************************************
** Function name:       KEY_EXPORT
** Descriptions:        按键实力化
** Input parameters:    x:按键名字
**                      xeffLeave：按下有效电平
**                      xshortTime：短按最短时间 (单位:秒)
**                      xlongTime：长按最短时间 (单位:秒)
**                      xcycle：扫描周期 (单位:秒)
**                      xGetKeyLeave：获取按键引脚电平
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
#define KEY_EXPORT(x,xeffLeave,xshortTime,xlongTime,xcycle,xGetKeyLeave)    \
Key_Struct x = {                                                            \
    .startTime = 0,                                                         \
    .event = 0,                                                             \
    .status = 0,                                                            \
    .timeOutFlag = 0,                                                       \
    .effLeave = xeffLeave,                                                  \
    .pressTime = 0,                                                         \
    .shortTime = xshortTime,                                                \
    .longTime = xlongTime,                                                  \
    .cycle = xcycle,                                                        \
    .GetKeyLeave = xGetKeyLeave,                                            \
};

/*************************************************************
** Function name:       KEY_TIMEBASE
** Descriptions:        时基,放在周期为1ms的函数里面执行
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
*************************************************************/
#define KEY_TIMEBASE(ms)                \
        gKEY_TimeCNT+= ms

/*************************************************************
** Function name:       KEY_GETTIME
** Descriptions:        获取起始时间
** Input parameters:    None
** Output parameters:   None
** Returned value:      (uint32_t)起始时间
*************************************************************/
#define KEY_GETTIME(void)                        \
    gKEY_TimeCNT

/*************************************************************
** Function name:       KEY_TIMEOUT
** Descriptions:        检查超时
** Input parameters:    timeOut：(uint32_t)超时时间
**                      startTime:(uint32_t)开始的时间
** Output parameters:   None
** Returned value:      false,未超时，true，超时
*************************************************************/
#define KEY_TIMEOUT(timeOut,startTime)                \
    ((gKEY_TimeCNT - startTime) >= timeOut ? 1 : 0)



void KEYRunCycle(PKey_Struct pKEY);
uint8_t GetKeyStatus(PKey_Struct pKEY);
uint8_t GetKeyEvent(PKey_Struct pKEY);




#endif //__KeyScan_H__



