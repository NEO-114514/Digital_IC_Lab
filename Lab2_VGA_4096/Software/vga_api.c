#include <lib.h>
#include <vga_api.h>
#include "math.h"
#include "stdio.h"
#include "stdlib.h"

extern volatile int* PIXEL_ADDRESS;

const int X_MIN=0;
const int Y_MIN=0;
const int X_MAX=99;
const int Y_MAX=119;
const double M_PI=3.14159;
volatile int r_text_width=0;

void VGA_INIT(volatile int text_width, volatile int text_color, volatile int image_zoom)
{
	VGA_TEXT_WIDTH_REG = text_width;
	r_text_width = text_width;
	VGA_TEXT_COLOR_REG = text_color;
	VGA_IMAGE_ZOOM_REG = image_zoom;
}

void vga_image_clean(void)
{
	switch(VGA_IMAGE_ZOOM_REG)
	{
		case 0:vga_draw_rectangle(0,0,639,479,BLACK,1,BLACK);break;
		case 1:vga_draw_rectangle(0,0,319,239,BLACK,1,BLACK);break;
		case 2:vga_draw_rectangle(0,0,159,119,BLACK,1,BLACK);break;
	}
}

void vga_text_clean(void)
{
	for(volatile int i;i<=2500;i++)
		vga_show_char(i,0,' ');
}

void vga_point(volatile int x ,volatile int y , volatile int color)
{

	PIXEL_ADDRESS = (volatile int*)(VGA_IMAGE_REG + (x << 2) + (y << 10)); 
	*PIXEL_ADDRESS = color ;
}
void vga_draw_line(volatile int x0, volatile int y0, volatile int x1, volatile int y1, volatile int color) 
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        vga_point(x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

void vga_draw_rectangle(volatile int x0, volatile int y0, volatile int x1, volatile int y1, volatile int color, int fill, volatile int fill_color) 
{
    if (fill) {
        for (volatile int y = y0 + 1; y < y1; y++) { // Adjusted to keep border
            vga_draw_line(x0 + 1, y, x1 - 1, y, fill_color);
        }
    }

    // Draw top and bottom sides
    vga_draw_line(x0, y0, x1, y0, color);
    vga_draw_line(x0, y1, x1, y1, color);

    // Draw left and right sides
    vga_draw_line(x0, y0, x0, y1, color);
    vga_draw_line(x1, y0, x1, y1, color);
}

void vga_draw_image(volatile int x_start, volatile int y_start, volatile int width, volatile int height, const unsigned short *image_data) {
    for (volatile int y = 0; y < height; y++) {
        for (volatile int x = 0; x < width; x++) {
            // 获取当前像素的颜色数据
            unsigned short color = image_data[y * width + x];

            // 提取红色、绿色、蓝色通道（每个通道4位）
            int red = (color >> 8) & 0x0F;   // 提取红色（4位）
            int green = (color >> 4) & 0x0F; // 提取绿色（4位）
            int blue = color & 0x0F;         // 提取蓝色（4位）

            // 组合为4-4-4 RGB格式
            color = (red << 8) | (green << 4) | blue;

            // 使用vga_point绘制当前像素点
            vga_point(x_start + x, y_start + y, color);
        }
    }
}






void vga_show_char(volatile int x, volatile int y, char ch) 
{
    // 将x和y坐标转换成VGA_CUR_REG的值
    volatile unsigned int address = (y << 7) | x;
    
    // 设置VGA字符地址
    VGA_CUR_REG = address;
    
    // 在指定位置写入字符
    VGA_TEXT_REG = ch;
}

void vga_show_str(volatile int x, volatile int y, const char* str) 
{
    volatile int current_x = x;
    volatile int current_y = y;

    while (*str) {
        // 计算字符地址
        unsigned int address = (current_y << 7) | current_x;
        VGA_CUR_REG = address;      // 设置字符地址
        VGA_TEXT_REG = *str++;      // 写入字符并移到下一个字符

        // 更新坐标
        current_x++;
        if (current_x >= (r_text_width/8)) {  // 到行末时换行
            current_x = 0;
            current_y++;
        }
    }
}

