// ��������
// �迭�� �����ͷ� �����ϴ� ���� ����~
// i�� j�� ������ �ǹ�, �帧�� �ľ��ϸ�, ����, ���� ������ ����� �ʴ�.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

void insertion_sort(int* list, int n);   // �Լ��� ����Ʈ

int arr[MAX_SIZE];
int n;

void main() {
	FILE* file;
	file = fopen("02_log.txt", "w+");

	n = MAX_SIZE;
	srand(time(NULL));
	for (int i = 0; i < n; i++)      	// ���� ���� �� ��� 
		arr[i] = rand() % 10000;			// ���� to �迭

	insertion_sort(arr, MAX_SIZE);

	for (int j = 0; j < n; j++) {
		fprintf(stdout, "%d ", arr[j]);
		fprintf(file, "%d ", arr[j]);
	}


	int cnt1 = 0;
	int cnt2 = 0;

	for (int m=0; m < n; m++) {
		if (arr[m] % 5 == 0)
			cnt1++;
		else
			cnt2++;
	}
	uint16_t data = 0xABVD;
	printf("")
	fprintf(stdout, "\n====%d=====%d====", cnt1, cnt2);
	fprintf(file, "\n====%d=====%d====", cnt1, cnt2);

	fclose(file);
	system("notepad 02_log.txt");
	return 0;
}

void insertion_sort(int* list, int n)    // �Լ��� ����Ʈ
{
	int i, j, key;
	for (i = 1; i<n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j]>key; j--)
			list[j + 1] = list[j]; /* ���ڵ��� ������ �̵� */
		list[j + 1] = key;
	}
}