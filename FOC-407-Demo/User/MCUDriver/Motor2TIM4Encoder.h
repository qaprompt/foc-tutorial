
/***********************************************************************
* @file Motor2TIM4Encoder
* Description:
*
**********************************************************************
* File name:      Motor2TIM4Encoder.h
* Date:           2021-03-10
* Version:        V1.0
* Author          liuxiang
* @history:
* V1.0 创建文件
***********************************************************************/
#ifndef __Motor2TIM4Encoder_H__
#define __Motor2TIM4Encoder_H__
#include "stdint.h"

#include "stdio.h"
#include "stdint.h"





void Timer4EncoderInit(void);
void Timer4EncoderReset(void);
int32_t GetTimer4EncoderCnt(void);
void SetTimer4EncoderCnt(int32_t cnt);
float GetTimer4EncoderAngle(void);

#endif //__Motor2TIM4Encoder_H__





