#include "functions.h"

extern Statement* statement;
extern Lattice* lattices;
extern ExMessage msg;
extern int toolbar_choice;
extern int character_nums;

/**********��һ����****************
* ������   1. x�����x����
*         2. y: ���y����
* ���ܣ��ڣ�x, y������һ����
* ����ֵ����
*/
void draw_dot(int x, int y) {
	solidcircle(x, y, DOT_RADIUS);
}

/*******��������ѡ��ʱ��ͣ����Ч*********
* ������ 1. (x, y)����Ҫ��Ч��ť�����Ͻ�����
*       2. (width, height)����ť�ĸ߶ȺͿ��
*       3. color����ɫ��ȡֵ
* ���ܣ������ͣ����һ����ť��ʱ����ʾͣ����Ч
* ����ֵ���� 
*/
void linger_effect(int x, int y, int width, int height, int color) {
    setlinecolor(color); //����ͣ���߿����ɫ
    roundrect(x, y, x + width, y + height, 10, 10);
}

/*******���ַ���������Ӧ�Ļ滭����������**************
* ��������
* ���ܣ����ַ�����ṹ�������ӡ����
* ����ֵ����
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

/**********��������������******************
* ��������
* ���ܣ����ƹ�����
* ����ֵ����
*/
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

/**********��(x, y)����һ����ť**************
* ������ 1. (x, y)����(x, y)����һ����ť
*       2. text����ť�ϵ��ı�
* ���ܣ�����һ����ť
* ����ֵ����
*/
void draw_button(int x, int y, const char* text) {

    setlinecolor(RED);      //���ÿ����ɫ
    setbkmode(TRANSPARENT); //�������屳��͸��
    setfillcolor(WHITE);    //���������ɫ
    fillroundrect(x, y, x + BUTTON_WIDTH, y + BUTTON_HEIGHT, 10, 10);//��һ����ť��

    char text_[50] = { 0 };
    strcpy(text_, text);
    settextcolor(RED);
    settextstyle(40, 0, _T("����"));
    int tx = x + (BUTTON_WIDTH - textwidth((LPCTSTR)text_)) / 2;
    int ty = y + (BUTTON_HEIGHT - textheight((LPCTSTR)text_)) / 2;
    outtextxy(tx, ty, (LPCTSTR)text_);

    graphdefaults();
}

/********ʵ�����ֵ�ѭ���ƶ�Ч��*************
* ��������
* ���ܣ�ʵ���ַ������ڴ�ӡ����ѭ���ƶ�
* ����ֵ����
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
        if (x < -(KERNING * character_nums + 5 * (LATTICE / 8))) {  //xΪ�����ֶ��ƶ�����Ļ���˵�x����
            x = WINDOW_WIDTH - 1;
        }

        if (peekmessage(&msg)) {
            manage_mouse_msg();
        }
    }
}

/********ʵ�����ֵ���ɫ����仯*************
* ��������
* ���ܣ�ʵ���ַ��������ɫ����任
* ����ֵ����
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
    int change_rate = 40;   //ͨ���޸�change_rate��ֵ�ı���˸��Ƶ��

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

        if (peekmessage(&msg)) {
            manage_mouse_msg();
        }
    }
}

/*************ʵ���ֵ�ѭ���Ƶ�Ч������ɫ����任***************
* ��������
* ���ܣ�ʵ���ֵ�ѭ���Ƶ�Ч������ɫ����任
* ����ֵ����
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
    int change_rate = 40;   //ͨ���޸�change_rate��ֵ�ı���˸��Ƶ��


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
                            perror("style2������switch��������һ�������dot_colorֵ��\n");
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

/***********������ʵ�����ֵ���ת(��������)************
* ��������
* ���ܣ�������ʵ�����ֵ���ת(��������)
* ����ֵ����
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