#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char word[40000][100]; //단어 목록 배열
int num[40000] = { 0, }; //단어 개수 배열

int main(int argc, char* argv[])
{
	const char delimiters[] = " @&^!\"#%%$\'()*+,-./<>{}[]~`_=|?;:\n\t\\";
	char str[6000]; //한 줄 읽을거
	
	int total = 0;
	int num_word = 0; //단어 목록 배열
	
	FILE* fp1, * fp2;

	if ((fp1 = fopen(argv[1], "r")) == NULL) {
		printf("파일 열기에 실패했습니다.");
		return 0;
	}
	if ((fp2 = fopen(argv[2], "wt")) == NULL) {
		printf("파일 생성 혹은 쓰기에 실패했습니다.");
		return 0;
	}

	while (fgets(str, sizeof(str), fp1)) { 
		char* token = strtok(str, delimiters);
		while (token != NULL)
		{
			_strlwr(token);

			int flag = 0;

			for (int i = 0; i < num_word; i++) {
				if (!strcmp(token, word[i])) {
					num[i] = num[i] + 1;
					flag++;
					break;
				}
			}

			if (flag == 0) {
				strcpy(word[num_word], token); //단어 목록 배열에 추가
				num[num_word] = num[num_word] + 1;
				num_word++;
			}
			token = strtok(NULL, delimiters);
			total++;
		}
	}

	for (int i = 0; i < num_word; i++) {
		fprintf(fp2, "[%04d] %s (%d)\n", i + 1, word[i], num[i]);
	}
	fprintf(fp2, "[total] %04d", total);


}
