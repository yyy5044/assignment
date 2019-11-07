#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 

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

int sumNumbers(int* pNumbers, int nIndex) {
	if (nIndex <= 1) {
		return *pNumbers;
	}
	else {
		*pNumbers += sumNumbers(pNumbers + 1, nIndex - 1);
	}
}

int main(int argc, char* argv[]) {

	FILE* fp1, * fp2;
	char str[64];   // change the number appropriately to your program
	// read_file = argv[1]
	// write_file = argv[2]

	// see the usage of r, rt, w, wt, r+, w+
	if ((fp1 = fopen(argv[1], "r")) == NULL) { //fail to open file for read
		printf("fail to open file.");
		return 0;
	}
	if ((fp2 = fopen(argv[2], "wt")) == NULL) { //fail to open file for write
		printf("fail to create file for write.");
		return 0;
	}

	// recursive sum

	int sum[101] = { 0, }; //맨 첫줄 포함 100 + 1
	int count = 0;

	while (fgets(str, sizeof(str), fp1)) {   //읽은 수를 sum 배열에 저장
		sum[count++] = atoi(str);
	}
	
	int     nSum = sumNumbers(&sum[1], sum[0]);

	for (int i = 0; i <= sum[0] - 1; i++) {
		fprintf(fp2, "[%03d] %d\n", sum[0] - i, sum[sum[0] - i]);
	}

	signiture(fp2);

	fclose(fp1);
	fclose(fp2);

	return 0;
}
