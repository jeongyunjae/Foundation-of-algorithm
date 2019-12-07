#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int minmult(int n, int *d, int **P);
void order(int i, int j);

int num;
int *d, **P;

void order(int i, int j)
{
    int k;
    if (i == j)
        printf("A%d", i);
    else
    {
        k = P[i][j];
        printf("(");
        order(i, k);
        order(k + 1, j);
        printf(")");
    }
}

int minmult(int n, int *d, int **P)
{
    int i, j, k, diagnonal;
    int min_k = 0;
    int **M, temp = 0;

    M = (int **)malloc(0);
    for (int i = 0; i <= num; i++)
        M[i] = (int *)malloc(sizeof(int) * num + 1);

    for (i = 1; i <= n; i++)
        M[i][i] = 0;
    for (diagnonal = 1; diagnonal <= n - 1; diagnonal++)
        for (i = 1; i <= n - diagnonal; i++)
        {
            j = i + diagnonal;
            for (k = i; k <= j - 1; k++)
            {
                M[i][j] = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (i == k)
                {
                    temp = M[i][j];
                    min_k = k;
                }
                else if (M[i][j] > temp)
                {
                    M[i][j] = temp;
                }
                else
                {
                    temp = M[i][j];
                    min_k = k;
                }
            }
            P[i][j] = min_k;
        }

    return M[1][n];
}

int main()
{
    int i;
    int result;

    printf("곱할 행렬 갯수 입력: ");
    scanf("%d", &num);

    printf("d0 ~ d%d 입력:", num);

    d = (int *)malloc(sizeof(int) * num + 1);
    for (i = 0; i <= num; i++)
        scanf("%d", &d[i]);

    P = (int **)malloc(0);
    for (i = 0; i < num; i++)
        P[i] = (int *)malloc(sizeof(int) * num + 1);

    result = minmult(num, d, P); // 알고리즘 3.6
    printf("\nOrder is ");
    order(1, num); //알고리즘 3.7
    printf("\nFinal result is %d\n", result);
}
