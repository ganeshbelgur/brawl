#include<stdio.h>
#define MAX 51

int main(){
	int T, N, C[MAX], D[MAX], E[MAX], i, j, k, flag, sum, temp, max, pos;

	scanf("%d", &T);

	while(T--){
		scanf("%d", &N);

		flag = 0;
		sum = 0;

			for(j = 1; j <= N; j++){
				scanf("%d", &C[j]);
				if(C[j] == N){
					flag = 1;
				}
				sum = sum + C[j];
				D[j] = 0;
			}

		if(flag == 1 || sum != N)
			printf("-1\n");
		else{
			flag = 0;
				while(flag == 0){
					max = C[1];
					pos = 1;
						for(i = 2; i <= N; i++){
							if(C[i] > max){
								max = C[i];
								pos = i;
							}
						}
					if(max == 1){
						flag = 1;
					}
					else{
						i = 1;
							while(C[i] != 0 || D[i] != 0){
								i++;
							}
						D[i] = pos;
						C[pos]--;
					}
				}

			j = 0;
				for(i = 1; i <= N; i++){
					if(C[i] == 1)
						E[j++] = i;
				}

			temp = 1;
				for(k = 1; k <= N; k++){
					if(D[k] == 0 && temp != j)
						D[k] = E[temp++];
					else if(D[k] == 0 && temp == j){
						D[k] = E[0];
					}	
				}

				for(i = 1; i <= N; i++){
					printf("%d ", D[i]);
				}

				printf("\n");
			}
		}
	return 0;
}