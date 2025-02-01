#include<iostream>
#include<cstdio>
using namespace std;
 
#define MAX 100001
 
int main(){
	int T, N, A[MAX];
	scanf("%d", &T);
 
	while(T--){
		scanf("%d", &N);
 
		for(int i = 1; i <= N-2; i++){
			if(i % 2 == 1)
				A[i] = i + 1;
			else
				A[i] = i - 1;
		}
 
		if(N % 2 == 0){
			A[N - 1] = N;
			A[N] = N-1;
		}
		else{
			A[N - 1] = N;
			A[N] = N - 2;
		}
 
		for(int i = 1; i <= N; i++){
			printf("%d ", A[i]);
		}
		printf("\n");
	}
return 0;
}

