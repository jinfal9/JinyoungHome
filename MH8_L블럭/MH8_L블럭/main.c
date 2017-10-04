#include <stdio.h>

#define MAX_N 64

int map[MAX_N][MAX_N];
int N;
int x, y;
int num;

void solve(int n, int lx, int ly, int ux, int uy, int x, int y)
{
	if (n == 0) return;

	//printf("solve:n=%d, lx=%d, ly=%d, ux=%d, uy=%d, x=%d, y=%d\n",
	//  n, lx, ly, ux, uy, x, y);

	int c_num = num++;

	int mx, my;
	int xin, yin;
	mx = (lx + ux) / 2;
	my = (ly + uy) / 2;

	xin = lx <= x && x < mx;
	yin = ly <= y && y < my;

	if (xin && yin)
	{
		solve(n - 1, lx, ly, mx, my, x, y);
	}
	else
	{
		map[mx - 1][my - 1] = c_num;
		solve(n - 1, lx, ly, mx, my, mx - 1, my - 1);
	}

	if (xin && !yin)
	{
		solve(n - 1, lx, my, mx, uy, x, y);
	}
	else
	{
		map[mx - 1][my] = c_num;
		solve(n - 1, lx, my, mx, uy, mx - 1, my);
	}

	if (!xin && yin)
	{
		solve(n - 1, mx, ly, ux, my, x, y);
	}
	else
	{
		map[mx][my - 1] = c_num;
		solve(n - 1, mx, ly, ux, my, mx, my - 1);
	}

	if (!xin && !yin)
	{
		solve(n - 1, mx, my, ux, uy, x, y);
	}
	else
	{
		map[mx][my] = c_num;
		solve(n - 1, mx, my, ux, uy, mx, my);
	}
}

int main()
{
	int TC;
	int ns;

	freopen("input.txt", "r", stdin);

	scanf("%d", &TC);

	for (int tc = 1; tc <= TC; tc++)
	{
		//초기화

		//입력
		scanf("%d %d %d", &N, &x, &y);

		ns = 1 << N;

#if 0
		//입력확인
		printf("N=%d, x=%d, y=%d\n", N, x, y);
#endif

		for (int r = 0; r < ns; r++)
		{
			for (int c = 0; c < ns; c++)
			{
				map[r][c] = 0;
			}
		}

		num = 1;
		--x;
		--y;
		map[x][y] = 0;

		//계산
		solve(N, 0, 0, ns, ns, x, y);

		//정답 입력

		//정답 출력
		for (int r = 0; r < ns; r++)
		{
			for (int c = 0; c < ns; c++)
			{
				printf("%2d ", map[r][c]);
			}
			printf("\n");
		}
	}

	return 0;
}
