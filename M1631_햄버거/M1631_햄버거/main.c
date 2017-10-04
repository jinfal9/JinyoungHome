#include <stdio.h>

#define MAXCNT 1000
int CAL[MAXCNT] = { 0, }, SCORE[MAXCNT] = { 0, };

void init(void)
{
	int i;

	for (i = 0; i < MAXCNT; i++)
	{
		CAL[i] = 0;
		SCORE[i] = 0;
	}
}

int main(void)
{
	int test_case, T, N;
	int i,j,k;
	int MAXCAL;
	int sco, calory, maxsco;
	
	//freopen("input.txt", "r", stdin);
	
	scanf(" %d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d ", &N, &MAXCAL);

		init();
		sco = 0;
		calory = 0;
		maxsco = 0;

		for (i = 0; i < N; i++)
		{
			scanf("%d %d ", &SCORE[i], &CAL[i]);
		}

		for (i = 0; i < (1 << N); i++)
		{
			for (j = 0; j < N; j++)
			{
				if (i & (1 << j))
				{
					sco += SCORE[j];
					calory += CAL[j];
				}
			}
			if (calory < MAXCAL)
			{
				if (sco > maxsco)
					maxsco = sco;
			}
			sco = 0;
			calory = 0;
		}

		printf("#%d %d\n", test_case, maxsco);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}