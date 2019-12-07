#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int minmult(int n, int *d, int **P);
void order(int i, int j);

int num;
int *d, **P;

void order(int i, int j)  // 최적