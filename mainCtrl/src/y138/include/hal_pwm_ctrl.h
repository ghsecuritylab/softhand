#ifndef __HAL_PWM_CTRL_H__
#define __HAL_PWM_CTRL_H__


#include "gd32f10x.h"
#include "public.h"


#define cfgSERVO_MAX_WAIT          (50)   // ��ȴ�ʱ��
#define cfgSERVO_NOTIFY_TIME       (10)   // ÿ10ms����һ������  

#define cfgSERVO_PWM_LR_HMAX       (2500)
#define cfgSERVO_PWM_LR_HMIN       (500)
#define cfgSERVO_ANGLE_LR_MAX      (180)
#define cfgSERVO_PWM_LR_SMAX       (2500)
#define cfgSERVO_PWM_LR_SMIN       (500)
#define cfgSERVO_PWM_LR_DEF        (1500)
#define cfgSERVO_PWM_LR_STEP       (4)    //ÿ4us��һ��


#define cfgSERVO_PWM_UD_HMAX       (2500)    // ��� 
#define cfgSERVO_PWM_UD_DEF        (1500)    // Ĭ�ϵ�PWMֵ
#define cfgSERVO_PWM_UD_SMAX       (2500)
#define cfgSERVO_PWM_UD_SMIN       (500)
#define cfgSERVO_PWM_UD_HMIN       (500)
#define cfgSERVO_PWM_UD_STEP       (4)
#define cfgSERVO_ANGLE_UD_MAX      (180)


#define cfgSERVO_PWM_EX_HMAX       (2500)    // ��� 
#define cfgSERVO_PWM_EX_DEF        (1500)    // Ĭ�ϵ�PWMֵ
#define cfgSERVO_PWM_EX_SMAX       (2500)
#define cfgSERVO_PWM_EX_SMIN       (500)
#define cfgSERVO_PWM_EX_HMIN       (500)
#define cfgSERVO_PWM_EX_STEP       (4)
#define cfgSERVO_ANGLE_EX_MAX      (180)

typedef enum SERVO_PWM_IDX_ENUM{
    SERVO_ID_LR,
    SERVO_ID_UD,
    SERVO_ID_EX,
}ServoPwmIdx_e;

/****************************
 *        ���Ʒ�ʽ
 ****************************/
typedef enum SERVO_CTRL_MODE{
   SERVO_CTRL_STOP=0x00,
   SERVO_CTRL_WITH_TIME,     /***���Ʋ�����ʱ��***/
   SERVO_CTRL_WITH_SPEED,         /***���Ʋ������ٶ�***/
   SERVO_CTRL_RESET,         /*******��λ********/
}ServoCtrlMode_e;


typedef enum SERVO_CTRL_STATE{
    SERVO_STATE_IDLE,
    SERVO_STATE_START,
    SERVO_STATE_RUN,
    SERVO_STATE_STOP,
}ServoState_e;


typedef struct SERVO_PWM_DEF_STRUCT{
    uint16_t defPwm;     // Ĭ�ϵ�PWMֵ
    uint16_t maxHPwm;     // Ӳ����������PWMֵ
    uint16_t minHPwm;     // Ӳ��������СPWM
    uint16_t maxSPwm;     // ����������PWM
    uint16_t minSPwm;     // ���������СPWM
    uint16_t maxWait;     // ÿһ����ȴ�ʱ��
    uint16_t step;        // ÿһ���ߵ�Step����
    uint32_t periph;      // �ӿ�
    uint16_t channel;     // ͨ����
    uint16_t maxHAngle;
    float   angle;
}ServoDef_t;


typedef struct SERVO_PWM_PARAM_STRUCT{
    uint16_t nTotoal;     // ��Ҫ���ߵ��ܲ���
    uint16_t nStep;       // ��ǰ�ߵĲ���
    uint16_t currentStep; //
    uint16_t currentPwm;
    uint16_t targetPwm;   // Ŀ�� PWMֵ  //ֻ�е���Ҫ�ܵ�1500��ʱ����Ҫ�õ�
    uint16_t waitTime;    // �ȴ�ʱ��    
    uint16_t time;        // ʱ�����
    uint8_t  mode;        // ����ģʽ
    uint8_t bRecyle;      // �Ƿ����ѭ�� 
    uint8_t direction;
}ServoPwmCtrl_t;

typedef struct SERVO_ANGLE_PARAM_STRUCT{
   uint16_t offset;
   uint8_t direction;
   uint8_t bchange;  //�и���
   uint16_t current;
   uint16_t target;
}ServoAngleCtrl_t;



typedef struct SERVO_PWM_CTRL_STRUCT{
    ServoAngleCtrl_t angle;
    ServoPwmCtrl_t pwm;    // ��������
    ServoDef_t defParam;         // Ĭ�ϲ��� 
    ServoState_e state;       // ����״̬
}ServoCtrlTypedef;


void hal_pwm_init(void);
void servo_writeCtrl(int idx,RKPwmCtrl_t rkCmd);


#endif


