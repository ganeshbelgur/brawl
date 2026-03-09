#include <iostream>
#include <cstdio>
 
int main(){
	int T, N1, N2;
	scanf("%d", &T);
	
	while(T--){
		scanf("%d%d",&N1, &N2);
		printf("%d\n", N1+N2);
	}
	return 0;
} 