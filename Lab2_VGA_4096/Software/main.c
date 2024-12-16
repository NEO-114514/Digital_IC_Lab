#include <vga_api.h>
#include <picture.h>
#include <stdio.h>
#include <stdlib.h> // 用于随机数生成
#include <time.h>   // 用于随机数种子

volatile int* PIXEL_ADDRESS;
volatile int t;
void draw_ball(int x, int y, int radius, int color) {
    for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++) {
            if (i * i + j * j <= radius * radius) { // 圆形判定
                vga_point(x + i, y + j, color);
            }
        }
    }
}

void clear_ball(int x, int y, int radius, int background_color) {
    for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++) {
            if (i * i + j * j <= radius * radius) { // 圆形判定
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
    int dx = (rand() % 3) - 1; // 随机水平速度：-1、0或1
    int dy = 1; // 初始垂直速度
    int radius = 5; // 设置小球的半径

    srand(time(NULL)); // 设置随机数种子

    // 模拟小球反弹
    while (1) {
        // 清除之前的小球位置
        if (previous_x >= 0 && previous_y >= 0) {
            clear_ball(previous_x, previous_y, radius, background_color);
        }
        
        // 绘制当前的小球位置
        draw_ball(x, y, radius, ball_color);
        
        // 延时以模拟自然移动效果
        for(t=0;t<=0x8FFF;t++);

        // 更新位置
        previous_x = x;
        previous_y = y;
        x += dx;
        y += dy;

        // 检查边界条件
        if (x - radius <= 5 || x + radius >= 155) { // 碰到左右边界时反转水平速度
            dx = -dx;
        }
        if (y + radius >= 119) { // 碰到底部时反转垂直速度
            dy = -(rand() % 3 + 1); // 随机反弹速度
						dx = -(rand() % 3 + 1); // 随机反弹速度
        }
        if (y - radius <= 0) { // 碰到顶部时反转垂直速度
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
		
		 simulate_ball_bounce(80, 0, 0xFFF, 0x000); // 白色小球，黑色背景
		
		
//    for (color = 0; color < 4096; color++) {
//        // 显示颜色在屏幕上的位置
//        vga_point(x, y, color);

//        // 更新x坐标，每行填满160个像素后，移动到下一行
//        x++;
//        if (x >= 63) {
//            x = 0;
//            y++;
//        }

//        // 当y超出显示区域时停止
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
