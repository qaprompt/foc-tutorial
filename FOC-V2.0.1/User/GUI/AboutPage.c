#include "AboutPage.h"

//UI库文件
#include "UI.h"
#include "DIALOG.h"
//页面管理文件
#include "PageGUI.h"
//事件触发事件
#include "GUIInputEvent.h"
//相关联界面
#include "LogoPage.h"
#include "WavePage.h"
#include "About2Page.h"

#include "stdio.h"
#include "SEGGER_RTT.h"
#include "SEGGER_RTT_Conf.h"

WM_HWIN gAboutPage;






/*************************************************************
** Function name:       AboutPageKeyUPFunction
** Descriptions:        上按键触发事件
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void AboutPageKeyUPFunction(void)
{
    //退出本次界面
    AboutPageHide();
    //进入新的界面
    WavePageShow();
}
/*************************************************************
** Function name:       AboutPageKeyDownFunction
** Descriptions:        下按键触发事件
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void AboutPageKeyDownFunction(void)
{
    //退出本次界面
    AboutPageHide();
    //进入新的界面
    LogoPageShow();
}
/*************************************************************
** Function name:       AboutPageKeyOKFunction
** Descriptions:        OK按键触发事件
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void AboutPageKeyOKFunction(void)
{
    //退出本次界面
    AboutPageHide();
    //进入新的界面
    About2PageShow();
}
/*************************************************************
** Function name:       AboutPageRefresh
** Descriptions:        页面刷新函数
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void AboutPageRefresh(void)
{
    GUI_Exec();
}



PAGEGUI_EXPORT(gAbout,1,0.05,GUIInputEvent,AboutPageRefresh,
    ISKeyUP,AboutPageKeyUPFunction,
    ISKeyDown,AboutPageKeyDownFunction,
    ISKeyOK,AboutPageKeyOKFunction,
)



/*************************************************************
** Function name:       AboutPageInit
** Descriptions:        About界面初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void AboutPage_Init(void)
{
    gAboutPage = CreateAbout();
	AboutPageHide();
}
/*************************************************************
** Function name:       AboutPageShow
** Descriptions:        显示About界面
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void AboutPageShow(void)
{
    WM_ShowWindow(gAboutPage);
    PageGUISetEnable(&gAbout,1);
}
/*************************************************************
** Function name:       AboutPageHide
** Descriptions:        隐藏About界面
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void AboutPageHide(void)
{
    WM_HideWindow(gAboutPage);
    PageGUISetEnable(&gAbout,0);
}

/*************************************************************
** Function name:       AboutPage_Loop
** Descriptions:        About界面循环
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void AboutPage_Loop(void)
{
    PageGUICycle(&gAbout);
}

