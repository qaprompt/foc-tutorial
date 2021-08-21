#include "GUIFunc.h"
//GUI库
#include "GUI.h"
#include "UI.h"
#include "DIALOG.h"


//界面
#include "LogoPage.h"
#include "WavePage.h"
#include "AboutPage.h"
#include "About2Page.h"
/*************************************************************
** Function name:      GUIFunc_Init
** Descriptions:       GUI功能初始化
** Input parameters:   none
** Output parameters:  none
** Returned value:     none
** Created by:         none
** Created date:       none
*************************************************************/
void GUIFunc_Init(void)
{
    GUI_Init();
	GUI_Clear();
	LogoPage_Init();
    WavePage_Init();
    AboutPage_Init();
    About2Page_Init();
	GUI_Exec();
}

/*************************************************************
** Function name:      GUIFunc_Loop
** Descriptions:       GUI功能循环
** Input parameters:   none
** Output parameters:  none
** Returned value:     none
** Created by:         none
** Created date:       none
*************************************************************/
void GUIFunc_Loop(void)
{
	LogoPage_Loop();
    WavePage_Loop();
    AboutPage_Loop();
    About2Page_Loop();
}
