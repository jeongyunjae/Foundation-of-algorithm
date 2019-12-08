#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void display(vector<vector<int>> &matrix, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (j != 0)
      {
        cout << "  ";
      }
      cout << matrix[i][j];
    }
    cout << endl;
  }
}

void add(int size, vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C)
{
  int i, j;

  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
}

void sub(int size, vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C)
{
  int i, j;

  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      C[i][j] = A[i][j] - B[i][j];
    }
  }
}

void strassen(int n, vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C)
{
  if (n <= 1)
  {
    C[0][0] = A[0][0] * B[0][0];
    return;
  }
  else
  {
    int new_size = n / 2;
    vector<int> t(new_size);
    vector<vector<int>>
        a11(new_size, t), a12(new_size, t), a21(new_size, t), a22(new_size, t),
        b11(new_size, t), b12(new_size, t), b21(new_size, t), b22(new_size, t),
        c11(new_size, t), c12(new_size, t), c21(new_size, t), c22(new_size, t),
        m1(new_size, t), m2(new_size, t), m3(new_size, t), m4(new_size, t),
        m5(new_size, t), m6(new_size, t), m7(new_size, t),
        aResult(new_size, t), bResult(new_size, t);

    for (int i = 0; i < new_size; i++)
    {
      for (int j = 0; j < new_size; j++)
      {
        a11[i][j] = A[i][j];
        a12[i][j] = A[i][j + new_size];
        a21[i][j] = A[i + new_size][j];
        a22[i][j] = A[i + new_size][j + new_size];
        b11[i][j] = B[i][j];
        b12[i][j] = B[i][j + new_size];
        b21[i][j] = B[i + new_size][j];
        b22[i][j] = B[i + new_size][j + new_size];
      }
    }
    /* 여기는 m1~7계산 구간*/
    add(new_size, a11, a22, aResult);
    add(new_size, b11, b22, bResult);
    strassen(new_size, aResult, bResult, m1);

    add(new_size, a21, a22, aResult);
    strassen(new_size, aResult, b11, m2);

    sub(new_size, b12, b22, bResult);
    strassen(new_size, a11, bResult, m3);

    sub(new_size, b21, b11, bResult);
    strassen(new_size, a22, bResult, m4);

    add(new_size, a11, a12, aResult);
    strassen(new_size, aResult, b22, m5);

    sub(new_size, a21, a11, aResult);
    add(new_size, b11, b12, bResult);
    strassen(new_size, aResult, bResult, m6);

    sub(new_size, a12, a22, aResult);
    add(new_size, b21, b22, bResult);
    strassen(new_size, aResult, bResult, m7);

    /* 여기서 부터 c요소계산*/
    add(new_size, m1, m4, aResult);
    add(new_size, aResult, m7, bResult);
    sub(new_size, bResult, m5, c11);

    add(new_size, m3, m5, c12);

    add(new_size, m2, m4, c21);

    add(new_size, m1, m3, aResult);
    add(new_size, aResult, m6, bResult);
    sub(new_size, bResult, m2, c22);

    for (int i = 0; i < new_size; i++)
    {
      for (int j = 0; j < new_size; j++)
      {
        C[i][j] = c11[i][j];
        C[i][j + new_size] = c12[i][j];
        C[i + new_size][j] = c21[i][j];
        C[i + new_size][j + new_size] = c22[i][j];
      }
    }
  }
}

int main()
{
  int n = 4;
  vector<vector<int>> A;
  vector<vector<int>> B;
  vector<vector<int>> C;
  for (int i = 1; i <= n; i++)
  {
    vector<int> temp;
    for (int j = 0; j < n; j++)
    {
      temp.push_back(1);
    }
    A.push_back(temp);
  }

  for (int i = 1; i <= n; i++)
  {
    vector<int> temp;
    for (int j = 0; j < n; j++)
    {
      temp.push_back(1);
    }
    B.push_back(temp);
  }

  for (int i = 1; i <= n; i++)
  {
    vector<int> temp;
    for (int j = 0; j < n; j++)
    {
      temp.push_back(0);
    }
    C.push_back(temp);
  }
  strassen(n, A, B, C);
  display(C, n);
}
