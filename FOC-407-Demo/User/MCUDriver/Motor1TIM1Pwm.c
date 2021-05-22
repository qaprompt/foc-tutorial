#include "Motor1TIM1Pwm.h"
#include "main.h"

extern TIM_HandleTypeDef htim1;


/*************************************************************
** Function name:       Motor1TIM1_Init
** Descriptions:        电机1定时器初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Motor1TIM1_Init(void)
{
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);
    __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,0);
    __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,0);
    __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3,0);

    SetMotor1ChannelAHighLeaveTime_us(0);
    SetMotor1ChannelBHighLeaveTime_us(0);
    SetMotor1ChannelCHighLeaveTime_us(0);
}



/*************************************************************
** Function name:       SetMotor1ChannelAHighLeaveTime_us
** Descriptions:        设置电机1通道A高电平时间（中央对齐模式二）
** Input parameters:    time：高电平时间 单位us 范围 0-100
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetMotor1ChannelAHighLeaveTime_us(float time)
{
    uint32_t ccr;
    if (time < 0) {
        time = 0;
    }
    if (time > 100) {
        time = 100;
    }
    ccr = 42 * time;
    __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1, ccr);
}
/*************************************************************
** Function name:       SetMotor1ChannelBHighLeaveTime_us
** Descriptions:        设置电机1通道B高电平时间（中央对齐模式二）
** Input parameters:    time：高电平时间 单位us 范围 0-100
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetMotor1ChannelBHighLeaveTime_us(float time)
{
    uint32_t ccr;
    if (time < 0) {
        time = 0;
    }
    if (time > 100) {
        time = 100;
    }
    ccr = 42 * time;
    __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2, ccr);
}
/*************************************************************
** Function name:       SetMotor1ChannelCHighLeaveTime_us
** Descriptions:        设置电机1通道C高电平时间（中央对齐模式二）
** Input parameters:    time：高电平时间 单位us 范围 0-100
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetMotor1ChannelCHighLeaveTime_us(float time)
{
    uint32_t ccr;
    if (time < 0) {
        time = 0;
    }
    if (time > 100) {
        time = 100;
    }
    ccr = 42 * time;
    __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3, ccr);
}




