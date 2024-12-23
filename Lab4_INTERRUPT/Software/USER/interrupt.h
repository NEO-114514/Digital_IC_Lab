//#define NVIC_INT_ENABLE		    *((volatile int*)0xE000E100)
//#define NVIC_INT_PRIORITY0	  *((volatile int*)0xE000E400)

//// 中断号定义
//#define TIMER_IRQ               0    // Timer 中断号
//#define UART_IRQ                1    // UART 中断号


//extern void INTERRUPT_INIT(unsigned int irq_num, unsigned int priority, unsigned int enable);
extern void UART_ISR();
extern void Timer_ISR();

