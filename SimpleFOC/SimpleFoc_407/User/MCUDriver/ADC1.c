#include "ADC1.h"
#include "main.h"


#include "stdio.h"
#include "SEGGER_RTT.h"
#include "SEGGER_RTT_Conf.h"


extern ADC_HandleTypeDef hadc1;



//一介低通滤波系数
#define FILTER_KP 0.8f


struct SADC1_Struct{
	uint32_t adDmaValue[3];
	int adValue[3];
	int lastAdValue[3];
};
struct SADC1_Struct gADC1 = {0};
/*************************************************************
** Function name:       ADC1_Init
** Descriptions:        ADC1初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void ADC1_Init(void)
{
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)gADC1.adDmaValue, 3);
}
/*************************************************************
** Function name:       GetADC1ChannelXValue
** Descriptions:        获取ADC通道 0-5的值
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
int32_t GetADC1ChannelXValue(uint8_t channel)
{
	if (channel >= 3) {
		return 0;
	}
	return gADC1.adValue[channel];
	int32_t value;
	value = (int32_t)(FILTER_KP * (float)gADC1.adValue[channel] + (1-FILTER_KP) * (float)gADC1.lastAdValue[channel]);
	gADC1.lastAdValue[channel] = value;
	return value;
}

/*************************************************************
** Function name:       GetMotor1ADCValue
** Descriptions:        Motor1读取一次ADC的值
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void GetMotor1ADCValue(void)
{
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)gADC1.adDmaValue, 3);

	gADC1.adValue[0] = gADC1.adDmaValue[0] - 2048;
	gADC1.adValue[1] = gADC1.adDmaValue[1] - 2048;
	gADC1.adValue[2] = gADC1.adDmaValue[2] - 2048;
}
/*************************************************************
** Function name:       GetMotor2ADCValue
** Descriptions:        Motor2读取一次ADC的值
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void GetMotor2ADCValue(void)
{
	gADC1.adValue[0] = gADC1.adDmaValue[0] - 2048;
	gADC1.adValue[1] = gADC1.adDmaValue[1] - 2048;
	gADC1.adValue[2] = gADC1.adDmaValue[2] - 2048;
}
/*************************************************************
** Function name:       Motor2ADCStart
** Descriptions:        Motor2开始一次ADC转换
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor2ADCStart(void)
{
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)gADC1.adDmaValue, 3);
}

