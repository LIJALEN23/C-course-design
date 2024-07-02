/*���������*/

#include "functions.h"

FILE* fpHZK = NULL;		//ָ��HZK�ļ����ļ�ָ��

Lattice* lattices = NULL;		//��ŵ���ĵ���ṹ������
Statement* statement = NULL;	//��������ַ����������ַ�����
ExMessage msg;
int character_nums;		//Ҫ��ӡ���ַ������ַ�������
int toolbar_choice = USER_INPUT;

unsigned char buffer[LATTICE][BYTES_PER_LINE];		//�����������ڴ洢���ֿ��ж����ĵ������ݣ�LATTICE������BYTES_PER_LINE�������ÿ�е��ֽ���
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
			perror("main������switch����toolbar_choice��������ȡֵ��\n");
			system("pause");
			closing;
			return 0;
			break;
		}
	}

	return 0;	
}