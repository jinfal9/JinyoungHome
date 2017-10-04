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
	/* �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	freopen �Լ��� �̿��ϸ� ���� scanf �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	freopen("input.txt", "r", stdin);
	/* �Ʒ� �ڵ带 �������� ������ �������� ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	����� ������ ���� ǥ�� ��¿� ��ϵ��� ���� �� �ֽ��ϴ�.
	���� ������ ���� �ݵ�� setbuf(stdout, NULL); �� �����Ͻñ� �ٶ��ϴ�.
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
// ����������(Permutation Generator)
// �ۼ� : �̽�ö, ���� ���� : 2003/09/21 16:04
// �����Ϸ� : Visual C++ 6.0 Professional
//*************************************************//
#include <stdio.h>
#include <stdlib.h>

int n;
int list[100], t;
long cnt;

// t�� �ӽú����� a,b�� ���� �ٲٴ� ��ũ�� �Լ�
#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

void data_input(); // ������ �Է� �Լ�
void perm1(int); // ���������Լ�
void perm0(void);

void main()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	data_input();
	perm1(0);
	perm0();
	printf("n������ �� = %d\n", cnt);
}

void data_input()
{
	int i;
	// ������ ũ�⸦ �Է� ����(��, �־��� ������ ��) 
	//printf("n = "); 
	scanf("%d", &n);

	// stdin�� ���۸� ����.(���۸� �� ����� �Ʒ� gets()�Լ����� ���Ͱ��� ��) 
	//fflush(stdin);

	// �޸��� �������� ���� ���̱� ���� ���� �Ҵ�
	//list = malloc(sizeof(char) * n);

	// list�� ���ڿ��� �Է� ����.
	//printf("������ �ϳ� �Է��Ͻÿ� : "); 
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

	if (i == n - 1) // ���� ����
	{
		cnt++; // ������ ���� ��
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

