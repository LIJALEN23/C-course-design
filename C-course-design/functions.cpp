/********************************************
*		�����Ժ�����ʵ��
* ���ߣ�lijalen 
* ���䣺lijalen23@outlook.com
*/
#include "functions.h"

extern FILE* fpHZK;

extern Lattice* lattices;
extern Statement* statement;
extern ExMessage msg;
extern int character_nums;
extern int toolbar_choice;

/*****************��ʼ������**********************
* ��������
* ���ܣ�	1. ʹmain.cpp�������ļ�ָ��ָ���ֿ��ļ� 
*		2. ������������е���������(��main.cpp�е�ȫ�ֱ���character_nums)Ϊ0
*		3. ��ʼ������
* ����ֵ����
************************************************/
void init() {
	fpHZK = fopen("res\\HZK48S", "rb");
	if (fpHZK == NULL) {
		perror("init(): ��ȡ�ļ�HZK48Sʧ�ܣ�\n");
		return;
	}

	character_nums = 0;


	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);

	//initgraph(WINDOW_WIDTH, WINDOW_HEIGHT, EX_SHOWCONSOLE);

}

/*************�ӿ���̨��ȡ�����ַ�������***************
* ��������
* ���ܣ�	1. �ӿ���̨��ȡ����ĺ����ַ���
*		2. ���������ַ�����С����ռ䣬��ʹȫ�ֱ���statementָ�������ַ��ṹ������
* ����ֵ����
******************************************************/
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

/*********�ӶԻ����ȡ�����ַ�������**************
* ��������
* ���ܣ�	1. ͨ��һ���Ի����ȡ���뺺���ַ���
*		2. ���������ַ�����С����ռ䣬��ʹȫ�ֱ���statementָ�������ַ��ṹ������
* ����ֵ����
*/
void statement_input_inputbox() {
	char buffer[50];
	char str[] = "���������ӡ�ַ�����";
	InputBox((LPTSTR)buffer, 50, (LPTSTR)str);

	size_t nums = strlen(buffer) / 2;
	character_nums = (int)nums;

	statement = (Statement*)malloc(sizeof(Statement) * nums);
	lattices = (Lattice*)malloc(sizeof(Lattice) * nums);

	for (size_t i = 0; i < nums; i++) {
		strncpy(statement[i].character, buffer + i * 2, 2);
		statement[i].character[2] = '\0';
	}
}

/******�빤�������л��й�***********
* ������	1. button_top_left_x����ť�����Ͻǵ�x����
*		2. button_top_left_y����ť�����Ͻǵ�y����
*		3. choice��������ѡ��
* ���ܣ�ʵ�ֶ�ȫ�ֱ���toolbar_choice �ĸ��ģ����л�����
* ����ֵ����
**********************************/
void choose_tool(int button_top_left_x, int button_top_left_y, int choice) {
	if (msg.x > button_top_left_x && msg.x < button_top_left_x + BUTTON_WIDTH && msg.y > button_top_left_y && msg.y < button_top_left_y + BUTTON_HEIGHT) {
		linger_effect(button_top_left_x, button_top_left_y, BUTTON_WIDTH, BUTTON_HEIGHT, LIGHTBLUE);

		if (msg.message == WM_LBUTTONDOWN) {
			toolbar_choice = choice;
		}
	}

}

/********�������������*************
* ��������
* ���ܣ�ʵ�ֶԳ��������Ĵ����رմ��ں��ͷſ��ٶ����ڴ�
* ����ֵ����
*/
void closing() {

	closegraph();

	fclose(fpHZK);
	fpHZK = NULL;
	
	free(statement);
	free(lattices);
}