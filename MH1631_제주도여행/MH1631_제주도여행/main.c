#include <stdio.h>

#define MAX 35
int input[MAX][MAX] = { 0, };
char input_loc[MAX] = { NULL, };
int input_loc_ext[MAX][2] = { -1, };
int visited[MAX] = { 0, };
//char out[MAX] = { NULL, };
int out[MAX] = { 0, };

void init(void)
{
	int i, j;

	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			input[i][j] = 0;
		}
		input_loc[i] = NULL;
		input_loc_ext[MAX][0] = -1;
		input_loc_ext[MAX][1] = -1;
	}
}

int dfs(int in, int cnt, int day)
{
	int i, j;
	int tempin, timesum;;
	
	if (in >= cnt)
	{
		for (i = 0; i < cnt; i++)
		{
			timesum = input[out[i]][out[i+1]]
			out[i]
		}
		return;
	}
	else
	{
		for (i = 0; i < cnt; i++)
		{
			if (visited[i] == 0)
			{
				out[in] = i;
				visited[i] = 1;
				dfs(in + 1, cnt, day);
				visited[i] = 0;
			}
		}
	}
}

int main(void)
{
	int test_case, T, N, M;
	int i,j,k;
	
	freopen("input.txt", "r", stdin);
	
	scanf(" %d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d ", &N, &M);

		init();

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N - 1 - i; j++)
			{
				scanf("%d ", &input[i][j]);
			}
		}

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N - 1 - i; j++)
			{
				scanf("%d ", &input[i][j]);
			}
		}
		for (i = 0; i < N; i++)
		{
			scanf("%1c ", &input_loc[i]);
			if (input_loc[i] != 'A' || input_loc[i] != 'H')
			{
				scanf("%d ", &input_loc_ext[i][0]);
				scanf("%d ", &input_loc_ext[i][1]);
			}
		}

		dfs(0, N, M);

		printf("#%d\n", test_case);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}