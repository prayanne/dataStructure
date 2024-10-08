#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000 // 10�� �¼� ��ŭ ����/���� ���� �����غ� ��
#define DVI 18    // ������ ��� ����
int black_cnt, red_cnt, blue_cnt, err_val, error_cnt, error_percent, total_cnt;

int main()
{
	srand(time(NULL));
	

	for (int i = 0; i < MAX; i++)
	{

		int rand1 = rand();


		printf("%03d�� ������� -> �����ȣ%d\n\n", i, rand1);

		if (rand1 % DVI == 0)
			red_cnt++;

		if (rand1 % DVI == 1)
			blue_cnt++;

		if (rand1 % DVI == 2)
			err_val++;

		if ((rand1 % DVI >= 3) && (rand1 % DVI <= DVI - 1))
			black_cnt++;

	}

	const double error_percent =  err_val / 100000 * 100; // 5%�� �ҷ���

	total_cnt = black_cnt + red_cnt + blue_cnt + err_val;

	printf("\n\n�ѻ��꺼�� %d=> ��%d, ��%d, ��%d, �ҷ�ǰ%d \n\n", total_cnt, black_cnt, red_cnt, blue_cnt, err_val);
	printf("�ҷ���%.03lf%%\n\n", error_percent);

	return 0;
}