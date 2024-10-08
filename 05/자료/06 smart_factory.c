#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000 // 10의 승수 만큼 감소/증가 시켜 실험해볼 것
#define DVI 18    // 나눗셈 상수 정의
int black_cnt, red_cnt, blue_cnt, err_val, error_cnt, error_percent, total_cnt;

int main()
{
	srand(time(NULL));
	

	for (int i = 0; i < MAX; i++)
	{

		int rand1 = rand();


		printf("%03d개 볼펜생산 -> 볼펜번호%d\n\n", i, rand1);

		if (rand1 % DVI == 0)
			red_cnt++;

		if (rand1 % DVI == 1)
			blue_cnt++;

		if (rand1 % DVI == 2)
			err_val++;

		if ((rand1 % DVI >= 3) && (rand1 % DVI <= DVI - 1))
			black_cnt++;

	}

	const double error_percent =  err_val / 100000 * 100; // 5%의 불량률

	total_cnt = black_cnt + red_cnt + blue_cnt + err_val;

	printf("\n\n총생산볼펜 %d=> 검%d, 빨%d, 파%d, 불량품%d \n\n", total_cnt, black_cnt, red_cnt, blue_cnt, err_val);
	printf("불량률%.03lf%%\n\n", error_percent);

	return 0;
}