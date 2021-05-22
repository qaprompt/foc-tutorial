#include "Motor1ADC1.h"
#include "main.h"


#include "stdio.h"
#include "SEGGER_RTT.h"
#include "SEGGER_RTT_Conf.h"


extern ADC_HandleTypeDef hadc1;



//一介低通滤波系数
#define FILTER_KP 0.9f


struct SMotor1ADC1_Struct{
	uint32_t adDmaValue[3];			//DMA原始数据
	int adValue[3];					//电流实际AD值
	int lastAdValue[3];				//上次电流实际AD值
};
struct SMotor1ADC1_Struct gMotor1ADC1 = {0};
/*************************************************************
** Function name:       Motor1ADC1StartOnce
** Descriptions:        Motor1ADC开始一次DMA转换
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor1ADC1StartOnce(void)
{
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)gMotor1ADC1.adDmaValue, 3);
}

/*************************************************************
** Function name:       Motor1ADCValueStorage
** Descriptions:        Motor1存储DMA获取到的数据
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor1ADC1ValueStorage(void)
{
	gMotor1ADC1.adValue[0] = gMotor1ADC1.adDmaValue[0] - 2048;
	gMotor1ADC1.adValue[1] = gMotor1ADC1.adDmaValue[1] - 2048;
	gMotor1ADC1.adValue[2] = gMotor1ADC1.adDmaValue[2] - 2048;
}
/*************************************************************
** Function name:       GetMotor1ADC1PhaseXValue
** Descriptions:        获取 Motor13相电流
** Input parameters:    Phase：1：A相 2：B相 3：C相
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
int32_t GetMotor1ADC1PhaseXValue(uint8_t Phase)
{
	if (Phase >= 3) {
		return 0;
	}
	int32_t value;
	value = (int32_t)(FILTER_KP * (float)gMotor1ADC1.adValue[Phase] + (1-FILTER_KP) * (float)gMotor1ADC1.lastAdValue[Phase]);
	gMotor1ADC1.lastAdValue[Phase] = value;
	return value;
}




