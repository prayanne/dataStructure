#include <stdio.h>

// 펙토리얼 함수 두 건이다. 순환, 반복으로 이루어져있다.

int factorial(int n);
int factorial_iter(int n);

void main(void)
{
    int r1 = factorial(5);
    int r2 = factorial_iter(5);

    printf("순환: %d 반환: %d", r1, r2);

}


int factorial(int n)
{
    printf("factorial(%d)\n", n);
    if (n <= 1) return(1);
    else return (n * factorial(n - 1));
}


int factorial_iter(int n)
{
    int i, result = 1;
    for (i = 1; i <= n; i++)
        result = result * i;
    return(result);
}