#include "hal_timer_ctrl.h"

TimerCtrlTypedef timer[cfgMaxTimerNum];//��ʱ��
static void rtos_timer_init(void);
static void gd_timer_init(void);
/**************************************
 *              ͨ��ʱ��Ƭ���Ƶ�
 *************************************/
void hal_timer_init(void){
    rtos_timer_init();
   // gd_timer_init();
}

static void rtos_timer_init(void){
    strcpy(timer[0].name,cfgTimerNameNotify);
    timer[0].id=(INT32U)TIMER_ID_NOTIFY;  //���ڸ��²������״̬
   
    strcpy(timer[1].name,cfgTimerNameSystem);
    timer[1].id=(INT32U)TIMER_ID_SYSTEM_STICK;  //δ�õ���

    strcpy(timer[2].name,cfgTimerNameNotify);
    timer[2].id=(INT32U)TIMER_ID_NOTIFY+2;  //δ�õ���
    
    strcpy(timer[3].name,cfgTimerNameNotify);
    timer[3].id=(INT32U)TIMER_ID_NOTIFY+3;  //δ�õ���
    
    strcpy(timer[4].name,cfgTimerNameNotify);
    timer[4].id=(INT32U)TIMER_ID_NOTIFY+4;  //δ�õ���
    
    timer[0].timer=NULL;
    timer[1].timer=NULL;
    timer[2].timer=NULL;
    timer[3].timer=NULL;
    timer[4].timer=NULL;
}

/*******************************
 *        ��ʼ������ʱ��
 ******************************/
bool rtos_timer_start(INT32U id,INT32U delay,TimerCallbackFunction_t callback){
    if(id>cfgMaxTimerNum){
      return TRUE;
    }
    timer[id].timer=xTimerCreate(timer[id].name,delay,pdTRUE,(void*)timer[id].id,callback);
    if(timer[id].timer==NULL){
    return FALSE;
    }else{
       if(xTimerStart(timer[id].timer,100)!=pdPASS){
        return TRUE;
       }
    }
   return TRUE;
}

void rtos_timer_stop(INT32U id){
   if(id>cfgMaxTimerNum || timer[id].timer==NULL){
     return;
   }
   xTimerStop(timer[id].timer,100);
   return;
}


void gd_timer_init(void){
// timer_parameter_struct initpara;
// rcu_periph_clock_enable(RCU_TIMER4);
// timer_deinit(TIMER4);
// initpara.clockdivision=TIMER_CKDIV_DIV1;
// initpara.counterdirection= TIMER_COUNTER_UP;
// initpara.prescaler=107;
// initpara.period=5400;
// timer_init(TIMER4,&initpara);
// timer_auto_reload_shadow_enable(TIMER4);
// nvic_irq_enable(TIMER4_IRQn,0,1);
}


void gd_timer_start(void){
    timer_enable(TIMER4);
    timer_interrupt_enable(TIMER4,TIMER_INT_UP);
    
}

void gd_timer_stop(void){
    timer_disable(TIMER4);
}

void gd_timer_setPlus(int plus){
    
}


void TIMER4_IRQHandler(void){
    if(timer_interrupt_flag_get(TIMER4,TIMER_INT_FLAG_UP)==SET){
       timer_interrupt_flag_clear(TIMER4,TIMER_INT_FLAG_UP);
    }  
}









