#if 0

#include<stdio.h>

void exhausive_search(int in[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		exhausive_search(in[i+1], n + 1);
	}
}

int main() 
{
	int i, j, k, l, m, n, o, num, input[6], result[6];
	/* 아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	freopen 함수를 이용하면 이후 scanf 를 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	freopen("input.txt", "r", stdin);
	/* 아래 코드를 수행하지 않으면 여러분의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	출력한 내용이 실제 표준 출력에 기록되지 않을 수 있습니다.
	따라서 안전을 위해 반드시 setbuf(stdout, NULL); 을 수행하시기 바랍니다.
	*/
	setbuf(stdout, NULL);
	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		scanf(" %d", &input[i]);
		//printf("%d ", input[i]);
	}
	exhausive_search(input[i], num);

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (input[j] != input[i])
			{
				for (k = 0; k < num; k++)
				{
					if (input[k] != input[i] && input[k] != input[j])
					{
						printf("%d %d %d\n", input[i], input[j], input[k]);
					}
				}
			}
		}
	}

	printf("\n");

}

#endif

//*************************************************//
// 순열생성기(Permutation Generator)
// 작성 : 이승철, 최종 수정 : 2003/09/21 16:04
// 컴파일러 : Visual C++ 6.0 Professional
//*************************************************//
#include <stdio.h>
#include <stdlib.h>

int n;
int list[100], t;
long cnt;

// t를 임시변수로 a,b를 서로 바꾸는 매크로 함수
#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

void data_input(); // 데이터 입력 함수
void perm1(int); // 순열생성함수
void perm0(void);

void main()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	data_input();
	perm1(0);
	perm0();
	printf("n순열의 수 = %d\n", cnt);
}

void data_input()
{
	int i;
	// 순열의 크기를 입력 받음(즉, 주어진 원소의 수) 
	//printf("n = "); 
	scanf("%d", &n);

	// stdin의 버퍼를 지움.(버퍼를 안 지우면 아래 gets()함수에서 엔터값이 들어감) 
	//fflush(stdin);

	// 메모리의 쓸데없는 낭비를 줄이기 위해 동적 할당
	//list = malloc(sizeof(char) * n);

	// list에 문자열로 입력 받음.
	//printf("순열을 하나 입력하시오 : "); 
	//gets(list);

	for (i = 0; i < n; i++)
	{
		scanf(" %d", &list[i]);
	}
}

void perm0 (void)
{
	int i, j, k;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j != i)
			{
				for (k = 0; k < 3; k++)
				{
					if (k != i && k != j)
					{
						printf("(%d %d %d)\n", list[i], list[j], list[k]);
					}
				}
			}
		}
	}
}

void perm1(int i)
{
	int j;

	if (i == n - 1) // 종료 조건
	{
		cnt++; // 순열의 수를 샘
		for (j = 0; j<n; j++) 
			printf("%d", list[j]);
		printf("\n");
	}
	else
		for (j = i; j<n; j++)
		{
			SWAP(list[i], list[j], t);
			perm1(i + 1);
			SWAP(list[i], list[j], t);
		}
}

