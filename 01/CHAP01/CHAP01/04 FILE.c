#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    FILE* p; //������ ����Ű�� ������ ����, ���� FILE, ������ ���� p
    p = fopen("logfile.txt", "a+");  //w���� ���� ������ ���� ������ �ۼ��� a+���� �������Ͽ� �߰���
    //D:\\ D����̺꿡 ������ �������
    clock_t start, stop;
    double  duration;
    start = clock();// ���� ����

    for (int i = 0; i < 1000; i++)
    {
        fprintf(stdout, "%d\n", i);
        fprintf(p, "%d\n", i);
    }

    stop = clock();// ���� ����

    duration = (double)(stop - start) / CLOCKS_PER_SEC;
    fprintf(stdout, "����ð��� %lf���Դϴ�.\n", duration);
    fprintf(p, "����ð��� %lf���Դϴ�.\n", duration);

    fclose(p);
    system("notepad.exe logfile.txt");

    return 0;
}