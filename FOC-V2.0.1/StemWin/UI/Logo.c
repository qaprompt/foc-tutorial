/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.32                          *
*        Compiled Oct  8 2015, 11:59:02                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0        (GUI_ID_USER + 0x00)
#define ID_IMAGE_0        (GUI_ID_USER + 0x01)

#define ID_IMAGE_0_IMAGE_0       0x00

// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
/*********************************************************************
*
*       _acImage_0, "C:\Users\Administrator\Pictures\Logo.dta", ID_IMAGE_0_IMAGE_0
*/
static const U8 _acImage_0[528] = {
  0x42, 0x4D, 0x64, 0x00, 0x80, 0x00, 0x20, 0x00, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xFB, 0xFF, 0xFE, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xDF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF,
  0xFB, 0xFF, 0x7F, 0xDF, 0xFF, 0xE0, 0x01, 0xFF, 0x8F, 0xFF, 0x80, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xFB, 0xFF, 0x7F, 0xDF, 0xFC, 0x0F, 0xBF, 0xFF, 0x2F, 0xF0, 0x3E, 0xFF, 0xFF, 0xF7, 0xFE, 0x01, 0xFB, 0xFE, 0x7F, 0xDF, 0xFF, 0xFF, 0xBF, 0xFF, 0x6F, 0xFF,
  0xFE, 0xFF, 0xFF, 0xF7, 0xFE, 0xF9, 0xFB, 0xFE, 0xE0, 0x00, 0xFF, 0xFF, 0xBF, 0xFF, 0x6F, 0xFF, 0xFC, 0xFF, 0xFF, 0xF7, 0xFE, 0xFB, 0xFB, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xBF, 0xFF, 0x6F, 0xFF, 0xF9, 0xFF, 0xFF, 0xF7, 0xFE, 0xFB, 0xF8, 0x70, 0xFF, 0xFF,
  0xFF, 0xFF, 0xBF, 0xFF, 0x6F, 0xFF, 0xF3, 0xFF, 0xFF, 0xE7, 0xFE, 0xFB, 0x03, 0xF6, 0xDC, 0xFF, 0xFF, 0xFF, 0xBF, 0xFF, 0x6F, 0xFF, 0xE7, 0xFF, 0xFF, 0xEF, 0xFE, 0xFB, 0xFB, 0xC6, 0xDE, 0xFF, 0xFC, 0x03, 0xBF, 0xFF, 0x6F, 0xFF, 0xEF, 0xFF, 0xFF, 0xEF,
  0x7E, 0x0B, 0xFB, 0xDE, 0xDE, 0xFF, 0xFD, 0xFB, 0xBF, 0xFF, 0x6F, 0xFF, 0xCF, 0xFF, 0xFF, 0x6F, 0x7E, 0xF3, 0xFB, 0xFE, 0xDE, 0x01, 0xFD, 0xF3, 0xBF, 0xFF, 0x6F, 0xFF, 0x1F, 0xFF, 0xFE, 0x6F, 0x3E, 0xF7, 0xFB, 0xFE, 0xDC, 0xEF, 0xFD, 0xF7, 0xBF, 0xFF,
  0x6F, 0xFF, 0x3F, 0xFF, 0xFE, 0xEF, 0xBE, 0xF7, 0x13, 0xFE, 0xF9, 0xEF, 0xFD, 0xF7, 0xBF, 0xFF, 0x61, 0xFF, 0xBF, 0xFF, 0xFC, 0xEF, 0xBE, 0xE7, 0xF7, 0xFE, 0xF3, 0xEF, 0xFD, 0x07, 0xBF, 0xC0, 0x65, 0xFF, 0xBF, 0xFF, 0xFF, 0xEF, 0xBE, 0xFF, 0xF7, 0xFE,
  0xFF, 0xEF, 0xFC, 0x7F, 0xBF, 0x92, 0x6C, 0x7F, 0xBF, 0xFF, 0xFF, 0xEF, 0xFC, 0x07, 0xF7, 0xFE, 0xFC, 0x03, 0xFF, 0xFF, 0xBF, 0xB6, 0x6C, 0x7F, 0xBF, 0xFF, 0xFF, 0xEF, 0xFF, 0xF7, 0xF7, 0xFE, 0xF9, 0xDF, 0xFF, 0xFF, 0xBF, 0x36, 0x6C, 0x7F, 0xBF, 0xFF,
  0xFF, 0xEF, 0xFF, 0xFF, 0xF7, 0xFE, 0xFF, 0x8F, 0xFF, 0xFF, 0x3F, 0x76, 0xED, 0x7F, 0xBF, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0x77, 0xFE, 0xFF, 0x27, 0xFF, 0xFF, 0x7F, 0x7F, 0xFF, 0x7F, 0xBF, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0x37, 0xFE, 0xFE, 0x77, 0xFF, 0xC7,
  0x7F, 0x7F, 0xFF, 0x7F, 0xBF, 0xFF, 0xFF, 0x2F, 0xFF, 0xFF, 0x97, 0xFF, 0xF8, 0xF1, 0xFF, 0xF1, 0x7F, 0x7F, 0xFF, 0x79, 0xBF, 0xFF, 0xFF, 0x8F, 0xFF, 0xFF, 0xC7, 0xFF, 0xE3, 0xFC, 0x3F, 0xFC, 0x7F, 0x7F, 0xFF, 0x7C, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xBF, 0xFF, 0x7F, 0x1F, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0xFC, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x01, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
};

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 128, 32, 0, 0x0, 0 },
  { IMAGE_CreateIndirect, "Image", ID_IMAGE_0, 0, 0, 128, 32, 0, 0, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
/*********************************************************************
*
*       _GetImageById
*/
static const void * _GetImageById(U32 Id, U32 * pSize) {
  switch (Id) {
  case ID_IMAGE_0_IMAGE_0:
    *pSize = sizeof(_acImage_0);
    return (const void *)_acImage_0;
  }
  return NULL;
}

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  const void * pData;
  WM_HWIN      hItem;
  U32          FileSize;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'Image'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_IMAGE_0);
    pData = _GetImageById(ID_IMAGE_0_IMAGE_0, &FileSize);
    IMAGE_SetDTA(hItem, pData, FileSize);
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateWindow
*/

WM_HWIN CreateLogo(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/