#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#define MAX 4
FILE* p; //���� ������ ����==> ���� ������ ����, �� ����Ƚ�� ī��Ʈ �ϱ�, ����ð�
FILE* f;
int i = 0;
void hanoi_tower(int, char, char, char);//�Լ��� ����Ʈ, ������ �̸��� ����ȭ
int main(void)//���� �Լ��� ��ġ�� �Լ��� ����Ʈ �ؿ�
{
    clock_t start, stop;//�ð��� ������ ���� ����
    double  duration;//��Ÿ���� ������ �Լ�
    p = fopen("log.txt", "a+");//�α� ����
    f = fopen("result.txt", "a+");//��� ����(���� ����)
    start = clock();// ���� ����
    hanoi_tower(MAX, 'A', 'B', 'C', p, f);
    stop = clock();// ���� ����
    duration = (double)(stop - start) / CLOCKS_PER_SEC;//���� �ð��� ������� ��� CLOCKS_PER_SEC�� �����ش�
    fprintf(f, "---������ ���� %d��, �ѿ��� %02dȸ, ����ð� %.2lf��---\n\n", MAX, i, duration);
    system("notepad.exe log.txt");//�޸��� ���α׷� ����
    //system("notepad.exe result.txt");//�޸��� ���α׷� ����
    return 0;
}
void hanoi_tower(int n, char from, char tmp, char to, FILE *p, FILE *f)
{
    if (n == 1)
    {
        i++;
        fprintf(p, "%02d %c %c\n", i, from, to);//�α� ���Ͽ� ����
        fprintf(f, "%02d ���� 1�� %c ���� %c���� �ű��.\n", i, from, to);//��� ���Ͽ� ����
        fprintf(stdout, "%02d ���� 1�� %c ���� %c���� �ű��.\n", i, from, to);
    }
    else
    {
        hanoi_tower(n - 1, from, to, tmp, p, f);
        i++;
        fprintf(p, "%02d %d % c % c\n", i, n, from, to);//�α� ���Ͽ� ����
        fprintf(f, "%02d ���� %d�� % c���� % c���� �ű��.\n", i, n, from, to);//��� ���Ͽ� ����
        fprintf(stdout, "%02d ���� %d�� %c���� %c���� �ű��.\n", i, n, from, to);
        hanoi_tower(n - 1, tmp, from, to, p, f);
    }
}