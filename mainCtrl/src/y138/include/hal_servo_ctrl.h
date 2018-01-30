#ifndef __HAL_SERVO_CTRL_H_
#define __HAL_SERVO_CTRL_H_


#include "gd32f10x.h"
#include "hal_servo_cfg.h"
#include "hal_rs485_ctrl.h"
#include "hal_pwm_ctrl.h"




/**********************
 *      ��Ӧ������
 *********************/
typedef enum SERVO_ACK_ERRORCODE{
   SERVO_OK,            // ״̬OK
   SERVO_OVER_LOAD,     // ����
   SERVO_OVER_TMP,      // �¶ȹ���
   SERVO_OVER_VOLTAGE,  // ��ѹ
}AckErrCode_e;


typedef enum SERVO_TYPE_CODE{
   SERVO_TYPE_RS485,
   SERVO_TYPE_PWM,
}ServoType_e;

//�Խ��ٶȽ���ת������ʱ��ȽǶȽ���ƫ�� 




#endif

