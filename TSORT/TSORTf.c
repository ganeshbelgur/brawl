/*
Author : Ganesh Belgur
Date : 27-11-14
The program was successfully executed on 5-12-14!
*/

#include<stdio.h>
#include<stdint.h>
#include<time.h>

int main(){
	clock_t begin, end;
	float time;
	begin = clock();
	int i, size, n, j; 
	int A[1000] = {0};

	scanf("%d", &size);

	for(i = 0; i < size; i++){
		scanf("%d", &n);
		++A[n-1];
	}

	for(i = 0; i < 1000; i++){
		for(j = 0; j < A[i]; j++){
			printf("%d\n",i+1);
		}
	}
	end = clock();
	time = end-begin/CLOCKS_PER_SEC;
	printf("%f\n", time);
	return 0;
}