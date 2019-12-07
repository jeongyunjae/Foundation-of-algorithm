

#include<stdio.h>
#include<stdlib.h>
#define INF 99999

int **P;

void PrintMatrix(int, int **P);
void path(int , int);

void floyd2(int n, int **W, int **D, int **P){
  int i,j,k;
  int q,r;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      D[i][j] = W[i][j];
      P[i][j]=0;
    }
  }
  for (k = 0; k < n; k++) {
    for (i = 0; i < n; i++) {
      for (j = 0; j <n; j++) {
        if (D[i][k] + D[k][j] < D[i][j]){
          P[i][j] = k+1;
          D[i][j] = D[i][k] + D[k][j];
        }
      }
    }
  }
  PrintMatrix(n,P);
  printf("경로를 알고 싶은 vertex의 시작과 끝을 입력:\n");
  scanf("%d %d",&q,&r);
  q=q-1;
  r=r-1;
  path(q,r);
}

void path(int q, int r){
  if(P[q][r] != 0){
    path(q, P[q][r]-1);
    printf("v%d ",P[q][r]);
    path(P[q][r]-1,r);
  }
}

void PrintMatrix(int n, int **P) {
    printf ("행과 열의 인덱스 범위가 모두 1부터 %d까지인 배열 P \n",n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (P[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", P[i][j]);
        }
        printf("\n");
    }
}

int main() {
  int n;
  printf("n값을 입력하십시오:");
  scanf("%d",&n);
  printf("가중치가 있는 n*n행렬을 입력(무한=99999):\n");

  int **W;
  W = (int**) malloc (sizeof(int*)*n);
  for(int i = 0;i<n;i++){
    W[i] = (int*)malloc(sizeof(int)*n);
  }

    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      scanf(" %d",&W[i][j]);
    }
  }

  int **D;
  D = (int**) malloc (sizeof(int*)*n);
  P = (int**) malloc (sizeof(int*)*n);

  for(int i = 0;i<n;i++){
    D[i] = (int*)malloc(sizeof(int)*n);
    P[i] = (int*)malloc(sizeof(int)*n);
  }

    floyd2(n, W, D, P);
    free(D);
    free(P);
    free(W);
}
