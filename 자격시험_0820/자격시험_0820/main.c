#include <stdio.h>

int main(void)
{
	int test_case, T, N;
	int i,j,k;
	
	freopen("input.txt", "r", stdin);
	
	scanf(" %d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf(" %d", &N);

		printf("#%d\n", test_case);
	}
	return 0; //��������� �ݵ�� 0�� �����ؾ� �մϴ�.
}