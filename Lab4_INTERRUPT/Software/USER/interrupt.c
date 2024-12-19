#include <interrupt.h>
#include <vga_api.h>
#include <uart.h>
#include <timer.h>

void INTERRUPT_INIT(unsigned int irq_num, unsigned int priority, unsigned int enable) 
{
    // 设置中断优先级寄存器
    volatile unsigned int* priority_register = (unsigned int*)NVIC_INT_PRIORITY0;

    // 每个中断占用 8 位，需要偏移 8 * irq_num 位
    unsigned int shift = irq_num * 8;
    unsigned int priority_mask = 0xFF << shift;          // 生成优先级掩码
    *priority_register &= ~priority_mask;               // 清除原优先级
    *priority_register |= (priority & 0xFF) << shift;   // 设置新的优先级

    // 设置中断使能寄存器
    volatile unsigned int* enable_register = (unsigned int*)NVIC_INT_ENABLE;
    if (enable) {
        *enable_register |= (1 << irq_num);  // 启用中断
    } else {
        *enable_register &= ~(1 << irq_num); // 禁用中断
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
