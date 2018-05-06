/*
Author : Ganesh Belgur
Program has been successfully executed
*/


#include<stdio.h>

int main(){
	int T, N, i;

	scanf("%d", &T);

	for(i = 0; i < T; i++){
		scanf("%d", &N);

		if(N&1)
			printf("BOB\n");
		else
			printf("ALICE\n");
	}
	return 0;
}