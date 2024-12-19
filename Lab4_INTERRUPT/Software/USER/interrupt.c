#include <interrupt.h>
#include <vga_api.h>
#include <uart.h>
#include <timer.h>

void INTERRUPT_INIT(unsigned int irq_num, unsigned int priority, unsigned int enable) 
{
    // �����ж����ȼ��Ĵ���
    volatile unsigned int* priority_register = (unsigned int*)NVIC_INT_PRIORITY0;

    // ÿ���ж�ռ�� 8 λ����Ҫƫ�� 8 * irq_num λ
    unsigned int shift = irq_num * 8;
    unsigned int priority_mask = 0xFF << shift;          // �������ȼ�����
    *priority_register &= ~priority_mask;               // ���ԭ���ȼ�
    *priority_register |= (priority & 0xFF) << shift;   // �����µ����ȼ�

    // �����ж�ʹ�ܼĴ���
    volatile unsigned int* enable_register = (unsigned int*)NVIC_INT_ENABLE;
    if (enable) {
        *enable_register |= (1 << irq_num);  // �����ж�
    } else {
        *enable_register &= ~(1 << irq_num); // �����ж�
    }
}

//void UART_ISR()
//{
//	//UART Interrupt
//	 uart_echo();
//	//always return input
//	//UART Interrupt
//}

//volatile static char counter=0x31;
//volatile static int x=0;

//void Timer_ISR()
//{
//	//Timer Intertupt
//	x++;
//	vga_show_char(x,0,counter);
//	x++;
//	vga_show_char(x,0,' ');
//	counter++;
//	if (counter==0x3A)
//		TIMER_CONTROL_REG=0;
//	
//	
//	//Timer Intertupt
//	Timer_ClearInterrupt();
//}
