#include "Motor1SPI1.h"
#include "main.h"

extern SPI_HandleTypeDef hspi1;





/*************************************************************
** Function name:       Motor1SPI1WriteData
** Descriptions:        SPI1写数据
** Input parameters:    data：要发送的数据
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor1SPI1WriteData(uint16_t data)
{
    HAL_SPI_Transmit(&hspi1,(uint8_t *)&data,1,1000);
}
/*************************************************************
** Function name:       Motor1SPI1ReadData
** Descriptions:        SPI1读数据
** Input parameters:    None
** Output parameters:   None
** Returned value:      读取到的数据
** Remarks:             None
*************************************************************/
uint16_t Motor1SPI1ReadData(void)
{
    uint16_t data;
    HAL_SPI_Receive(&hspi1,(uint8_t *)&data,1,1000);
    return data;
}
/*************************************************************
** Function name:       Motor1SPI1SetCS1
** Descriptions:        设置SPI1 片选1引脚电平
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor1SPI1SetCS(uint8_t leave)
{
    HAL_GPIO_WritePin(M1_SPI_CS_GPIO_Port,M1_SPI_CS_Pin, (GPIO_PinState)leave);
}

