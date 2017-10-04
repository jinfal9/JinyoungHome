#include <stdio.h>

int main(void)
{
	int test_case, T, A, B, Money;
	int remain, cnt;
	
	freopen("1_input.txt", "r", stdin);
	
	scanf(" %d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf(" %d %d %d", &A, &B, &Money);

		if (A >= B)
		{
			remain = Money%B;
			cnt = Money / B;
		}
		else
		{
			remain = Money%A;
			cnt = Money / A;
		}

		printf("#%d %d\n", test_case, cnt);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}