#include <stdio.h>

int input[6][3] = { NULL, };

int main(void)
{
	int test_case, T, N;
	int i, j, k;
	
	freopen("input.txt", "r", stdin);
	
	scanf(" %d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf(" %d", &N);
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < 3; j++)
			{
				scanf(" %d", &input[i][j]);
			}
		}

		for (i = 0; i < N; i++)
		{
			in
		}



		printf("#%d", test_case);
	}
	return 0; //��������� �ݵ�� 0�� �����ؾ� �մϴ�.
}