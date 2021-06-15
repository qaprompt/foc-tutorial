#include "CAN1.h"

#include "main.h"
#include "string.h"

#include "stdio.h"
#include "SEGGER_RTT.h"
#include "SEGGER_RTT_Conf.h"


#define MASTER_DEVICE_CAN_ID 0x1000

extern CAN_HandleTypeDef hcan1;

CAN_TxHeaderTypeDef gTxData;
CAN_RxHeaderTypeDef gRxData;


/*************************************************************
** Function name:       CANFilterSet
** Descriptions:        设置CAN筛选器
** Input parameters:    pCan：Can指针
**                      masterID：主控制器ID
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
static void CANFilterSet(CAN_HandleTypeDef* pCan,uint8_t masterID)
{
    CAN_FilterTypeDef sFilterConfig;
    //打开过滤器
    sFilterConfig.FilterActivation = ENABLE;
    //过滤器0 这里可设0-27
    sFilterConfig.FilterBank = 0;
    //采用列表模式
    sFilterConfig.FilterMode = CAN_FILTERMODE_IDLIST;
    //采用32位掩码模式
    sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
    //采用FIFO0
    sFilterConfig.FilterFIFOAssignment = CAN_FILTER_FIFO0;
    //设置ID列表
    sFilterConfig.FilterIdHigh = 0x0000;    
    sFilterConfig.FilterIdLow = masterID;    
    sFilterConfig.FilterMaskIdHigh = 0x0000;
    sFilterConfig.FilterMaskIdLow = masterID; 
    //初始化过滤器
    if(HAL_CAN_ConfigFilter(pCan,&sFilterConfig) != HAL_OK) {
        Error_Handler();
    }
}
/*************************************************************
** Function name:       CAN_Init
** Descriptions:        CAN初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void CAN_Init(void)
{
    //设置ID筛选器
    CANFilterSet(&hcan1,(uint8_t)MASTER_DEVICE_CAN_ID);
    //打开CAN
    HAL_CAN_Start(&hcan1);
    //开启中断
    HAL_CAN_ActivateNotification(&hcan1,CAN_IT_RX_FIFO0_MSG_PENDING);

}
/*************************************************************
** Function name:       CANSendData
** Descriptions:        CAN发送一包数据
** Input parameters:    data:数据起始地址
**						length：长度，最大8位
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void CANSendData(uint8_t *data,uint8_t length)
{
    uint8_t message[8];
	uint32_t txMailBox;
    gTxData.StdId = 0x1000;
    gTxData.ExtId = 0x0000;
    //标准帧
    gTxData.IDE = CAN_ID_STD;
    //数据帧
    gTxData.RTR = CAN_RTR_DATA;
    //数据长度
    gTxData.DLC = length;
	memcpy(message,data,length);
    //发送
    HAL_CAN_AddTxMessage(&hcan1, &gTxData, message, &txMailBox);
	while(HAL_CAN_GetTxMailboxesFreeLevel(&hcan1) != 3) {}
}
/*************************************************************
** Function name:       CANReceiveData
** Descriptions:        CAN接收一包数据
** Input parameters:    data:接收数据存放的起始地址
**						*length：接收到的长度，最大8位
** Output parameters:   None
** Returned value:      0：成功 1/2：失败
** Remarks:             None
*************************************************************/
uint8_t CANReceiveData(uint8_t *data, uint8_t *length)
{
    uint8_t message[8];
    if (HAL_CAN_GetRxFifoFillLevel(&hcan1, CAN_RX_FIFO0) != 1) {
        *length = 0;
        return 1;
    }
    if (HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &gRxData, message) != HAL_OK) {
        *length = 0;
        return 2;
    }
    *length = gTxData.DLC;
    memcpy(data,message,*length);
    return 0;
}

/*************************************************************
** Function name:       CAN_Test
** Descriptions:        CAN_测试
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void CAN_Test(void)
{
    uint8_t txData[8];
    txData[0] = 1;
    txData[1] = 2;
    txData[2] = 3;
    txData[3] = 4;
    txData[4] = 5;
    txData[5] = 6;
    txData[6] = 7;
    txData[7] = 8;

    uint8_t rxData[8];
    uint8_t rxLen;
    CANSendData(txData,8);
    CANReceiveData(rxData,&rxLen);
    if (rxLen == 0) {
        return;
    }
    for(uint8_t i = 0; i < rxLen; i++){
        printf("data[%d] = %d",i,rxData[i]);
    }
    printf("\r\n");


}