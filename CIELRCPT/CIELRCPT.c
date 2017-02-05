#include<stdio.h>
 
int main(){
	int T, P, i, menuCount;
 
	scanf("%d", &T);
 
	for(i = 0; i < T; i++){
		scanf("%d", &P);
 
		menuCount = 0;
 
		if(P >= 2048){
			menuCount = P / 2048;
			P = P % 2048;
		}
 
		while(P != 0){
			if(P % 2 == 1)
				menuCount++;
			P = P / 2;
		}
 
		printf("%d\n", menuCount);
	}
	return 0;
} 