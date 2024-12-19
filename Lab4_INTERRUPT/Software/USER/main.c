//#include <vga_api.h>
//#include <uart.h>
//#include <picture.h>
//#include <interrupt.h>
//#include <timer.h>

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
//	VGA_TEXT_REG = counter;
//	VGA_TEXT_REG = ' ';
//	counter++;
//	if (counter==0x3A)
//		TIMER_CONTROL_REG=0;
//	
//	
//	//Timer Intertupt
//	TIMER_CLEAR_REG=1;
//}


//int main()
//{
//	volatile int i;
//	volatile int j;
//	volatile int y=0;
//	volatile int color;
//	volatile char letter;
//	volatile char last_letter;

//	TIMER_LOAD_REG=25000000;
//	TIMER_CONTROL_REG=0x03;
//	
////	Timer_SetLoad(25000000);
////	Timer_Enable(1);
////	Timer_SetMode(1);
//	
////	INTERRUPT_INIT(TIMER_IRQ, 0x00, 1);
////	INTERRUPT_INIT(UART_IRQ, 0x40, 1);

//	NVIC_INT_PRIORITY0 = 0x00004000;	
//	NVIC_INT_ENABLE = 0x00000003;		
//	
//	while(1)
//	{

//	}
//}

//------------------------------------------------------------------------------------------------------
// Program SoC using C
// 1)Input from 8-bit switch and output to LEDs
// 2)Input characters from keyboard (UART) and output to the terminal
// 3)A counter is incremented from 1 to 10, and displayed on the VGA monitor
//------------------------------------------------------------------------------------------------------

#define AHB_VGA_BASE				0x50000000
#define AHB_UART_BASE				0x51000000
#define AHB_TIMER_BASE			0x52000000
#define AHB_GPIO_BASE				0x53000000
#define NVIC_INT_ENABLE			0xE000E100
#define NVIC_INT_PRIORITY0	0xE000E400

volatile static int counter=0x31;

void UART_ISR()
{
	char c;
	c=*(unsigned char*) AHB_UART_BASE;		//read a character from UART
	*(unsigned char*) AHB_UART_BASE = c;	//write the character to UART
}

void Timer_ISR()
{
	*(unsigned int*) AHB_VGA_BASE = counter;		//print the counter value to VGA
	*(unsigned int*) AHB_VGA_BASE = ' ';				//print space

	counter++;
	if (counter==0x3A)
		*(unsigned int*) (AHB_TIMER_BASE+8) = 0;	//Stop timer if counter reaches 9
	*(unsigned int*) (AHB_TIMER_BASE+0x0C) = 1;	//Clear timer interrupt request
	}

//////////////////////////////////////////////////////////////////
// Main Function
//////////////////////////////////////////////////////////////////

int main(void) {
	
	int i;
	*(unsigned int*) AHB_TIMER_BASE = 50000000;			  //Timer load register: =<clock frequency>
	*(unsigned int*) (AHB_TIMER_BASE+8) = 0x03;				//Timer 4-bits control register: [0]: timer enable, [1] mode (free-run or reload) [2]: prescaler

	*(unsigned int*) NVIC_INT_PRIORITY0 = 0x00004000;	//Priority: IRQ0(Timer): 0x00, IRQ1(UART): 0x40
  *(unsigned int*) NVIC_INT_ENABLE = 0x00000003;		//Enable interrupts for UART and timer
	
	while(1){
		*(unsigned int*) (AHB_GPIO_BASE+4) = 0x00;		//GPIO read mode
		i=*(unsigned int*) AHB_GPIO_BASE;							//Read switch
		*(unsigned int*) (AHB_GPIO_BASE+4) = 0x01;		//GPIO write mode
		*(unsigned int*) AHB_GPIO_BASE = i;				//Write to the LEDs
	}
}



