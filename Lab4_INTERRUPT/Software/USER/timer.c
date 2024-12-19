#include "timer.h"

// 设置定时器加载值
void Timer_SetLoad(unsigned int value) 
{
    TIMER_LOAD_REG = value;
}

// 获取定时器当前值
unsigned int Timer_GetCurrent(void) 
{
    return TIMER_CURRENT_REG;
}

// 启用或禁用定时器
void Timer_Enable(int enable) 
{
    if (enable) {
        TIMER_CONTROL_REG |= TIMER_ENABLE_BIT;  // 设置启用位
    } else {
        TIMER_CONTROL_REG &= ~TIMER_ENABLE_BIT; // 清除启用位
    }
}

// 设置定时器为自动重载模式
void Timer_SetMode(int mode)
{
	if (mode==1) { //If mode=1 timer is periodic counter;
			 TIMER_CONTROL_REG |= TIMER_MODE_RELOAD_BIT;
	} else { //If mode=0 timer is free-running counter
		   TIMER_CONTROL_REG &= ~TIMER_MODE_RELOAD_BIT;
	}

}

// 清除定时器中断标志
void Timer_ClearInterrupt(void)
{
    TIMER_CLEAR_REG = 1;
}
