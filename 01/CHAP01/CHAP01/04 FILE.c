#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    FILE* p; //파일을 가르키는 포인터 변수, 형식 FILE, 포인터 변수 p
    p = fopen("logfile.txt", "a+");  //w모드는 기존 파일을 전부 삭제후 작성함 a+모드는 기존파일에 추가함
    //D:\\ D드라이브에 파일을 만들어줌
    clock_t start, stop;
    double  duration;
    start = clock();// 측정 시작

    for (int i = 0; i < 1000; i++)
    {
        fprintf(stdout, "%d\n", i);
        fprintf(p, "%d\n", i);
    }

    stop = clock();// 측정 종료

    duration = (double)(stop - start) / CLOCKS_PER_SEC;
    fprintf(stdout, "수행시간은 %lf초입니다.\n", duration);
    fprintf(p, "수행시간은 %lf초입니다.\n", duration);

    fclose(p);
    system("notepad.exe logfile.txt");

    return 0;
}