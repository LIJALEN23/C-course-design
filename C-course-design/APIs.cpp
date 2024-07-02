#include "functions.h"

extern ExMessage msg;
extern int toolbar_choice;
extern Lattice* lattices;
extern Statement* statement;

void manage_mouse_msg() {
	//��������밴ť����ʾ��ѡ��Ч��
	if (msg.x > BUTTON_WIDTH * 0 && msg.x < BUTTON_WIDTH * 1 && msg.y > 0 && msg.y < BUTTON_HEIGHT) {
		if (msg.message == WM_LBUTTONDOWN) {
			free(statement);
			free(lattices);
			statement_input_inputbox();
			generate_lattices();
			print_lattice();
		}
		choose_tool(BUTTON_WIDTH * 0, 0, USER_INPUT);
	}
	//������ѡ��
	else {
		linger_effect(BUTTON_WIDTH * 0, 0, BUTTON_WIDTH, BUTTON_HEIGHT, RED);
	}

	//����ڷ��һ��ť����ʾ��ѡ��Ч��
	if (msg.x > BUTTON_WIDTH * 1 && msg.x < BUTTON_WIDTH * 2 && msg.y > 0 && msg.y < BUTTON_HEIGHT) {
		if (msg.message == WM_LBUTTONDOWN) {
			style_1();
		}
		choose_tool(BUTTON_WIDTH * 1, 0, STYLE_1);
	}
	//������ѡ��
	else {
		linger_effect(BUTTON_WIDTH * 1, 0, BUTTON_WIDTH, BUTTON_HEIGHT, RED);
	}

	//����ڷ�����ť����ʾ��ѡ��Ч��
	if (msg.x > BUTTON_WIDTH * 2 && msg.x < BUTTON_WIDTH * 3 && msg.y > 0 && msg.y < BUTTON_HEIGHT) {
		if (msg.message == WM_LBUTTONDOWN) {
			style_2();
		}
		choose_tool(BUTTON_WIDTH * 2, 0, STYLE_2);
	}
	//������ѡ��
	else {
		linger_effect(BUTTON_WIDTH * 2, 0, BUTTON_WIDTH, BUTTON_HEIGHT, RED);
	}

	//����ڷ������ť����ʾ��ѡ��Ч��
	if (msg.x > BUTTON_WIDTH * 3 && msg.x < BUTTON_WIDTH * 4 && msg.y > 0 && msg.y < BUTTON_HEIGHT) {
		if (msg.message == WM_LBUTTONDOWN) {
			style_3();
		}
		choose_tool(BUTTON_WIDTH * 3, 0, STYLE_3);
	}
	//������ѡ��
	else {
		linger_effect(BUTTON_WIDTH * 3, 0, BUTTON_WIDTH, BUTTON_HEIGHT, RED);
	}

	//����ڷ���İ�ť����ʾ��ѡ��Ч��
	if (msg.x > BUTTON_WIDTH * 4 && msg.x < BUTTON_WIDTH * 5 && msg.y > 0 && msg.y < BUTTON_HEIGHT) {
		if (msg.message == WM_LBUTTONDOWN) {
			style_4();
		}
		choose_tool(BUTTON_WIDTH * 4, 0, STYLE_4);
	}
	//������ѡ��
	else {
		linger_effect(BUTTON_WIDTH * 4, 0, BUTTON_WIDTH, BUTTON_HEIGHT, RED);
	}

	//������˳���ť����ʾ��ѡ��Ч��
	if (msg.x > BUTTON_WIDTH * 5 && msg.x < BUTTON_WIDTH * 6 && msg.y > 0 && msg.y < BUTTON_HEIGHT) {
		choose_tool(BUTTON_WIDTH * 5, 0, ESCAPE);
	}
	//������ѡ��
	else {
		linger_effect(BUTTON_WIDTH * 5, 0, BUTTON_WIDTH, BUTTON_HEIGHT, RED);
	}
}

void user_input_API() {
	draw_toolbar();
	while (toolbar_choice == USER_INPUT) {
		if (peekmessage(&msg)) {
			manage_mouse_msg();
		}
	}
}

void style1_API() {
	draw_toolbar();
	if (isEmpty) {
		toolbar_choice = USER_INPUT;
		return;

	}
	while (toolbar_choice == STYLE_1) {
		if (peekmessage(&msg)) {
			manage_mouse_msg();
		}
	}
}

void style2_API() {
	draw_toolbar();
	if (isEmpty) {
		toolbar_choice = USER_INPUT;
		return;

	}
	while (toolbar_choice == STYLE_2) {
		if (peekmessage(&msg)) {
			manage_mouse_msg();
		}
	}
}

void style3_API() {
	draw_toolbar();
	if (isEmpty) {
		toolbar_choice = USER_INPUT;
		return;

	}
	while (toolbar_choice == STYLE_3) {
		if (peekmessage(&msg)) {
			manage_mouse_msg();
		}
	}
}

void style4_API() {
	draw_toolbar();
	if (isEmpty) {
		toolbar_choice = USER_INPUT;
		return;

	}
	while (toolbar_choice == STYLE_4) {
		if (peekmessage(&msg)) {
			manage_mouse_msg();
		}
	}
}