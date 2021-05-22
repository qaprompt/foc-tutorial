
/***********************************************************************
* @file Motor1TIM2Encoder
* Description:
*
**********************************************************************
* File name:      Motor1TIM2Encoder.h
* Date:           2021-03-10
* Version:        V1.0
* Author          liuxiang
* @history:
* V1.0 创建文件
***********************************************************************/
#ifndef __Motor1TIM2Encoder_H__
#define __Motor1TIM2Encoder_H__
#include "stdint.h"

#include "stdio.h"
#include "stdint.h"





void TimerEncoderInit(void);
void TimerEncoderReset(void);
int32_t GetTimer2EncoderCnt(void);
void SetTimer2EncoderCnt(int32_t cnt);
float GetTimer2EncoderAngle(void);

#endif //__Motor1TIM2Encoder_H__





