#define _CRT_SECURE_NO_WARNIGS 
#pragma warning(disable:4996)
#include <stdio.h>

#define MAX_AMT  5 // 배열의 크기를 상수로 정의

int arr[MAX_AMT];

int seq_search(int list[], int n, int key); // 함수 정의1
void input_value();                         // 함수 정의2


int main(void)
{
	int result;
	input_value();
	result = seq_search(arr, MAX_AMT, 2);
	if (result == -1) // 배열에서 값이 없을 때, result = -1
	{
		printf("해당하는 값이 배열 내에 없습니다.");
	}
	else              // 배열에서 값이 있을 때, result != -1
	{
		printf("해당하는 값이 배열 내에 있습니다.\n 해당 값은 배열 중, %d번째에 있습니다.", result + 1);
	}
	return 0;
}

int seq_search(int list[], int n, int key)
{
	int i;
	for (i = 0; i < n; i++)
		if (list[i] == key)
			return i;       /* 탐색에 성공하면 키 값의 인덱스 반환 */
	return -1;              /* 탐색에 실패하면 -1 반환 */
}
void input_value()          // main 함수에서 알고리즘 적용 전에, 배열 내, 값을 넣는 함수이다.
{
	int n;
	for (n = 0; n < MAX_AMT; n++)
	{
		printf("%d번째 수를 입력하세요.\n", n + 1);
		scanf("%d", &arr[n]);// pragma warning(disable:4996)을 넣어 scanf의 오류를 해결한다. |  반환값을 대입하거나, 사용하지 않아서 나오는 오류이다.
	}
}