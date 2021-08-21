/***********************************************************************
* @file UI
* Description:
*
**********************************************************************
* File name:      UI.h
* Date:           2021-08-16
* Version:        V1.0
* Author          liuxiang
* @history:
* V1.0 创建文件
***********************************************************************/
#ifndef __UI_H__
#define __UI_H__
#include "stdint.h"
#include "DIALOG.h"



WM_HWIN CreateLogo(void);
WM_HWIN CreateWave(void);
WM_HWIN CreateAbout(void);
WM_HWIN CreateAbout2(void);

extern WM_HWIN About2Lisbox;

#endif //__UI_H__


