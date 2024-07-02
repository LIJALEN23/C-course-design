#include "functions.h"

extern FILE* fpHZK;

extern Lattice* lattices;
extern Statement* statement;
extern ExMessage msg;
extern int character_nums;
extern int toolbar_choice;

/*��ʼ������*/
void init() {
	fpHZK = fopen("res\\HZK48S", "rb");
	if (fpHZK == NULL) {
		perror("init(): ��ȡ�ļ�HZK48Sʧ�ܣ�\n");
		return;
	}

	character_nums = 0;


	//initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT, EX_SHOWCONSOLE);

}

/*�ӿ���̨��ȡ�����ַ�������*/
void statement_input_console() {
	char buffer[50];
	scanf("%s", buffer);

	size_t nums = strlen(buffer) / 2;
	character_nums = (int)nums;

	statement = (Statement*)malloc(sizeof(Statement) * nums);
	lattices = (Lattice*)malloc(sizeof(Lattice) * nums);

	for (size_t i = 0; i < nums; i++) {
		strncpy(statement[i].character, buffer + i * 2, 2);
		statement[i].character[2] = '\0';
	}

}

/*�ӶԻ����ȡ�����ַ�������*/
void statement_input_inputbox() {
	char buffer[50];
	InputBox(buffer, 50, "���������ӡ�ַ�����");

	size_t nums = strlen(buffer) / 2;
	character_nums = (int)nums;

	statement = (Statement*)malloc(sizeof(Statement) * nums);
	lattices = (Lattice*)malloc(sizeof(Lattice) * nums);

	for (size_t i = 0; i < nums; i++) {
		strncpy(statement[i].character, buffer + i * 2, 2);
		statement[i].character[2] = '\0';
	}
}

/*�빤�������л��й�*/
void choose_tool(int button_top_left_x, int button_top_left_y, int choice) {
	if (msg.x > button_top_left_x && msg.x < button_top_left_x + BUTTON_WIDTH && msg.y > button_top_left_y && msg.y < button_top_left_y + BUTTON_HEIGHT) {
		linger_effect(button_top_left_x, button_top_left_y, BUTTON_WIDTH, BUTTON_HEIGHT, LIGHTBLUE);

		if (msg.message == WM_LBUTTONDOWN) {
			toolbar_choice = choice;
		}
	}

}

/*�����ַ����Ƿ�Ϊ��*/
bool isEmpty() {
	return (lattices == NULL && statement == NULL);
}

/*�������������*/
void closing() {

	closegraph();

	fclose(fpHZK);
	fpHZK = NULL;
	
	free(statement);
	free(lattices);
}