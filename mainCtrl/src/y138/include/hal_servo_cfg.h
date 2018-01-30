#ifndef __HAL_SERVO_CFG_H_
#define __HAL_SERVO_CFG_H_


//define cfgSERVO_REG_ALL_PERMITE         //����ָ��ȫ������



#define cfgSERVO_REQ_HEAD_1          (0xff)   // ��������1
#define cfgSERVO_REQ_HEAD_2          (0xff)   // ��������2


#define cfgSERVO_ACK_HEAD_1          (0xff)   // ��Ӧ����ͷ
#define cfgSERVO_ACK_HEAD_2          (0xf5)   // ��Ӧ����ͷ2


#define cfgSERVO_VOL_MAX             (0x08)   // ��ѹ������8V
#define cfgSERVO_VOL_MIN             (0x04)   // ��ѹ����
#define cfgSERVO_TEMP_MAX            (0x50)   // ����¶�����


#define cfgSERVO_REQ_CMD_PING        (0x01)   // ��ѯ����״̬
#define cfgSERVO_REQ_CMD_READ        (0x02)   // ��ѯ���Ʊ��е�����
#define cfgSERVO_REQ_CMD_WRITE       (0x03)   // �����Ʊ���д������
#define cfgSERVO_REQ_CMD_REG_WRITE   (0x04)   // д�Ĵ���
#define cfgSERVO_REQ_CMD_ACTION      (0x05)   // ��REGд������ACTION����
#define cfgSERVO_REQ_CMD_RESET       (0x06)   // ��λ
#define cfgSERVO_REQ_CMD_SYNC_WRITE  (0x07)   // ͬ��д��



/**********************************
 *      �Ĵ�����ַ
 *********************************/
 
 
#ifdef cfgSERVO_REG_ALL_PERMITE             // �������õļĴ���
     #define REG_FAC_YEAR          (0x00)   // ����   ��
     #define REG_FAC_MONTH         (0x01)   // ����   ��
     #define REG_FAC_DAY           (0x02)   // ����   ��
     #define REG_VER_H             (0x03)   // ����汾��(H)
     #define REG_VER_L             (0x04)   // ����汾��(L)
     #define REG_BAUDRATE          (0x06)   // ����������
     #define REG_NPOWER_H          (0x07)   // ��������H
     #define REG_NPOWER_L          (0x08)   // ��������L
     #define REG_TEMP_MAX          (0x0d)   // ����¶�����(0x50)
     #define REG_VOL_MAX           (0x0e)   // ����ѹ����(0x08)
     #define REG_VOL_MIN           (0x0f)   // ��ѹ����
     #define REG_UNLOAD            (0x13)   // ж������
     #define REG_LED0_ONOFF        (0x16)   // LED0���ƿ���
     #define REG_LED1_ONOFF        (0x17)   // LED1���ƿ���
     #define REG_LED2_ONOFF        (0x18)   // LED2���ƿ���
     #define REG_LED0_ON_TIME      (0x19)   // LED0����ʱ��
     #define REG_LED1_ON_TIME      (0x1a)   // LED1����ʱ��
     #define REG_LED2_ON_TIME      (0x1b)   // LED2����ʱ��
     #define REG_MODE_ONOFF        (0x1c)   // �������л�ģʽ
     #define REG_MOTOR_DIR         (0x1d)   // ���ģʽ�����л�
     #define REG_LED               (0x29)   // LED
     #define REG_CURRENT_H         (0x2e)   // ��ǰ����H
     #define REG_CURRENT_L         (0x2f)   // ��ǰ����L
     #define REG_LOCK_FLG          (0x30)   // LOCK��־
     #define REG_CURRENT_LOAD_H    (0x3c)   // ��ǰ����H
     #define REG_CURRENT_LOAD_L    (0x3d)   // ��ǰ����L
     #define REG_CURRENT_VOL       (0x3e)   // ��ǰ��ѹ
     #define REG_CURRENT_TEMP      (0x3f)   // ��ǰ�¶�
     #define REG_SPEED_ADJ_H       (0x41)   // �ٶȵ���H
     #define REG_SPEED_ADJ_L       (0x42)   // �ٶȵ���L
#endif

#define REG_ID                (0x05)   // �豸ID��
#define REG_ANGLE_MIN_H       (0x09)   // ��С�Ƕ�����H
#define REG_ANGLE_MIN_L       (0x0a)   // ��С�Ƕ�����L
#define REG_ANGLE_MAX_H       (0x0b)   // ���Ƕ�����H
#define REG_ANGLE_MAX_L       (0x0c)   // ���Ƕ�����L
#define REG_TORQUE_MAX_H      (0x10)   // ���Ť��H
#define REG_TORQUE_MAX_L      (0x11)   // ���Ť��L
#define REG_SPEED             (0x12)   // ��ǰ�ٶ�
#define REG_MID_POS_H         (0x14)   // ��λ����H
#define REG_MID_POS_L         (0x15)   // ��λ����L
#define REG_TORQUE_ONOFF      (0x28)   // Ť�ؿ���
#define REG_TARGET_POS_H      (0x2a)   // Ŀ��λ��H
#define REG_TARGET_POS_L      (0x2b)   // Ŀ��λ��L
#define REG_RUNTIME_H         (0x2c)   // ����ʱ��H
#define REG_RUNTIME_L         (0x2d)   // ����ʱ��L
#define REG_CURRENT_POS_H     (0x38)   // ��ǰλ��H
#define REG_CURRENT_POS_L     (0x39)   // ��ǰλ��L
#define REG_SPEED_H           (0x3a)   // �ٶ�H
#define REG_SPEED_L           (0x3b)   // �ٶ�L
#define REG_WRITE_FLG         (0x40)   // д��־

#endif

