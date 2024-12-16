
#include <uart.h>
#include "stdio.h"
#include "stdint.h"

void UART_INIT(volatile int BAUDRATE, volatile int PARITY)
{
    volatile int config_value = 0;
    // ���ò�����
    switch (BAUDRATE) 
		{
        case 19200:
            config_value |= 0;break;  // ������19200��Ӧbit[1:0] = 0b00
        case 57600:
            config_value |= 1;break;  // ������57600��Ӧbit[1:0] = 0b01
        case 115200:
            config_value |= 2;break;  // ������115200��Ӧbit[1:0] = 0b10
        case 230400:
            config_value |= 3;break;  // ������230400��Ӧbit[1:0] = 0b11 
        default:
            config_value |= 0;break;  // Ĭ�ϲ�����Ϊ19200
    }
    // ������żУ��
    if (PARITY) 
        config_value |= (1 << 2);  // ʹ����żУ�飬��Ӧbit[2] = 1
    else
        config_value &= ~(1 << 2);  // ��ֹ��żУ�飬��Ӧbit[2] = 0
    // д����ƼĴ���
    UART_CONTROL_REG = config_value;
}

//void uart_echo() 
//{
//    while (1) {
//        // 1. ��ȡ״̬�Ĵ���
//        uint32_t status = UART_STATUS_REG;

//        // 2. ������FIFO�Ƿ�Ϊ��
//        if (!(status & RX_FIFO_EMPTY)) {  // ����FIFO��Ϊ��
//            // 3. ��ȡ��������
//            uint32_t received_data = UART_DATA_REG;

//            // 4. ��鷢��FIFO�Ƿ�����
//            while (status & TX_FIFO_FULL) {
//                status = UART_STATUS_REG;  // �ȴ�ֱ������FIFO�п���
//            }

//            // 5. ����������д�뷢��FIFO
//            UART_DATA_REG = received_data;
//        }
//    }
//}


//ȫ�ֱ���
volatile uint32_t last_received = 0;  // ������һ�����յ����ַ�
volatile uint32_t last_sent = 0;      // ������һ�����͵��ַ�

void uart_echo() {
    while (1) {
        // 1. ��ȡ״̬�Ĵ���
        uint32_t status = UART_STATUS_REG;
        // 2. ������FIFO�Ƿ�Ϊ��
        if (!(status & RX_FIFO_EMPTY)) {  // ����FIFO��Ϊ��
            // 3. ��ȡ��������
            uint32_t received_data = UART_DATA_REG;
            // 4. ��鷢��FIFO�Ƿ�����
            while (status & TX_FIFO_FULL) {
                status = UART_STATUS_REG;  // �ȴ�ֱ������FIFO�п���
            }
            // 5. ��������
            if (received_data == 0x0A || received_data == 0x0D) {
                if (last_received == 0x0A && received_data == 0x0D) {
                    // �����յ�0x0A 0x0D, ����Ҫ����0x0D 0x0A
                    if (last_sent != 0x0A) {
                        UART_DATA_REG = 0x0D;  // ֻ����0x0D
                        while (status & TX_FIFO_FULL) { status = UART_STATUS_REG; }
                    }
                    UART_DATA_REG = 0x0A;  // Ȼ�����0x0A
                } else if (last_received == 0x0D && received_data == 0x0A) {
                    // �����յ�0x0D 0x0A, ����Ҫ����0x0D 0x0A
                    if (last_sent != 0x0A) {
                        UART_DATA_REG = 0x0D;  // ֻ����0x0D
                        while (status & TX_FIFO_FULL) { status = UART_STATUS_REG; }
                    }
                    UART_DATA_REG = 0x0A;  // Ȼ�����0x0A
                } else {
                    // ����ǵ�����0x0A��0x0D, ����0x0D 0x0A
                    if (last_sent != 0x0D) {
                        UART_DATA_REG = 0x0D;  // ����0x0D
                        while (status & TX_FIFO_FULL) { status = UART_STATUS_REG; }
                    }
                    UART_DATA_REG = 0x0A;  // Ȼ�����0x0A
                }
            } else {  // �����ַ�ֱ�ӻ���
                UART_DATA_REG = received_data;
            }
            // 6. ����ȫ�ֱ���
            last_received = received_data;
            last_sent = (received_data == 0x0A || received_data == 0x0D) ? 0x0A : received_data;
        }
    }
}
