#define _CRT_SECURE_NO_WARNIGS 
#pragma warning(disable:4996)
#include <stdio.h>

#define MAX_AMT  5 // �迭�� ũ�⸦ ����� ����

int arr[MAX_AMT];

int seq_search(int list[], int n, int key); // �Լ� ����1
void input_value();                         // �Լ� ����2


int main(void)
{
	int result;
	input_value();
	result = seq_search(arr, MAX_AMT, 2);
	if (result == -1) // �迭���� ���� ���� ��, result = -1
	{
		printf("�ش��ϴ� ���� �迭 ���� �����ϴ�.");
	}
	else              // �迭���� ���� ���� ��, result != -1
	{
		printf("�ش��ϴ� ���� �迭 ���� �ֽ��ϴ�.\n �ش� ���� �迭 ��, %d��°�� �ֽ��ϴ�.", result + 1);
	}
	return 0;
}

int seq_search(int list[], int n, int key)
{
	int i;
	for (i = 0; i < n; i++)
		if (list[i] == key)
			return i;       /* Ž���� �����ϸ� Ű ���� �ε��� ��ȯ */
	return -1;              /* Ž���� �����ϸ� -1 ��ȯ */
}
void input_value()          // main �Լ����� �˰��� ���� ����, �迭 ��, ���� �ִ� �Լ��̴�.
{
	int n;
	for (n = 0; n < MAX_AMT; n++)
	{
		printf("%d��° ���� �Է��ϼ���.\n", n + 1);
		scanf("%d", &arr[n]);// pragma warning(disable:4996)�� �־� scanf�� ������ �ذ��Ѵ�. |  ��ȯ���� �����ϰų�, ������� �ʾƼ� ������ �����̴�.
	}
}