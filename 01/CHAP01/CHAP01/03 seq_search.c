#define _CRT_SECURE_NO_WARNIGS 
#include <stdio.h>

#define MAX_AMT = 5

int arr[MAX_AMT]

int main(void)
{
	seq_search(arr, MAX_AMT, 2);
	return 0;
}

int seq_search(int list[], int n, int key)
{
	int i;
	for (i = 0; i < n; i++)
		if (list[i] == key)
			return i;  /* Ž���� �����ϸ� Ű ���� �ε��� ��ȯ */
	return -1;    /* Ž���� �����ϸ� -1 ��ȯ */
}