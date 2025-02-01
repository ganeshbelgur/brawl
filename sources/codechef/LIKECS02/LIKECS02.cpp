#include<iostream>
#include<cstdio>
using namespace std;
 
#define MAX 1000000000
 
int main(){
	int T, N;
	scanf("%d", &T);
 
	while(T--){
		int mid;
		int pad;
 
		scanf("%d", &N);
 
		if(N == 1){
			printf("1\n");
			continue;
		}
 
		mid = (N + 1) / 2;
		pad = N - 1 - mid;
 
		if(N + pad > MAX)
			pad = -1;
 
		if(pad != -1){
			for(int i = 1; i <= N; i++){
				printf("%d ", i + pad);
			}
			printf("\n");
		}
		else
			printf("-1\n");
	}
 
return 0;
}

