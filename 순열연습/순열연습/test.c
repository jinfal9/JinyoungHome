#include <stdio.h>
int input[5] = { 1,2,3,4,5 };
int out[5] = { 0, };

void perm(int in)
{
	int i, j, temp;

	if (in > 5)
	{
		for (i = 0; i < 5; i++)
		{
			printf("%d", out[i]);
		}
	}
	else
	{
		for (j = in; j < 5; j++)
		{
			temp = input[in];
			input[in] = input[j];
			input[j] = temp;
		}
	}

}

main()
{
	perm(0);
}