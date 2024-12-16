#include <stdio.h>

volatile int* getPixelAddress(int x, int y) {
    // ����ַ
    unsigned int baseAddress = 0x50000004;
    // x �����ƫ����
    unsigned int xOffset = x;
    // y �����ƫ����
    unsigned int yOffset = y<<9;
    // �������յ�ַ
    unsigned int address = baseAddress + xOffset + yOffset;
    // ���ص�ַ
    return (volatile int*)address;
}

int main() {
    int x, y;
    while(1)
    {
	
    printf("������x��y���꣺");
    scanf("%d %d", &x, &y);
    volatile int* pixelAddress = getPixelAddress(x, y);
    printf("���ص�ַΪ: 0x%X\n", (unsigned int)pixelAddress);
    
	}
    return 0;
}
