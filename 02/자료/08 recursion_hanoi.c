#include <stdio.h>

// 이미 학자들이 알아낸 알고리즘을 기반으로 작성된 코드이다.
// 하노이 탑을 수많은 시행착오 끝에 보니, 특정한 알고리즘을 갖고 있음을 알아 내었다. 이는 아래와 같다.

void hanoi_tower(int n, char from, char tmp, char to)

{	// 아래의 알고리즘은 하노이의 탑의 해답 알고리즘임
	if( n==1 ) printf("원판 1을 %c 에서 %c으로 옮긴다.\n",from,to);
	else {
		hanoi_tower(n-1, from, to, tmp);
		printf("원판 %d을 %c에서 %c으로 옮긴다.\n",n,from,to);
		hanoi_tower(n-1, tmp, from, to);
	}
}
int main(void)
{
	hanoi_tower(4, 'A', 'B', 'C'); // hanoi_tower 함수 호출 
	return 0;
}
