#include<stdio.h>
 
int main(){
	int T, N, i;
 
	scanf("%d", &T);
 
	for(i = 0; i < T; i++){
		scanf("%d", &N);
 
		printf("%d\n", N/2 + 1);		
	} 
	return 0;
} 