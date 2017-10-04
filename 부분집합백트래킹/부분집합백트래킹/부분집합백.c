#include <stdio.h>

int temp[100];
int data[3] = { 1,2,3 };

int is_solution(int k, int in)
{
	if (k == in)
		return 1;
	else
		return 0;
}

void process_solution(int a[], int k)
{
	int i;
	printf("{");
	for (i = 1; i <= k; i++)
	{
		if (a[i])
		{
			printf("%d ", data[i-1]);
		}
	}
	printf("}\n");
}

void construct_canidate(int a[], int k, int n, int c[], int *ncanidate)
{
	c[0] = 1;
	c[1] = 0;
	ncanidate[0] = 2;
}

void backtrack(int a[], int k, int input)
{
	int c[3] = { 0, };
	int ncanidate = 0;
	int i = 0;
	int finished;

	if (is_solution(k, input))
	{
		process_solution(a, k);
	}
	else
	{
		k++;
		construct_canidate(a, k, input, c, &ncanidate);
		for (i = 0; i < ncanidate; i++)
		{
			a[k] = c[i];
			backtrack(a, k, input);
		}
	}

}

int main(void)
{
	backtrack(temp, 0, 3);

	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}