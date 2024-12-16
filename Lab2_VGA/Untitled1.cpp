#include <stdio.h>
#include <stdlib.h>

// ͼ���Ⱥ͸߶ȶ���
#define WIDTH 160  // ����Ϊ160���ؿ�
#define HEIGHT 120 // ����Ϊ120���ظ�

// ͼ����������
unsigned char IMAGE[WIDTH * HEIGHT];

// ��ɫ����
#define BLACK        0x00
#define BLUE         0x03
#define GREEN        0x1C
#define PURPLE       0xA3
#define RED          0xE0
#define MAGENTA      0xE3
#define BROWN        0xA0
#define LIGHT_GRAY   0xAA
#define DARK_GRAY    0x55
#define LIGHT_BLUE   0x57
#define LIGHT_GREEN  0x5D
#define LIGHT_CYAN   0x5F
#define LIGHT_RED    0xE5
#define LIGHT_MAGENTA 0xE7
#define YELLOW       0xFC
#define WHITE        0xFF

// ����ͼ����
void generateImage() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int border_layer = (x < y ? x : y);
            border_layer = (border_layer < (WIDTH - x - 1) ? border_layer : (WIDTH - x - 1));
            border_layer = (border_layer < (HEIGHT - y - 1) ? border_layer : (HEIGHT - y - 1));

            if (border_layer % 2 == 0) {
                IMAGE[y * WIDTH + x] = RED; // ʾ�����ù̶���ɫ���
            } else {
                IMAGE[y * WIDTH + x] = BLUE; // ʾ�����ù̶���ɫ���
            }
        }
    }
}

// ��ͼ�����ݱ��浽txt�ļ��ĺ���
void saveImageToFile(const char* filename, const unsigned char* image_data, int width, int height) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("�޷����ļ� %s\n", filename);
        return;
    }

    fprintf(file, "const unsigned char IMAGE[%d] = { /* 0X08,0X08,0XA0,0X00,0X78,0X00, */\n", width * height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            fprintf(file, "0X%02X", image_data[index]);
            if (x < width - 1 || y < height - 1) {
                fprintf(file, ",");
            }
            if ((index + 1) % 16 == 0) {
                fprintf(file, "\n");
            } else {
                fprintf(file, " ");
            }
        }
    }

    fprintf(file, "};\n");
    fclose(file);
    printf("ͼ�������ѳɹ�д�뵽 %s\n", filename);
}

int main() {
    // ����ͼ������
    generateImage();

    // ��ͼ������д�뵽txt�ļ�
    saveImageToFile("image_output.txt", IMAGE, WIDTH, HEIGHT);

    return 0;
}

