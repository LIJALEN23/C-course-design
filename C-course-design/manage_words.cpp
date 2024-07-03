/**************************************
* 
*			处理中文字符串函数的实现
* 作者：lijalen
* 邮箱：lijalen@outlook.com
* 
* 
*/
#include "functions.h"

extern FILE* fpHZK;

extern Lattice* lattices;
extern Statement* statement;
extern int character_nums;

extern unsigned char buffer[LATTICE][BYTES_PER_LINE];
extern unsigned char key[8];

/******通过一个中文字符从HZK中算出该字符对应的字符*******
* 参数：1. character：指向一个汉字的数组
* 功能：从字库文件中读取一个给定汉字的点阵数据
* 返回值：无 
****************************************************/
void read_character(char* character) {
	int offset = (94 * (unsigned int)((unsigned char)character[0] - 0xa0 - 1 - 15) + ((unsigned char)character[1] - 0xa0 - 1)) * SIZE;
	fseek(fpHZK, offset, SEEK_SET);
	fread(buffer, 1, SIZE, fpHZK);
}

/*********通过缓冲区算出的字符生成对应的字符点阵*****************
* 参数：1. lattice：指向点阵字符结构体数组的指针
* 功能：将缓冲区中的点阵数据转换为表示字符的二维数组，即该点阵字符的结构体中的二维数组
* 返回值：无
*/
void generate_font_patterns(Lattice* lattice) {
	int flag;

	for (int i = 0; i < LATTICE; i++) {
		for (int j = 0; j < BYTES_PER_LINE; j++) {
			for (int k = 0; k < 8; k++) {
				flag = buffer[i][j] & key[k];
				if (flag)
					lattice->lattice[i][j * 8 + k] = 1;
				else
					lattice->lattice[i][j * 8 + k] = 0;
			}
		}
	}
}

/************生成转置字模***************
* 参数：1. lattice：指向点阵字符结构体数组的指针
* 功能：将缓冲区中的点阵数据转换为表示字符的二维数组(转置的)，即该点阵字符的结构体中的二维数组
* 返回值：无
*/
void generate_transposed_font_patterns(Lattice* lattice) {
	int flag;
	for (int i = 0; i < LATTICE; i++) {
		for (int j = 0; j < BYTES_PER_LINE; j++) {
			for (int k = 0; k < 8; k++) {
				flag = buffer[i][j] & key[k];	//使用按位与操作检查第 k 行第 j 个字节的第 i 位是否被设置。
				if (flag)
					lattice->lattice[j * 8 + k][i] = 1;
				else
					lattice->lattice[j * 8 + k][i] = 0;
			}
		}
	}
}

/*********算出将整个字符数组的每个字符的字符矩阵***************
* 参数：无
* 功能：将输入的所有中文字符转化为字符矩阵
* 返回值：无
*/
void generate_lattices() {
	int lattices_nums = character_nums;

	for (int i = 0; i < lattices_nums; i++) {
		read_character(statement[i].character);
		generate_font_patterns(&(lattices[i]));
	}
}