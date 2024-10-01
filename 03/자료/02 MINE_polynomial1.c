#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101
typedef struct { 			// ���׽� ����ü Ÿ�� ����
	int degree;			// ���׽��� ����
	float coef[MAX_DEGREE];	// ���׽��� ���
} polynomial;

void print_poly(polynomial p);
polynomial poly_add1(polynomial A, polynomial B);
polynomial poly_min1(polynomial A, polynomial B);
polynomial poly_mul1(polynomial A, polynomial B); // �Լ� ����Ʈ

// ���Լ�
int main(void)
{
	polynomial a = { 5,{ 3, 6, 0, 0, 0, 10 } };
	polynomial b = { 4,{ 7, 0, 5, 0, 1} };
	polynomial add, min, mul;

	print_poly(a);
	print_poly(b);

	printf("------------------------------------------------------------------------------------------------------ \n");
	add = poly_add1(a, b);
	print_poly(add);
	printf("------------------------------------------------------------------------------------------------------ \n");
	min = poly_min1(a, b);
	print_poly(min);
	printf("------------------------------------------------------------------------------------------------------ \n");
	mul = poly_mul1(a, b);
	print_poly(mul);
	printf("------------------------------------------------------------------------------------------------------ \n");

	return 0;
}

// C = A+B ���⼭ A�� B�� ���׽��̴�. ����ü�� ��ȯ�ȴ�. 
polynomial poly_add1(polynomial A, polynomial B)
{
	polynomial C;				// ��� ���׽�
	int Apos = 0, Bpos = 0, Cpos = 0;	// �迭 �ε��� ����
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); // ��� ���׽� ����

	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {  // A�� > B��
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {  // A�� == B��
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else {			// B�� > A��
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

polynomial poly_min1(polynomial A, polynomial B)
{
	polynomial C;				// ��� ���׽�
	int Apos = 0, Bpos = 0, Cpos = 0;	// �迭 �ε��� ����
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); // ��� ���׽� ����

	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {  // A�� > B��
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {  // A�� == B��
			C.coef[Cpos++] = A.coef[Apos++] - B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else {			// B�� > A��
			C.coef[Cpos++] = -B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

polynomial poly_mul1(polynomial A, polynomial B)
{
	static polynomial temp; //��� ������, static������ �����⸸ �ܶ�? ��°��??
	temp.degree = A.degree + B.degree;
	int degree_a = 0;
	while (degree_a <= A.degree+1)
	{
		static polynomial C; // (A�� �ְ�����) * (B�� �ְ�����, ��������, 3��° ��...)�� ����ü C�� ����
		C.degree = A.degree + B.degree;
		int degree_c = 0;
		int degree_b = 0;
		while (degree_b <= A.degree+1)
		{
			C.coef[degree_c] = A.coef[degree_a] * B.coef[degree_b];
			degree_b += 1;
			degree_c += 1;
		}
		C.degree -= degree_a;
		temp = poly_add1(temp, C); //static ����ütemp���ٰ� C�� poly_add1, �Ѱ��� �ٽ� temp�� ����
		degree_a += 1;
	}

	return temp;
}

void print_poly(polynomial p)
{
	for (int i = p.degree; i>0; i--)
		if (p.coef[p.degree - i] < 0) printf(" - %3.1fx^%d", -p.coef[p.degree - i], i);
		else                          printf(" + %3.1fx^%d", p.coef[p.degree - i], i);

	if(p.coef[p.degree] < 0) printf(" - %3.1f \n", -p.coef[p.degree]);
	else                     printf(" + %3.1f \n", p.coef[p.degree]);
	
}

