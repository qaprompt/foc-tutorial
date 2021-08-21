#include "KeyScan.h"
#include "stdio.h"
#include "SEGGER_RTT.h"
#include "SEGGER_RTT_Conf.h"


volatile uint32_t gKEY_TimeCNT;



/*************************************************************
** Function name:       KeyScan
** Descriptions:        按键扫描
** Input parameters:    pKEY：结构体指针
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void KeyScan(PKey_Struct pKEY)
{
    uint8_t leave;
    //判断按键状态 按下/弹起
    leave = pKEY->GetKeyLeave();
    if (leave == pKEY->effLeave) {
        pKEY->status = KEY_DOWN_STATUS;
        //按下的时候判断长按动作是否完成
        pKEY->pressTime += pKEY->realCycleTime;
        //判断长按超标志，如果已经发生超时不再进一步判断
        if (pKEY->timeOutFlag == 1) {
            return;
        }
        if (pKEY->pressTime > pKEY->longTime) {
            pKEY->event = KEY_LONG_TIMEOUT_EVENT;
            //长按超时标志置1
            pKEY->timeOutFlag = 1;
        }
    } else {
        pKEY->status = KEY_UP_STATUS;
        //弹起的时候判断是长按还是短按
        if (pKEY->pressTime > pKEY->longTime) {
            pKEY->event = KEY_LONG_EVENT;
        } else if (pKEY->pressTime > pKEY->shortTime) {
            pKEY->event = KEY_SHORT_EVENT;
        }
        //清除按下时间
        pKEY->pressTime = 0;
        //清除长按超时标志
        pKEY->timeOutFlag = 0;
    }
	printf("KeyEvent:%d\r\n",pKEY->event);
}
/*************************************************************
** Function name:       KEYRunCycle
** Descriptions:        KEY周期执行函数
** Input parameters:    pKEY:PKey_Struct结构体指针
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void KEYRunCycle(PKey_Struct pKEY)
{
    if(KEY_TIMEOUT(pKEY->cycle * 1000,pKEY->startTime)) {
		pKEY->realCycleTime = (KEY_GETTIME() - pKEY->startTime)/1000.0;
        pKEY->startTime = KEY_GETTIME();
        KeyScan(pKEY);
    }
}

/*************************************************************
** Function name:       GetKeyStatus
** Descriptions:        获取按键状态
** Input parameters:    None
** Output parameters:   None
** Returned value:      按键状态：KEY_UP_STATUS/KEY_DOWN_STATUS
** Remarks:             None
*************************************************************/
uint8_t GetKeyStatus(PKey_Struct pKEY)
{
    return pKEY->status;
}
/*************************************************************
** Function name:       GetKeyEvent
** Descriptions:        获取按键事件
** Input parameters:    None
** Output parameters:   None
** Returned value:      按键事件:KEY_IDLE_EVENT/KEY_SHORT_EVENT/KEY_LONG_EVENT
** Remarks:             None
*************************************************************/
uint8_t GetKeyEvent(PKey_Struct pKEY)
{
    uint8_t res;
    res = pKEY->event;
    pKEY->event = KEY_IDLE_EVENT;
    return res;
}



