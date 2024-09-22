#include<stdio.h>

// �Ǻ���ġ ������ �˰����� ���� �Լ� �� ���� �ִ�.
// ���� ��ȯ, �ݺ��� ������ ¥���� �˰����̴�.
// int r1�� ��� �����Ͽ�, �ּ� ó���ϸ� �� �˰����� �����Ͽ�, Ȯ���� �� �ִ�.

int fib(int n);
int fib_iter(int n);

int main()
{
	//int r1 = fib(25);
    int r1 = fib_iter(25);
	printf("%d\n",r1);
	return 0;
}

// ��ȯ �˰���
int fib(int n)
{
    // ���� ȣ��� �Լ��� ���������� ���
	printf("���� ȣ����Լ� fib(%d)\n", n);
	
    // 0�� 1�� �Ǻ���ġ �������� �ǹ̰� ��������, �ڽ��� return
	if( n==0 ) return 0;
    if( n==1 ) return 1;
	return (fib(n-1) + fib(n-2)); //��ȯ
}

// �ݺ� �˰���
int fib_iter(int n)
{
    // 0�� 1�� �Ǻ���ġ ���� ��, �ڱ� �ڽ��� ���ϱ⿡, ���� ó��
    if (n == 0) return 0;
    if (n == 1) return 1;

    // �ݺ� �˰��� ���� ���� ���� ���� �� �ʱ�ȭ
    int pp = 0;
    int p = 1;
    int result = 0;

    // �Ǻ���ġ ���� �ݺ� �˰��� | ��� �ݺ��Ͽ� SUM�Ѵ�.
    for (int i = 2; i <= n; i++) {
        result = p + pp;
        pp = p;
        p = result;
    }
    return result; // ��ȯ
}