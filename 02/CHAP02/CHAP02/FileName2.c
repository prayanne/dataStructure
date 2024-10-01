#define _CRT_SECURE_NO_WARRINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void hanoi(int num, FILE* p);
void hanoi_tower(int n, char from, char tmp, char to, FILE* p);
void hanoi_tower_csv(int n, char from, char tmp, char to, FILE* p);

int chk = 0;
int i = 1;

// 시간 측정함수 리스트 *


int main()
{
    FILE* p;
    int num;
    p = fopen("output2.txt", "w");

    fprintf(stdout, "원판 개수: ");
    scanf("%d", &num);

    fprintf(stdout, "csv여부 (0 or 1): ");
    scanf("%d", &chk);

    int h = 1;
    for (h = 1; h <= num; h++)
    {
        hanoi(h, p);
    }
    fclose(p);
    p = NULL;              // 반복문안에서 파일이 돌 때, 혹은 중간에 오류가 발생할 여부가 있다면, 반복 동작하는 함수 안 파일을 열고 닫을 것이며, 이떄, p를 NULL 처리해주어야 안정적이다. 왜냐하면 이 p가 죽지 않는다.
    system("notepad.exe output2.txt");


    return 0;
}

void hanoi(int num, FILE*p)
{
    fprintf(stdout, "%d개의 하노이 탑 해결 알고리즘\n", num);
    fprintf(p, "%d개의 하노이 탑 해결 알고리즘\n", num);

    if (chk == 0) {
        hanoi_tower(num, 'A', 'B', 'C', p);
    }
    else if (chk == 1) {
        hanoi_tower_csv(num, 'A', 'B', 'C', p);
    }
    else {
        printf("csv 여부를 다시 확인하십시오.\n");
    }
    fprintf(stdout, "===================================\n\n");
    fprintf(p, "===================================\n\n");
    i = 1;
}

void hanoi_tower(int n, char from, char tmp, char to, FILE* p)
{
    if (n == 1)
    {
        fprintf(stdout, "%d: 원판 1을 %c 에서 %c으로 옮긴다.\n", i, from, to);
        fprintf(p, "%d: 원판 1을 %c 에서 %c으로 옮긴다.\n", i, from, to);
        i = i + 1;
    }
    else {
        hanoi_tower(n - 1, from, to, tmp, p);
        fprintf(stdout, "%d: 원판 %d을 %c에서 %c으로 옮긴다.\n", i, n, from, to);
        fprintf(p, "%d: 원판 %d을 %c에서 %c으로 옮긴다.\n", i, n, from, to);
        i = i + 1;
        hanoi_tower(n - 1, tmp, from, to, p);
    }
}

void hanoi_tower_csv(int n, char from, char tmp, char to, FILE* p)
{
    if (n == 1)
    {
        fprintf(stdout, "1 %c %c\n", from, to);
        fprintf(p, "1 %c %c\n", from, to);
        i = i + 1;
    }
    else {
        hanoi_tower_csv(n - 1, from, to, tmp, p);
        fprintf(stdout, "%d %c %c\n", n, from, to);
        fprintf(p, "%d %c %c\n", n, from, to);
        i = i + 1;
        hanoi_tower_csv(n - 1, tmp, from, to, p);
    }
}
