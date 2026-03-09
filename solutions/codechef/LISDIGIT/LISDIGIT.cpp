#include <iostream>
#include <cstdio>
#define MAX 10
 
int main(){
  int T, N, LIS[MAX], number, add_value;
  scanf("%d", &T);
 
  while(T--){
      scanf("%d", &N);
      number = 0;
 
      for(int i = 0; i < N; i++){
        scanf("%d", &LIS[i]);
 
        if (LIS[i] != 0)
          add_value = LIS[i];
        else
          add_value = 1;
 
        number = number * 10 + LIS[i];
      }
 
      printf("%d\n", number);
  }
 
  return 0;
}