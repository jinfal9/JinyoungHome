#include <stdio.h>

int nationcolor[100];
int input[100][100];
int color[4] = { 1,2,3,4 };

void recursive(int t, int num)
{
	int i, j;

	for (i = 1; i <= 4; i++)
	{
		recursive()

	}
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (input[i][j])
			{
			}
		}
	}
}

int main(void)
{
	int test_case;
	int T, N, B;
	int i, j, k;
	int tall[100];
	int sum, min, result;
	
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf(" %d", &N);
		
		for (i = 0; i < N; i++)
		{
			scanf(" %d", &nationcolor[i]);
		}
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				scanf(" %d", &input[i][j]);
			}
		}

		recursive(0, N);

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (input[i][j])
				{
					if (nationcolor[i] == nationcolor[j])
					{

					}
				}
			}
		}


		/*	
		k = 0;
		min = 0;
		for (i = 0; i < (1<<N) ; i++)
		{
			sum = 0;
			for (j = 0; j < N; j++)
			{
				if (i & 1 << j)
				{
					sum += input[j];
				}
			}
			if (sum > B)
			{
				if (min == 0)
				{
					min = sum;
				}
				if (min > sum)
				{
					min = sum;
				}
			}
		}
		*/
		printf("#%d %d\n", T, min);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}