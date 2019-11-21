#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 

int count = 1; //번호표

void signiture(fp) {
	fputs("********************************************************\n", fp);
	fputs("□■□□□■□□□■■□□□■□□□■□□□■■■■□□\n", fp);
	fputs("□□■□■□□□■□□■□□■■□□■□□■□□□□■□\n", fp);
	fputs("□□□■□□□□■□□■□□■□■□■□□■□□□□□□\n", fp);
	fputs("□□□■□□□□■■■■□□■□■□■□□■□□■■■□\n", fp);
	fputs("□□□■□□□□■□□■□□■□□■■□□■□□□■■□\n", fp);
	fputs("□□□■□□□□■□□■□□■□□□■□□□■■■□■□\n", fp);
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
		print_arr(fp2, n, arr); //prefixed 된 원소들이 set의 cardinality와 같아질 때
		return;
	}

	for (int i = k; i < n; i++) {
		swap(&arr[i], &arr[k]);
		permutation(fp2, arr, n, k + 1); //각 원소를 한번씩 fix 시켜주고 오른쪽으로 이동하며 차례로 하나씩 fix 시켜줌
		swap(&arr[i], &arr[k]); //원본을 되찾기 위해 한 번 더 스왑
	}
	
}

int main(int argc, char* argv[]) {

	int i = 0;
	char str[5];
	int num = 0;
	char arr[6]; //maximum 6

	FILE* fp1, * fp2;

	if ((fp1 = fopen(argv[1], "r")) == NULL) {
		printf("파일 열기에 실패했습니다.");
		return 0;
	}
	if ((fp2 = fopen(argv[2], "wt")) == NULL) {
		printf("파일 생성 혹은 쓰기에 실패했습니다.");
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