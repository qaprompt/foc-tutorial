#include "OLED.h"

volatile uint32_t gOLED_TimeCNT;

#define OLED_CMD 0x00
#define OLED_DATA 0x40
/*************************************************************
** Function name:       OLEDWriteByte
** Descriptions:        OLED写一个字节
** Input parameters:    pOLED:结构体指针
**						data要发送的数据
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void OLEDWriteByte(POLED_Struct pOLED,uint8_t data)
{
	pOLED->IIC1TransmitByte(pOLED->devAddr,OLED_DATA,data);
}
/*************************************************************
** Function name:       OLEDWriteCMD
** Descriptions:        OLED写一个命令
** Input parameters:    pOLED:结构体指针
**						cmd:要发送的命令
** Returned value:      None
** Remarks:             None
*************************************************************/
void OLEDWriteCMD(POLED_Struct pOLED,uint8_t cmd)
{
	pOLED->IIC1TransmitByte(pOLED->devAddr,OLED_CMD,cmd);
}
/*************************************************************
** Function name:       OLEDDisPlayOn
** Descriptions:        OLED显示
** Input parameters:    pOLED：结构体指针
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void OLEDDisPlayON(POLED_Struct pOLED)
{
	OLEDWriteCMD(pOLED,0x8D);//电荷泵使能
	OLEDWriteCMD(pOLED,0x14);//电荷泵打开
	OLEDWriteCMD(pOLED,0xAF);//点亮屏幕
}
/*************************************************************
** Function name:       OLEDDisPlayOFF
** Descriptions:        OLED关闭显示
** Input parameters:    pOLED：结构体指针
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void OLEDDisPlayOFF(POLED_Struct pOLED)
{
	OLEDWriteCMD(pOLED,0x8D);//电荷泵使能
	OLEDWriteCMD(pOLED,0x10);//电荷泵关闭
	OLEDWriteCMD(pOLED,0xAE);//关闭屏幕
}
/*************************************************************
** Function name:       OLEDRefresh
** Descriptions:        OLED刷新函数
** Input parameters:    pOLED：结构体指针
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void OLEDRefresh(POLED_Struct pOLED)
{
	for (uint8_t i = 0; i < 4; i++) {
		OLEDWriteCMD(pOLED,0xb0+i);
		OLEDWriteCMD(pOLED,0x00);
		OLEDWriteCMD(pOLED,0x10);
		for (uint8_t j = 0; j < 128; j++) {
			OLEDWriteByte(pOLED,pOLED->pixeData[j][i]);
		}
	}
}
/*************************************************************
** Function name:       OLEDClear
** Descriptions:        OLED清屏函数
** Input parameters:    pOLED：结构体指针
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void OLEDClear(POLED_Struct pOLED)
{
	for (uint8_t i = 0; i < 4; i++) {
		for (uint8_t j = 0; j < 128; j++) {
			pOLED->pixeData[j][i] = 0;
		}
	}
	OLEDRefresh(pOLED);
}

/*************************************************************
** Function name:       OLEDDrawPoint
** Descriptions:        OLED画点函数
** Input parameters:    pOLED：结构体指针
**						x:0-127
**						y:0-63
**						status:1亮 0灭
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void OLEDDrawPoint(POLED_Struct pOLED,uint8_t x,uint8_t y,uint8_t status)
{
	uint8_t ucValue;
	uint8_t ucPageAddr;
	uint8_t ucColAddr;

	const uint8_t aOrTab[8]  = {0x01, 0x02, 0x04, 0x08,0x10,0x20,0x40,0x80};
	const uint8_t aAndTab[8] = {0xFE, 0xFD, 0xFB, 0xF7,0xEF,0xDF,0xBF,0x7F};

	ucPageAddr = y / 8;
	ucColAddr = x;

	ucValue = pOLED->pixeData[ucColAddr][ucPageAddr];
	if (status == 0)
	{
		ucValue &= aAndTab[y % 8];
	}
	else
	{
		ucValue |= aOrTab[y % 8];
	}
	pOLED->pixeData[ucColAddr][ucPageAddr] = ucValue;


//	OLEDWriteCMD(pOLED,0xB0 + ucPageAddr);					
//	OLEDWriteCMD(pOLED,0x00 + (ucColAddr & 0x0F));			
//	OLEDWriteCMD(pOLED,0x10 + ((ucColAddr >> 4) & 0x0F));	
//	OLEDWriteByte(pOLED,ucValue);
	
	// uint8_t i,m,n;
	// i = y/8;
	// m = y%8;
	// n = 1<<m;
	// if(status == 1) {
	// 	pOLED->pixeData[x][i] = n;
	// } else {
	// 	pOLED->pixeData[x][i] = ~pOLED->pixeData[x][i];
	// 	pOLED->pixeData[x][i] |= n;
	// 	pOLED->pixeData[x][i] = ~pOLED->pixeData[x][i];
	// }
	// pOLED->pointData[x][y] = status;
	// OLEDRefresh(pOLED);
}
/*************************************************************
** Function name:       OLEDGetPoint
** Descriptions:        OLED获取点状态函数
** Input parameters:    pOLED：结构体指针
**						x:0-127
**						y:0-63
** Output parameters:   None
** Returned value:      status:1亮 0灭
** Remarks:             None
*************************************************************/
uint8_t OLEDGetPoint(POLED_Struct pOLED,uint8_t x,uint8_t y)
{
	uint8_t ucValue;
	uint8_t ucPageAddr;
	uint8_t ucColAddr;

	ucPageAddr = y / 8;
	ucColAddr = x;

	ucValue = pOLED->pixeData[ucColAddr][ucPageAddr];
	if (ucValue & (y % 8)) {
		return 1;
	}
	else {
		return 0;
	}
}

/*************************************************************
** Function name:       OLEDInit
** Descriptions:        OLED初始化
** Input parameters:    pOLED：结构体指针
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void OLEDInit(POLED_Struct pOLED)
{
	OLEDWriteCMD(pOLED,0xAE);
	OLEDWriteCMD(pOLED,0x40);
	OLEDWriteCMD(pOLED,0xB0);
	OLEDWriteCMD(pOLED,0xC8);
	OLEDWriteCMD(pOLED,0x81);
	OLEDWriteCMD(pOLED,0xFF);
	OLEDWriteCMD(pOLED,0xA1);
	OLEDWriteCMD(pOLED,0xA6);
	OLEDWriteCMD(pOLED,0xA8);
	OLEDWriteCMD(pOLED,0x1f);
	OLEDWriteCMD(pOLED,0xD3);
	OLEDWriteCMD(pOLED,0x00);
	OLEDWriteCMD(pOLED,0xD5);
	OLEDWriteCMD(pOLED,0xF0);
	OLEDWriteCMD(pOLED,0xD9);
	OLEDWriteCMD(pOLED,0x22);
	OLEDWriteCMD(pOLED,0xDA);
	OLEDWriteCMD(pOLED,0x02);
	OLEDWriteCMD(pOLED,0xDB);
	OLEDWriteCMD(pOLED,0x49);
	OLEDWriteCMD(pOLED,0x8D);
	OLEDWriteCMD(pOLED,0x14);
	OLEDWriteCMD(pOLED,0xAF);
	OLEDClear(pOLED);
	OLEDRefresh(pOLED);
}




/*************************************************************
** Function name:       OLEDRunCycle
** Descriptions:        OLED周期执行函数
** Input parameters:    pOLED:POLED_Struct
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void OLEDRunCycle(POLED_Struct pOLED)
{
    if(OLED_TIMEOUT(pOLED->cycle * 1000,pOLED->startTime)) {
        pOLED->startTime = OLED_GETTIME();
        OLEDRefresh(pOLED);
    }
}
