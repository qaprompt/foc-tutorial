#include "About2Page.h"

//UI库文件
#include "UI.h"
#include "DIALOG.h"
//页面管理文件
#include "PageGUI.h"
//事件触发事件
#include "GUIInputEvent.h"

//相关联界面
#include "AboutPage.h"



WM_HWIN gAbout2Page;






/*************************************************************
** Function name:       About2PageKeyUPFunction
** Descriptions:        上按键触发事件
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void About2PageKeyUPFunction(void)
{
	//向下翻页
    if(LISTBOX_GetSel(About2Lisbox) == 0) {
        LISTBOX_SetSel(About2Lisbox, LISTBOX_GetNumItems(About2Lisbox) - 1);
    } else {
        LISTBOX_DecSel(About2Lisbox);
    }
}
/*************************************************************
** Function name:       About2PageKeyDownFunction
** Descriptions:        下按键触发事件
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void About2PageKeyDownFunction(void)
{
    //向上翻页
    if(LISTBOX_GetSel(About2Lisbox) == (LISTBOX_GetNumItems(About2Lisbox) - 1)) {
        LISTBOX_SetSel(About2Lisbox, 0);
    } else {
        LISTBOX_IncSel(About2Lisbox);
    }
}
/*************************************************************
** Function name:       About2PageKeyExitFunction
** Descriptions:        退出按键触发事件
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void About2PageKeyExitFunction(void)
{
    //退出本次界面
    About2PageHide();
    //进入新的界面
    AboutPageShow();
	
}
/*************************************************************
** Function name:       About2PageRefresh
** Descriptions:        页面刷新函数
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void About2PageRefresh(void)
{
    GUI_Exec();
}



PAGEGUI_EXPORT(gAbout2,1,0.05,GUIInputEvent,About2PageRefresh,
    ISKeyUP,About2PageKeyUPFunction,
    ISKeyDown,About2PageKeyDownFunction,
    ISKeyExit,About2PageKeyExitFunction,
)



/*************************************************************
** Function name:       About2PageInit
** Descriptions:        About2界面初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void About2Page_Init(void)
{
    gAbout2Page = CreateAbout2();
	About2PageHide();
}
/*************************************************************
** Function name:       About2PageShow
** Descriptions:        显示About2界面
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void About2PageShow(void)
{
    WM_ShowWindow(gAbout2Page);
    PageGUISetEnable(&gAbout2,1);
}
/*************************************************************
** Function name:       About2PageHide
** Descriptions:        隐藏About2界面
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void About2PageHide(void)
{
    WM_HideWindow(gAbout2Page);
    PageGUISetEnable(&gAbout2,0);
}

/*************************************************************
** Function name:       About2Page_Loop
** Descriptions:        About2界面循环
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void About2Page_Loop(void)
{
    PageGUICycle(&gAbout2);
}

