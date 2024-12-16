#include <vga_api.h>
#include <uart.h>
#include <picture.h>

volatile int* PIXEL_ADDRESS;



int main()
	{
	volatile int i;
	volatile int j;
	volatile int y=0;
	volatile int color;
	volatile char letter;
	volatile char last_letter;
		
	VGA_INIT(160,0xFF,2);
		
	UART_INIT(115200,0);
		while(1)
		{
			uart_echo() ;
		}
	
}
