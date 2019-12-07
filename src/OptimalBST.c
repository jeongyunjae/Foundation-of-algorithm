#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 99999

char **KEY;
float **A, *P;
int num = 5;

void print(int **);
void optimalBST(int, float *, float *, int **);
float sum(int, int, float *);

void optimalBST(int num, float *P, float *minavg, int **R)
{
	int i, j, k, diagonal;
	float comp_p;
	minavg = &comp_p;
	A = (float **)malloc(0);
	for (int i = 0; i <= num + 1; i++)
		A[i] = (float *)malloc(sizeof(float) * num + 1);
	for (int i = 1; i <= num; i++)
	{
		A[i][i] = P[i];
		A[i][i - 1] = 0;
		R[i][i] = i;
		R[i][i - 1] = 0;
	}

	//print(R);

	A[num][num - 1] = 0;
	R[num][num - 1] = 0;
	for (diagonal = 1; diagonal <= num - 1; diagonal++)
	{
		printf("  diagonal = %d\n", diagonal);
		for (i = 1; i <= num - diagonal; i++)
		{
			j = i + diagonal;
			A[i][j] = INF;
			for (k = i; k <= j; k++)
			{
				comp_p = A[i][k - 1] + A[k + 1][j] + sum(i, j, P);
				//printf("  i = %d, j = %d, k = %d, %s ~ %s = %.2f\n", i, j, k,  KEY[i], KEY[j], comp_p);
				if (comp_p < A[i][j])
				{
					printf("  A[%d][%d] = %.2f, R[%d][%d] = %d\n", i, j, comp_p, i, j, k);
					A[i][j] = comp_p;
					R[i][j] = k;
				}
			}
		}
		printf("\n");
	}

	print(R);
	*minavg = A[1][4];
	printf("minavg: %.3f", *minavg);
}

float sum(int start, int end, float *P)
{
	float plus = 0;
	for (int i = start; i <= end; i++)
	{
		plus += P[i];
	}
	return plus;
}

void print(int **R)
{
	printf("\nMatrix KEY\n");
	for (int i = 1; i <= num - 1; i++)
	{
		printf("  %s", KEY[i]);
	}
	printf("\n");
	printf("\nMatrix P\n");
	for (int i = 1; i <= num - 1; i++)
	{
		printf("  %.3f", P[i]);
	}
	printf("\n");
	printf("\nMatrix R\n");
	for (int i = 1; i <= num; i++)
	{
		for (int j = 0; j <= num - 1; j++)
		{
			printf("  %d", R[i][j]);
		}
		printf("\n");
	}
	printf("\nMatrix A\n");
	for (int i = 1; i <= num; i++)
	{
		for (int j = 0; j <= num - 1; j++)
		{
			printf("  %.3f", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	int **R;
	float *minavg;
	KEY = (char **)malloc(0);
	KEY[0] = (char *)malloc(sizeof(char) * 100);
	KEY[0] = "\0";
	for (int i = 1; i <= num - 1; i++)
		KEY[i] = (char *)malloc(sizeof(char) * 100);
	R = (int **)malloc(0);
	for (int i = 0; i <= num + 1; i++)
		R[i] = (int *)malloc(sizeof(int) * num + 1);
	P = (float *)malloc(sizeof(float) * num);

	printf("단어 4개 입력:");
	for (int i = 1; i <= num - 1; i++)
		scanf("%s", KEY[i]);
	printf("주어진 확률 p1~p4 입력:");
	P[0] = 0;
	for (int i = 1; i <= num - 1; i++)
		scanf("%f", &P[i]);
	optimalBST(num, P, minavg, R);
}
