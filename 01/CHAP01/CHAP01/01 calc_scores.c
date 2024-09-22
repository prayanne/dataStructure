#define _CRT_SECURE_NO_WARNIGS
#pragma warning(disable:4996) // pragma warning(disable:4996)을 넣어 scanf의 오류를 해결한다. |  반환값을 대입하거나, 사용하지 않아서 나오는 오류이다.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>       // clock_t, CLOCK_PER_SEC 등을 사용하기 위해 header파일을 불러온다.

#define MAX_ELEMENTS 3
#define MAX_AMT  5          // 배열의 크기를 상수로 정의
#define MAX_INT 100000

int scores[MAX_ELEMENTS];	// 자료구조, 전역배열, 전역배열은 기본 초기화 값이 0이다. 쓰레기 값이 아님,
int arr[MAX_AMT];           // arr 배열 선언

int get_max_score(int n);   // 함수의 선언, 정의 | 배열을 넣으면, 최대값이 도출되는 함수이다.
int search2arr(void);       // 함수의 선언, 정의 | 배열에서 값을 찾는 함수.
void input_value4max();

int seq_search(int list[], int n, int key); // 함수 정의1
void input_value4seq();

int get_time();      // getTime단


FILE* p; //파일을 가르키는 포인터 변수, 형식 FILE, 포인터 변수 p



int main(void)
{	
	p = fopen("logfile.txt", "a+");  //w모드는 기존 파일을 전부 삭제후 작성함 a+모드는 기존파일에 추가함

	input_value4max();      // 배열 값 입력 함수
	int result;             // 함수에서 최대값을 반환하면, 그 값을 저장하는 변수이다.
	result = get_max_score(MAX_ELEMENTS);
	printf("결과:%d\n ",result);// 반환된 최대값을 자연어로 모니터에 출력한다.
	fprintf(p, "최대값은 %d초입니다.\n", result);

	get_time();

	search2arr();
	
	

	fclose(p);
	system("notepad.exe logfile.txt");

	return 0;               // 함수 끝.
}


/*************************************************************************************************************************************************************************************/

// get_max_score 단
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


/*************************************************************************************************************************************************************************************/

// get_time 단

int get_time()
{
	clock_t start, stop;// time.h 
	double  duration;   // start 와 stop의 시간 간격을 나타내는 변수이다.
	start = clock();	// 측정 시작

	for (int i = 0; i < MAX_INT; i++);	// 의미 없는 반복 루프, define MAX_INT로 정의하여, 이후 사후 관리에 유념한다.

	stop = clock();	// 측정 종료
	duration = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("수행시간은 %lf초입니다.\n", duration);

	return 0;
}


/*************************************************************************************************************************************************************************************/

// seq_search단

int search2arr(void)
{
	int result;
	input_value4seq();
	result = seq_search(arr, MAX_AMT, 2);
	if (result == -1) // 배열에서 값이 없을 때, result = -1
	{
		printf("해당하는 값이 배열 내에 없습니다.");
		fprintf(p, "해당하는 값이 배열 내에 없습니다");

	}
	else              // 배열에서 값이 있을 때, result != -1
	{
		printf("해당하는 값이 배열 내에 있습니다.\n 해당 값은 배열 중, %d번째에 있습니다.", result + 1);
		fprintf(p, "해당하는 값이 배열 내에 있습니다.\n 해당 값은 배열 중, % d번째에 있습니다.", result + 1);

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


/*************************************************************************************************************************************************************************************/

// 유틸리티 단
// main 함수에서 최대값 반환 함수 전에, 배열 내, 값을 넣는 함수이다.
void input_value4max()          
{
	int n;                 
	for (n = 0; n < MAX_ELEMENTS; n++)
	{
		printf("%d번째 수를 입력하세요.\n", n + 1);
		scanf("%d", &scores[n]);
	}
}

void input_value4seq()          
{
	int n;
	for (n = 0; n < MAX_AMT; n++)
	{
		printf("%d번째 수를 입력하세요.\n", n + 1);
		scanf("%d", &arr[n]);
	}
}