#ifndef FUNCTIONS_H

#include "lib.h"

#define LATTICE 48	//点阵
#define SIZE ((LATTICE * LATTICE) / 8)	//
#define BYTES_PER_LINE (LATTICE / 8)	//每行字节数

#define WINDOW_WIDTH 1400		//窗口的宽度
#define WINDOW_HEIGHT 450		//窗口的高度
#define KERNING 350				//字距
#define MAX_CHARACTER_SIZE 5	//字符数组中一个中文字符嘴的长度
#define DOT_RADIUS 1			//绘制点的半径
#define TOOLBAR_WIDTH 1400		//工具栏宽度
#define TOOLBAR_HEIGHT 50		//工具栏高度
#define TOOLBAR_NUMS 6			//工具栏数量
#define BUTTON_WIDTH 150		//按钮宽度
#define BUTTON_HEIGHT 50		//按钮高度
#define MOVE_SPEED 2			//字符串移动的速度

//将一个字符矩阵设置成结构体，以实现字符矩阵数组
typedef struct Lattice {
	int lattice[LATTICE][LATTICE];
} Lattice;

//将一个中文字符设置为结构体，以实现中文字符串
typedef struct Statement {
	char character[MAX_CHARACTER_SIZE];
} Statement;

//枚举工具栏
enum {
	USER_INPUT = 0,
	STYLE_1,
	STYLE_2,
	STYLE_3,
	STYLE_4,
	ESCAPE
};


/*functions.cpp中的函数声明*/
void init();
void statement_input_console();
void statement_input_inputbox();
void choose_tool(int button_top_left_x, int button_top_left_y, int choice);
void closing();

/*manage_words.cpp中的函数声明*/
void read_character(char* character);
void generate_font_patterns(Lattice* lattice);
void generate_transposed_font_patterns(Lattice* lattice);
void generate_rotated_font_patterns(Lattice* lattice);
void generate_lattices();

/*draw_functions.cpp中的函数声明*/
void draw_dot(int x, int y);
void linger_effect(int x, int y, int width, int height, int color);
void print_lattice();
void draw_toolbar();
void draw_button(int x, int y, const char* text);
void style_1();
void style_2();
void style_3();
void style_4();


/*APIs.cpp中的函数声明*/
void manage_mouse_msg();
void user_input_API();
void style1_API();
void style2_API();
void style3_API();
void style4_API();

#endif // !FUNCTIONS_H