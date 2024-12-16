
#include <uart.h>
#include "stdio.h"
#include "stdint.h"

void UART_INIT(volatile int BAUDRATE, volatile int PARITY)
{
    volatile int config_value = 0;
    // 设置波特率
    switch (BAUDRATE) 
		{
        case 19200:
            config_value |= 0;break;  // 波特率19200对应bit[1:0] = 0b00
        case 57600:
            config_value |= 1;break;  // 波特率57600对应bit[1:0] = 0b01
        case 115200:
            config_value |= 2;break;  // 波特率115200对应bit[1:0] = 0b10
        case 230400:
            config_value |= 3;break;  // 波特率230400对应bit[1:0] = 0b11 
        default:
            config_value |= 0;break;  // 默认波特率为19200
    }
    // 设置奇偶校验
    if (PARITY) 
        config_value |= (1 << 2);  // 使能奇偶校验，对应bit[2] = 1
    else
        config_value &= ~(1 << 2);  // 禁止奇偶校验，对应bit[2] = 0
    // 写入控制寄存器
    UART_CONTROL_REG = config_value;
}

//void uart_echo() 
//{
//    while (1) {
//        // 1. 读取状态寄存器
//        uint32_t status = UART_STATUS_REG;

//        // 2. 检查接收FIFO是否为空
//        if (!(status & RX_FIFO_EMPTY)) {  // 接收FIFO不为空
//            // 3. 读取接收数据
//            uint32_t received_data = UART_DATA_REG;

//            // 4. 检查发送FIFO是否已满
//            while (status & TX_FIFO_FULL) {
//                status = UART_STATUS_REG;  // 等待直到发送FIFO有空闲
//            }

//            // 5. 将接收数据写入发送FIFO
//            UART_DATA_REG = received_data;
//        }
//    }
//}


//全局变量
volatile uint32_t last_received = 0;  // 保存上一个接收到的字符
volatile uint32_t last_sent = 0;      // 保存上一个回送的字符

void uart_echo() {
    while (1) {
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
}
