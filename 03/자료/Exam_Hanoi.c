#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#define MAX 4
FILE* p; //파일 포인터 선언==> 전역 변수로 선언, 총 연산횟수 카운트 하기, 실행시간
FILE* f;
int i = 0;
void hanoi_tower(int, char, char, char);//함수의 리스트, 변수의 이름을 유연화
int main(void)//메인 함수의 위치는 함수의 리스트 밑에
{
    clock_t start, stop;//시간을 저장할 변수 선언
    double  duration;//런타임을 저장할 함수
    p = fopen("log.txt", "a+");//로그 파일
    f = fopen("result.txt", "a+");//결과 파일(데코 있음)
    start = clock();// 측정 시작
    hanoi_tower(MAX, 'A', 'B', 'C', p, f);
    stop = clock();// 측정 종료
    duration = (double)(stop - start) / CLOCKS_PER_SEC;//실제 시간을 얻기위해 상수 CLOCKS_PER_SEC로 나눠준다
    fprintf(f, "---원판의 개수 %d개, 총연산 %02d회, 실행시간 %.2lf초---\n\n", MAX, i, duration);
    system("notepad.exe log.txt");//메모장 프로그램 실행
    //system("notepad.exe result.txt");//메모장 프로그램 실행
    return 0;
}
void hanoi_tower(int n, char from, char tmp, char to, FILE *p, FILE *f)
{
    if (n == 1)
    {
        i++;
        fprintf(p, "%02d %c %c\n", i, from, to);//로그 파일에 저장
        fprintf(f, "%02d 원판 1을 %c 에서 %c으로 옮긴다.\n", i, from, to);//결과 파일에 저장
        fprintf(stdout, "%02d 원판 1을 %c 에서 %c으로 옮긴다.\n", i, from, to);
    }
    else
    {
        hanoi_tower(n - 1, from, to, tmp, p, f);
        i++;
        fprintf(p, "%02d %d % c % c\n", i, n, from, to);//로그 파일에 저장
        fprintf(f, "%02d 원판 %d을 % c에서 % c으로 옮긴다.\n", i, n, from, to);//결과 파일에 저장
        fprintf(stdout, "%02d 원판 %d을 %c에서 %c으로 옮긴다.\n", i, n, from, to);
        hanoi_tower(n - 1, tmp, from, to, p, f);
    }
}