#include<stdio.h>
#define MAX 4950

int findmax(int X[], int level,int last);

int main(){
	int T, N, A[MAX], i, j, total;

	//Number of test cases
	scanf("%d", &T);

	for(i = 0; i < T; i++){
		//Number of levels
		scanf("%d", &N);

		total = (N * (N+1)) / 2;

		for(j = 0; j < total; j++){
			scanf("%d", &A[j]);
		}

		printf("%d\n", findmax(A, N-1, total-1));
	}
	return 0;
}

int findmax(int X[], int level, int last){
	//Uses memoization!
	int j, temp;
	if(level == 0)
		return X[0];
	else{
		temp = (level * (level + 1)) / 2;

			for(j = last; j >= (temp+1); j--){
				if((X[j-level-1] + X[j]) >= (X[j-level-1] + X[j-1]))
					X[j-level-1] = (X[j-level-1] + X[j]);
				else
					X[j-level-1] = (X[j-level-1] + X[j-1]);
			}

		findmax(X, level-1, temp-1);
	}
}