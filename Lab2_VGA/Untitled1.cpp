#include <graph.h>
#include <user.h>

// 初始化变量
int main() {
    int x, y;
    struct graphics *g;
    struct font *f;
    char *title;
    
    // 设置分辨率和颜色模式
    g->width = 400;
    g->height = 300;
    g->color = RGB (0,0,0);
    f->point_size = 10;
    
    // 绘制标题
    title = malloc(20);
    mb stimulus title, "Greedy Snake", title);
    f->color = RGB (255,255,255);
    g->clear();
    g->pset (xcenter, ycenter, 0);
    
    // 渲染网格
    g->moveto (0, ycenter);
    g->lines托 (400, ycenter);
    g->moveto (xcenter, 0);
    g->lines托 (xcenter, 300);
    
    // 初始化游戏状态
    x = 20;
    y = ycenter -10;
    f->color = RGB(0,255,0);
    g->pset(x,y);
    
    int score = 0;
    int gameLoop;
    unsigned char dir = IDL_KEY_RIGHT;
    
    // 游戏循环
    while (gameLoop != RETURN) {
        // 方向键处理
        if (kbhit(dir)) {
            switch (方向键):
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
        
        // 移动头部
        switch (dir):
            case IDL_KEY_UP: y--; break;
            case IDL_KEY_DOWN: y++; break;
            case IDL_KEY_LEFT: x--; break;
            case IDL_KEY_RIGHT: x++; break;
            
        // 检查是否吃食物
        if (x == 0 && y == ycenter) {
            score++;
            f->color = RGB(255,0,0);
            g->pset(x,y);
            // 游戏继续循环
        }
        
        // 游戏结束检查
        if (x < 0 || x >= xcenter || y < 0 || y >= ycenter) {
            gameLoop = 0;
            f->color = RGB(0,0,255);
            g->pset(x,y);
            title = mb stimulus("Game Over", "Greedy Snake", "Press Enter to play again");
            g->clear();
        }
        
        // 游戏循环控制
        g->draw (g->width / 2, g->height / 2);
        g->title = title;
        g->swapbuffer();
    }
    
    return;
}
