//N_QUEEN Backtracking

#include <stdio.h>

#define M 13
int sc[M + 1], dr[M * 2 + 1], dl[M * 2 + 1], cnt;
int N;
int chess[10][10];

int check(int x, int y)
{
	int i, j;

	for (i = x; i < N; i++) // row-right
	{
		if (chess[y][i] == 1)
			return 0;
	}
	for (i = x; i >= 0; i--) // row-left
	{
		if (chess[y][i] == 1)
			return 0;
	}
	for (i = y; i < N; i++) //column-down
	{
		if (chess[i][x] == 1)
			return 0;
	}
	for (i = y; i >= 0; i--) //column-up
	{
		if (chess[i][x] == 1)
			return 0;
	}
	i = x; j = y;
	//i++; j++;
	while (++i < N && ++j < N) //loginal right-down
	{
		if (chess[j][i] == 1)
			return 0;
	}
	i = x; j = y;
	//i--; j--;
	while (--i >= 0 && --j >= 0) //loginal left-up
	{
		if (chess[j][i] == 1)
			return 0;
	}
	i = x; j = y;
	//i++; j--;
	while (++i < N && --j >= 0) //loginal right-up
	{
		if (chess[j][i] == 1)
			return 0;
	}
	i = x; j = y;
	//i--; j++;
	while (--i >= 0 && ++j < N) //loginal left-down
	{
		if (chess[j][i] == 1)
			return 0;
	}

	return 1;
}

void nqueen(int lv)
{
	int i, j;

	if (lv == N)
		cnt++;

	for (i = lv - 1; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (check(i, j) == 1)
			{
				chess[i][j] = 1;
				nqueen(lv + 1);
				chess[i][j] = 0;
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	nqueen(1);
	printf("%d", cnt);
}
