#include <stdio.h>

int trainlen[100] = { 0, };
int trainlight[100] = { 0, };
int trainarray[100] = { 0, };

int check(int cnt, int tunnellen)
{
	int i, j;
	int pass;

	pass = 0;

	for (i = 0; i < cnt; i++)
	{
		for (j = 0; j < tunnellen; j++)
		{
			if (trainarray[i + j] == 1)
				pass = 1;
		}
		if (!pass)
		{
			break;
		}
	}
}

int main(void)
{
	int test_case, T, N, H;
	int i,j,k;
	int cnt, pass;
	
	freopen("input.txt", "r", stdin);
	
	scanf(" %d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d ", &N, &H);

		for (i = 0; i < N; i++)
		{
			scanf("%d ", &trainlen[i]);
		}
		for (i = 0; i < N; i++)
		{
			scanf("%d ", &trainlight[i]);
		}

		cnt = 0;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < trainlen[i]; j++)
			{
				trainarray[cnt++] = trainlight[i];
			}
		}

		check(cnt, H);

		printf("#%d\n", test_case);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}