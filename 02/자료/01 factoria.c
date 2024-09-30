#define _CRT_SECURE_NO_WARRINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int factorial(int n);
int factorial_iter(int n);
// 시간 측정함수 리스트 *
int main()
{
    FILE* p2;
    int result1;
    int result2;
    int num = 3;

    p2 = fpoen("./output.txt", "a+");

    //scanf("#d", &num);
    result1 = factorial(num);
    fprintf(stdout, "%순환: d", result1);
    fprintf(p2, "%순환: d", result1);
    
    result2 = factorial_iter(num);
    fprintf(stdout, "%순환: d", result2);
    fprintf(p2, "%순환: d", result2);

    fprintf(p2, "sdsdsdsdsdsdsddsdsdsdsd\n");
    fclose(p2);
    system("notepad.exe output.txt");
    return 0;
}

int factorial(int n)
{
    fprintf(stdout, "factorial(%d)\n",n);
    if( n <= 1 ) return(1);
    else return (n * factorial(n-1) );
}

int factorial_iter(int n)
{
    int i, result = 1;
    for (i = 1; i <= n; i++)
        result = result * i;
    return(result);
}