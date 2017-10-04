#include <stdio.h>

#define MAX 20

char input_n[MAX][MAX] = { NULL, };
char input_k[MAX][MAX] = { NULL, };

void init(void)
{
	int i, j;

	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			input_n[i][j] = NULL;
			input_k[i][j] = NULL;
		}
	}
}

int start(int stx, int sty, int Nnum, int Knum)
{
	int i, j;
	char  tempchar;

	tempchar = input_n[stx][sty];

	if (stx > (Nnum - Knum) || sty > (Nnum - Knum))
	{
		return 0;
	}

	for (i = 0; i < Knum; i++)
	{
		for (j = 0; j < Knum; j++)
		{
			if ((input_k[i][j] == '1'))
			{
				if (input_n[sty + i][stx + j] != tempchar)
				{
					return 0;
				}
			}
			else
			{
				if (input_n[sty + i][stx + j] != 'A')
					return 0;
			}
		}
	}
	return 1;
}

int main(void)
{
	int test_case, T, N, K;
	int i,j,k;
	int result;
	
	freopen("sample_input.txt", "r", stdin);
	
	scanf(" %d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf(" %d %d", &N, &K);

		init();
		result = 0;

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				scanf(" %c", &input_n[i][j]);
			}
		}

		for (i = 0; i < K; i++)
		{
			for (j = 0; j < K; j++)
			{
				scanf(" %c", &input_k[i][j]);
			}
		}

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				result = start(j, i, N, K);
				if (result)
					goto end;
			}
		}

end:
		if(result)
			printf("Possible\n");
		else
			printf("Impossible\n");
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}