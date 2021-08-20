#include "GUIFunc.h"
//GUI库
#include "GUI.h"
#include "UI.h"
#include "DIALOG.h"
//PLED驱动
#include "OLEDConfig.h"




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
    OLEDConfig_Init();
    GUI_Init();
	GUI_Clear();
    //CreateParams();
    CreateLogo();
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
	OLEDConfig_Loop();
}
