#include "PageGUI.h"

volatile uint32_t gPageGUI_TimeCNT;


/*************************************************************
** Function name:       PageGUIFuncCheck
** Descriptions:        页面判断函数
** Input parameters:    pPageGUI：页面结构体
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void PageGUIFuncCheck(PPageGUI_STruct pPageGUI)
{
    if(pPageGUI->isEnable == 0) {
        return;
    }
    pPageGUI->GUIGetEvent();
    for (uint8_t i = 0; i < pPageGUI->funcNums; i++) {
        if (pPageGUI->PageGUIFunc[i].ConditionFunc() == 1) {
            pPageGUI->PageGUIFunc[i].ExecutionFunc();
        }
    }
    pPageGUI->GUIRefresh();
}
/*************************************************************
** Function name:       PageGUICycle
** Descriptions:        页面循环函数
** Input parameters:    pPageGUI：页面结构体
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void PageGUICycle(PPageGUI_STruct pPageGUI)
{
    if(PAGEGUI_TIMEOUT(pPageGUI->cycle * 1000,pPageGUI->startTime)) {
        pPageGUI->startTime = PAGEGUI_GETTIME();
        PageGUIFuncCheck(pPageGUI);
    }
}


/*************************************************************
** Function name:       PageGUISetEnable
** Descriptions:        设置页面使能
** Input parameters:    pPageGUI：页面结构体
**                      isEnable：1：使能 0：失能
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void PageGUISetEnable(PPageGUI_STruct pPageGUI,uint8_t isEnable)
{
    pPageGUI->isEnable = isEnable;
}



