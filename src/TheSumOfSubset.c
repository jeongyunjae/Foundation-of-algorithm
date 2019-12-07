#include <stdio.h>
#include <stdlib.h>

int num, num2;
int *w, W;
int x[10] = {0,};
int promising(int, int, int);
void sumOfSubset(int, int, int);

int promising(int i, int weight, int total)
{
    if (weight + total >= W && (weight == W || weight + w[i] <= W))
        return 1;
    else
        return 0;
}

void print()
{
    for (int i = 0; i < num2; i++)
    {
        if (x[i] != 0)
            printf("%d ", x[i]);
    }
    printf("\n");
}

void sumOfSubset(int i, int weight, int total)
{
    if (promising(i, weight, total))
    {
        if (weight == W)
            print();
        else
        {
            x[i + 1] = w[i + 1];
            sumOfSubset(i + 1, weight + w[i + 1], total - w[i + 1]);
            x[i + 1] = 0;
            sumOfSubset(i + 1, weight, total - w[i + 1]);
        }
    }
}

int main()
{
    int total = 0;

    printf("입력할 n값의 수를 입력:\n");
    scanf("%d", &num2);
    w = (int *)malloc(sizeof(int) * (num2));

    printf("n값들을 입력하시오:\n");
    for (int i = 0; i < num2; i++)
        scanf("%d", &w[i]);
        
    printf("검사할 숫자 입력:\n");
    scanf("%d", &W);

    for (int i = 0; i < num2; i++)
        total += w[i];

    sumOfSubset(-1, 0, total);
}
