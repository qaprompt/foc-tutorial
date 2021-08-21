#include "LogoPage.h"

//UI库文件
#include "UI.h"
#include "DIALOG.h"
//页面管理文件
#include "PageGUI.h"
//事件触发事件
#include "GUIInputEvent.h"
//相关联界面
#include "WavePage.h"



WM_HWIN gLogoPage;


/*************************************************************
** Function name:       LogoPageKeyUPFunction
** Descriptions:        上按键触发事件
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void LogoPageKeyUPFunction(void)
{
    //退出本次界面
    LogoPageHide();
    //进入新的界面
    AboutPageShow();
}
/*************************************************************
** Function name:       LogoPageKeyDownFunction
** Descriptions:        下按键触发事件
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void LogoPageKeyDownFunction(void)
{
    //退出本次界面
    LogoPageHide();
    //进入新的界面
    WavePageShow();
}

/*************************************************************
** Function name:       LogoPageRefresh
** Descriptions:        页面刷新函数
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void LogoPageRefresh(void)
{
    GUI_Exec();
}
PAGEGUI_EXPORT(gLogo,1,0.05,GUIInputEvent,LogoPageRefresh,
    ISKeyUP,LogoPageKeyUPFunction,
    ISKeyDown,LogoPageKeyDownFunction,
)



/*************************************************************
** Function name:       LogoPageInit
** Descriptions:        LOGO界面初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void LogoPage_Init(void)
{
    gLogoPage = CreateLogo();
	LogoPageShow();
}
/*************************************************************
** Function name:       LogoPageShow
** Descriptions:        显示LOGO界面
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void LogoPageShow(void)
{
    WM_ShowWindow(gLogoPage);
    PageGUISetEnable(&gLogo,1);
}
/*************************************************************
** Function name:       LogoPageHide
** Descriptions:        隐藏Logo界面
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void LogoPageHide(void)
{
    WM_HideWindow(gLogoPage);
    PageGUISetEnable(&gLogo,0);
}

/*************************************************************
** Function name:       LogoPage_Loop
** Descriptions:        LOGO界面循环
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void LogoPage_Loop(void)
{
    PageGUICycle(&gLogo);
}

