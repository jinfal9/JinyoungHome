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
		// ǥ�����(ȭ��)���� ����� ����մϴ�.
		printf("#%d = %d\n", test_case, MoneyEarn);
	}
	return 0; //��������� �ݵ�� 0�� �����ؾ� �մϴ�.
}
