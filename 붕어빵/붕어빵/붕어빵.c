#include <stdio.h>

int main(void)
{
	int test_case;
	int T, N, M, K;
	int i, j;
	int input[100];
	int result;
	
	freopen("1_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	
	/*
	���� ���� �׽�Ʈ ���̽��� ó���ϱ� ���� �κ��Դϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d %d", &N, &M, &K);
		for (i = 0; i < 100; i++)
		{
			input[i] = 0;
		}
		result = 1;
		for (i = 0; i < N; i++)
		{
			scanf("%d", &input[i]);
		}

		for (i = 0; i < N; i++)
		{
			if (input[i] < M);
			{
				result = 0;
				goto end;
			}
		}
		
		for (i = 0; i < N; i++)
		{
			if (input[i] > M)
			{
				while (input[i] > M)
				{
					M = M * 2;
					Bunga
				}

			}
			{
				result = 0;
				break;
			}
		}

end:
		if (result)
		{
			printf("#%d Possible\n", T);
		}
		else
		{
			printf("#%d Impossible\n", T);
		}


	}
	return 0; //��������� �ݵ�� 0�� �����ؾ� �մϴ�.
}