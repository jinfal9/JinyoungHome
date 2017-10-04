#include<stdio.h>

int N;
int H, W;
double input[50000], highest[50000];

int main() 
{
	int testcase, tc;
	int i, j, k;
	int l_count, r_count;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &tc);

	for (testcase = 0; testcase < tc; i++)
	{
		scanf(" %d", &N);

		l_count = 0;
		r_count = 0;
		k = 0;

		for (i = 0; i < H; i++)
		{
			scanf(" %d", &input[i]);
		}
		printf("\n");
		for (i = 0; i < H; i++)
		{
			if (input[i + 1] > input[i])
			{
				l_count++;
				highest[k] = i + 1;
			}
			else if (input[i + 1] < input[i])
			{
				r_count++;
			}
		}
	}
}

#if 0

void check_horizon(int height, int width)
{
	int i, j;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (input[i][j] == 1)
				break;
		}
		if (j == width) //complete road
			calc_house(i, height, width);
	}
}

void calc_house(int line, int height, int width)
{
	int i, j, k, max = 0;

	for (j = 0; j < width; j++)
	{
		for (i = 1; (i < height) && (line + i < height); i++) // down
		{
			if (input[line + i][j])
			{
				if (i > max)
					max = i;
			}
		}
		for (i = line -1, k=0; i > -1; i--) // up
		{
			k++;
			if (input[i][j])
			{
				if (k > max)
					max = k;
			}
		}
	}
}

void check_vertical(int height, int width)
{

}

void check_diagonal(int x, int y)
{
	int i, j;
	for (i = 0; i < W; i++)
	{
		x = 0;
		y = 0;

		while(1)
		{
			if (i + x == W || y == H)
				break;

			if (input[i + x][y] == 1)
				break;
			x++;
			y++;
		}
	}

}

int diagonal(void)
{
	int a[100][100] = { 0, };
	int i;
	int j;
	int input;
	int c;
	int num = 1;


	input = 5;

	for (i = 0; i < input; i++) // 내가 입력한 값 만큼 i++ ex)5
	{
		c = 0; // 줄 마다 맨 위를 가리켜야 하므로 계속 0으로 초기화
		for (j = i; j >= 0; j--) //  i가 0일 때 0, i가 1일 때 1,0 i가 2일 때 2,1,0 이런 식
		{
			a[c][j] = num;      //a[0][4], a[1][3], a[2][2], a[3][1], a[4][0]
			c++;                // 0,1,2,3,4
			num++;              // 값 계속 증가.
		}
	}
	for (i = 0; i < input; i++) // 내가 입력한 값 만큼 i++ ex)5
	{
		c = i + 1;                    // 1~4가 c에 들어가짐
		for (j = input - 1; c <= input - 1; j--) // j=4;1<=4;j-- j=4;2<=4;j-- j=4;3<=4;j-- j=4;4<=4;j--
		{
			a[c][j] = num;        // a[1][4], a[2][3], a[3][2], a[4][1]
			c++;                // 1,2,3,4
			num++;              // 값 계속 증가
		}
	}

	for (i = 0; i < input; i++)
	{
		for (j = 0; j < input; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

#endif