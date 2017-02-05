#include<stdio.h>
 
int main(){
	int T, N, C, A;
 
	scanf("%d", &T);
 
	while(T--){
		scanf("%d%d", &N, &C);
 
		while(N--){
			scanf("%d", &A);
			C = C - A;
		}
 
		if(C < 0)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
} 