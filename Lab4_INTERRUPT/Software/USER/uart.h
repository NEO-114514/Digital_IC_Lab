#define UART_DATA_REG     		*((volatile int*)0x51000000)
#define UART_STATUS_REG     	*((volatile int*)0x51000004)
#define UART_CONTROL_REG     	*((volatile int*)0x51800004)


#define RX_FIFO_EMPTY      0x01  // Bit0: ����FIFO�Ƿ�Ϊ��
#define TX_FIFO_FULL       0x02  // Bit1: ����FIFO�Ƿ���

// ģ�⻺������С
#define BUFFER_SIZE 64

extern void UART_INIT(volatile int BAUDRATE , volatile int PARITY);
extern void uart_echo();
