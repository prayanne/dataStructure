#define _CRT_SECURE_NO_WARRINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int factorial(int n, FILE* p);
int factorial_iter(int n, FILE* p);
// 시간 측정함수 리스트 *
int main()
{
    FILE* p2;
    unsigned int result1;
    unsigned int result2;
    int num = 10;

    p2 = fopen("output.txt", "a+");

    //scanf("#d", &num);
    result1 = factorial(num, p2);
    fprintf(stdout, "순환: %u\n", result1);
    fprintf(p2, "순환: %u\n", result1);

    result2 = factorial_iter(num, p2);
    fprintf(stdout, "순환: %u\n", result2);
    fprintf(p2, "순환: %u\n", result2);

    fprintf(p2, "==================");
    fclose(p2);
    system("notepad.exe output.txt");
    return 0;
}


int factorial(int n, FILE* p)
{
    fprintf(stdout, "factorial(%u)\n", n);
    fprintf(p, "factorial(%u)\n", n);

    if (n <= 1) return(1);
    else return (n * factorial(n - 1, p));
}


int factorial_iter(int n, FILE* p)
{ 

    int i, result = 1;
    for (i = 1; i <= n; i++)
    {
        fprintf(p, "%u\n", result);
        result = result * i;
    }
     return(result);
}