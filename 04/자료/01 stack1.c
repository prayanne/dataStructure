#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100	// ������ �ִ� ũ��

typedef int element;		// �������� �ڷ���
element  stack[MAX_STACK_SIZE]; // 1���� �迭
int  top = -1;			

// ���� ���� ���� �Լ�
int is_empty()
{
	return (top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}
// ���� �Լ�
void push(element item)
{
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else stack[++top] = item;
}
// ���� �Լ�
element pop()
{
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top--];
}
// ��ũ �Լ�
element peek()
{
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top];
}

int main(void)
{
	element result = 0;
	FILE* p = fopen("file.txt", "w");
	for (int n = 1; n <= 100; n++ ){
	push(n);
	}
	for (int n = 1; n <= 100; n++) {
		result = pop();
		fprintf(p, "%d\n", result);
		printf("%d\n", result);
	}
	fclose(p);
	system("start file.txt");
	return 0;
}