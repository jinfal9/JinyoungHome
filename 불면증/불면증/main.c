#include <stdio.h>

int numstore[10] = {0, };

int checkstore(int num)
{
	int i;

	while (num > 0)
	{
		numstore[num % 10] = 1;
		num = num / 10;
	}
	for (i = 0; i < 10; i++)
	{
		if (numstore[i] == 0)
			return 0;
	}
	return 1;
}

int main(void)
{
	int test_case, T, N, num, i, result;
	char C;
	
	freopen("input.txt", "r", stdin);
	
	scanf(" %d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf(" %d", &N);
		for (i = 0; i < 10; i++)
		{
			numstore[i] = 0;
		}
		i = 1;

		while (1)
		{
			num = i * N;
			result = checkstore(num);
			if (result)
				break;
			i++;
		}
		printf("#%d %d\n", test_case, num);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}