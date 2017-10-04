#include <stdio.h>

int main(void)
{
	int test_case, T, i, len, dec, dec1, need, temp;
	char str[1002];
	
	freopen("1_input.txt", "r", stdin);
	
	scanf(" %d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (i = 0; i < 1002; i++)
		{
			str[i] = NULL;
		}
		scanf("%s", str);
		dec = str[0] - '0';
		need = 0;
		len = 0;

		while (str[++len]);

		for (i = 1; i < len; i++)
		{
			dec1 = str[i] - 48;
			if (dec < i)
			{
				temp = i - dec;
				need += temp;
				dec += temp;
			}
			dec += dec1;
		}

		printf("#%d %d\n", test_case, need);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}