#include "functions.h"

extern FILE* fpHZK;

extern Lattice* lattices;
extern Statement* statement;
extern int character_nums;

extern unsigned char buffer[LATTICE][BYTES_PER_LINE];
extern unsigned char key[8];

/*ͨ��һ�������ַ���HZK��������ַ���Ӧ���ַ�*/
void read_character(char* character) {
	int offset = (94 * (unsigned int)((unsigned char)character[0] - 0xa0 - 1 - 15) + ((unsigned char)character[1] - 0xa0 - 1)) * SIZE;
	fseek(fpHZK, offset, SEEK_SET);
	fread(buffer, 1, SIZE, fpHZK);
}

/*ͨ��������������ַ����ɶ�Ӧ���ַ�����*/
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

/*����ת����ģ*/
void generate_transposed_font_patterns(Lattice* lattice) {
	int flag;
	for (int i = 0; i < LATTICE; i++) {
		for (int j = 0; j < BYTES_PER_LINE; j++) {
			for (int k = 0; k < 8; k++) {
				flag = buffer[i][j] & key[k];
				if (flag)
					lattice->lattice[j * 8 + k][i] = 1;
				else
					lattice->lattice[j * 8 + k][i] = 0;
			}
		}
	}
}

/*����������ַ������ÿ���ַ����ַ�����*/
void generate_lattices() {
	int lattices_nums = character_nums;

	for (int i = 0; i < lattices_nums; i++) {
		read_character(statement[i].character);
		generate_font_patterns(&(lattices[i]));
	}
}