#include "LEDControl.h"

volatile uint32_t gLED_TimeCNT;

/*************************************************************
** Function name:       LEDON
** Descriptions:        LED常亮
** Input parameters:    pLED:SLEDControl_Struct结构体指针
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetLEDON(PLEDControl_Struct pLED)
{
    pLED->state = LEDState_ON;
    pLED->SetSYSLedLeave(pLED->onLeave);
}
/*************************************************************
** Function name:       LEDFF
** Descriptions:        LED常灭
** Input parameters:    pLED:SLEDControl_Struct结构体指针
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetLEDOFF(PLEDControl_Struct pLED)
{
    pLED->state = LEDState_OFF;
    pLED->SetSYSLedLeave(!(pLED->onLeave));
}
/*************************************************************
** Function name:       LEDToggle
** Descriptions:        LED闪烁
** Input parameters:    pLED:SLEDControl_Struct结构体指针
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void LEDToggle(PLEDControl_Struct pLED)
{
    pLED->onoff = !pLED->onoff;
    pLED->SetSYSLedLeave(pLED->onoff);
}
/*************************************************************
** Function name:       LEdRunCycle
** Descriptions:        LED周期执行函数
** Input parameters:    pLED:SLEDControl_Struct结构体指针
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void LEDRunCycle(PLEDControl_Struct pLED)
{
    if(LED_TIMEOUT(pLED->cycle * 1000,pLED->startTime)) {
        pLED->startTime = LED_GETTIME();
        if(pLED->state == LEDState_Toggle) {
            LEDToggle(pLED);
        }
    }
}
/*************************************************************
** Function name:       LEDFlashing
** Descriptions:        LED闪烁
** Input parameters:    pLED:SLEDControl_Struct结构体指针
**                      cycle:闪烁周期(单位ms)
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetLEDFlashing(PLEDControl_Struct pLED,float cycle)
{
    pLED->state = LEDState_Toggle;
    pLED->cycle = cycle;
}

/*************************************************************
** Function name:       SetLedStatus
** Descriptions:        设置LEDz状态
** Input parameters:    pLED:SLEDControl_Struct结构体指针
**                      status:LED状态
**                      cycle:闪烁周期(单位ms)
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetLedStatus(PLEDControl_Struct pLED,uint8_t status,float cycle)
{
    switch(status) {
        case LEDState_OFF:
            SetLEDOFF(pLED);
            break;
        case LEDState_ON:
            SetLEDON(pLED);
            break;
        case LEDState_Toggle:
            SetLEDFlashing(pLED,cycle);
            break;
    }
}















