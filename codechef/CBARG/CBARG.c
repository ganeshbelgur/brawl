#include<stdio.h>
#define MAX 100000

int main(){
	int T, N, i; 
	long long alloc, sum;
	long long M[MAX];

	scanf("%d", &T);

	while(T--){
		scanf("%d", &N);

		sum = 0;

		for(i = 0; i < N; i++){
			scanf("%lld", &M[i]);
			if(i == 0){
			sum = sum + M[i];
			alloc = M[i];
			}
			else if(M[i] > alloc){
				sum = sum + (M[i] - alloc);
				alloc = M[i];
			}
			else if(M[i] < alloc)
				alloc = M[i];
		}

		printf("%lld\n", sum);
	}
	return 0;
}