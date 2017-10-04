//N_QUEEN Backtracking

#include<stdio.h>

char input[100][100];

int main()
{
	int i, j, k, l, m, n, o, num;
	char c;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			scanf(" %c", &input[i][j]);
		}
	}
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			printf("%c", input[i][j]);
		}
		printf("\n");
	}
	c = '.';
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (input[i][j] != '.')
			{
				c = input[i][j];
				if (c == input[i][j + 1])
				{
					if (c == input[i][j + 2])
						goto end;
				}
				else if (c == input[i + 1][j])
				{
					if (c == input[i + 2][j])
						goto end;
				}
				else if (c == input[i + 1][j + 1])
				{
					if (c == input[i + 2][j + 2])
						goto end;
				}
			}
		}
	}
end:
	if (c == '.')
	{
		printf("Ongoing\n");
	}
	else
	{
		printf("%c\n", c);
	}
}
