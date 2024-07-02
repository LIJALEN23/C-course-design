/**************************************
* 
*			���������ַ���������ʵ��
* ���ߣ�lijalen
* ���䣺lijalen@outlook.com
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

/******ͨ��һ�������ַ���HZK��������ַ���Ӧ���ַ�*******
* ������1. character��ָ��һ�����ֵ�����
* ���ܣ����ֿ��ļ��ж�ȡһ���������ֵĵ�������
* ����ֵ���� 
****************************************************/
void read_character(char* character) {
	int offset = (94 * (unsigned int)((unsigned char)character[0] - 0xa0 - 1 - 15) + ((unsigned char)character[1] - 0xa0 - 1)) * SIZE;
	fseek(fpHZK, offset, SEEK_SET);
	fread(buffer, 1, SIZE, fpHZK);
}

/*********ͨ��������������ַ����ɶ�Ӧ���ַ�����*****************
* ������1. lattice��ָ������ַ��ṹ�������ָ��
* ���ܣ����������еĵ�������ת��Ϊ��ʾ�ַ��Ķ�ά���飬���õ����ַ��Ľṹ���еĶ�ά����
* ����ֵ����
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

/************����ת����ģ***************
* ������1. lattice��ָ������ַ��ṹ�������ָ��
* ���ܣ����������еĵ�������ת��Ϊ��ʾ�ַ��Ķ�ά����(ת�õ�)�����õ����ַ��Ľṹ���еĶ�ά����
* ����ֵ����
*/
void generate_transposed_font_patterns(Lattice* lattice) {
	int flag;
	for (int i = 0; i < LATTICE; i++) {
		for (int j = 0; j < BYTES_PER_LINE; j++) {
			for (int k = 0; k < 8; k++) {
				flag = buffer[i][j] & key[k];	//ʹ�ð�λ��������� k �е� j ���ֽڵĵ� i λ�Ƿ����á�
				if (flag)
					lattice->lattice[j * 8 + k][i] = 1;
				else
					lattice->lattice[j * 8 + k][i] = 0;
			}
		}
	}
}

/*********����������ַ������ÿ���ַ����ַ�����***************
* ��������
* ���ܣ�����������������ַ�ת��Ϊ�ַ�����
* ����ֵ����
*/
void generate_lattices() {
	int lattices_nums = character_nums;

	for (int i = 0; i < lattices_nums; i++) {
		read_character(statement[i].character);
		generate_font_patterns(&(lattices[i]));
	}
}