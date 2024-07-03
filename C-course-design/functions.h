#ifndef FUNCTIONS_H

#include "lib.h"

#define LATTICE 48	//����
#define SIZE ((LATTICE * LATTICE) / 8)	//
#define BYTES_PER_LINE (LATTICE / 8)	//ÿ���ֽ���

#define WINDOW_WIDTH 1400		//���ڵĿ��
#define WINDOW_HEIGHT 450		//���ڵĸ߶�
#define KERNING 350				//�־�
#define MAX_CHARACTER_SIZE 5	//�ַ�������һ�������ַ���ĳ���
#define DOT_RADIUS 1			//���Ƶ�İ뾶
#define TOOLBAR_WIDTH 1400		//���������
#define TOOLBAR_HEIGHT 50		//�������߶�
#define TOOLBAR_NUMS 6			//����������
#define BUTTON_WIDTH 150		//��ť���
#define BUTTON_HEIGHT 50		//��ť�߶�
#define MOVE_SPEED 2			//�ַ����ƶ����ٶ�

//��һ���ַ��������óɽṹ�壬��ʵ���ַ���������
typedef struct Lattice {
	int lattice[LATTICE][LATTICE];
} Lattice;

//��һ�������ַ�����Ϊ�ṹ�壬��ʵ�������ַ���
typedef struct Statement {
	char character[MAX_CHARACTER_SIZE];
} Statement;

//ö�ٹ�����
enum {
	USER_INPUT = 0,
	STYLE_1,
	STYLE_2,
	STYLE_3,
	STYLE_4,
	ESCAPE
};


/*functions.cpp�еĺ�������*/
void init();
void statement_input_console();
void statement_input_inputbox();
void choose_tool(int button_top_left_x, int button_top_left_y, int choice);
void closing();

/*manage_words.cpp�еĺ�������*/
void read_character(char* character);
void generate_font_patterns(Lattice* lattice);
void generate_transposed_font_patterns(Lattice* lattice);
void generate_rotated_font_patterns(Lattice* lattice);
void generate_lattices();

/*draw_functions.cpp�еĺ�������*/
void draw_dot(int x, int y);
void linger_effect(int x, int y, int width, int height, int color);
void print_lattice();
void draw_toolbar();
void draw_button(int x, int y, const char* text);
void style_1();
void style_2();
void style_3();
void style_4();


/*APIs.cpp�еĺ�������*/
void manage_mouse_msg();
void user_input_API();
void style1_API();
void style2_API();
void style3_API();
void style4_API();

#endif // !FUNCTIONS_H