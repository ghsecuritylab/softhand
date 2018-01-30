#ifndef __USER_PUBLIC_H__
#define __USER_PUBLIC_H__


#include "gd32f10x.h"





typedef struct RK_CTRL_SERVO_PWM{
   uint8_t  idx;
   uint8_t  direction;
   uint8_t  mode;     // ����ģʽ
   uint8_t  bRecyle;  // �Ƿ�ѭ��
   uint16_t angle;    // ��Ҫ���Ƶ�ƫ�ƽǶ�
   uint16_t param;    // ���ݿ���ģʽ����������������ٶȻ���ʱ��
   uint16_t nop1;      // Ԥ��
   uint16_t nop2;      // Ԥ��
   uint16_t nop3;      // Ԥ��
   uint16_t nop4;      // Ԥ��
}RKPwmCtrl_t;   //RK������


/*************************
 *      485����ָ��
 ************************/
typedef struct RK_CTRL_SERVO_RS485{
   uint32_t nop;



}RKRS485Ctrl_t;  //����485��Ϣ��


/**************************
 *    I2C�����ƿ���
 *************************/
typedef struct RK_CTRL_BLIGHT_I2C{//����I2Cָ��
  uint32_t nop;


}RKLightCtrl_t;

/***************************
 *      touch ����
 **************************/
typedef struct RK_CTRL_TOUCH{
   uint32_t nop;



}RKTouchCtrl_t;

typedef struct RK_CTRL_PLAM{
   uint32_t nop;


}RKPlamCtrl_t;


#endif


