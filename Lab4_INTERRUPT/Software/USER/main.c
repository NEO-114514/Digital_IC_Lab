//------------------------------------------------------------------------------------------------------
// Program SoC using C
// 1)Input from 8-bit switch and output to LEDs
// 2)Input characters from keyboard (UART) and output to the terminal
// 3)A counter is incremented from 1 to 10, and displayed on the VGA monitor
//------------------------------------------------------------------------------------------------------

#include "stdint.h"

#define AHB_VGA_BASE        0x50000000
#define AHB_UART_BASE       0x51000000
#define AHB_TIMER_BASE      0x52000000
#define AHB_GPIO_BASE       0x53000000
#define NVIC_INT_ENABLE     0xE000E100
#define NVIC_INT_PRIORITY0  0xE000E400

#define UART_DATA_REG            *((volatile char*) AHB_UART_BASE)
#define UART_STATUS_REG          *((volatile unsigned int*) (AHB_UART_BASE + 0x04))
#define UART_CONTROL_REG         *((volatile unsigned int*) (AHB_UART_BASE + 0x08))
#define TIMER_LOAD_REG           *((volatile unsigned int*) AHB_TIMER_BASE)
#define TIMER_CONTROL_REG        *((volatile unsigned int*) (AHB_TIMER_BASE + 0x08))
#define TIMER_INT_CLEAR_REG      *((volatile unsigned int*) (AHB_TIMER_BASE + 0x0C))
#define VGA_DISPLAY_REG          *((volatile unsigned int*) AHB_VGA_BASE)
#define GPIO_MODE_REG            *((volatile unsigned int*) (AHB_GPIO_BASE + 0x04))
#define GPIO_DATA_REG            *((volatile unsigned int*) AHB_GPIO_BASE)
#define NVIC_INT_ENABLE_REG      *((volatile unsigned int*) NVIC_INT_ENABLE)
#define NVIC_INT_PRIORITY0_REG   *((volatile unsigned int*) NVIC_INT_PRIORITY0)
	
#define RX_FIFO_EMPTY      0x01  // Bit0: 接收FIFO是否为空
#define TX_FIFO_FULL       0x02  // Bit1: 发送FIFO是否满


void UART_ISR(void);
void Timer_ISR(void);

//////////////////////////////////////////////////////////////////
// Main Function
//////////////////////////////////////////////////////////////////

int main(void)
{
    TIMER_LOAD_REG = 25000000;                // Timer load register: =<clock frequency>
    TIMER_CONTROL_REG = 0x03;                 // Timer 4-bits control register: [0]: timer enable, [1] mode (free-run or reload) [2]: prescaler

    NVIC_INT_PRIORITY0_REG = 0x00010200;      // Priority: IRQ0(Timer): 0x00, IRQ1(UART): 0x40
    NVIC_INT_ENABLE_REG = 0x00000007;         // Enable interrupts for UART and timer


    while (1) {
	  __asm("wfi");
    }
		
}



volatile static int counter = 0x31;

void Timer_ISR()
{
	VGA_DISPLAY_REG = counter;                // Print the counter value to VGA
	VGA_DISPLAY_REG = ' ';                    // Print space

	counter++;
	if (counter == 0x3A)
			TIMER_CONTROL_REG = 0;                // Stop timer if counter reaches 9

	TIMER_INT_CLEAR_REG = 1;                  // Clear timer interrupt request
}

volatile static int i;
volatile static char output_char;
volatile static int current_state[8] = {0};
volatile static int last_state[8] = {0};
		
void GPIO_ISR()
{
    GPIO_MODE_REG = 0x00;                 // GPIO read mode
    int gpio_data = GPIO_DATA_REG;        // Read switch

    for (int bit = 0; bit < 8; bit++) {
        current_state[bit] = (gpio_data >> bit) & 0x01; // Extract each bit's state

        if (current_state[bit] != last_state[bit]) {    // Detect state change
            output_char = '0' + bit;                   // Determine switch number (0-based)
            while ((UART_STATUS_REG & 0x01) == 0);     // Wait for UART to be ready
            UART_DATA_REG = output_char;               // Output character via UART
        }

        last_state[bit] = current_state[bit];          // Update last state
    }

    GPIO_MODE_REG = 0x01;                 // GPIO write mode
    GPIO_DATA_REG = gpio_data;            // Write to the LEDs
		for( i=0 ; i<0x2F ;i++);
}

volatile uint32_t last_received = 0;  // 保存上一个接收到的字符
volatile uint32_t last_sent = 0;      // 保存上一个回送的字符

void UART_ISR()
{
	// 1. 读取状态寄存器
	uint32_t status = UART_STATUS_REG;
	// 2. 检查接收FIFO是否为空
	if (!(status & RX_FIFO_EMPTY)) {  // 接收FIFO不为空
			// 3. 读取接收数据
			uint32_t received_data = UART_DATA_REG;
			// 4. 检查发送FIFO是否已满
			while (status & TX_FIFO_FULL) {
				status = UART_STATUS_REG;  // 等待直到发送FIFO有空闲
		}
			// 5. 处理数据
			if (received_data == 0x0A || received_data == 0x0D) {
				if (last_received == 0x0A && received_data == 0x0D) {
						// 连续收到0x0A 0x0D, 不需要插入0x0D 0x0A
						if (last_sent != 0x0A) {
								UART_DATA_REG = 0x0D;  // 只回送0x0D
								while (status & TX_FIFO_FULL) { status = UART_STATUS_REG; }
						}
						UART_DATA_REG = 0x0A;  // 然后回送0x0A
				} else if (last_received == 0x0D && received_data == 0x0A) {
						// 连续收到0x0D 0x0A, 不需要插入0x0D 0x0A
						if (last_sent != 0x0A) {
								UART_DATA_REG = 0x0D;  // 只回送0x0D
								while (status & TX_FIFO_FULL) { status = UART_STATUS_REG; }
						}
						UART_DATA_REG = 0x0A;  // 然后回送0x0A
				} else {
						// 如果是单独的0x0A或0x0D, 插入0x0D 0x0A
						if (last_sent != 0x0D) {
								UART_DATA_REG = 0x0D;  // 回送0x0D
								while (status & TX_FIFO_FULL) { status = UART_STATUS_REG; }
						}
						UART_DATA_REG = 0x0A;  // 然后回送0x0A
				}
			} else {  // 其他字符直接回送
					UART_DATA_REG = received_data;
			}
			// 6. 更新全局变量
			last_received = received_data;
			last_sent = (received_data == 0x0A || received_data == 0x0D) ? 0x0A : received_data;
	}
}
