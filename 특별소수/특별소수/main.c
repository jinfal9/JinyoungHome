#include <stdio.h>

#define MAX 1000001
int sosunum[MAX] = { 0, };

void get_sosu(void)
{
	int i, j;

	sosunum[1] = 1;
	for (i = 2; i <= MAX; i++)
	{
		for (j = 2; j*i <= MAX; j++)
		{
			sosunum[j*i] = 1;
		}
	}
}

int main(void)
{
	int test_case, T, i, count, temp, tt;
	int SN, ST, ED;
	
	freopen("input.txt", "r", stdin);
	
	scanf(" %d", &T);

	get_sosu();

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d %d", &SN, &ST, &ED);
		count = 0;

		for (i = ST; i <= ED; i++)
		{
			temp = i;
			if (sosunum[i] == 0)
			{
				while (temp > 0)
				{
					if (temp % 10 == SN)
					{
						count++;
						break;
					}
					temp = temp / 10;
				}
			}
		}

		printf("#%d %d\n", test_case, count);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}