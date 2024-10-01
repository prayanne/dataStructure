#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101
typedef struct { 			// 다항식 구조체 타입 선언
	int degree;			// 다항식의 차수
	float coef[MAX_DEGREE];	// 다항식의 계수
} polynomial;

void print_poly(polynomial p);
polynomial poly_add1(polynomial A, polynomial B);
polynomial poly_min1(polynomial A, polynomial B);
polynomial poly_mul1(polynomial A, polynomial B); // 함수 리스트

// 주함수
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

// C = A+B 여기서 A와 B는 다항식이다. 구조체가 반환된다. 
polynomial poly_add1(polynomial A, polynomial B)
{
	polynomial C;				// 결과 다항식
	int Apos = 0, Bpos = 0, Cpos = 0;	// 배열 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); // 결과 다항식 차수

	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {  // A항 > B항
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {  // A항 == B항
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else {			// B항 > A항
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

polynomial poly_min1(polynomial A, polynomial B)
{
	polynomial C;				// 결과 다항식
	int Apos = 0, Bpos = 0, Cpos = 0;	// 배열 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); // 결과 다항식 차수

	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {  // A항 > B항
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {  // A항 == B항
			C.coef[Cpos++] = A.coef[Apos++] - B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else {			// B항 > A항
			C.coef[Cpos++] = -B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

polynomial poly_mul1(polynomial A, polynomial B)
{
	static polynomial temp; //결과 저장통, static없으면 쓰레기만 잔뜩? 어째서??
	temp.degree = A.degree + B.degree;
	int degree_a = 0;
	while (degree_a <= A.degree+1)
	{
		static polynomial C; // (A항 최고차항) * (B항 최고차항, 차고차항, 3번째 항...)을 구조체 C에 저장
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
		temp = poly_add1(temp, C); //static 구조체temp에다가 C를 poly_add1, 한것을 다시 temp로 정의
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

