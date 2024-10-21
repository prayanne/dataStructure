#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

void selection_sort(int* list, int n);
void selection_sort_re(int* list, int n);


// 시험 문제
// 1. 암호화
// 2. 섞인 배열을 활용해, sorting 하는 것, 레코드 단위

// rewind 함수 탐구 필

// list는 전역변수로 선언되어, 프로그램이 종료될 때 까지 메모리에 잔여한다.
// 또한, 배열의 주소에 참조하면, 해당 배열에 접근할 수 있으므르, 포인터로 지정이 가능하다.
int list[MAX_SIZE];
int n;

// 빅 O의 n제곱이 나온다. 확인해 볼 것, count가 포인트
int main(void)
{
	FILE* file;

	file = fopen("01_log.txt", "w+");

	int i;
	n = MAX_SIZE;
	srand(time(NULL));          // 
	for (i = 0; i<n; i++)      	// 난수 생성 및 출력 
		list[i] = rand() % 1000; // 난수 발생 범위 0~99

	selection_sort_re(list, n); // 선택정렬 호출 
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
	// 최소값 올림차순 배열 | 
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) 	// 최소값 탐색
			if (list[j] < list[least]) least = j;
		SWAP(list[i], list[least], temp);
	}
}

void selection_sort_re(int* list, int n)
{
	// 최소값 올림차순 배열 | 
	int i, j, max, temp;
	for (i = MAX_SIZE; i >= n - 1; i--) {
		max = i;
		for (j = i - 1; j > n; j--) 	// 최소값 탐색
			if (list[j] < list[max]) max = j;
		SWAP(list[i], list[max], temp);
	}
}