#include "functions.h"

extern Statement* statement;
extern Lattice* lattices;
extern ExMessage msg;
extern int toolbar_choice;
extern int character_nums;

/**********画一个点****************
* 参数：   1. x：点的x坐标
*         2. y: 点的y坐标
* 功能：在（x, y）处画一个点
* 返回值：无
*/
void draw_dot(int x, int y) {
	solidcircle(x, y, DOT_RADIUS);
}

/*******工具栏被选中时有停留特效*********
* 参数： 1. (x, y)：需要特效按钮的左上角坐标
*       2. (width, height)：按钮的高度和宽度
*       3. color：颜色的取值
* 功能：当鼠标停留在一个按钮上时，显示停留特效
* 返回值：无 
*/
void linger_effect(int x, int y, int width, int height, int color) {
    setlinecolor(color); //设置停留边框的颜色
    roundrect(x, y, x + width, y + height, 10, 10);
}

/*******将字符矩阵用相应的绘画函数画出来**************
* 参数：无
* 功能：将字符点阵结构体数组打印出来
* 返回值：无
*/
void print_lattice() {
    cleardevice();
    draw_toolbar();
	for (int i = 0; i < character_nums; i++) {
		for (int j = 0; j < LATTICE; j++) {
			for (int k = 0; k < LATTICE; k++) {
				if (lattices[i].lattice[j][k] == 1)
					draw_dot(k * 8 + i * KERNING, j * 8 + 70);
			}
		}
	}
}

/**********将工具栏画出来******************
* 参数：无
* 功能：绘制工具栏
* 返回值：无
*/
void draw_toolbar() {

    graphdefaults();
    fillrectangle(0, 0, WINDOW_WIDTH, BUTTON_HEIGHT);
    for (int i = 0; i < TOOLBAR_NUMS; i++) {
        switch (i) {
        case USER_INPUT:
            draw_button(0 + i * BUTTON_WIDTH, 0, "输入");
            break;
        case STYLE_1:
            draw_button(0 + i * BUTTON_WIDTH, 0, "风格一");
            break;
        case STYLE_2:
            draw_button(0 + i * BUTTON_WIDTH, 0, "风格二");
            break;
        case STYLE_3:
            draw_button(0 + i * BUTTON_WIDTH, 0, "风格三");
            break;
        case STYLE_4:
            draw_button(0 + i * BUTTON_WIDTH, 0, "风格四");
            break;
        case ESCAPE:
            draw_button(0 + i * BUTTON_WIDTH, 0, "退出");
            break;
        }
    }


}

/**********在(x, y)处画一个按钮**************
* 参数： 1. (x, y)：在(x, y)处画一个按钮
*       2. text：按钮上的文本
* 功能：绘制一个按钮
* 返回值：无
*/
void draw_button(int x, int y, const char* text) {

    setlinecolor(RED);      //设置框边颜色
    setbkmode(TRANSPARENT); //设置字体背景透明
    setfillcolor(WHITE);    //设置填充颜色
    fillroundrect(x, y, x + BUTTON_WIDTH, y + BUTTON_HEIGHT, 10, 10);//画一个按钮框

    char text_[50] = { 0 };
    strcpy(text_, text);
    settextcolor(RED);
    settextstyle(40, 0, _T("黑体"));
    int tx = x + (BUTTON_WIDTH - textwidth((LPCTSTR)text_)) / 2;
    int ty = y + (BUTTON_HEIGHT - textheight((LPCTSTR)text_)) / 2;
    outtextxy(tx, ty, (LPCTSTR)text_);

    graphdefaults();
}

/********实现文字的循环移动效果*************
* 参数：无
* 功能：实现字符矩阵在打印区域循环移动
* 返回值：无
*/
void style_1() {
    int x = 0;

    while (toolbar_choice == STYLE_1) {
        cleardevice();

        BeginBatchDraw();
        draw_toolbar();
        for (int i = 0; i < character_nums; i++) {
            for (int j = 0; j < LATTICE; j++) {
                for (int k = 0; k < LATTICE; k++) {
                    if (lattices[i].lattice[j][k] == 1)
                        draw_dot(x + k * 8 + i * KERNING, j * 8 + 70);
                }
            }
        }
        EndBatchDraw();

        x -= MOVE_SPEED;
        if (x < -(KERNING * character_nums + 5 * (LATTICE / 8))) {  //x为所有字都移动到屏幕外了的x坐标
            x = WINDOW_WIDTH - 1;
        }

        if (peekmessage(&msg)) {
            manage_mouse_msg();
        }
    }
}

/********实现文字的颜色随机变化*************
* 参数：无
* 功能：实现字符矩阵的颜色随机变换
* 返回值：无
*/
void style_2() {
    srand(time(NULL));
    enum {
        red = 1,
        green,
        cyan,
        blue,
        magenta,
        yellow,
        white
    };

    int dot_color = red;
    int change_rate = 40;   //通过修改change_rate的值改变闪烁的频率

    while (toolbar_choice == STYLE_2) {
        if (change_rate % 20 == 0) {
            dot_color = 1 + (rand() % (7 - 1 + 1));
        }
        change_rate -= 1;
        if (change_rate < 0) {
            change_rate = 100;
        }

        cleardevice();
        BeginBatchDraw();
        draw_toolbar();

        for (int i = 0; i < character_nums; i++) {
            for (int j = 0; j < LATTICE; j++) {
                for (int k = 0; k < LATTICE; k++) {
                    if (lattices[i].lattice[j][k] == 1) {
                        switch (dot_color) {
                        case red:
                            setfillcolor(RED);
                            break;
                        case blue:
                            setfillcolor(BLUE);
                            break;
                        case green:
                            setfillcolor(GREEN);
                            break;
                        case cyan:
                            setfillcolor(CYAN);
                            break;
                        case magenta:
                            setfillcolor(MAGENTA);
                            break;
                        case yellow:
                            setfillcolor(YELLOW);
                            break;
                        case white:
                            setfillcolor(WHITE);
                            break;
                        default:
                            perror("style2函数的switch语句产生了一个错误的dot_color值！\n");
                            return;
                        }
                        draw_dot(k * 8 + i * KERNING, j * 8 + 70);
                        graphdefaults();
                    }

                }
            }
        }
        EndBatchDraw();

        if (peekmessage(&msg)) {
            manage_mouse_msg();
        }
    }
}

/*************实现字的循环移的效果和颜色随机变换***************
* 参数：无
* 功能：实现字的循环移的效果和颜色随机变换
* 返回值：无
*/
void style_3() {
    srand(time(NULL));
    enum {
        red = 1,
        green,
        cyan,
        blue,
        magenta,
        yellow,
        white
    };

    int x = 0;
    int dot_color = red;
    int change_rate = 40;   //通过修改change_rate的值改变闪烁的频率


    while (toolbar_choice == STYLE_3) {
        if (change_rate % 20 == 0) {
            dot_color = 1 + (rand() % (7 - 1 + 1));
        }
        change_rate -= 1;
        if (change_rate < 0) {
            change_rate = 100;
        }

        cleardevice();
        BeginBatchDraw();
        draw_toolbar();

        for (int i = 0; i < character_nums; i++) {
            for (int j = 0; j < LATTICE; j++) {
                for (int k = 0; k < LATTICE; k++) {
                    if (lattices[i].lattice[j][k] == 1) {
                        switch (dot_color) {
                        case red:
                            setfillcolor(RED);
                            break;
                        case blue:
                            setfillcolor(BLUE);
                            break;
                        case green:
                            setfillcolor(GREEN);
                            break;
                        case cyan:
                            setfillcolor(CYAN);
                            break;
                        case magenta:
                            setfillcolor(MAGENTA);
                            break;
                        case yellow:
                            setfillcolor(YELLOW);
                            break;
                        case white:
                            setfillcolor(WHITE);
                            break;
                        default:
                            perror("style2函数的switch语句产生了一个错误的dot_color值！\n");
                            return;
                        }
                        draw_dot(x + k * 8 + i * KERNING, j * 8 + 70);
                        graphdefaults();
                    }

                }
            }

        }
        x -= MOVE_SPEED;
        if (x < -(KERNING * character_nums + 5 * (LATTICE / 8))) {
            x = WINDOW_WIDTH - 1;
        }
        EndBatchDraw();


        if (peekmessage(&msg)) {
            manage_mouse_msg();
        }
    }
}

/***********将文字实现文字的旋转(矩阵运算)************
* 参数：无
* 功能：将文字实现文字的旋转(矩阵运算)
* 返回值：无
*/
void style_4() {
    int lattices_nums = character_nums;

    cleardevice();
    for (int i = 0; i < lattices_nums; i++) {
        read_character(statement[i].character);
        generate_transposed_font_patterns(&(lattices[i]));
        //generate_rotated_font_patterns(&(lattices[i]));
    }

    print_lattice();
}