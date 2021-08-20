#include "OLEDConfig.h"
#include "OLED.h"
#include "IIC1.h"



OLED_EXPORT(gOLED,0.05,0x78,IIC1TransmitByte)


/*************************************************************
** Function name:       OLEDConfig_Init
** Descriptions:        OLED初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void OLEDConfig_Init(void)
{
    OLEDInit(&gOLED);
}
/*************************************************************
** Function name:       OLEDConfigDrawPoint
** Descriptions:        OLED画点函数
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void OLEDConfigDrawPoint(uint8_t x,uint8_t y,uint8_t status)
{
    OLEDDrawPoint(&gOLED,x,y,status);
}
/*************************************************************
** Function name:       OLEDConfigGetPoint
** Descriptions:        OLED获取点状态点函数
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
uint8_t OLEDConfigGetPoint(uint8_t x,uint8_t y)
{
    return OLEDGetPoint(&gOLED,x,y);
}
/*************************************************************
** Function name:       OLEDConfigRefresh
** Descriptions:        OLED刷新函数
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void OLEDConfigRefresh(void)
{
    OLEDRefresh(&gOLED);
}


/*************************************************************
** Function name:       OLEDConfig_Loop
** Descriptions:        OLED循环函数
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void OLEDConfig_Loop(void)
{
	OLEDRunCycle(&gOLED);
}
