#include <stdio.h>

int N, S, sum = 0, ans = 0;
int arr[21];

void func(int idx) {
	if (N == idx) {        //base case
		if (sum == S) {
			ans++;
		}
		return;
	}
	//recursive case
	sum += arr[idx];    //idx번째 원소를 포함여
	func(idx + 1);
	sum -= arr[idx];    //idx번째 원소를 안포함여
	func(idx + 1);
}

int main() {

	scanf("%d%d", &N, &S);
	for (int i = 0; i<N; ++i)
		scanf("%d", &arr[i]);

	func(0);

	if (S == 0) ans--;
	printf("%d\n", ans);

	return 0;
}

#if 0

int sosu[1001] = { 0, };

int main(void)
{
	int test_case, T;
	int i, j;
	
	freopen("input.txt", "r", stdin);
	
	scanf(" %d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		printf("#%d\n", test_case);
	}

	sosu[0] = 1;
	sosu[1] = 1;
	for (i = 2; i < 1001; i++)
	{
		for (j = 2; i*j < 1001; j++)
		{
			sosu[i*j] = 1;
		}
	}

	for (i = 0; i < 1001; i++)
	{
		if (sosu[i] == 0)
		{
			printf("%d ", i);
		}
	}

	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}

#endif