#include "ADC1.h"
#include "main.h"


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
** Function name:       GetADC1ChannelXValue
** Descriptions:        获取ADC通道 10 - 11的值
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
int32_t GetADC1ChannelXValue(uint8_t channel)
{
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
void ADCDMAStart(void)
{
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)gADC1.adDmaValue, 3);
}

/*************************************************************
** Function name:       ADCDMAIRQHandler
** Descriptions:        ADC1DMA读取中断服务函数
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void ADCDMAIRQHandler(void)
{
	gADC1.adValue[0] = (int)gADC1.adDmaValue[0] - 2075;
	gADC1.adValue[1] = (int)gADC1.adDmaValue[1] - 2015;
	gADC1.adValue[2] = (int)gADC1.adDmaValue[2] - 2042;
}


