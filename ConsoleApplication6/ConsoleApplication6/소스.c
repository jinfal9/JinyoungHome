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

	/* 아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	freopen 함수를 이용하면 이후 scanf 를 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	freopen("sample_input.txt", "r", stdin);
	/* 아래 코드를 수행하지 않으면 여러분의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	출력한 내용이 실제 표준 출력에 기록되지 않을 수 있습니다.
	따라서 안전을 위해 반드시 setbuf(stdout, NULL); 을 수행하시기 바랍니다.
	*/
	setbuf(stdout, NULL);
	scanf("%d", &T);
	/*
	여러 개의 테스트 케이스를 처리하기 위한 부분입니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		이 부분에 여러분의 알고리즘 구현이 들어갑니다.
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
		// 표준출력(화면)으로 답안을 출력합니다.
		printf("#%d \n", test_case);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
