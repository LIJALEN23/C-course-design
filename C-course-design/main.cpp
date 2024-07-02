/*主程序入口*/

#include "functions.h"

FILE* fpHZK = NULL;		//指向HZK文件的文件指针

Lattice* lattices = NULL;		//存放点阵的点阵结构体数组
Statement* statement = NULL;	//存放中文字符串的中文字符数组
ExMessage msg;
int character_nums;		//要打印的字符串中字符的数量
int toolbar_choice = USER_INPUT;

unsigned char buffer[LATTICE][BYTES_PER_LINE];		//缓冲区，用于存储从字库中读出的点阵数据，LATTICE：点阵，BYTES_PER_LINE：点阵的每行的字节数
unsigned char key[8] = { 0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01 };

int main(void) {

	init();
	while (toolbar_choice != ESCAPE) {
		switch (toolbar_choice) {
		case USER_INPUT:
			user_input_API();
			break;
		case STYLE_1:
			style1_API();
			break;
		case STYLE_2:
			style2_API();
			break;
		case STYLE_3:
			style3_API();
			break;
		case STYLE_4:
			style4_API();
			break;
		case ESCAPE:
			closing;
			break;
		default:
			perror("main函数的switch语句的toolbar_choice出现意外取值！\n");
			system("pause");
			closing;
			return 0;
			break;
		}
	}

	return 0;	
}