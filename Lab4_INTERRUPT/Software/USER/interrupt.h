//#define NVIC_INT_ENABLE		    *((volatile int*)0xE000E100)
//#define NVIC_INT_PRIORITY0	  *((volatile int*)0xE000E400)

//// �жϺŶ���
//#define TIMER_IRQ               0    // Timer �жϺ�
//#define UART_IRQ                1    // UART �жϺ�


//extern void INTERRUPT_INIT(unsigned int irq_num, unsigned int priority, unsigned int enable);
extern void UART_ISR();
extern void Timer_ISR();

