#include "hal_pwm_ctrl.h"

ServoCtrlTypedef servo[3];  //���������
static void servo_pwm_def(int idx);

static uint8_t timeTable[16]={0};   //�ٶȵȼ�����  ���ò�ͬ��PWM�ȼ�
static void servo_pwm_init(int idx);
static void servo_timer_init(int idx);
static void servo_write_pwm(int idx,uint16_t pwm);
static void servo_power_on(void);
static void servo_power_off(void);

void hal_pwm_init(void){
     rcu_periph_clock_enable(RCU_GPIOC);
     rcu_periph_clock_enable(RCU_GPIOB);
     rcu_periph_clock_enable(RCU_TIMER2);
     gpio_init(GPIOC,GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_1);
     servo_power_on();
     servo_pwm_def(SERVO_ID_LR);    // ��ʼ��ͷ������
     servo_pwm_def(SERVO_ID_UD);    // ��ʼ��ͷ������
     servo_pwm_def(SERVO_ID_EX);    // ��ʼ��ͷ������
     servo_timer_init(SERVO_ID_EX); // ֻ��Ҫ��ʼ��һ��
     servo_pwm_init(SERVO_ID_LR);   // 
     servo_pwm_init(SERVO_ID_UD);   //
     servo_pwm_init(SERVO_ID_EX);   //
}

void servo_power_on(void){
   gpio_bit_set(GPIOC,GPIO_PIN_1);

}

void servo_power_off(void){
   gpio_bit_reset(GPIOC,GPIO_PIN_1);
}

void servo_timer_init(int idx){
     timer_parameter_struct initpara;
     rcu_periph_clock_enable(RCU_TIMER2);
     timer_deinit(TIMER2);
     initpara.clockdivision=TIMER_CKDIV_DIV1;
     initpara.counterdirection= TIMER_COUNTER_UP;
     initpara.prescaler=108-1;  //  ��Ƶ
     initpara.period=20000-1;     //  20ms ��ʱ
     timer_init(TIMER2,&initpara);
}

/****************************
 *        PWM��ʼ��
 ***************************/
void servo_pwm_init(int idx){
     timer_oc_parameter_struct ocPara;  // PWM���
     ocPara.ocidlestate=TIMER_OC_IDLE_STATE_LOW;
     ocPara.ocpolarity=TIMER_OC_POLARITY_LOW;
     ocPara.outputstate=TIMER_CCX_ENABLE;
     timer_channel_output_config(servo[idx].defParam.periph,servo[idx].defParam.channel,&ocPara);  
     timer_channel_output_mode_config(servo[idx].defParam.periph,servo[idx].defParam.channel,TIMER_OC_MODE_PWM1);
     timer_auto_reload_shadow_enable(servo[idx].defParam.periph);
     timer_enable(servo[idx].defParam.periph);
     timer_channel_output_pulse_value_config(servo[idx].defParam.periph,servo[idx].defParam.channel,servo[idx].defParam.defPwm); 
}

void servo_write_pwm(int idx,uint16_t pwm){
     timer_channel_output_pulse_value_config(servo[idx].defParam.periph,servo[idx].defParam.channel,servo[idx].defParam.defPwm); 
}

/*************************
 *    �ϵ�����PWM����
 ************************/
void servo_pwm_def(int idx){
     switch(idx){
         case SERVO_ID_LR:{
             gpio_init(GPIOB,GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_0);
             servo[idx].defParam.maxHPwm=cfgSERVO_PWM_LR_HMAX;     // Ӳ������ ��� MAX
             servo[idx].defParam.minHPwm=cfgSERVO_PWM_LR_HMIN;     // Ӳ������ ��С MIN  
             servo[idx].defParam.maxSPwm=cfgSERVO_PWM_LR_SMAX;     // ������� ��� MAX
             servo[idx].defParam.minSPwm=cfgSERVO_PWM_LR_SMIN;     // ������� ��С MIN  
             servo[idx].defParam.defPwm=cfgSERVO_PWM_LR_DEF;       // Ĭ��PWM
             servo[idx].defParam.step=cfgSERVO_PWM_LR_STEP;       // ÿһ���ߵ�����
             servo[idx].defParam.periph=TIMER2;
             servo[idx].defParam.angle=(float)cfgSERVO_ANGLE_LR_MAX/500;
             servo[idx].defParam.maxHAngle=cfgSERVO_ANGLE_LR_MAX;
             servo[idx].defParam.channel=TIMER_CH_2;
             servo[idx].pwm.currentStep=250;
         }break;
         case SERVO_ID_UD:{
             gpio_init(GPIOB,GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_1);
             servo[idx].defParam.maxHPwm=cfgSERVO_PWM_UD_HMAX;     // Ӳ������ ��� MAX
             servo[idx].defParam.minHPwm=cfgSERVO_PWM_UD_HMIN;     // Ӳ������ ��С MIN  
             servo[idx].defParam.maxSPwm=cfgSERVO_PWM_UD_SMAX;     // ������� ��� MAX
             servo[idx].defParam.minSPwm=cfgSERVO_PWM_UD_SMIN;     // ������� ��С MIN  
             servo[idx].defParam.defPwm=cfgSERVO_PWM_UD_DEF;       // Ĭ��PWM
             servo[idx].defParam.step=cfgSERVO_PWM_UD_STEP;       // ÿһ���ߵ����� 
             servo[idx].defParam.periph=TIMER2;
             servo[idx].defParam.maxHAngle=cfgSERVO_ANGLE_UD_MAX;
             servo[idx].defParam.angle=(float)cfgSERVO_ANGLE_UD_MAX/500;
             servo[idx].defParam.channel=TIMER_CH_3;
             servo[idx].pwm.currentStep=250;
         }break;
         
         case SERVO_ID_EX:{
             gpio_init(GPIOB,GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_5);
             servo[idx].defParam.maxHPwm=cfgSERVO_PWM_EX_HMAX;     // Ӳ������ ��� MAX
             servo[idx].defParam.minHPwm=cfgSERVO_PWM_EX_HMIN;     // Ӳ������ ��С MIN  
             servo[idx].defParam.maxSPwm=cfgSERVO_PWM_EX_SMAX;     // ������� ��� MAX
             servo[idx].defParam.minSPwm=cfgSERVO_PWM_EX_SMIN;     // ������� ��С MIN  
             servo[idx].defParam.defPwm=cfgSERVO_PWM_EX_DEF;       // Ĭ��PWM
             servo[idx].defParam.step=cfgSERVO_PWM_EX_STEP;        // ÿһ���ߵ����� 
             servo[idx].defParam.periph=TIMER2;
             servo[idx].defParam.maxHAngle=cfgSERVO_ANGLE_EX_MAX;
             servo[idx].defParam.angle=(float)cfgSERVO_ANGLE_EX_MAX/500;
             servo[idx].defParam.channel=TIMER_CH_1;               // ����Ҫ��Ӧ�ļ�ȥ1
             servo[idx].pwm.currentStep=250;
         }break;
         default:{
         
         }break;
     }
}

static uint16_t servo_getPwmFromAngle(uint8_t idx, uint16_t angle){
     return (uint16_t)(500+angle*((float)(servo[idx].defParam.maxHPwm-servo[idx].defParam.minHPwm)/servo->defParam.maxHAngle));//���Ƕ�ת����PWMֵ
}




static uint16_t servo_getAngleFromPwm(){



}

void servo_pwm_start(int idx){
   if( servo[idx].state!=SERVO_STATE_RUN){
       servo[idx].state=SERVO_STATE_START;
   }
}

void servo_pwm_stop(int idx){
   servo[idx].state=SERVO_STATE_STOP;
}


void servo_pwm_notifyAngle(int idx,uint16_t step){
    uint16_t angle=step*servo[idx].defParam.maxHAngle/500;
    if(angle!=servo[idx].angle.current){
       servo[idx].angle.current=angle;
       servo[idx].angle.bchange=1;   // ��������
    }
}

void servo_pwm_writeTimeParam(int idx,RKPwmCtrl_t rkCmd){  //ѭ����ʱ�����ʱ��ͽǶ��������ٶ� ѭ�����������ٶȽ��п���
    uint16_t leftPwm=0,step=0;
    if(rkCmd.param==0){// ʱ��Ϊ0
       servo_pwm_stop(idx);   
       return;
   }
   servo[idx].pwm.bRecyle=rkCmd.bRecyle;  //�Ƿ�����ѭ��
   servo[idx].pwm.direction=rkCmd.direction;
   if( servo[idx].pwm.direction==0){
       leftPwm=servo[idx].defParam.maxSPwm-servo[idx].pwm.currentPwm;
       if(leftPwm<=servo[idx].defParam.step){
         servo[idx].pwm.currentStep+=1; //�ֶ�����һ��
         servo[idx].pwm.currentPwm=servo[idx].pwm.targetPwm=servo[idx].defParam.maxSPwm;
         servo_write_pwm(idx,servo[idx].pwm.currentPwm);
         servo[idx].pwm.direction=1;
         if(!servo[idx].pwm.bRecyle){
            servo_pwm_stop(idx);              
            return;
         }
         servo_pwm_notifyAngle(idx,servo[idx].pwm.currentStep);
       }else{
         step=(servo[idx].pwm.targetPwm-servo[idx].pwm.currentPwm)/servo[idx].defParam.step;
         servo[idx].pwm.nStep=((servo[idx].pwm.targetPwm-servo[idx].pwm.currentPwm)%servo[idx].defParam.step==0)?step:step+1;
       }
   }else{
       leftPwm=servo[idx].pwm.currentPwm-servo[idx].defParam.minSPwm;
       if(leftPwm<=servo[idx].defParam.step){
         servo[idx].pwm.currentStep+=1; //�ֶ�����һ��
         servo[idx].pwm.currentPwm=servo[idx].pwm.targetPwm=servo[idx].defParam.minSPwm;
         servo_write_pwm(idx,servo[idx].pwm.currentPwm);
         servo[idx].pwm.direction=0;
         if(!servo[idx].pwm.bRecyle){
            servo_pwm_stop(idx);   
            return;
         }
       }else{
         step=(servo[idx].pwm.currentPwm-servo[idx].pwm.targetPwm)/servo[idx].defParam.step;
         servo[idx].pwm.nStep=((servo[idx].pwm.currentPwm-servo[idx].pwm.targetPwm)%servo[idx].defParam.step==0)?step:step+1; //��Ҫ�ߵ��ܲ���
       }
   }
     servo[idx].pwm.waitTime=(rkCmd.param/rkCmd.angle)*servo[idx].defParam.angle;//��Ҫ����ʱʱ��
     servo[idx].pwm.waitTime=(servo[idx].pwm.waitTime==0)?timeTable[8]:servo[idx].pwm.waitTime;
     servo_pwm_start(idx);
}

void servo_pwm_writeSpeedParam(int idx,RKPwmCtrl_t rkCmd){
   uint16_t leftPwm=0,step=0;
    // ��λ��ʱ�������ٶȽ��п���
  if(rkCmd.param==0){// ʱ��Ϊ0
       return;
   }
  servo[idx].pwm.bRecyle=rkCmd.bRecyle;  //�Ƿ�����ѭ��
  servo[idx].pwm.direction=rkCmd.direction;
 if( servo[idx].pwm.direction==0){
       leftPwm=servo[idx].defParam.maxSPwm-servo[idx].pwm.currentPwm;
       if(leftPwm<=servo[idx].defParam.step){
         servo[idx].pwm.currentStep+=1; //�ֶ�����һ��
         servo[idx].pwm.currentPwm=servo[idx].pwm.targetPwm=servo[idx].defParam.maxSPwm;
         servo_write_pwm(idx,servo[idx].pwm.currentPwm);
         servo[idx].pwm.direction=1;
         if(!servo[idx].pwm.bRecyle){
            servo_pwm_stop(idx);   
            return;
         }  
       }else{
         step=(servo[idx].pwm.targetPwm-servo[idx].pwm.currentPwm)/servo[idx].defParam.step;
         servo[idx].pwm.nStep=((servo[idx].pwm.targetPwm-servo[idx].pwm.currentPwm)%servo[idx].defParam.step==0)?step:step+1;
       }
   }else{
       leftPwm=servo[idx].pwm.currentPwm-servo[idx].defParam.minSPwm;
       if(leftPwm<=servo[idx].defParam.step){
         servo[idx].pwm.currentStep+=1; //�ֶ�����һ��
         servo[idx].pwm.currentPwm=servo[idx].pwm.targetPwm=servo[idx].defParam.minSPwm;
         servo_write_pwm(idx,servo[idx].pwm.currentPwm);
         servo[idx].pwm.direction=0;
         if(!servo[idx].pwm.bRecyle){
            servo_pwm_stop(idx);   
            return;
         }     
       }else{
         step=(servo[idx].pwm.currentPwm-servo[idx].pwm.targetPwm)/servo[idx].defParam.step;
         servo[idx].pwm.nStep=((servo[idx].pwm.currentPwm-servo[idx].pwm.targetPwm)%servo[idx].defParam.step==0)?step:step+1; //��Ҫ�ߵ��ܲ���
       }
   }   
}

void servo_pwm_writeResetParam(int idx,RKPwmCtrl_t rkCmd){
    // ��λ��ʱ�������ٶȽ��п���
    uint16_t leftPwm=0,step=0;
    servo[idx].pwm.targetPwm=1500;
    if(servo[idx].pwm.currentPwm>=1500){
       servo[idx].pwm.direction=1;
    }else{
       servo[idx].pwm.direction=0;
    }
    if(servo[idx].pwm.direction==0){
       leftPwm=1500-servo[idx].pwm.currentPwm;
       if(leftPwm<=servo[idx].defParam.step){
         servo[idx].pwm.currentStep+=1; //�ֶ�����һ��
         servo[idx].pwm.currentPwm=servo[idx].pwm.targetPwm=1500;
         servo_write_pwm(idx,servo[idx].pwm.currentPwm);
         servo[idx].pwm.direction=1;
       }else{
         step=(1500-servo[idx].pwm.currentPwm)/servo[idx].defParam.step;
         servo[idx].pwm.nStep=((1500-servo[idx].pwm.currentPwm)%servo[idx].defParam.step==0)?step:step+1;
       }
   }else{
       leftPwm=servo[idx].pwm.currentPwm-1500;
       if(leftPwm<=servo[idx].defParam.step){
         servo[idx].pwm.currentStep+=1; //�ֶ�����һ��
         servo[idx].pwm.currentPwm=servo[idx].pwm.targetPwm=1500;
         servo_write_pwm(idx,servo[idx].pwm.currentPwm);
         servo[idx].pwm.direction=0;
       }else{
         step=(servo[idx].pwm.currentPwm-1500)/servo[idx].defParam.step;
         servo[idx].pwm.nStep=((servo[idx].pwm.currentPwm-1500)%servo[idx].defParam.step==0)?step:step+1; //��Ҫ�ߵ��ܲ���
       }
   }   
   servo[idx].pwm.waitTime=timeTable[8];
}

/********************
 *    ���ٳ�ʼ��
 *******************/
void servo_initAcc(){

}

/********************
 *     ���ٳ�ʼ��
 ********************/
void servo_initDec(){

}


void servo_writeCtrl(int idx,RKPwmCtrl_t rkCmd){
     switch(rkCmd.mode){
         case SERVO_CTRL_WITH_TIME:{
           servo_pwm_writeTimeParam(idx,rkCmd);
         }break;
         
         case SERVO_CTRL_WITH_SPEED:{
           servo_pwm_writeSpeedParam(idx,rkCmd);  // 
         }break;
         
         case SERVO_CTRL_RESET:{
           servo_pwm_writeResetParam(idx,rkCmd);  // ֱ�Ӹ�λ
         }break;
         
         default:{
         
         }break;
     }
}

/**************************
 *   ���ͨ��ʱ�����
 *************************/
void servo_ctrl_withTime(int idx){
      uint16_t leftPwm=0;
     if(servo[idx].pwm.time>=servo[idx].pwm.waitTime){
        servo[idx].pwm.time=0;  //�ȴ�ʱ����0
        servo[idx].pwm.currentPwm=cfgSERVO_PWM_LR_HMIN+servo[idx].pwm.currentStep*servo[idx].defParam.step;// Ĭ��
        if(servo[idx].pwm.direction==0){
          leftPwm=servo[idx].pwm.targetPwm-servo[idx].pwm.currentPwm;
          if(leftPwm<=servo[idx].defParam.step){//������һ����ʱ��
             servo[idx].pwm.currentPwm=servo[idx].pwm.targetPwm;
             servo[idx].pwm.targetPwm=servo[idx].defParam.minSPwm;
             servo[idx].pwm.direction=1; 
          }else{
              servo_write_pwm(idx,servo[idx].pwm.currentPwm);     
              servo_pwm_stop(idx);  
              return;  
          }              
        }else{
          leftPwm=servo[idx].pwm.currentPwm-servo[idx].pwm.targetPwm;
          if(leftPwm<=servo[idx].defParam.step){//������һ����ʱ��
             servo[idx].pwm.currentPwm=servo[idx].pwm.targetPwm;
             if(servo[idx].pwm.bRecyle==1){
                servo[idx].pwm.targetPwm=servo[idx].defParam.maxSPwm;
                servo[idx].pwm.direction=0;
             }else{
                servo_write_pwm(idx,servo[idx].pwm.currentPwm);     
                servo_pwm_stop(idx);  
                return;                 
             }        
          } 
        }     
        servo_write_pwm(idx,servo[idx].pwm.currentPwm);     
     }
}

/**************************
 *    ���ͨ���ٶȿ���
 *************************/
void servo_ctrl_withSpeed(int idx){
     uint16_t leftPwm=0,currentPwm=0;
     if(servo[idx].pwm.time>=servo[idx].pwm.waitTime){
        servo[idx].pwm.time=0;  //�ȴ�ʱ����0
     }
}

void servo_runCtrl(int idx){
    switch(servo[idx].pwm.mode){
         case SERVO_CTRL_WITH_TIME:{
            servo_ctrl_withTime(idx);
         }break;
         
         case SERVO_CTRL_RESET:
         case SERVO_CTRL_WITH_SPEED:{
            servo_ctrl_withSpeed(idx);
         }break;
   
         default:{
         
         }break;
    }
}


/*************************
 *       ����״̬
 ************************/
void servo_pwm_notifyCtrl(int idx){
    switch(servo[idx].state){
        case SERVO_STATE_IDLE:{
          
        }break;
        case SERVO_STATE_START:{
           servo[idx].pwm.time=0; 
           servo[idx].state=SERVO_STATE_RUN;
        }break;
       
        case SERVO_STATE_RUN:{
             servo_runCtrl(idx);
        }break;

        case SERVO_STATE_STOP:{
            servo[idx].pwm.time=0; 
            servo[idx].state=SERVO_STATE_IDLE;
        }break;            
       
        default:{
        
        }break;
    }
}

void servo_pwm_notifyMs(int idx){
    if(servo[idx].state==SERVO_STATE_RUN){   //ÿ10msת4us
       servo[idx].pwm.time++;  
    }
}














