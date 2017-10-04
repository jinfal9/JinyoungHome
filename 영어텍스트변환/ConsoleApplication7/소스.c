#include <stdio.h>
#include <string.h>


#define MAX_STRING_LENGTH 400
#define MAX_LINES 200
char input[MAX_LINES][MAX_STRING_LENGTH];
char ENG[MAX_LINES][MAX_STRING_LENGTH];
char KOR[MAX_LINES][MAX_STRING_LENGTH];

int main(int argc, char *argv[])
//int main(void)
{
	int test_case;
	int T;
	int N, M;
	int i, j, k, l, m;
	int temp_i, cnt;
	char tempstr[MAX_STRING_LENGTH];
	char *tempp1 = NULL, *tempp2 = NULL;
	FILE* fin;
	char outputfname[20] = { 0, };

	freopen(argv[1], "r", stdin);
	setbuf(stdout, NULL);

	for (i = 0; i < MAX_LINES; i++)
	{
		gets(input[i]);
	}
	cnt = 0;
	for (i = 0; i < MAX_LINES; i++)
	{
		if ((input[i][0] >= 'A' && input[i][0] <= 'Z') || (input[i][0] >= 'a' && input[i][0] <= 'z'))
		{
			k = 0;
			while (input[i][k] != NULL)
			{
				if (input[i][k] == ' ' && input[i][k+1] == ' ')
				{
					break;
				}
				else
				{
					ENG[i][k] = input[i][k];
				}
				k++;
			}
			strcpy(&tempstr[0], &input[i][k]);
			tempp2 = strstr(tempstr, "예문보기");
			if (tempp2 != NULL)
			{
				strcpy(&KOR[i][0], tempp2 + 8);
				strcat(&ENG[i][k], &KOR[i][0]);
			}
		}
		else
		{
			break;
		}
		cnt++;
	}

	sprintf(outputfname, "formed_%s", argv[1]);
	fin = fopen(outputfname, "w");
	if (fin != NULL)
	{
		for (i = 0; i < cnt; i++)
		{
			fputs(&ENG[i][0], fin);
			fputs("\n", fin);
		}
	}
	fclose(fin);

	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
