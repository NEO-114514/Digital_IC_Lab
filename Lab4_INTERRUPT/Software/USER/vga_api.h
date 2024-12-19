#define VGA_TEXT_REG     		*((volatile int*)0x50000000)
#define VGA_IMAGE_REG   	  0x50000004

#define VGA_CUR_REG      		*((volatile int*)0x50800000)
#define VGA_TEXT_COLOR_REG  *((volatile int*)0x50800004)
#define VGA_TEXT_WIDTH_REG  *((volatile int*)0x50800008)
#define VGA_IMAGE_ZOOM_REG  *((volatile int*)0x50800010)

//color list


#define BLACK        0x00  // RGB: 00000000 (R=0, G=0, B=0)
#define BLUE         0x03  // RGB: 00000011 (R=0, G=0, B=3)
#define GREEN        0x1C  // RGB: 00011100 (R=0, G=7, B=0)
#define PURPLE       0xA3  // RGB: 10100011 (R=5, G=0, B=3)
#define RED          0xE0  // RGB: 11100000 (R=7, G=0, B=0)
#define MAGENTA      0xE3  // RGB: 11100011 (R=7, G=0, B=3)
#define BROWN        0xA0  // RGB: 10100000 (R=5, G=2, B=0)
#define LIGHT_GRAY   0xAA  // RGB: 10101010 (R=5, G=5, B=2)
#define DARK_GRAY    0x55  // RGB: 01010101 (R=2, G=2, B=1)
#define LIGHT_BLUE   0x57  // RGB: 01010111 (R=2, G=2, B=3)
#define LIGHT_GREEN  0x5D  // RGB: 01011101 (R=2, G=7, B=0)
#define LIGHT_CYAN   0x5F  // RGB: 01011111 (R=2, G=7, B=3)
#define LIGHT_RED    0xE5  // RGB: 11100101 (R=7, G=2, B=1)
#define LIGHT_MAGENTA 0xE7 // RGB: 11100111 (R=7, G=2, B=3)
#define YELLOW       0xFC  // RGB: 11111100 (R=7, G=7, B=0)
#define WHITE        0xFF  // RGB: 11111111 (R=7, G=7, B=3)


extern void VGA_INIT(volatile int text_width, volatile unsigned char text_color, volatile int image_zoom);
extern void vga_image_clean(void);
extern void vga_text_clean(void);
extern void vga_point(volatile int x ,volatile int y ,unsigned char color);

extern void vga_draw_line(volatile int x1, volatile int y1, volatile int x2, volatile int y2, unsigned char color);
extern void vga_draw_rectangle(volatile int x1, volatile int y1, volatile int x2, volatile int y2, unsigned char border_color, int fill, unsigned char fill_color);
extern void vga_draw_image(volatile int x0, volatile int y0, volatile int width, volatile int height, const unsigned char* image_data);


extern void vga_show_char(volatile int x, volatile int y, char ch);
extern void vga_show_str(volatile int x, volatile int y, const char* str);

