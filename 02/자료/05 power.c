#include <stdio.h>

// 거듭 제곱 함수를 두 가지 방법으로 구현한다.
// 1. 순환
// 2. 반복
// 해당 방식을 통해 순환과 반복의 알고리즘 차이를 확인한다.

// 함수 정의
double power(double x, int n);
double slow_power(double x, int n);

void main(void)
{
	// r1은 순환, r2는 반복이다.
	double r1 = slow_power(2, 3);
	double r2 = power(2, 3);

	printf("결과 1은 %.3lf, 결과 2는 %.3lf 입니다.", r1, r2);
}


// 순환 방식의 알고리즘은 거듭 제곱이 짝수일 때와 홀수일 때가 다르다.
// 거듭 제곱이 짝수인 경우 n / 2로 밑수를 제곱, 지수를 반절로 줄여 계산을 수월하게 하고,
// 홀수의 경우, 1을 제하여, 짝수로 계산토록 한 후, 제한 1을 이후에 따로 계산한다.
double power(double x, int n)
{
	if (n == 0) return 1;
	else if ((n % 2) == 0)
		return power(x * x, n / 2);
	else 
		return x * power(x * x, (n - 1) / 2);
}

double slow_power(double x, int n)
{
	int i;
	double result = 1.0;

	for (i = 0; i < n; i++)
		result = result * x;
	return(result);
}




