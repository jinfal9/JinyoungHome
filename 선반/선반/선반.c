#include <stdio.h>

int main(void)
{
	int test_case;
	int T, N, B;
	int i, j, k;
	int input[100], tall[100];
	int sum, min, result;
	
	freopen("1_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	
	/*
	���� ���� �׽�Ʈ ���̽��� ó���ϱ� ���� �κ��Դϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf(" %d %d", &N, &B);
		for (i = 0; i < 100; i++)
		{
			input[i] = 0;
		}
		for (i = 0; i < N; i++)
		{
			scanf(" %d", &input[i]);
		}
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
		printf("#%d %d\n", T, min);
	}
	return 0; //��������� �ݵ�� 0�� �����ؾ� �մϴ�.
}