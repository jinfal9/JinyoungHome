#include <stdio.h>

int main(void)
{
	int test_case, T, len, i, j, k, last;
	char str[100] = { NULL, };
	char out[5][5] = { { '.','.','#','.','.' },
		{ '.','#','.','#','.' },
		{ '#','.','X','.','#' },
		{ '.','#','.','#','.' },
		{ '.','.','#','.','.' } };

	freopen("input.txt", "r", stdin);
	
	scanf(" %d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%s", &str);
		len = 0;
		while (str[++len]);
		
		for (i = 0; i < 5; i++)
		{
			if (len > 1)
			{
				for (j = 0; j < len; j++)
				{
					if (j == len - 1)
					{
						last = 5;
					}
					else
					{
						last = 4;
					}
					for (k = 0; k < last; k++)
					{
						if (i == 2 && k == 2)
						{
							out[i][k] = str[j];
						}
						printf("%c", out[i][k]);
					}
				}
				printf("\n");
			}
			else
			{
				for (k = 0; k < 5; k++)
				{
					if (i == 2 && k == 2)
					{
						out[i][k] = str[0];
					}
					printf("%c", out[i][k]);
				}
				printf("\n");
			}
		}
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}