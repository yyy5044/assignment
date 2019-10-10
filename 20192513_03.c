#include <stdio.h>
#include <math.h>

void signiture() {
	printf("********************************************************\n");
	printf("□■□□□■□□□■■□□□■□□□■□□□■■■■□□\n");
	printf("□□■□■□□□■□□■□□■■□□■□□■□□□□■□\n");
	printf("□□□■□□□□■□□■□□■□■□■□□■□□□□□□\n");
	printf("□□□■□□□□■■■■□□■□■□■□□■□□■■■□\n");
	printf("□□□■□□□□■□□■□□■□□■■□□■□□□■■□\n");
	printf("□□□■□□□□■□□■□□■□□□■□□□■■■□■□\n");
	printf("Oh Yangho\n");
	printf("Student ID : 20192513\n");
	printf("********************************************************\n");
}
int main(int argc, char* argv[]) {
	
	int any = argc - 1; //원소의 개수(프로그램 이름 뺀 것)
	int num = pow(2.0, any); //2의 원소의 개수 제곱
	
	int arr[10] = { 0, }; //최대 10개의 원소를 받을 수 있음
	int binary; //십진법 - 이진법으로 바꾸기 위해 필요한 변수

	int number = 2; //번호표를 출력하기 위한 변수
	char emptyset = 155; //공집합의 ASCII

	printf("[0001] \u00f8\n");

	for (int j = num - 1; j > 0; j--) {

		//십진법을 이진법으로 바꾸어서 arr 배열에 거꾸로 집어넣는 과정 (시프트연산 사용)
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

		//원소의 개수를 세고 (원소의 개수 - 1)만큼의 콤마를 출력하기 위한 변수 두 개
		int tmp = 0;
		int count = 0;

		//원소의 개수를 세는 과정
		for (int i = 0; i < any; i++) {

			if (arr[9 - i] == 1) {
				tmp = tmp + 1;
			}
		}

		//번호표를 출력하기 위한 과정
		if (number < 10) {
			printf("[000%d] ", number);
		}
		if (number >= 10 && number < 100) {
			printf("[00%d] ", number);
		}
		if (number >= 100 && number < 1000) {
			printf("[0%d] ", number);
		}
		if (number >= 1000 && number < 10000) {
			printf("[%d] ", number);
		}

		//powerset 출력
		for (int i = 0; i < any; i++) {

			if (arr[9 - i] == 1) {
				count = count + 1;
				printf("%s", argv[i + 1]); //powerset 출력
		
				if (count < tmp) { 
					printf(", "); //원소의 개수보다 하나 적은 개수의 콤마를 출력
				}
			}
			
			if (i == any - 1) {
				printf("\n"); //마지막 항에서 줄바꿈
			}
		}

		number = number + 1;

	}
	
	signiture();
}