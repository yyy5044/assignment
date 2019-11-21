#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 

int count = 1; //��ȣǥ

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

void swap(char *a, char *b) {
	char tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_arr(FILE *fp2, int n, char arr[]) {
	
	fprintf(fp2, "[%03d] ", count);
	for (int i = 0; i < n; i++) {
		fprintf(fp2, "%c ", arr[i]);
	}
	fprintf(fp2, "\n");

	count++;
}

void permutation(FILE *fp2, char arr[], int n, int k) {

	if (k == n) {
		print_arr(fp2, n, arr); //prefixed �� ���ҵ��� set�� cardinality�� ������ ��
		return;
	}

	for (int i = k; i < n; i++) {
		swap(&arr[i], &arr[k]);
		permutation(fp2, arr, n, k + 1); //�� ���Ҹ� �ѹ��� fix �����ְ� ���������� �̵��ϸ� ���ʷ� �ϳ��� fix ������
		swap(&arr[i], &arr[k]); //������ ��ã�� ���� �� �� �� ����
	}
	
}

int main(int argc, char* argv[]) {

	int i = 0;
	char str[5];
	int num = 0;
	char arr[6]; //maximum 6

	FILE* fp1, * fp2;

	if ((fp1 = fopen(argv[1], "r")) == NULL) {
		printf("���� ���⿡ �����߽��ϴ�.");
		return 0;
	}
	if ((fp2 = fopen(argv[2], "wt")) == NULL) {
		printf("���� ���� Ȥ�� ���⿡ �����߽��ϴ�.");
		return 0;
	}

	while (fgets(str, sizeof(str), fp1) != NULL) {
		if (i == 0) num = atoi(str);
		else arr[i - 1] = str[0];
		i++;
	}

	permutation(fp2, arr, num, 0);
	signiture(fp2);
}