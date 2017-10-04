//N_QUEEN Backtracking

#include<stdio.h>

#define M 13
int sc[M + 1], dr[M * 2 + 1], dl[M * 2 + 1], n, cnt;

//dr은 행+열로 체크,dl=n+lv-i
//lv : 행 sc[i]:열 dr[lv+i]:역사선대각선 dl[n+lv-i]:사선 대각선
void f(int lv)
{
	if (lv>n)
	{
		cnt++;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (sc[i] == 0 && dr[lv + i] == 0 && dl[n + lv - i] == 0)
		{
			//체크가 안 되어있으면 체크를 하고 재귀
			sc[i] = dr[lv + i] = dl[n + lv - i] = 1;
			f(lv + 1);
			sc[i] = dr[lv + i] = dl[n + lv - i] = 0;
		}
	}
}

int main()
{
	scanf("%d", &n);
	f(1);
	printf("%d", cnt);
}
