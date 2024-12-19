
#include <vga_api.h>
#include "math.h"
#include "stdio.h"
#include "stdlib.h"

volatile int* PIXEL_ADDRESS;

const int X_MIN=0;
const int Y_MIN=0;
const int X_MAX=99;
const int Y_MAX=119;
const double M_PI=3.14159;
volatile int r_text_width=0;

void VGA_INIT(volatile int text_width, volatile unsigned char text_color, volatile int image_zoom)
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

void vga_point(volatile int x ,volatile int y ,unsigned char color)
{

	PIXEL_ADDRESS = (volatile int*)(VGA_IMAGE_REG + (y << 2) + (x << 11)); // 修改为 <<11 以避免隔行问题		
			
	*PIXEL_ADDRESS = color ;
}

void vga_draw_line(volatile int x1, volatile int y1, volatile int x2, volatile int y2, unsigned char color) 
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    
    int err = dx - dy;

    while (1) {
        vga_point(x1, y1, color);  // 绘制点

        if (x1 == x2 && y1 == y2) {
            break;  // 线段绘制完成
        }

        int e2 = err * 2;
        
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void vga_draw_rectangle(volatile int x1, volatile int y1, volatile int x2, volatile int y2, unsigned char border_color, int fill, unsigned char fill_color)
{
    // 确保x1, y1是左上角，x2, y2是右下角
    if (x1 > x2) {
        int temp = x1; x1 = x2; x2 = temp;
    }
    if (y1 > y2) {
        int temp = y1; y1 = y2; y2 = temp;
    }

    // 画出矩形的四条边
    vga_draw_line(x1, y1, x2, y1, border_color);  // 上边
    vga_draw_line(x1, y2, x2, y2, border_color);  // 下边
    vga_draw_line(x1, y1, x1, y2, border_color);  // 左边
    vga_draw_line(x2, y1, x2, y2, border_color);  // 右边

    // 是否填充
    if (fill) {
        for (int y = y1 + 1; y < y2; y++) {  // 避开上、下边界
            for (int x = x1 + 1; x < x2; x++) {  // 避开左、右边界
                vga_point(x, y, fill_color);  // 填充内部
            }
        }
    }
}

void vga_draw_image(volatile int x0, volatile int y0, volatile int width, volatile int height, const unsigned char* image_data) 
{
    // 遍历图片的每一个像素
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // 计算当前像素在数组中的位置
            int index = y * width + x;
            
            // 从数组中获取当前像素的颜色
            unsigned char color = image_data[index];
            
            // 在指定位置绘制该像素
            vga_point(x0 + x, y0 + y, color);
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

