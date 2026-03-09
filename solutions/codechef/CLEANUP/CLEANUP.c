#include<stdio.h>
#define SIZE 10001
 
int main(){
	int jobs[SIZE][2], chefArray[SIZE], assisArray[SIZE], jobsDone, chefCount, assisCount, T, N, M, i, j;
 
	scanf("%d", &T);
 
	while(T--){
		scanf("%d%d", &N,&M);
//Initialises the jobs array to the true:
		for(i = 1; i <= N; i++){
			jobs[i][0] = i;
			jobs[i][1] = 0;
		}
//Marks those jobs which are already done in the jobs array:
		for(i = 0; i < M; i++){
				scanf("%d", &jobsDone);
				jobs[jobsDone][1] = 1;
			}
//Initalise the count of chef's jobs and the count of assistant's jobs to zero:
		chefCount = 0;
		assisCount = 0;
//Assigns the respective jobs to chef and his assistant and stores the job indices in their respective arrays:
		if(N != M){
			j = 0;
			for(i = 1; i <= N; i++){
				if(jobs[i][1] != 1){
					j++;
					if(j % 2 == 1)
						chefArray[chefCount++] = i;
					else
						assisArray[assisCount++] = i;
				}
			}
		}
//Prints the corresponding job indices of both the individuals:
		for(i = 0; i < chefCount; i++){
				printf("%d ", chefArray[i]);
		}
		printf("\n");
 
		for(i = 0; i < assisCount; i++){
				printf("%d ", assisArray[i]);
		}
		printf("\n");
	}
	return 0;
} 