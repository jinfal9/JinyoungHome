#include<stdio.h>


int main() 
{
	int i, j, k, l, m, n, o, num, input[6], result[6];

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf(" %d", &input[i]);
		//printf("%d ", input[i]);
	}

	for (i = 0; i < (1<<num); i++)
	{
		printf("{");
		for (j = 0; j < num; j++)
		{
			if (i&(1 << j))
			{
				printf("%d, ", input[j]); 
			}
		}
		printf("}\n");
		
	}
	//printf("%d ", i);

	printf("\n");

}

