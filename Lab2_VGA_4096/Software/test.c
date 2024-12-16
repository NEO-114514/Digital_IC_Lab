#include <stdio.h>

volatile int* getPixelAddress(int x, int y) {
    // 基地址
    unsigned int baseAddress = 0x50000004;
    // x 坐标的偏移量
    unsigned int xOffset = x;
    // y 坐标的偏移量
    unsigned int yOffset = y<<9;
    // 计算最终地址
    unsigned int address = baseAddress + xOffset + yOffset;
    // 返回地址
    return (volatile int*)address;
}

int main() {
    int x, y;
    while(1)
    {
	
    printf("请输入x和y坐标：");
    scanf("%d %d", &x, &y);
    volatile int* pixelAddress = getPixelAddress(x, y);
    printf("像素地址为: 0x%X\n", (unsigned int)pixelAddress);
    
	}
    return 0;
}
