/***********************************************************************
* @file PageGUI
* Description:
*
**********************************************************************
* File name:      PageGUI.h
* Date:           2021-08-19
* Version:        V1.0
* Author          liuxiang
* @history:
* V1.0 创建文件
***********************************************************************/
#ifndef __PageGUI_H__
#define __PageGUI_H__
#include "stdint.h"



extern volatile uint32_t gPageGUI_TimeCNT;

struct SPageGUIFunc_STruct
{
    uint8_t (*ConditionFunc)(void);     //条件函数
    void (*ExecutionFunc)(void);        //执行函数
};
typedef struct SPageGUIFunc_STruct PageGUIFunc_STruct;
typedef PageGUIFunc_STruct *PPageGUIFunc_STruct;


struct SPageGUI_STruct
{
    uint32_t startTime;                 //系统事件
    float cycle;                        //刷新周期(单位s)
    uint8_t isEnable;                   //是否使能
    uint8_t funcNums;                   //函数个数
    void (*GUIGetEvent)(void);           //页面刷新函数
    void (*GUIRefresh)(void);           //页面刷新函数
    PPageGUIFunc_STruct PageGUIFunc;    //页面函数列表
};
typedef struct SPageGUI_STruct PageGUI_STruct;
typedef PageGUI_STruct *PPageGUI_STruct;



/*************************************************************
** Function name:       PAGEGUI_EXPORT
** Descriptions:        页面实例化
** Input parameters:    x:页面名字
**                      xcycle：页面刷新周期
**                      xFuncList...：函数列表
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
#define PAGEGUI_EXPORT(x,xisEnable,xcycle,xGUIGetEvent,xGUIRefresh,xFuncList...)                                   \
PageGUIFunc_STruct gFuncList##x[] = {                                           \
    xFuncList                                                                   \
};                                                                              \
PageGUI_STruct x = {                                                            \
    .startTime = 0,                                                             \
    .isEnable = xisEnable,                                                      \
    .cycle = xcycle,                                                            \
    .GUIGetEvent = xGUIGetEvent,                                                \
    .GUIRefresh = xGUIRefresh,                                                  \
    .funcNums = sizeof(gFuncList##x) / sizeof(PageGUIFunc_STruct),              \
    .PageGUIFunc = gFuncList##x,                                                \
};



/*************************************************************
** Function name:        PAGEGUI_TIMEBASE
** Descriptions:        时基,放在周期为1ms的函数里面执行
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
*************************************************************/
#define PAGEGUI_TIMEBASE(ms)                \
        gPageGUI_TimeCNT+= ms

/*************************************************************
** Function name:        PAGEGUI_GETTIME
** Descriptions:        获取起始时间
** Input parameters:    None
** Output parameters:   None
** Returned value:      (uint32_t)起始时间
*************************************************************/
#define  PAGEGUI_GETTIME(void)                        \
    gPageGUI_TimeCNT

/*************************************************************
** Function name:        PAGEGUI_TIMEOUT
** Descriptions:        检查超时
** Input parameters:    timeOut：(uint32_t)超时时间
**                      startTime:(uint32_t)开始的时间
** Output parameters:   None
** Returned value:      false,未超时，true，超时
*************************************************************/
#define  PAGEGUI_TIMEOUT(timeOut,startTime)                \
    ((gPageGUI_TimeCNT - startTime) >= timeOut ? 1 : 0)






void PageGUIFuncCheck(PPageGUI_STruct pPageGUI);
void PageGUICycle(PPageGUI_STruct pPageGUI);
void PageGUISetEnable(PPageGUI_STruct pPageGUI,uint8_t isEnable);
#endif //__PageGUI_H__





