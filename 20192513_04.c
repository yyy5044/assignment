#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <math.h>

void signiture(fp) {
	fputs("********************************************************\n", fp);
	fputs("�����������������������������\n", fp);
	fputs("�����������������������������\n", fp);
	fputs("�����������������������������\n", fp);
	fputs("�����������������������������\n", fp);
	fputs("�����������������������������\n", fp);
	fputs("�����������������������������\n", fp);
	fputs("Oh Yangho\n", fp);
	fputs("Student ID : 20192513\n", fp);
	fputs("********************************************************\n", fp);
}

int main(int argc, char* argv[]) {

	FILE* fp = NULL;
	fp = fopen(argv[1], "w");

	int any = argc - 2; //������ ����(���α׷� �̸� �� ��)
	int num = pow(2.0, any); //2�� ������ ���� ����

	int arr[10] = { 0, }; //�ִ� 10���� ���Ҹ� ���� �� ����
	int binary; //������ - ���������� �ٲٱ� ���� �ʿ��� ����

	int number = 2; //��ȣǥ�� ����ϱ� ���� ����
	char emptyset = 155; //�������� ASCII

	char str_num[64];

	if (fp == NULL)
	{
		printf("���� ���⿡ �����߽��ϴ�.\n");
	}
	else
	{
		printf("���� ���⿡ �����߽��ϴ�.\n");

		//���α׷�
		fputs("[0001] \u00f8\n", fp);

		for (int j = num - 1; j > 0; j--) {

			//�������� ���������� �ٲپ arr �迭�� �Ųٷ� ����ִ� ���� (����Ʈ���� ���)
			for (int i = 9; i >= 0; i--)
			{
				binary = num - j >> i;

				if (binary & 1)
				{
					arr[9 - i] = 1;
				}
				else
				{
					arr[9 - i] = 0;
				}

			}

			//������ ������ ���� (������ ���� - 1)��ŭ�� �޸��� ����ϱ� ���� ���� �� ��
			int tmp = 0;
			int count = 0;

			//������ ������ ���� ����
			for (int i = 0; i < any; i++) {

				if (arr[9 - i] == 1) {
					tmp = tmp + 1;
				}
			}

			//��ȣǥ�� ����ϱ� ���� ����

			if (number < 10) {
				sprintf(str_num,"[000%d] ", number);
				fputs(str_num, fp);
			}
			if (number >= 10 && number < 100) {
				sprintf(str_num,"[00%d] ", number);
				fputs(str_num, fp);
			}
			if (number >= 100 && number < 1000) {
				sprintf(str_num,"[0%d] ", number);
				fputs(str_num, fp);
			}
			if (number >= 1000 && number < 10000) {
				sprintf(str_num,"[%d] ", number);
				fputs(str_num, fp);
			}

			//powerset ���
			for (int i = 0; i < any; i++) {

				if (arr[9 - i] == 1) {
					count = count + 1;
					sprintf(str_num,"%s", argv[i + 2]); //powerset ���
					fputs(str_num, fp);

					if (count < tmp) {
						fputs(", ", fp); //������ �������� �ϳ� ���� ������ �޸��� ���
					}
				}

				if (i == any - 1) {
					fputs("\n", fp); //������ �׿��� �ٹٲ�
				}
			}

			number = number + 1;

		}

		signiture(fp);
	}
}
