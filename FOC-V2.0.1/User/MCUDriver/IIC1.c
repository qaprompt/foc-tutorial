#include "IIC1.h"
#include "main.h"

extern I2C_HandleTypeDef hi2c1;



/*************************************************************
** Function name:       IIC1TransmitByte
** Descriptions:        IIC发送一个字节
** Input parameters:    addr：寄存器地址
**                      data:字节
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void IIC1TransmitByte(uint8_t devAddr,uint8_t regAddr,uint8_t data)
{
    //HAL_I2C_Mem_Write_DMA(&hi2c1, devAddr,regAddr, 1, &data, 1);
	HAL_I2C_Mem_Write(&hi2c1, devAddr,regAddr, 1, &data, 1,100);
}

