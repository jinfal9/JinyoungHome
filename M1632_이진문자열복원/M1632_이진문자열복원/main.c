#include <stdio.h>

#define MAX 81
int cnt, myexit;
int visited[MAX] = { 0, };
int input[MAX] = { 0, };
int out[MAX] = { 0, };
int comb[MAX][2] = { 0, };
char str[MAX] = { NULL, };

void init(void)
{
	int i;

	for (i = 0; i < MAX; i++)
	{
		visited[i] = 0;
		input[i] = 0;
		out[i] = 0;
		comb[i][0] = -1;
		comb[i][1] = -1;
		str[i] = NULL;
	}
}

int DFS(int in)
{
	int i;

	if (myexit)
		return;

	if (in >= cnt)
	{
		for (i = 0; i < cnt; i++)
		{
			if (out[i] == 1)
			{
				comb[i][0] = 0;
				comb[i][1] = 0;
			}
			else if (out[i] == 2)
			{
				comb[i][0] = 0;
				comb[i][1] = 1;
			}
			else if (out[i] == 3)
			{
				comb[i][0] = 1;
				comb[i][1] = 0;
			}
			else if (out[i] == 4)
			{
				comb[i][0] = 1;
				comb[i][1] = 1;
			}
		}

		str[0] = comb[0][0] + '0';
		for (i = 0; i < cnt - 1; i++)
		{
			if (comb[i][1] != comb[i + 1][0])
			{
				return;
			}
			else
			{
				str[i+1] = comb[i + 1][0] + '0';
			}
		}
		str[cnt] = comb[cnt - 1][1] + '0';
		myexit = 1;
	}
	else
	{
		for (i = 0; i < cnt; i++)
		{
			if (visited[i] == 0)
			{
				out[in] = input[i];
				visited[i] = 1;
				DFS(in + 1);
				if (myexit)
					return;
				visited[i] = 0;
			}
		}
	}
}

int main(void)
{
	int test_case, T, n1, n2, n3, n4;
	int i,j,k;
	int num;
	
	freopen("1_input.txt", "r", stdin);
	
	scanf(" %d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d %d %d ", &n1, &n2, &n3, &n4);
		init();
		cnt = 0;
		myexit = 0;

		for (i = 0; i < n1; i++)
		{
			input[cnt++] = 1;
		}
		for (i = 0; i < n2; i++)
		{
			input[cnt++] = 2;
		}
		for (i = 0; i < n3; i++)
		{
			input[cnt++] = 3;
		}
		for (i = 0; i < n4; i++)
		{
			input[cnt++] = 4;
		}

		DFS(0);

		if (myexit)
		{
			printf("#%d %s\n", test_case, str);
		}
		else
		{
			printf("#%d impossible\n", test_case);
		}
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
