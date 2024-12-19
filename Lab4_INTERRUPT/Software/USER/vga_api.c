
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

	PIXEL_ADDRESS = (volatile int*)(VGA_IMAGE_REG + (y << 2) + (x << 11)); // �޸�Ϊ <<11 �Ա����������		
			
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
        vga_point(x1, y1, color);  // ���Ƶ�

        if (x1 == x2 && y1 == y2) {
            break;  // �߶λ������
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
    // ȷ��x1, y1�����Ͻǣ�x2, y2�����½�
    if (x1 > x2) {
        int temp = x1; x1 = x2; x2 = temp;
    }
    if (y1 > y2) {
        int temp = y1; y1 = y2; y2 = temp;
    }

    // �������ε�������
    vga_draw_line(x1, y1, x2, y1, border_color);  // �ϱ�
    vga_draw_line(x1, y2, x2, y2, border_color);  // �±�
    vga_draw_line(x1, y1, x1, y2, border_color);  // ���
    vga_draw_line(x2, y1, x2, y2, border_color);  // �ұ�

    // �Ƿ����
    if (fill) {
        for (int y = y1 + 1; y < y2; y++) {  // �ܿ��ϡ��±߽�
            for (int x = x1 + 1; x < x2; x++) {  // �ܿ����ұ߽�
                vga_point(x, y, fill_color);  // ����ڲ�
            }
        }
    }
}

void vga_draw_image(volatile int x0, volatile int y0, volatile int width, volatile int height, const unsigned char* image_data) 
{
    // ����ͼƬ��ÿһ������
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // ���㵱ǰ�����������е�λ��
            int index = y * width + x;
            
            // �������л�ȡ��ǰ���ص���ɫ
            unsigned char color = image_data[index];
            
            // ��ָ��λ�û��Ƹ�����
            vga_point(x0 + x, y0 + y, color);
        }
    }
}



void vga_show_char(volatile int x, volatile int y, char ch) 
{
    // ��x��y����ת����VGA_CUR_REG��ֵ
    volatile unsigned int address = (y << 7) | x;
    
    // ����VGA�ַ���ַ
    VGA_CUR_REG = address;
    
    // ��ָ��λ��д���ַ�
    VGA_TEXT_REG = ch;
}

void vga_show_str(volatile int x, volatile int y, const char* str) 
{
    volatile int current_x = x;
    volatile int current_y = y;

    while (*str) {
        // �����ַ���ַ
        unsigned int address = (current_y << 7) | current_x;
        VGA_CUR_REG = address;      // �����ַ���ַ
        VGA_TEXT_REG = *str++;      // д���ַ����Ƶ���һ���ַ�

        // ��������
        current_x++;
        if (current_x >= (r_text_width/8)) {  // ����ĩʱ����
            current_x = 0;
            current_y++;
        }
    }
}

