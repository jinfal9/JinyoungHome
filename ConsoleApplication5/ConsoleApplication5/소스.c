#include <stdio.h>

int Stock_price[16][17];
int Stock_gain[16];
int Stock_gain_idx[16];
int Stock_buy_ea[16];
int decode[7];

void bubble_sort(int month, int num)
{
	int i, j, temp, temp2;

	for (i = num - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (Stock_gain[j + 1] > Stock_gain[j])
			{
				temp = Stock_gain[j];
				Stock_gain[j] = Stock_gain[j + 1];
				Stock_gain[j + 1] = temp;
				temp2 = Stock_gain_idx[j];
				Stock_gain_idx[j] = Stock_gain_idx[j + 1];
				Stock_gain_idx[j + 1] = temp2;
			}
			else if (Stock_gain[j + 1] == Stock_gain[j])
			{
				//check if which stock is higher gain rate
				if (Stock_price[Stock_gain_idx[j]][month] > Stock_price[Stock_gain_idx[j + 1]][month])
				{
					temp = Stock_gain[j];
					Stock_gain[j] = Stock_gain[j + 1];
					Stock_gain[j + 1] = temp;
					temp2 = Stock_gain_idx[j];
					Stock_gain_idx[j] = Stock_gain_idx[j + 1];
					Stock_gain_idx[j + 1] = temp2;
				}
			}
		}
	}
}

int main(void)
{
	int test_case;
	int T;
	int i, j, k, m;
	int Money, Salary;
	int Stock_ea, Stoack_total_month;
	int Stock_gain_cnt, Buy_ea, Stock_buy_cnt, Orig_money, MoneyEarn;

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
		scanf("%d %d", &Money, &Salary);
		scanf("%d %d", &Stock_ea, &Stoack_total_month);
		Stock_gain_cnt = 0;
		Buy_ea = 0;
		Stock_buy_cnt = 0;
		Orig_money = 0;
		MoneyEarn = 0;
		Orig_money = Money + (Salary*Stoack_total_month);

		for (i = 0; i < Stock_ea; i++)
		{
			for (j = 0; j < Stoack_total_month+1; j++)
			{
				scanf("%d", &Stock_price[i][j]);
			}
		}

		//*************** delete temp_print
		for (i = 0; i < Stock_ea; i++)
		{
			for (j = 0; j < Stoack_total_month+1; j++)
			{
				printf("%d ", Stock_price[i][j]);
			}
			printf("\n");
		}

		for (i = 0; i < Stoack_total_month; i++)
		{
			//*************** Sell stock
			if (Stock_buy_cnt > 0)
			{
				for (m = 0; m < Stock_buy_cnt; m++)
				{
					Money = Money + (Stock_buy_ea[m]*Stock_price[Stock_gain_idx[m]][i]);
				}
			}
			
			//*************** check gain
			//init gain, idx
			for (j = 0; j < 16; j++)
			{
				Stock_gain[j] = 0;
				Stock_gain_idx[j] = 0;
			}
			for (j = 0; j < Stock_ea; j++)
			{
				Stock_gain[j] = Stock_price[j][i+1] - Stock_price[j][i];
				Stock_gain_idx[j] = j;
			}

			//*************** sort gain
			bubble_sort(i, Stock_ea);

			//*************** set no gain to zero
			Stock_gain_cnt = 0;
			for (j = 0; j < Stock_ea; j++)
			{
				if (Stock_gain[j] < 0)
					Stock_gain[j] = 0;
				else if (Stock_gain[j] > 0)
					Stock_gain_cnt++;
			}

			//*************** buy stock
			Stock_buy_cnt = 0;
			if (Stock_gain[0] > 0)
			{
				for (k = 0; k < Stock_gain_cnt; k++)
				{
					Buy_ea = Money / Stock_price[Stock_gain_idx[k]][i];
					if (Buy_ea <= 0)
						break;
					Money = Money - (Buy_ea * Stock_price[Stock_gain_idx[k]][i]);
					Stock_buy_ea[k] = Buy_ea;
					Stock_buy_cnt++;
				}
			}

			//*************** Get salary
			Money = Money + Salary;
		}

		//*************** Sell stock
		if (Stock_buy_cnt > 0)
		{
			for (m = 0; m < Stock_buy_cnt; m++)
			{
				Money = Money + (Stock_buy_ea[m] * Stock_price[Stock_gain_idx[m]][i]);
			}
		}
		MoneyEarn = Money - Orig_money;
		// 표준출력(화면)으로 답안을 출력합니다.
		printf("#%d = %d\n", test_case, MoneyEarn);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
