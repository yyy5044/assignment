#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void signiture() {
	printf("********************************************************\n");
	printf("�����������������������������\n");
	printf("�����������������������������\n");
	printf("�����������������������������\n");
	printf("�����������������������������\n");
	printf("�����������������������������\n");
	printf("�����������������������������\n");
	printf("Oh Yangho\n");
	printf("Student ID : 20192513\n");
	printf("********************************************************\n");
}

int main(int argc, char* argv[]) {
	int sum = 0;

	if (argc > 201) {
		printf("Out of Range!");
	}
	else {
		for (int i = 1; i < argc; i += 2) {
			if (strcmp(argv[i], "+") == 0) {
				sum += atoi(argv[i + 1]);
			}
			else if (strcmp(argv[i], "-") == 0) {
				sum += -1 * atoi(argv[i + 1]);
			}
		}
	}
	printf("%d\n", sum);
	signiture();

	return 0;

}
