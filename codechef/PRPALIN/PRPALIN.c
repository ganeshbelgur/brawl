#include<stdio.h>
#include<math.h>
 
 
int main(){
	int N, primeFlag, checkTill, tempN, reversedN, i, j;
 
	scanf("%d", &N);
 
	if(N % 2 == 0)
		N = N + 1;
 
	for(i = N;;i = i + 2){
		primeFlag = 0;
		checkTill = sqrt(i);
 
		for(j = 3; j <= checkTill; j = j + 2){
			if(i % j == 0){
				primeFlag = 1;
				break;
			}
		}
 
		if(primeFlag == 0){
			tempN = i;
			reversedN = 0;
			while(tempN != 0){
				reversedN = reversedN * 10 + (tempN % 10);
				tempN = tempN / 10;
			}
			if(reversedN == i){
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
} 