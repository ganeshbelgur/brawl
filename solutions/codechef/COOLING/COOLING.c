#include<stdio.h>
#define MAX 30

int main(){
	int T, N, A[MAX], B[MAX], i, j, count;

	//Enter the number of test cases:
	scanf("%d", &T);

	while(T--){
		count = 0;

		//Enter the number of pies:
		scanf("%d", &N);

		scanf("%d", &A[0]);
		for(i = 1; i < N; i++){
			scanf("%d", &A[i]);

			j = i;
			while((A[j] < A[j-1]) && (j != 0)){
				A[j] = A[j-1] + A[j];
				A[j-1] = A[j] - A[j-1];
				A[j] = A[j] - A[j-1];

				j--;
			}
		}

		scanf("%d", &B[0]);
		for(i = 1; i < N; i++){
			scanf("%d", &B[i]);

			j = i;
			while((B[j] < B[j-1]) && (j != 0)){
				B[j] = B[j-1] + B[j];
				B[j-1] = B[j] - B[j-1];
				B[j] = B[j] - B[j-1];

				j--;
			}
		}

		i = j = 0;
		while((i<N) && (j<N))
		{
			if(A[i] <= B[j])
			{
				count++;
				i++;
			}
			j++;
		}

		printf("%d\n", count);
	}
	return 0;
}