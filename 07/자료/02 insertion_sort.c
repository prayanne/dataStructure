// ��������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define MAX 100

//void insertion_sort(int*, int);

int main()
{
	FILE* p1 = NULL;  // ��������
	FILE* p2 = NULL;  // �ۼ��� ������ �б�

	clock_t start, end;
	int i, rand1, data;
	
	p1 = fopen("01.txt","w");

	start = clock(); // ���� �ð� ���
	for (int i = 0; i < MAX; i++)
	{

		int rand1 = rand()%10;
		fprintf(p1,"unsorted number %d\n",rand1);		
	}

	fclose(p1);

	p2 = fopen("01.txt", "r");
	while (!feof(p2))
	{
		fscanf(p2, "unsorted number %d\n", &data);
		fprintf(stdout, "unsorted number %d\n", data);		
	}

	end = clock(); // ���� �ð� ���
	printf("\n");
	fclose(p2); // ���� ��Ʈ�� �ݱ�

	printf("�ҿ� �ð� : %.2lf��\n", (double)(end - start) / 1000.0); // �� ���� ���
	system("notepad.exe 01.txt");
	
	return 0;
}
//void insertion_sort(int* list, int n)
//{
//	int i, j, key;
//	for (i = 1; i<n; i++) {
//		key = list[i];
//		for (j = i - 1; j >= 0 && list[j]>key; j--)
//			list[j + 1] = list[j]; /* ���ڵ��� ������ �̵� */
//		list[j + 1] = key;
//	}
//}