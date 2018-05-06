#include<stdio.h>
#define SIZE 10001
#define MAX 100
 
int main(){
	int FREQ[SIZE], pseudoArray, max, index, T, N, i, j;
 
	scanf("%d", &T);
 
	for(i = 0; i < T; i++){
		//Initialise the Frequency array to '0'
		for(j = 0; j < SIZE; j++){
			FREQ[j] = 0;
		}
 
		scanf("%d", &N);
		max = 0;
		index = 1;
 
		for(j = 0; j < N; j++){
			scanf("%d", &pseudoArray);
			FREQ[pseudoArray]++;
		}
 
		for(j = 1; j <= SIZE - 1; j++){
			if(max < FREQ[j]){
				max = FREQ[j];
				index = j;
			}
		}
 
		printf("%d %d\n", index, max);
	}
	return 0;
} 