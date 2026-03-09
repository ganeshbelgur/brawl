#include<stdio.h>
#define MAX 10

int main(){
	int T, A[MAX], i, flag, pos1, pos2, pos3, min1, min2;

	//Enter the number of test cases:
	scanf("%d", &T);

	while(T--){
		for(i = 0; i < MAX; i++){
			scanf("%d", &A[i]);
		}

		flag = 0;

		if(A[0] == 0)
			flag = 1;
		else{
			min1 = A[0];
			pos2 = 0;
		}

		for(i = 1; i < MAX; i++){
			if(A[i] == 0){
				flag = 2;
				pos1 = i;
				break;
			}
			else{
				if(A[i] < min1){
					min1 = A[i];
					pos2 = i;
				}
			}
		}

		if(flag == 1)
			printf("10\n");
		else if(flag == 2)
			printf("%d\n", pos1);
		else if(flag == 0){
			if(pos2 == 0){
				min2 = A[1];
				pos3 = 1;
				for(i = 2; i < MAX; i++){
					if(A[i] < min2){
						min2 = A[i];
						pos3 = i;
					}
				}

				if(min2 == min1){
					for(i = min2; i >= 0; i--){
						printf("%d", pos3);
					}
					printf("\n");
				}
				else{
					printf("1");

					min1++;

					while(min1--){
						printf("0");
					}

					printf("\n");
				}
			}
			else{	
				for(i = min1; i >= 0; i--){
					printf("%d", pos2);
				}
				printf("\n");
			}
		}
	}
	return 0;
}