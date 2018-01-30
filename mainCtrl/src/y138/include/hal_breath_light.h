#ifndef __HAL_BREATH_LIGHT_H_
#define __HAL_BREATH_LIGHT_H_



#include "gd32f10x.h"
#include "hal_i2c_ctrl.h"


#define cfgREG_IN_STATUS_P0      (0x00)   // ��ȡP0�ڵ�ƽ       ��
#define cfgREG_IN_STATUS_P1      (0x01)   // ��ȡP1�ڵ�ƽ       ��
#define cfgREG_OUT_STATUS_P0     (0x02)   // ��ȡP0�����״̬   ��д
#define cfgREG_OUT_STATUS_P1     (0x03)   // ��ȡP1�����״̬   ��д
#define cfgREG_CFG_PORT_P0      (0x04)   // ����P0�������     ��д
#define cfgREG_CFG_PORT_P1      (0x05)   // ����P0�������     ��д
#define cfgREG_IT_EN_P0         (0x06)   // �ж�ʹ��P0         ��д
#define cfgREG_IT_EN_P1         (0x07)   // �ж�ʹ��P1         ��д
#define cfgREG_READ_ID          (0x10)   // ��ȡID��           ��
#define cfgREG_CTRL             (0x11)   // ȫ�ֿ��ƼĴ���     ��д
#define cfgREG_CFG_LED_MODE0    (0x12)   // P0_0~7����ģʽ�л� ��
#define cfgREG_CFG_LED_MODE1    (0x13)   // P1_0~7����ģʽ�л� ��
#define cfgREG_LED_P1_0         (0x20)   // LED P1_0��������   д
#define cfgREG_LED_P1_1         (0x21)   // LED P1_1��������   д
#define cfgREG_LED_P1_2         (0x22)   // LED P1_2��������   д
#define cfgREG_LED_P1_3         (0x23)   // LED P1_3��������   д
#define cfgREG_LED_P0_0         (0x24)   // LED P0_0��������   д
#define cfgREG_LED_P0_1         (0x25)   // LED P0_1��������   д
#define cfgREG_LED_P0_2         (0x26)   // LED P0_2��������   д
#define cfgREG_LED_P0_3         (0x27)   // LED P0_3��������   д
#define cfgREG_LED_P0_4         (0x28)   // LED P0_4��������   д
#define cfgREG_LED_P0_5         (0x29)   // LED P0_5��������   д
#define cfgREG_LED_P0_6         (0x2a)   // LED P0_6��������   д
#define cfgREG_LED_P0_7         (0x2b)   // LED P0_7��������   д
#define cfgREG_LED_P1_4         (0x2c)   // LED P1_4��������   д
#define cfgREG_LED_P1_5         (0x2d)   // LED P1_5��������   д
#define cfgREG_LED_P1_6         (0x2e)   // LED P1_6��������   д
#define cfgREG_LED_P1_7         (0x2f)   // LED P1_7��������   д

#endif
