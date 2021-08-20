/***********************************************************************
* @file IIC1
* Description:
*
**********************************************************************
* File name:      IIC1.h
* Date:           2021-07-24
* Version:        V1.0
* Author          liuxiang
* @history:
* V1.0 创建文件
***********************************************************************/
#ifndef __IIC1_H__
#define __IIC1_H__
#include "stdint.h"

void IIC1TransmitByte(uint8_t devAddr,uint8_t regAddr,uint8_t data);

#endif //__IIC1_H__




