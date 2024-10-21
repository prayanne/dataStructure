// 삽입정렬
// 배열은 포인터로 지정하는 것이 좋아~
// i와 j가 가지는 의미, 흐름을 파악하면, 삽입, 선택 정렬은 어렵지 않다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

void insertion_sort(int* list, int n);   // 함수의 리스트

int arr[MAX_SIZE];
int n;

void main() {
	FILE* file;
	file = fopen("02_log.txt", "w+");

	n = MAX_SIZE;
	srand(time(NULL));
	for (int i = 0; i < n; i++)      	// 난수 생성 및 출력 
		arr[i] = rand() % 10000;			// 난수 to 배열

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

void insertion_sort(int* list, int n)    // 함수의 리스트
{
	int i, j, key;
	for (i = 1; i<n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j]>key; j--)
			list[j + 1] = list[j]; /* 레코드의 오른쪽 이동 */
		list[j + 1] = key;
	}
}