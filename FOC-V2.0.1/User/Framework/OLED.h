/***********************************************************************
* @file OLED
* Description:
*
**********************************************************************
* File name:      OLED.h
* Date:           2021-05-07
* Version:        V1.0
* Author          liuxiang
* @history:
* V1.0 创建文件
***********************************************************************/
#ifndef __OLED_H__
#define __OLED_H__
#include "stdint.h"

extern volatile uint32_t gOLED_TimeCNT;

struct SOLED_Struct
{
    uint32_t startTime;
    float cycle;//刷新周期(单位s)
	uint8_t pixeData[128][4];
	uint8_t pointData[128][32];
    uint8_t devAddr;
    void (*IIC1TransmitByte)(uint8_t devAddr,uint8_t regAddr,uint8_t adta);
};



typedef struct SOLED_Struct OLED_Struct;
typedef OLED_Struct *POLED_Struct;

/*************************************************************
** Function name:       OLED_EXPORT
** Descriptions:        x:OLED对象名字
**                      xIIC1TransmitByte：IIC1传输数据
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
#define OLED_EXPORT(x,xcycle,xdevAddr,xIIC1TransmitByte)   \
OLED_Struct x = {                                   \
    .startTime = 0,                                   \
    .cycle = xcycle,                                \
    .devAddr = xdevAddr,                            \
    .IIC1TransmitByte = xIIC1TransmitByte,          \
};

/*************************************************************
** Function name:       OLED_TIMEBASE
** Descriptions:        时基,放在周期为1ms的函数里面执行
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
*************************************************************/
#define OLED_TIMEBASE(ms)                \
        gOLED_TimeCNT+= ms

/*************************************************************
** Function name:       OLED_GETTIME
** Descriptions:        获取起始时间
** Input parameters:    None
** Output parameters:   None
** Returned value:      (uint32_t)起始时间
*************************************************************/
#define OLED_GETTIME(void)                        \
    gOLED_TimeCNT

/*************************************************************
** Function name:       OLED_TIMEOUT
** Descriptions:        检查超时
** Input parameters:    timeOut：(uint32_t)超时时间
**                      startTime:(uint32_t)开始的时间
** Output parameters:   None
** Returned value:      false,未超时，true，超时
*************************************************************/
#define OLED_TIMEOUT(timeOut,startTime)                \
    ((gOLED_TimeCNT - startTime) >= timeOut ? 1 : 0)




uint8_t OLEDGetPoint(POLED_Struct pOLED,uint8_t x,uint8_t y);
void OLEDDrawPoint(POLED_Struct pOLED,uint8_t x,uint8_t y,uint8_t status);
void OLEDInit(POLED_Struct pOLED);
void OLEDRefresh(POLED_Struct pOLED);
void OLEDRunCycle(POLED_Struct pOLED);

#endif //__OLED_H__




