#include <stdio.h>

#define NUM 5

int input[NUM] = { 1,2,3,4,5 };
int out[NUM] = { 0, };
int visited[NUM] = { 0, };

void dfs (int in)
{
	int i;

	if (in >= NUM)
	{
		for (i = 0; i < NUM; i++)
		{
			printf("%d ", out[i]);
		}
		printf("\n");
	}
	else
	{
		for (i = 0; i < NUM; i++)
		{
			if (visited[i] == 0)
			{
				out[in] = input[i];
				visited[i] = 1;
				dfs(in + 1);
				visited[i] = 0;
			}
		}
	}
}

main()
{
	dfs(0);
}