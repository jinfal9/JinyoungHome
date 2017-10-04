#include<stdio.h>

char inputbuf[20][15] = { 0, };

int main() 
{
	int tc;
	int i, j, k, l, m, n, o, num;
	FILE* fin;
	char configbin[15] = { 0, };

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf("%s ", &inputbuf[i][0]);
	}

	for (i = 0; i < num; i++)
	{
		sprintf(configbin, "%s.bin", &inputbuf[i][0]);
		fin = fopen(configbin,"w");
		if (fin != NULL)
		{
			fputs(&inputbuf[i][0], fin);
		}
		fclose(fin);
	}
}
