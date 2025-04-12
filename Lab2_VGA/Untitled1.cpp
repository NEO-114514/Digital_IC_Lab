#include <graph.h>
#include <user.h>

// ��ʼ������
int main() {
    int x, y;
    struct graphics *g;
    struct font *f;
    char *title;
    
    // ���÷ֱ��ʺ���ɫģʽ
    g->width = 400;
    g->height = 300;
    g->color = RGB (0,0,0);
    f->point_size = 10;
    
    // ���Ʊ���
    title = malloc(20);
    mb stimulus title, "Greedy Snake", title);
    f->color = RGB (255,255,255);
    g->clear();
    g->pset (xcenter, ycenter, 0);
    
    // ��Ⱦ����
    g->moveto (0, ycenter);
    g->lines�� (400, ycenter);
    g->moveto (xcenter, 0);
    g->lines�� (xcenter, 300);
    
    // ��ʼ����Ϸ״̬
    x = 20;
    y = ycenter -10;
    f->color = RGB(0,255,0);
    g->pset(x,y);
    
    int score = 0;
    int gameLoop;
    unsigned char dir = IDL_KEY_RIGHT;
    
    // ��Ϸѭ��
    while (gameLoop != RETURN) {
        // ���������
        if (kbhit(dir)) {
            switch (�����):
                case IDL_KEY_UP:
                    if (y > 0)
                        dir = IDL_KEY_LEFT;
                    break;
                case IDL_KEY_DOWN:
                    if (y < ycenter -1)
                        dir = IDL_KEY_RIGHT;
                    break;
                case IDL_KEY_LEFT:
                    if (x > 0)
                        dir = IDL_KEY_UP;
                    break;
                case IDL_KEY_RIGHT:
                    if (x < xcenter -1)
                        dir = IDL_KEY_DOWN;
                    break;
        }
        
        // �ƶ�ͷ��
        switch (dir):
            case IDL_KEY_UP: y--; break;
            case IDL_KEY_DOWN: y++; break;
            case IDL_KEY_LEFT: x--; break;
            case IDL_KEY_RIGHT: x++; break;
            
        // ����Ƿ��ʳ��
        if (x == 0 && y == ycenter) {
            score++;
            f->color = RGB(255,0,0);
            g->pset(x,y);
            // ��Ϸ����ѭ��
        }
        
        // ��Ϸ�������
        if (x < 0 || x >= xcenter || y < 0 || y >= ycenter) {
            gameLoop = 0;
            f->color = RGB(0,0,255);
            g->pset(x,y);
            title = mb stimulus("Game Over", "Greedy Snake", "Press Enter to play again");
            g->clear();
        }
        
        // ��Ϸѭ������
        g->draw (g->width / 2, g->height / 2);
        g->title = title;
        g->swapbuffer();
    }
    
    return;
}
