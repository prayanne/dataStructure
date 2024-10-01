#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct 
{
	int student_no;
	char name[MAX_STRING];
	char address[MAX_STRING];
} element;

element  stack[MAX_STACK_SIZE]; // ���ڵ� ������ �迭�� ���� �޸� ���� �Ҵ�

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
// ��ũ�Լ�
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
	FILE* p = fopen("file.txt", "w");

	for (int i = 0; i < MAX_STACK_SIZE; i++) {
		element ie = { 20240000 + i,
			"Honga',
			"Seoul"};
		push(ie);
	}
	

	for (int i = 0; i < MAX_STACK_SIZE; i++) {
		element oe = pop();
		printf("�й�: %d\n", oe.student_no);
		printf("�̸�: %s\n", oe.name);
		printf("�ּ�: %s\n\n", oe.address);
		fprintf(p, "%d ", oe.student_no);
		fprintf(p, "%s ", oe.name);
		fprintf(p, "%s\n", oe.address);
	}
	fclose(p);
	system("start file.txt");
	return 0;
}