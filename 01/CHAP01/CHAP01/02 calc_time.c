#define _CRT_SECURE_NO_WARNIGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>       // clock_t, CLOCK_PER_SEC 등을 사용하기 위해 header파일을 불러온다.
#define MAX_INT 1000000 // 사후 관리를 위해 상수를 MAX_INT로 설정한다.

int main(void)
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