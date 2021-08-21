#include "WavePage.h"

//UI库文件
#include "UI.h"
#include "DIALOG.h"
//页面管理文件
#include "PageGUI.h"
//事件触发事件
#include "GUIInputEvent.h"
//相关联界面
#include "LogoPage.h"
#include "AboutPage.h"
// #include "Wave2Page.h"

#include "stdio.h"
#include "SEGGER_RTT.h"
#include "SEGGER_RTT_Conf.h"

WM_HWIN gWavePage;






/*************************************************************
** Function name:       WavePageKeyUPFunction
** Descriptions:        上按键触发事件
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void WavePageKeyUPFunction(void)
{
    //退出本次界面
    WavePageHide();
    //进入新的界面
    LogoPageShow();
}
/*************************************************************
** Function name:       WavePageKeyDownFunction
** Descriptions:        下按键触发事件
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void WavePageKeyDownFunction(void)
{
    //退出本次界面
    WavePageHide();
    //进入新的界面
    AboutPageShow();
}
/*************************************************************
** Function name:       WavePageKeyOKFunction
** Descriptions:        OK按键触发事件
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void WavePageKeyOKFunction(void)
{
    //退出本次界面
    WavePageHide();
    //进入新的界面
    // Wave2PageShow();
}
/*************************************************************
** Function name:       WavePageRefresh
** Descriptions:        页面刷新函数
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void WavePageRefresh(void)
{
    GUI_Exec();
}



PAGEGUI_EXPORT(gWave,1,0.05,GUIInputEvent,WavePageRefresh,
    ISKeyUP,WavePageKeyUPFunction,
    ISKeyDown,WavePageKeyDownFunction,
    ISKeyOK,WavePageKeyOKFunction,
)



/*************************************************************
** Function name:       WavePageInit
** Descriptions:        Wave界面初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void WavePage_Init(void)
{
    gWavePage = CreateWave();
	WavePageHide();
}
/*************************************************************
** Function name:       WavePageShow
** Descriptions:        显示Wave界面
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void WavePageShow(void)
{
    WM_ShowWindow(gWavePage);
    PageGUISetEnable(&gWave,1);
}
/*************************************************************
** Function name:       WavePageHide
** Descriptions:        隐藏Wave界面
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void WavePageHide(void)
{
    WM_HideWindow(gWavePage);
    PageGUISetEnable(&gWave,0);
}

/*************************************************************
** Function name:       WavePage_Loop
** Descriptions:        Wave界面循环
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void WavePage_Loop(void)
{
    PageGUICycle(&gWave);
}

