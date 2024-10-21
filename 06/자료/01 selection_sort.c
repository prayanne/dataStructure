#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

void selection_sort(int* list, int n);
void selection_sort_re(int* list, int n);


// ���� ����
// 1. ��ȣȭ
// 2. ���� �迭�� Ȱ����, sorting �ϴ� ��, ���ڵ� ����

// rewind �Լ� Ž�� ��

// list�� ���������� ����Ǿ�, ���α׷��� ����� �� ���� �޸𸮿� �ܿ��Ѵ�.
// ����, �迭�� �ּҿ� �����ϸ�, �ش� �迭�� ������ �� �����Ǹ�, �����ͷ� ������ �����ϴ�.
int list[MAX_SIZE];
int n;

// �� O�� n������ ���´�. Ȯ���� �� ��, count�� ����Ʈ
int main(void)
{
	FILE* file;

	file = fopen("01_log.txt", "w+");

	int i;
	n = MAX_SIZE;
	srand(time(NULL));          // 
	for (i = 0; i<n; i++)      	// ���� ���� �� ��� 
		list[i] = rand() % 1000; // ���� �߻� ���� 0~99

	selection_sort_re(list, n); // �������� ȣ�� 
	for (i = 0; i<n; i++){
		printf("%d ", list[i]);
		if (i % 10 == 0){
			printf("\n");
			fprintf(file, "\n");
		}
		fprintf(file, "%d ", list[i]);
	}
	printf("\n");

	fclose(file);
	system("notepad 01_log.txt");

	return 0;
}


void selection_sort(int* list, int n)
{
	// �ּҰ� �ø����� �迭 | 
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) 	// �ּҰ� Ž��
			if (list[j] < list[least]) least = j;
		SWAP(list[i], list[least], temp);
	}
}

void selection_sort_re(int* list, int n)
{
	// �ּҰ� �ø����� �迭 | 
	int i, j, max, temp;
	for (i = MAX_SIZE; i >= n - 1; i--) {
		max = i;
		for (j = i - 1; j > n; j--) 	// �ּҰ� Ž��
			if (list[j] < list[max]) max = j;
		SWAP(list[i], list[max], temp);
	}
}