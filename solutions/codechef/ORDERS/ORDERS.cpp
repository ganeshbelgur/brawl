#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
  int T, N, temp;
  scanf("%d", &T);

  while(T--)
  {
      scanf("%d", &N);
      int A[N], B[N];

      for(int i = 0; i < N; i++)
      {
        A[i] = i + 1;
      }

      for(int i = 0; i < N; i++)
      {
        scanf("%d", &temp);
        int iterator = i;
        int value = A[i];

        while(temp)
        {
          A[iterator] = A[iterator - 1];
          temp--;
          iterator--;
        }
        A[iterator] = value;
      }

      for(int i = 0; i < N; i++)
      {
        B[A[i] - 1] = i + 1;
      }

      for(int i = 0; i < N; i++)
      {
        printf("%d ", B[i]);
      }
      printf("\n");
  }

  return 0;
}
