//N_QUEEN Backtracking

#include<stdio.h>

#define M 13
int sc[M + 1], dr[M * 2 + 1], dl[M * 2 + 1], n, cnt;

//dr�� ��+���� üũ,dl=n+lv-i
//lv : �� sc[i]:�� dr[lv+i]:���缱�밢�� dl[n+lv-i]:�缱 �밢��
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
			//üũ�� �� �Ǿ������� üũ�� �ϰ� ���
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
