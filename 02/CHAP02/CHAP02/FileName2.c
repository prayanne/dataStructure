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

// �ð� �����Լ� ����Ʈ *


int main()
{
    FILE* p;
    int num;
    p = fopen("output2.txt", "w");

    fprintf(stdout, "���� ����: ");
    scanf("%d", &num);

    fprintf(stdout, "csv���� (0 or 1): ");
    scanf("%d", &chk);

    int h = 1;
    for (h = 1; h <= num; h++)
    {
        hanoi(h, p);
    }
    fclose(p);
    p = NULL;              // �ݺ����ȿ��� ������ �� ��, Ȥ�� �߰��� ������ �߻��� ���ΰ� �ִٸ�, �ݺ� �����ϴ� �Լ� �� ������ ���� ���� ���̸�, �̋�, p�� NULL ó�����־�� �������̴�. �ֳ��ϸ� �� p�� ���� �ʴ´�.
    system("notepad.exe output2.txt");


    return 0;
}

void hanoi(int num, FILE*p)
{
    fprintf(stdout, "%d���� �ϳ��� ž �ذ� �˰���\n", num);
    fprintf(p, "%d���� �ϳ��� ž �ذ� �˰���\n", num);

    if (chk == 0) {
        hanoi_tower(num, 'A', 'B', 'C', p);
    }
    else if (chk == 1) {
        hanoi_tower_csv(num, 'A', 'B', 'C', p);
    }
    else {
        printf("csv ���θ� �ٽ� Ȯ���Ͻʽÿ�.\n");
    }
    fprintf(stdout, "===================================\n\n");
    fprintf(p, "===================================\n\n");
    i = 1;
}

void hanoi_tower(int n, char from, char tmp, char to, FILE* p)
{
    if (n == 1)
    {
        fprintf(stdout, "%d: ���� 1�� %c ���� %c���� �ű��.\n", i, from, to);
        fprintf(p, "%d: ���� 1�� %c ���� %c���� �ű��.\n", i, from, to);
        i = i + 1;
    }
    else {
        hanoi_tower(n - 1, from, to, tmp, p);
        fprintf(stdout, "%d: ���� %d�� %c���� %c���� �ű��.\n", i, n, from, to);
        fprintf(p, "%d: ���� %d�� %c���� %c���� �ű��.\n", i, n, from, to);
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
