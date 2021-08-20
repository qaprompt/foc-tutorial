#include "KeyConfig.h"
#include "KeyGpio.h"
#include "KeyScan.h"



KEY_EXPORT(gKey_Up,0,0.01,3.0,0.01,ReadKeyUPLeave)


KEY_EXPORT(gKey_Down,0,0.01,3.0,0.01,ReadKeyDownLeave)





/*************************************************************
** Function name:       KeyConfig_Init
** Descriptions:        按键初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void KeyConfig_Init(void)
{


}



/*************************************************************
** Function name:       void KeyConfig_Loop(void)
** Descriptions:        按键循环扫描
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void KeyConfig_Loop(void)
{
    KEYRunCycle(&gKey_Up);
    KEYRunCycle(&gKey_Down);
}


/*************************************************************
** Function name:       ReadUPKeyStatus
** Descriptions:        获取上按键的状态
** Input parameters:    None
** Output parameters:   None
** Returned value:      状态
** Remarks:             None
*************************************************************/
uint8_t ReadUPKeyStatus(void)
{
    return GetKeyEvent(&gKey_Up);
}
/*************************************************************
** Function name:       ReadUPKeyEvent
** Descriptions:        获取上按键的事件
** Input parameters:    None
** Output parameters:   None
** Returned value:      事件
** Remarks:             None
*************************************************************/
uint8_t ReadUPKeyEvent(void)
{
    return GetKeyEvent(&gKey_Up);
}

/*************************************************************
** Function name:       ReadDownKeyStatus
** Descriptions:        获取下按键的状态
** Input parameters:    None
** Output parameters:   None
** Returned value:      状态
** Remarks:             None
*************************************************************/
uint8_t ReadDownKeyStatus(void)
{
    return GetKeyEvent(&gKey_Down);
}
/*************************************************************
** Function name:       ReadDownKeyEvent
** Descriptions:        获取下按键的事件
** Input parameters:    None
** Output parameters:   None
** Returned value:      事件
** Remarks:             None
*************************************************************/
uint8_t ReadDownKeyEvent(void)
{
    return GetKeyEvent(&gKey_Down);
}

