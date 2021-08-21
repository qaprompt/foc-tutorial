#include "GUIInputEvent.h"
#include "KeyConfig.h"


struct SGUIInputEvent_Struct
{
    uint8_t keyUpEcent;
    uint8_t keyDownEcent;
};

typedef struct SGUIInputEvent_Struct GUIInputEvent_Struct;
typedef GUIInputEvent_Struct *PGUIInputEvent_Struct;

GUIInputEvent_Struct gGUIInputEvent = {KEYCONFIG_IDLE_EVENT,KEYCONFIG_IDLE_EVENT};




/*************************************************************
** Function name:       GUIInputEvent
** Descriptions:        GUI输入事件获取
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void GUIInputEvent(void)
{
    gGUIInputEvent.keyUpEcent = ReadUPKeyEvent();
    gGUIInputEvent.keyDownEcent = ReadDownKeyEvent();
}
/*************************************************************
** Function name:       ISKeyUP
** Descriptions:        是否上按键被按下
** Input parameters:    None
** Output parameters:   None
** Returned value:      1：按下 0：没有按下
** Remarks:             None
*************************************************************/
uint8_t ISKeyUP(void)
{
    if (gGUIInputEvent.keyUpEcent == KEYCONFIG_SHORT_EVENT) {
        return 1;
    } else {
        return 0;
    }
}

/*************************************************************
** Function name:       ISKeyDown
** Descriptions:        是否下按键被按下
** Input parameters:    None
** Output parameters:   None
** Returned value:      1：按下 0：没有按下
** Remarks:             None
*************************************************************/
uint8_t ISKeyDown(void)
{
    if (gGUIInputEvent.keyDownEcent == KEYCONFIG_SHORT_EVENT) {
        return 1;
    } else {
        return 0;
    }
}
/*************************************************************
** Function name:       ISKeyExit
** Descriptions:        是否退出按键被按下
** Input parameters:    None
** Output parameters:   None
** Returned value:      1：按下 0：没有按下
** Remarks:             None
*************************************************************/
uint8_t ISKeyExit(void)
{
    if (gGUIInputEvent.keyUpEcent == KEYCONFIG_LONG_TIMEOUT_EVENT) {
        return 1;
    } else {
        return 0;
    }
}
/*************************************************************
** Function name:       ISKeyOK
** Descriptions:        是否OK按键被按下
** Input parameters:    None
** Output parameters:   None
** Returned value:      1：按下 0：没有按下
** Remarks:             None
*************************************************************/
uint8_t ISKeyOK(void)
{
    if (gGUIInputEvent.keyDownEcent == KEYCONFIG_LONG_TIMEOUT_EVENT) {
        return 1;
    } else {
        return 0;
    }
}
