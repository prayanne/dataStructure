#define _CRT_SECURE_NO_WARNIGS
#pragma warning(disable:4996)

#include <stdio.h>
#define MAX_ELEMENTS 3
int scores[MAX_ELEMENTS];	// 자료구조, 전역배열, 전역배열은 기본 초기화 값이 0이다. 쓰레기 값이 아님,

int get_max_score(int n);   // 함수의 선언, 정의 | 배열을 넣으면, 최대값이 도출되는 함수이다.
void input_value();         // 함수의 선언, 정의 | 배열에 값을 입력하는 함수이다.
int main(void)
{	
	input_value();          // 배열 값 입력 함수
	int result;             // 함수에서 최대값을 반환하면, 그 값을 저장하는 변수이다.
	result = get_max_score(MAX_ELEMENTS);
	printf("결과:%d\n ",result);// 반환된 최대값을 자연어로 모니터에 출력한다.
	return 0;               // 함수 끝.
}

int get_max_score(int n) 	// 학생의 숫자는 n
{
	int i, largest;
	largest = scores[0];	// 알고리즘
	for (i = 1; i<n; i++)   // 첫 비교군을 넣기 위해 i가 1로 설정되어있다.
	{
		if (scores[i] > largest) 
		{
			largest = scores[i];
		}
	}
	return largest;
}// 입력: n, 처리: 가장 큰 점수 획득, 출력: int(정수)

void input_value()          // main 함수에서 최대값 반환 함수 전에, 배열 내, 값을 넣는 함수이다.
{
	int n;                  // 알고리즘과 반복문 형태를 통일시켰다.
	for (n = 0; n < MAX_ELEMENTS; n++)
	{
		printf("%d번째 수를 입력하세요.\n", n + 1);
		scanf("%d", &scores[n]);// pragma warning(disable:4996)을 넣어 scanf의 오류를 해결한다. |  반환값을 대입하거나, 사용하지 않아서 나오는 오류이다.
	}
}