//N_QUEEN Backtracking

#include<stdio.h>

int input[100];
int blueidx[100];
int bluedur[100];

int main()
{
	int i, j, k, l, m, n, o, num;
	int temp_i, runlength, maxidx;

	freopen("input_blue2.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf(" %d", &input[i]);
	}
	j = 0;
	k = 0;
	for (i = 0; i < num; i++)
	{
		if (input[i] < 0)
		{
			temp_i = i + 1;
			runlength = 1;
			while (input[temp_i] < 0)
			{
				temp_i++;
				runlength++;
			}
			blueidx[j] = i;
			bluedur[j] = runlength;
			j++;
		}
	}
	//get max runlength
	maxidx = blueidx[0];
	for (i = 0; i < j; i++)
	{
		if (maxidx < bluedur[i + 1])
		{
			maxidx = blueidx[i + 1];
		}
	}
	if (maxidx == blueidx[0])
	{
		//all same length
	}
	//calc
	

	printf("Ongoing\n");
}
