#include<stdio.h>
#define MAX 100000

int main(){
	int A[MAX], B[MAX], N, i, flag;

	while(1){
		scanf("%d", &N);

		flag = 0;

		if(N == 0)
			break;
		else{
			for(i = 0; i < N; i++){
				scanf("%d", &A[i]);
			}

			for(i = 0; i < N; i++){
				B[A[i] - 1] = i+1;
			}

			for(i = 0; i < N; i++){
				if(A[i] != B[i]){
					flag = 1;
				}
			}

			if(flag == 1)
				printf("not ambiguous\n");
			else
				printf("ambiguous\n");
		}
	}
	return 0;
}