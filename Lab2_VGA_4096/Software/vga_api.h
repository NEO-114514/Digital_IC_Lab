#define VGA_TEXT_REG     		*((volatile int*)0x50000000)
#define VGA_IMAGE_REG   	  0x50000004

#define VGA_CUR_REG      		*((volatile int*)0x50800000)
#define VGA_TEXT_COLOR_REG  *((volatile int*)0x50800004)
#define VGA_TEXT_WIDTH_REG  *((volatile int*)0x50800008)
#define VGA_IMAGE_ZOOM_REG  *((volatile int*)0x50800010)

//color list
#define BLACK        0x000 
#define RED          0xF00 // 红色
#define GREEN        0x0F0 // 绿色
#define BLUE         0x00F // 蓝色
#define CYAN         0x0FF // 青色
#define MAGENTA      0xF0F // 品红色
#define YELLOW       0xFF0 // 黄色
#define ORANGE       0xFA0 // 橙色
#define PURPLE       0x80F // 紫色
#define GRAY         0x808 // 灰色
#define LIGHT_GRAY   0xC0C // 浅灰色
#define DARK_GRAY    0x404 // 深灰色
#define BROWN        0x5A0 // 棕色
#define PINK         0xF81 // 粉红色
#define LIME         0x0E0 // 酸橙色
#define WHITE        0xFFF

extern void VGA_INIT(volatile int text_width, volatile int text_color, volatile int image_zoom);
extern void vga_image_clean(void);
extern void vga_text_clean(void);
extern void vga_point(volatile int x ,volatile int y ,volatile int color);

extern void vga_draw_line(volatile int x0, volatile int y0, volatile int x1, volatile int y1, volatile int color) ;
extern void vga_draw_rectangle(volatile int x0, volatile int y0, volatile int x1, volatile int y1, volatile int color, int fill, volatile int fill_color) ;
extern void vga_draw_image(volatile int x_start, volatile int y_start, volatile int width, volatile int height, const unsigned short *image_data);
 

extern void vga_show_char(volatile int x, volatile int y, char ch);
extern void vga_show_str(volatile int x, volatile int y, const char* str);

