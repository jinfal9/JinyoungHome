#include<stdio.h>

int input[100][100];
int num, cnt=0, min=100000;

void DFS(int y, int x);

//최단거리
int main() 
{
	int testcase, tc;
	int H, W;
	int i, j;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &tc);

	for (testcase = 0; testcase < tc; testcase++)
	{
		scanf("%d", &num);

		for (i = 0; i < num; i++)
		{
			for (j = 0; j < num; j++)
			{
				scanf(" %d", &input[i][j]);
			}
		}
		for (i = 0; i < num; i++)
		{
			for (j = 0; j < num; j++)
			{
				printf("%d ", input[i][j]);
			}
			printf("\n");
		}
		DFS(0, 0);

		printf("\n");
	}
}

void DFS(int y, int x)
{
	int i;

	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { -1, 1, 0, 0 };
	//대각선 int dx[4] = { 0, 0, -1, 1, 1, 1, -1, -1 };
	//대각선 int dy[4] = { -1, 1, 0, 0, 1, -1, 1, -1 };
	//체스판 int dx[4] = { 1, 2, -1, -2, -1, 2, -2, 1 };
	//체스판 int dy[4] = { 2, 1, -2, -1, 2, -1, 1, -2 };

	input[y][x] = 0;
	cnt++;

	if (x == num-1 && y == num-1)
	{
		if (cnt < min)
			min = cnt;
	}

	for (i = 0; i < 4; i++)
	{
		if (input[y + dy[i]][x + dx[i]])
			DFS(y + dy[i], x + dx[i]);
	}

	input[y][x] = 1;
	cnt--;
}