#include "timer.h"

// ���ö�ʱ������ֵ
void Timer_SetLoad(unsigned int value) 
{
    TIMER_LOAD_REG = value;
}

// ��ȡ��ʱ����ǰֵ
unsigned int Timer_GetCurrent(void) 
{
    return TIMER_CURRENT_REG;
}

// ���û���ö�ʱ��
void Timer_Enable(int enable) 
{
    if (enable) {
        TIMER_CONTROL_REG |= TIMER_ENABLE_BIT;  // ��������λ
    } else {
        TIMER_CONTROL_REG &= ~TIMER_ENABLE_BIT; // �������λ
    }
}

// ���ö�ʱ��Ϊ�Զ�����ģʽ
void Timer_SetMode(int mode)
{
	if (mode==1) { //If mode=1 timer is periodic counter;
			 TIMER_CONTROL_REG |= TIMER_MODE_RELOAD_BIT;
	} else { //If mode=0 timer is free-running counter
		   TIMER_CONTROL_REG &= ~TIMER_MODE_RELOAD_BIT;
	}

}

// �����ʱ���жϱ�־
void Timer_ClearInterrupt(void)
{
    TIMER_CLEAR_REG = 1;
}
