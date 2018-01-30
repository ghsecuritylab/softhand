#ifndef __HAL_RS485_CTRL_H_
#define __HAL_RS485_CTRL_H_



#include "gd32f10x.h"
#include "hal_servo_cfg.h"
#include "hal_uart_ctrl.h"
#include <string.h>


#define cfgBUS_EN_PORT         (GPIOB)
#define cfgBUS_EN_PIN          (GPIO_PIN_3)





typedef enum SERVO_ACK_STATE_E{
    ACK_STATE_HEAD_1,
    ACK_STATE_HEAD_2,
    ACK_STATE_ID,
    ACK_STATE_LEN,
    ACK_STATE_CONTENT,
    ACK_STATE_ODD,
}ServoAckState_e;

typedef enum SERVO_BUS_IDX{
      BUS_ID_LARM_0,   // ���ֱ�  ���ϵ��·ֱ���00--05
      BUS_ID_LARM_1,
      BUS_ID_LARM_2,
      BUS_ID_LARM_3,
      BUS_ID_LARM_4,
      BUS_ID_LARM_5,
    
      BUS_ID_RARM_0,
      BUS_ID_RARM_1,
      BUS_ID_RARM_2,
      BUS_ID_RARM_3,
      BUS_ID_RARM_4,
      BUS_ID_RARM_5,
}BusServoIdx_e;


typedef struct{
   uint8_t bHeadRecv;  // ���յ�����ͷ
   uint8_t bHead1Recv;
   uint8_t id; 
   uint8_t paramLen;   // ���ݳ���
   uint8_t len;        // ��ǰ���յ������ݳ���
   uint8_t odd;    
   uint16_t startPos;  // ��ʼָ��
   uint16_t endPos;    // ����λָ��
   uint8_t  curPos;
   ServoAckState_e state; 
}ServoAck_t;


typedef struct{
    uint8_t  id;       // ID��
    uint8_t  bActive;  //  �Ƿ���Ч
    uint16_t maxPos;   // 0---4096   ���λ�ú���Сλ��
    uint16_t minPos;   // 0---4096   ���λ�ú���Сλ��
    uint16_t midPos;   // ��λ����
    uint16_t targetPos; // Ŀ��λ��
    uint16_t runTime;  // ����ʱ��
    uint16_t curPos;   // ��ǰλ��
    uint16_t speed;    // �����ٶ�
    uint8_t  speedAdjust; // �ٶȵ���
    uint8_t  regFlg;    // REG Write Flg
}BusServoState_t;


void hal_rs485_init(void);
int rs485_get_id(int id);



#endif


