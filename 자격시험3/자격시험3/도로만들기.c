#include<stdio.h>

int H, W;
int input[50][50];

void check_horizon(int height, int width);
void check_vertical(int height, int width);
void calc_house(int line, int height, int width);
void check_diagonal(int x, int y);

int main() 
{
	int testcase, tc;
	int i, j;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &tc);

	for (testcase = 0; testcase < tc; i++)
	{
		scanf(" %d %d", &H, &W);

		for (i = 0; i < H; i++)
		{
			for (j = 0; j < W; j++)
			{
				scanf(" %d", &input[i][j]);
			}
		}

		check_horizon(H, W);
		check_vertical(H, W);
		diagonal();
		check_diagonal(0, 0); //start point

		printf("\n");
	}
}

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

	for (i = 0; i < input; i++) // ���� �Է��� �� ��ŭ i++ ex)5
	{
		c = 0; // �� ���� �� ���� �����Ѿ� �ϹǷ� ��� 0���� �ʱ�ȭ
		for (j = i; j >= 0; j--) //  i�� 0�� �� 0, i�� 1�� �� 1,0 i�� 2�� �� 2,1,0 �̷� ��
		{
			a[c][j] = num;      //a[0][4], a[1][3], a[2][2], a[3][1], a[4][0]
			c++;                // 0,1,2,3,4
			num++;              // �� ��� ����.
		}
	}
	for (i = 0; i < input; i++) // ���� �Է��� �� ��ŭ i++ ex)5
	{
		c = i + 1;                    // 1~4�� c�� ����
		for (j = input - 1; c <= input - 1; j--) // j=4;1<=4;j-- j=4;2<=4;j-- j=4;3<=4;j-- j=4;4<=4;j--
		{
			a[c][j] = num;        // a[1][4], a[2][3], a[3][2], a[4][1]
			c++;                // 1,2,3,4
			num++;              // �� ��� ����
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

