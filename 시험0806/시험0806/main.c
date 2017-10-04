#include <stdio.h>

#define MAX 100
int input[MAX][MAX] = { 0, };
int killed[MAX][MAX] = { 0, };
int jumpcnt, killcnt;

void DFS(int x, int y, int num)
{
	int i, k, killflag = 0;
	
	if (jumpcnt >= 3)
	{
		return;
	}
	else
	{
		for (i = x + 1; i < num; i++) //right
		{
			if (input[y][i] == 1 && i + 1 < num)
			{
				for (k = i + 1; k < num; k++)
				{
					if (input[y][k] == 1 && killed[y][k] != 1)
					{
						killcnt++;
						input[y][k] = 0;
						killed[y][k] = 1;
						killflag = 1;
					}
					jumpcnt++;
					DFS(k, y, num);
					jumpcnt--;
					if (killflag == 1)
					{
						input[y][k] = 1;
						killflag = 0;
					}
				}
			}
		}
		for (i = x - 1; i >= 0; i--) //left
		{
			if (input[y][i] == 1 && i - 1 >= 0)
			{
				for (k = i - 1; k >= 0; k--)
				{
					if (input[y][k] == 1 && killed[y][k] != 1)
					{
						killcnt++;
						input[y][k] = 0;
						killed[y][k] = 1;
						killflag = 1;
					}
					jumpcnt++;
					DFS(k, y, num);
					jumpcnt--;
					if (killflag == 1)
					{
						input[y][k] = 1;
						killflag = 0;
					}
				}
			}
		}
		for (i = y + 1; i < num; i++) //down
		{
			if (input[i][x] == 1 && i + 1 < num)
			{
				for (k = i + 1; k < num; k++)
				{
					if (input[k][x] == 1 && killed[k][x] != 1)
					{
						killcnt++;
						input[k][x] = 0;
						killed[k][x] = 1;
						killflag = 1;
					}
					jumpcnt++;
					DFS(x, k, num);
					jumpcnt--;
					if (killflag == 1)
					{
						input[k][x] = 1;
						killflag = 0;
					}
				}
			}
		}
		for (i = y - 1; i >= 0; i--) //up
		{
			if (input[i][x] == 1 && i - 1 >= 0)
			{
				for (k = i - 1; k >= 0; k--)
				{
					if (input[k][x] == 1 && killed[k][x] != 1)
					{
						killcnt++;
						input[k][x] = 0;
						killed[k][x] = 1;
						killflag = 1;
					}
					jumpcnt++;
					DFS(x, k, num);
					jumpcnt--;
					if (killflag == 1)
					{
						input[k][x] = 1;
						killflag = 0;
					}
				}
			}
		}
	}
}

int main(void)
{
	int test_case, T, N;
	int i, j;
	int stx, sty;

	freopen("input.txt", "r", stdin);

	scanf(" %d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf(" %d", &N);

		stx = 0;
		sty = 0;
		jumpcnt = 0;
		killcnt = 0;
		for (i = 0; i < MAX; i++)
		{
			for (j = 0; j < MAX; j++)
			{
				input[i][j] = 0;
				killed[i][j] = 0;
			}
		}

		for(i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				scanf(" %d", &input[i][j]);
			}
		}

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (input[i][j] == 2)
				{
					stx = j;
					sty = i;
					input[i][j] = 0;
				}
			}
		}

		DFS(stx, sty, N);

		printf("#%d %d", test_case, killcnt);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}