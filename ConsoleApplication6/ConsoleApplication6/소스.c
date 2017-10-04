#include <stdio.h>

#define MAX_ROW_N 51
#define MAX_COLUMN_M 51
char input[MAX_ROW_N][MAX_COLUMN_M];
int RGBcount[MAX_ROW_N][3];
int PaintCount;

void Paint(int column, int line, char color)
{
	int temp;
	switch (color)
	{
	case 'W':
		temp = column - RGBcount[line][0];
		break;
	case 'B':
		temp = column - RGBcount[line][1];
		break;
	case 'R':
		temp = column - RGBcount[line][2];
		break;
	}
	PaintCount += temp;
}

int main(void)
{
	int test_case;
	int T;
	int N, M;
	int i, j, k, m;

	/* �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	freopen �Լ��� �̿��ϸ� ���� scanf �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	freopen("sample_input.txt", "r", stdin);
	/* �Ʒ� �ڵ带 �������� ������ �������� ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	����� ������ ���� ǥ�� ��¿� ��ϵ��� ���� �� �ֽ��ϴ�.
	���� ������ ���� �ݵ�� setbuf(stdout, NULL); �� �����Ͻñ� �ٶ��ϴ�.
	*/
	setbuf(stdout, NULL);
	scanf("%d", &T);
	/*
	���� ���� �׽�Ʈ ���̽��� ó���ϱ� ���� �κ��Դϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		�� �κп� �������� �˰��� ������ ���ϴ�.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		scanf("%d %d", &N, &M);
		//***************** initialize
		for (i = 0; i < MAX_ROW_N; i++)
		{
			for (j = 0; j < MAX_COLUMN_M; j++)
			{
				input[i][j] = 'X';
			}
			RGBcount[i][0] = 0;
			RGBcount[i][1] = 0;
			RGBcount[i][2] = 0;
		}

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				scanf(" %c", &input[i][j]);
			}
		}

		//***************** find and record W B R
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				switch (input[i][j])
				{
				case 'W':
					RGBcount[i][0]++;
					break;
				case 'B':
					RGBcount[i][1]++;
					break;
				case 'R':
					RGBcount[i][2]++;
					break;
				}
			}
		}

		//***************** delete print input
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				printf("%c", input[i][j]);
			}
			printf("\n");
			printf("W=%d, B=%d, R=%d\n", RGBcount[i][0], RGBcount[i][1], RGBcount[i][2]);
		}

		//***************** Paint 1st and last
		Paint(M, 0, 'W'); //white
		Paint(M, N - 1, 'R'); //red

		for (i = 1; i < N - 1; i++)
		{
			if (RGBcount[i][0] > RGBcount[i][1])
			{

			}
		}
		// ǥ�����(ȭ��)���� ����� ����մϴ�.
		printf("#%d \n", test_case);
	}
	return 0; //��������� �ݵ�� 0�� �����ؾ� �մϴ�.
}
