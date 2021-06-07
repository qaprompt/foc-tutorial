#ifndef Motor1TIM1Pwm_h
#define Motor1TIM1Pwm_h

#include "stdint.h"


void Motor1TIM1_Init(void);
void SetMotor1ChannelAHighLeaveTime_us(float time);
void SetMotor1ChannelBHighLeaveTime_us(float time);
void SetMotor1ChannelCHighLeaveTime_us(float time);
#endif /* Motor1TIM1Pwm_h */
