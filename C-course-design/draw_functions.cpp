#include "functions.h"

extern Statement* statement;
extern Lattice* lattices;
extern int character_nums;

/*画一个点*/
void draw_dot(int x, int y) {
	solidcircle(x, y, DOT_RADIUS);
}

/*工具栏被选中时有停留特效*/
void linger_effect(int x, int y, int width, int height, int color) {
    setlinecolor(color); //设置停留边框的颜色
    roundrect(x, y, x + width, y + height, 10, 10);
}

/*将字符矩阵用相应的绘画函数画出来*/
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

/*将工具栏画出来*/
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

/*在(x, y)处画一个按钮*/
void draw_button(int x, int y, const char* text) {

    setlinecolor(RED);      //设置框边颜色
    setbkmode(TRANSPARENT); //设置字体背景透明
    setfillcolor(WHITE);    //设置填充颜色
    fillroundrect(x, y, x + BUTTON_WIDTH, y + BUTTON_HEIGHT, 10, 10);//画一个按钮框

    char text_[50] = { 0 };
    strcpy(text_, text);
    settextcolor(RED);
    settextstyle(40, 0, _T("黑体"));
    int tx = x + (BUTTON_WIDTH - textwidth(text_)) / 2;
    int ty = y + (BUTTON_HEIGHT - textheight(text_)) / 2;
    outtextxy(tx, ty, text_);

    graphdefaults();
}

/*实现文字的循环移动效果*/
void style_1() {
    int x = 0;
    int frequency = 3;

    while (frequency > 0) {
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
        x -= 1;
        if (x < 0) {
            x = WINDOW_WIDTH - 1;
            frequency -= 1;
        }
    }

}

/*实现文字的颜色随机变化*/
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

    int dot_color;
    int frequency = 15;

    while (frequency) {
        dot_color = 1 + (rand() % (7 - 1 + 1));

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
        Sleep(400);
        frequency -= 1;
    }
}

/*实现字的循环移的效果和颜色随机变换*/
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
    int dot_color;
    int frequency = 3;

    while (frequency) {
        if (x % 20 == 0) {
            dot_color = 1 + (rand() % (7 - 1 + 1));
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
            x -= 1;
            if (x < 0) {
                x = WINDOW_WIDTH - 1;
                frequency -= 1;
            }
        }
        EndBatchDraw();
    }
}

/*将文字实现文字的旋转(矩阵运算)*/
void style_4() {
    int lattices_nums = character_nums;

    for (int i = 0; i < lattices_nums; i++) {
        read_character(statement[i].character);
        generate_transposed_font_patterns(&(lattices[i]));
    }

    print_lattice();
}