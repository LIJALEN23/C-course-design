#include "functions.h"

extern Statement* statement;
extern Lattice* lattices;
extern int character_nums;

/*��һ����*/
void draw_dot(int x, int y) {
	solidcircle(x, y, DOT_RADIUS);
}

/*��������ѡ��ʱ��ͣ����Ч*/
void linger_effect(int x, int y, int width, int height, int color) {
    setlinecolor(color); //����ͣ���߿����ɫ
    roundrect(x, y, x + width, y + height, 10, 10);
}

/*���ַ���������Ӧ�Ļ滭����������*/
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

/*��������������*/
void draw_toolbar() {

    graphdefaults();
    fillrectangle(0, 0, WINDOW_WIDTH, BUTTON_HEIGHT);
    for (int i = 0; i < TOOLBAR_NUMS; i++) {
        switch (i) {
        case USER_INPUT:
            draw_button(0 + i * BUTTON_WIDTH, 0, "����");
            break;
        case STYLE_1:
            draw_button(0 + i * BUTTON_WIDTH, 0, "���һ");
            break;
        case STYLE_2:
            draw_button(0 + i * BUTTON_WIDTH, 0, "����");
            break;
        case STYLE_3:
            draw_button(0 + i * BUTTON_WIDTH, 0, "�����");
            break;
        case STYLE_4:
            draw_button(0 + i * BUTTON_WIDTH, 0, "�����");
            break;
        case ESCAPE:
            draw_button(0 + i * BUTTON_WIDTH, 0, "�˳�");
            break;
        }
    }


}

/*��(x, y)����һ����ť*/
void draw_button(int x, int y, const char* text) {

    setlinecolor(RED);      //���ÿ����ɫ
    setbkmode(TRANSPARENT); //�������屳��͸��
    setfillcolor(WHITE);    //���������ɫ
    fillroundrect(x, y, x + BUTTON_WIDTH, y + BUTTON_HEIGHT, 10, 10);//��һ����ť��

    char text_[50] = { 0 };
    strcpy(text_, text);
    settextcolor(RED);
    settextstyle(40, 0, _T("����"));
    int tx = x + (BUTTON_WIDTH - textwidth(text_)) / 2;
    int ty = y + (BUTTON_HEIGHT - textheight(text_)) / 2;
    outtextxy(tx, ty, text_);

    graphdefaults();
}

/*ʵ�����ֵ�ѭ���ƶ�Ч��*/
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

/*ʵ�����ֵ���ɫ����仯*/
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
                            perror("style2������switch��������һ�������dot_colorֵ��\n");
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

/*ʵ���ֵ�ѭ���Ƶ�Ч������ɫ����任*/
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
                            perror("style2������switch��������һ�������dot_colorֵ��\n");
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

/*������ʵ�����ֵ���ת(��������)*/
void style_4() {
    int lattices_nums = character_nums;

    for (int i = 0; i < lattices_nums; i++) {
        read_character(statement[i].character);
        generate_transposed_font_patterns(&(lattices[i]));
    }

    print_lattice();
}