#include <vga_api.h>
#include <picture.h>
#include <stdio.h>
#include <stdlib.h> // �������������
#include <time.h>   // �������������

volatile int* PIXEL_ADDRESS;
volatile int t;
void draw_ball(int x, int y, int radius, int color) {
    for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++) {
            if (i * i + j * j <= radius * radius) { // Բ���ж�
                vga_point(x + i, y + j, color);
            }
        }
    }
}

void clear_ball(int x, int y, int radius, int background_color) {
    for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++) {
            if (i * i + j * j <= radius * radius) { // Բ���ж�
                vga_point(x + i, y + j, background_color);
            }
        }
    }
}

void simulate_ball_bounce(int start_x, int start_y, int ball_color, int background_color) {
    int x = start_x;
    int y = start_y;
    int previous_x = -1;
    int previous_y = -1;
    int dx = (rand() % 3) - 1; // ���ˮƽ�ٶȣ�-1��0��1
    int dy = 1; // ��ʼ��ֱ�ٶ�
    int radius = 5; // ����С��İ뾶

    srand(time(NULL)); // �������������

    // ģ��С�򷴵�
    while (1) {
        // ���֮ǰ��С��λ��
        if (previous_x >= 0 && previous_y >= 0) {
            clear_ball(previous_x, previous_y, radius, background_color);
        }
        
        // ���Ƶ�ǰ��С��λ��
        draw_ball(x, y, radius, ball_color);
        
        // ��ʱ��ģ����Ȼ�ƶ�Ч��
        for(t=0;t<=0x8FFF;t++);

        // ����λ��
        previous_x = x;
        previous_y = y;
        x += dx;
        y += dy;

        // ���߽�����
        if (x - radius <= 5 || x + radius >= 155) { // �������ұ߽�ʱ��תˮƽ�ٶ�
            dx = -dx;
        }
        if (y + radius >= 119) { // �����ײ�ʱ��ת��ֱ�ٶ�
            dy = -(rand() % 3 + 1); // ��������ٶ�
						dx = -(rand() % 3 + 1); // ��������ٶ�
        }
        if (y - radius <= 0) { // ��������ʱ��ת��ֱ�ٶ�
            dy = 1;
        }
    }
}

int main()
	{
	volatile int i;
	volatile int j;
	volatile int x=0;
	volatile int y=0;
	volatile int color=0;
		
	VGA_INIT(0,0xFFF,2);
		
	vga_show_str(0,0,"35320212200396");
  vga_show_str(0,1,"Huang Tengxi");
	
	//vga_point(0,0,0xFFF);
//	vga_point(0,119,WHITE);
//	vga_point(159,0,WHITE);
//	vga_point(159,119,WHITE);
		
		 simulate_ball_bounce(80, 0, 0xFFF, 0x000); // ��ɫС�򣬺�ɫ����
		
		
//    for (color = 0; color < 4096; color++) {
//        // ��ʾ��ɫ����Ļ�ϵ�λ��
//        vga_point(x, y, color);

//        // ����x���꣬ÿ������160�����غ��ƶ�����һ��
//        x++;
//        if (x >= 63) {
//            x = 0;
//            y++;
//        }

//        // ��y������ʾ����ʱֹͣ
//        if (y >= 120) {
//            break;
//        }
//    }
		
		
//	vga_draw_rectangle(1,1,3,3,RED,1,RED);
//	vga_draw_rectangle(7,7,9,9,GREEN,1,GREEN);	
//	vga_draw_rectangle(20,20,22,22,BLUE,1,BLUE);
//	vga_draw_image(0,0,160,120,gImage_pic);

		while(1)
		{
		
		}
	
}
