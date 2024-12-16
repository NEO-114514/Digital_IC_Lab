#include <vga_api.h>
#include <picture.h>

volatile int* PIXEL_ADDRESS;



int main()
	{
	volatile int i;
	volatile int j;
	volatile int y=0;
	volatile int color;
		
	VGA_INIT(0,0xFF,0);
		
	vga_show_str(0,0,"35320212200396");
  vga_show_str(0,1,"Huang Tengxi");
	
	
//	vga_point(0,0,WHITE);
//	vga_point(1,1,WHITE);
//	vga_point(0,119,WHITE);
//	vga_point(159,0,WHITE);
//	vga_point(2,2,WHITE);

//  vga_draw_image(0,0,160,120,IMAGE);
//	vga_draw_image(159,0,160,120,IMAGE);
//  vga_draw_image(319,0,160,120,IMAGE);
	vga_draw_image(479,0,160,120,IMAGE);

//	vga_draw_image(0,119,160,120,IMAGE);
//	vga_draw_image(159,119,160,120,IMAGE);
	vga_draw_image(319,119,160,120,IMAGE);
//	vga_draw_image(479,119,160,120,IMAGE);
//	
//	vga_draw_image(0,239,160,120,IMAGE);
	vga_draw_image(159,239,160,120,IMAGE);
//	vga_draw_image(319,239,160,120,IMAGE);
//	vga_draw_image(479,239,160,120,IMAGE);

	vga_draw_image(0,359,160,120,IMAGE);
//	vga_draw_image(159,359,160,120,IMAGE);
//	vga_draw_image(319,359,160,120,IMAGE);
//	vga_draw_image(479,359,160,120,IMAGE);

//	vga_draw_image(0,0,160,120,IMAGE);
//	vga_draw_image(159,0,160,120,IMAGE);
//	vga_draw_image(0,119,160,120,IMAGE);
//	vga_draw_image(159,119,160,120,IMAGE);
		
	
//	for(i=0;i<=256*1024;i++)
//		{
//			color=(i%256);
//			vga_point(i*2,0,color);
//			for(j=0;j<=0x2F;j++);
//		}
//		
//	for(i=0;i<=800;i++)
//		{
//			if((i%100==0)|(i==0)|(i>520)) color=LIGHT_RED;
//			else color=WHITE;
//			vga_point(1,i,color);
//			for(j=0;j<=0x2FFF;j++);
//		}
//	for(i=50;i<=99;i++)
//	vga_point(4,i,BLUE);



	
	
//	VGA_TEXT_COLOR_REG = (WHITE<<8)|LIGHT_RED;
//	
//  vga_show_str(0,5,"35320212200396");
//  vga_show_str(0,6,"Huang Tengxi");
//	
//	vga_show_char(0,0,'A');
//	vga_show_char(79,0,'B');
//	vga_show_char(0,28,'C');
//	vga_show_char(79,28,'D');
	

//	vga_draw_line(0,0,0,4,RED);
//	vga_draw_line(0,0,4,0,RED);
//	
//	vga_draw_line(155,0,159,0,RED);
//	vga_draw_line(159,4,159,0,RED);
//	
//	vga_draw_line(0,119,4,119,RED);
//	vga_draw_line(0,115,0,119,RED);
//	
//	vga_draw_line(155,119,159,119,RED);
//	vga_draw_line(159,115,159,119,RED);
	
//	vga_draw_line(0,69,120,79,RED);
//	vga_draw_line(0,79,120,69,GREEN);
//	vga_draw_rectangle(0,90,159,119,PURPLE,1,LIGHT_BLUE);
//	vga_point(159,65,WHITE);
//	for(i=0;i<=159;i++)
//		{
//			vga_point(i,65,WHITE);
//			for(j=0;j<=0x2FFFF;j++);
//		}


//	vga_show_str(1,2,"Huang Tengxi");
//	vga_show_str(1,5,"Hello, Digital IC Design!");

		while(1)
		{
//			
		}
	
}
