/********************************************
*		功能性函数的实现
* 作者：lijalen 
* 邮箱：lijalen23@outlook.com
*/
#include "functions.h"

extern FILE* fpHZK;

extern Lattice* lattices;
extern Statement* statement;
extern ExMessage msg;
extern int character_nums;
extern int toolbar_choice;

/*****************初始化函数**********************
* 参数：无
* 功能：	1. 使main.cpp声明的文件指针指向字库文件 
*		2. 设置输入语句中的文字数量(即main.cpp中的全局变量character_nums)为0
*		3. 初始化窗口
* 返回值：无
************************************************/
void init() {
	fpHZK = fopen("res\\HZK48S", "rb");
	if (fpHZK == NULL) {
		perror("init(): 读取文件HZK48S失败！\n");
		return;
	}

	character_nums = 0;


	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);

	//initgraph(WINDOW_WIDTH, WINDOW_HEIGHT, EX_SHOWCONSOLE);

}

/*************从控制台读取中文字符串函数***************
* 参数：无
* 功能：	1. 从控制台读取输入的汉字字符串
*		2. 根据输入字符串大小分配空间，并使全局变量statement指向中文字符结构体数组
* 返回值：无
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

/*********从对话框读取中文字符串函数**************
* 参数：无
* 功能：	1. 通过一个对话框读取输入汉字字符串
*		2. 根据输入字符串大小分配空间，并使全局变量statement指向中文字符结构体数组
* 返回值：无
*/
void statement_input_inputbox() {
	char buffer[50];
	char str[] = "请输入需打印字符串：";
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

/******与工具栏的切换有关***********
* 参数：	1. button_top_left_x：按钮的左上角的x坐标
*		2. button_top_left_y：按钮的左上角的y坐标
*		3. choice：做出的选择
* 功能：实现对全局变量toolbar_choice 的更改，以切换界面
* 返回值：无
**********************************/
void choose_tool(int button_top_left_x, int button_top_left_y, int choice) {
	if (msg.x > button_top_left_x && msg.x < button_top_left_x + BUTTON_WIDTH && msg.y > button_top_left_y && msg.y < button_top_left_y + BUTTON_HEIGHT) {
		linger_effect(button_top_left_x, button_top_left_y, BUTTON_WIDTH, BUTTON_HEIGHT, LIGHTBLUE);

		if (msg.message == WM_LBUTTONDOWN) {
			toolbar_choice = choice;
		}
	}

}

/********程序结束处理函数*************
* 参数：无
* 功能：实现对程序结束后的处理，关闭窗口和释放开辟堆区内存
* 返回值：无
*/
void closing() {

	closegraph();

	fclose(fpHZK);
	fpHZK = NULL;
	
	free(statement);
	free(lattices);
}