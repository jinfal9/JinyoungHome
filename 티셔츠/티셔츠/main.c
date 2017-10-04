#include <stdio.h>

int candidate[100] = { 0, };
int input[3][100] = { { NULL, }, };
int totcnt = 0;

int recur(int num)
{
	int i, cnt;

	cnt = 0;

	for (i = 0; i < num; i++)
	{
		if (candidate[i] == input[0][num - 1])
		{
			;
		}
		else if (candidate[i] == input[1][num - 1])
		{
			;
		}
		else if (candidate[i] == input[2][num - 1])
		{
			;
		}
		else
		{
			candidate[cnt] = i;
			cnt++;
			totcnt++;
		}
	}
	recur(num - 1);
	return totcnt;
}

int main(void)
{
	int test_case, T, N;
	int i, j;

	freopen("input.txt", "r", stdin);
	
	scanf(" %d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf(" %d", &N);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < N; j++)
			{
				scanf(" %d", &input[i][j]);
			}
			candidate[i] = i + 1;
		}

		recur(N);

		printf("#%d", test_case);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}