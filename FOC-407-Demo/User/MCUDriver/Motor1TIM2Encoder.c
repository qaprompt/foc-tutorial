#include "Motor1TIM2Encoder.h"
#include "SEGGER_RTT_Conf.h"
#include "SEGGER_RTT.h"
#include "main.h"

#define CNTZERO 10000
#define ENCODERPLUSE 8192


extern TIM_HandleTypeDef hTIM2;

struct STimEnc_Struct {
    int32_t TIM2Cnt;        //编码器脉冲数 0-360°
    float angle;			//编码器角度 0-360°
};
typedef struct STimEnc_Struct TimEnc_Struct; /* TimEnc 类型 */
typedef TimEnc_Struct *PTimEnc_Struct;      /* PTimEnc 指针类型 */

TimEnc_Struct gSTTimerEncoder = {
    .TIM2Cnt = 0,
    .angle = 0,
};

/*************************************************************
** Function name:       TimerEncoderInit
** Descriptions:        初始化定时器2
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
*************************************************************/
void TimerEncoderInit(void)
{
    HAL_TIM_Encoder_Start(&hTIM2, TIM_CHANNEL_1|TIM_CHANNEL_2);
    __HAL_TIM_SET_COUNTER(&hTIM2,CNTZERO);
    gSTTimerEncoder.angle = 0.0;
    gSTTimerEncoder.TIM2Cnt = 0;
}
/*************************************************************
** Function name:       TimerEncoderInit
** Descriptions:        复位定时器2
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
*************************************************************/
void TimerEncoderReset(void)
{
    __HAL_TIM_SET_COUNTER(&hTIM2,CNTZERO);
    gSTTimerEncoder.angle = 0.0;
    gSTTimerEncoder.TIM2Cnt = 0;
}
/*************************************************************
** Function name:       GetTimer2EncoderCnt
** Descriptions:        获取定时器2编码器模式CNT的值
** Input parameters:    None
** Output parameters:   None
** Returned value:      Timer2->CNT的值
*************************************************************/
int32_t GetTimer2EncoderCnt(void)
{
    gSTTimerEncoder.TIM2Cnt += __HAL_TIM_GET_COUNTER(&hTIM2) - CNTZERO;
	__HAL_TIM_SET_COUNTER(&hTIM2,CNTZERO);
	if (gSTTimerEncoder.TIM2Cnt < 0) {
		gSTTimerEncoder.TIM2Cnt += ENCODERPLUSE;
	}
    gSTTimerEncoder.TIM2Cnt = gSTTimerEncoder.TIM2Cnt % ENCODERPLUSE;
    return gSTTimerEncoder.TIM2Cnt;
}
/*************************************************************
** Function name:       SetTimer2EncoderCnt
** Descriptions:        设置Timer2Cnt的值
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetTimer2EncoderCnt(int32_t cnt)
{
	gSTTimerEncoder.TIM2Cnt = cnt;
}
/*************************************************************
** Function name:       GetTimerEncoderAngle
** Descriptions:        获取编码器角度
** Input parameters:    None
** Output parameters:   None
** Returned value:      编码器角度
*************************************************************/
float GetTimer2EncoderAngle(void)
{
    gSTTimerEncoder.angle = (float)GetTimer2EncoderCnt() / (float)ENCODERPLUSE * 360.0f;
    if (gSTTimerEncoder.angle < 0) {
        gSTTimerEncoder.angle = gSTTimerEncoder.angle + 360.0f;
    }
    return gSTTimerEncoder.angle;
}
