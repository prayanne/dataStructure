#include<stdio.h>

// 피보나치 수열의 알고리즘을 지닌 함수 두 건이 있다.
// 각각 순환, 반복의 구조로 짜여진 알고리즘이다.
// int r1을 취사 선택하여, 주석 처리하면 각 알고리즘을 선택하여, 확인할 수 있다.

int fib(int n);
int fib_iter(int n);

int main()
{
	//int r1 = fib(25);
    int r1 = fib_iter(25);
	printf("%d\n",r1);
	return 0;
}

// 순환 알고리즘
int fib(int n)
{
    // 현재 호출된 함수를 가시적으로 출력
	printf("현재 호출된함수 fib(%d)\n", n);
	
    // 0과 1은 피보나치 수열에서 의미가 없음으로, 자신을 return
	if( n==0 ) return 0;
    if( n==1 ) return 1;
	return (fib(n-1) + fib(n-2)); //반환
}

// 반복 알고리즘
int fib_iter(int n)
{
    // 0과 1은 피보나치 수열 상, 자기 자신을 지니기에, 예외 처리
    if (n == 0) return 0;
    if (n == 1) return 1;

    // 반복 알고리즘에 사용될 지역 변수 선언 및 초기화
    int pp = 0;
    int p = 1;
    int result = 0;

    // 피보나치 수열 반복 알고리즘 | 계속 반복하여 SUM한다.
    for (int i = 2; i <= n; i++) {
        result = p + pp;
        pp = p;
        p = result;
    }
    return result; // 반환
}