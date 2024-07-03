#include "functions.h"

extern ExMessage msg;
extern int toolbar_choice;
extern bool first_run_sign;
extern Lattice* lattices;
extern Statement* statement;

/*****处理鼠标事件的函数*****
* 参数：无
* 功能： 1. 当鼠标停留在相应区域时调用停留特效函数
*		 2. 当鼠标点击工具栏时，切换界面
* 返回值：无
*/
void manage_mouse_msg() {
	//鼠标在输入按钮上显示被选中效果
	if (msg.x > BUTTON_WIDTH * 0 && msg.x < BUTTON_WIDTH * 1 && msg.y > 0 && msg.y < BUTTON_HEIGHT) {
		if (msg.message == WM_LBUTTONDOWN && !first_run_sign) {
			free(statement);
			free(lattices);
			statement_input_inputbox();
			generate_lattices();
			print_lattice();
		}
		choose_tool(BUTTON_WIDTH * 0, 0, USER_INPUT);
	}
	//消除被选中
	else {
		linger_effect(BUTTON_WIDTH * 0, 0, BUTTON_WIDTH, BUTTON_HEIGHT, RED);
	}

	//鼠标在风格一按钮上显示被选中效果
	if (msg.x > BUTTON_WIDTH * 1 && msg.x < BUTTON_WIDTH * 2 && msg.y > 0 && msg.y < BUTTON_HEIGHT) {
		if (msg.message == WM_LBUTTONDOWN) {
			style_1();
		}
		choose_tool(BUTTON_WIDTH * 1, 0, STYLE_1);
	}
	//消除被选中
	else {
		linger_effect(BUTTON_WIDTH * 1, 0, BUTTON_WIDTH, BUTTON_HEIGHT, RED);
	}

	//鼠标在风格二按钮上显示被选中效果
	if (msg.x > BUTTON_WIDTH * 2 && msg.x < BUTTON_WIDTH * 3 && msg.y > 0 && msg.y < BUTTON_HEIGHT) {
		if (msg.message == WM_LBUTTONDOWN) {
			style_2();
		}
		choose_tool(BUTTON_WIDTH * 2, 0, STYLE_2);
	}
	//消除被选中
	else {
		linger_effect(BUTTON_WIDTH * 2, 0, BUTTON_WIDTH, BUTTON_HEIGHT, RED);
	}

	//鼠标在风格三按钮上显示被选中效果
	if (msg.x > BUTTON_WIDTH * 3 && msg.x < BUTTON_WIDTH * 4 && msg.y > 0 && msg.y < BUTTON_HEIGHT) {
		if (msg.message == WM_LBUTTONDOWN) {
			style_3();
		}
		choose_tool(BUTTON_WIDTH * 3, 0, STYLE_3);
	}
	//消除被选中
	else {
		linger_effect(BUTTON_WIDTH * 3, 0, BUTTON_WIDTH, BUTTON_HEIGHT, RED);
	}

	//鼠标在风格四按钮上显示被选中效果
	if (msg.x > BUTTON_WIDTH * 4 && msg.x < BUTTON_WIDTH * 5 && msg.y > 0 && msg.y < BUTTON_HEIGHT) {
		if (msg.message == WM_LBUTTONDOWN) {
			style_4();
		}
		choose_tool(BUTTON_WIDTH * 4, 0, STYLE_4);
	}
	//消除被选中
	else {
		linger_effect(BUTTON_WIDTH * 4, 0, BUTTON_WIDTH, BUTTON_HEIGHT, RED);
	}

	//鼠标在退出按钮上显示被选中效果
	if (msg.x > BUTTON_WIDTH * 5 && msg.x < BUTTON_WIDTH * 6 && msg.y > 0 && msg.y < BUTTON_HEIGHT) {
		choose_tool(BUTTON_WIDTH * 5, 0, ESCAPE);
	}
	//消除被选中
	else {
		linger_effect(BUTTON_WIDTH * 5, 0, BUTTON_WIDTH, BUTTON_HEIGHT, RED);
	}
}

/******用户输入API***********
* 参数：无
* 功能：实现用户输入时调用的函数，实现一个用户输入API
* 返回值：无
*/
void user_input_API() {
	draw_toolbar();
	while (toolbar_choice == USER_INPUT) {
		if (first_run_sign) {	//第一次运行需要直接弹出对话框进行输入
			statement_input_inputbox();
			generate_lattices();
			print_lattice();
			first_run_sign = false;		//第一次运行后将标志设置成false，即接下来不是第一次运行
		}
		if (peekmessage(&msg)) {
			manage_mouse_msg();
		}
	}
}

/****风格一API******
* 参数：无
* 功能：实现对风格一调用时的函数，实现一个风格一的API
* 返回值：无
*/
void style1_API() {
	style_1();
}

/****风格二API******
* 参数：无
* 功能：实现对风格二调用时的函数，实现一个风格二的API
* 返回值：无
*/
void style2_API() {
	style_2();
}

/****风格三API******
* 参数：无
* 功能：实现对风格三调用时的函数，实现一个风格三的API
* 返回值：无
*/
void style3_API() {
	style_3();
}

/****风格四API******
* 参数：无
* 功能：实现对风格四调用时的函数，实现一个风格四的API
* 返回值：无
*/
void style4_API() {
	draw_toolbar();
	while (toolbar_choice == STYLE_4) {
		if (peekmessage(&msg)) {
			manage_mouse_msg();
		}
	}
}