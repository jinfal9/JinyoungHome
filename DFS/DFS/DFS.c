#include<stdio.h>


int stack[10];
int visited[10];
int st_idx;

void DFS(int in[][3], int st);
void stack_init(void);
void push(int v);
int pop(void);

int main() 
{
	int tc;
	int i, j, k, l, m, n, o, num;
	int	input[100][2], result[6];
	int near[8][3] = { {0,0,0},{2,3,0},{4,5,0},{1,7,0},{2,6,0},{2,6,0},{4,5,7},{3,6,0} };


	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	for (i = 0; i < 8; i++)
	{
		printf("%d ", near[i][0]);
		printf("%d ", near[i][1]);
		printf("%d ", near[i][2]);
		printf("\n");
	}
	stack_init();
	DFS(near, 1);
	printf("\n");
}

void DFS(int in[][3], int st)
{
	int i;

	visited[st] = 1;

	for (i = 0; i < 3; i++)
	{
		if ((in[st][i] != 0) && (visited[st] != 1))
		{

		}
	}
}

void stack_init(void)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		stack[i] = -1;
		visited[i] = -1;
	}
	st_idx = -1;
}

void push(int v)
{
	stack[++st_idx] = v;
}

int pop(void)
{
	if (st_idx == -1)
		return -1;

	return stack[st_idx--];
}