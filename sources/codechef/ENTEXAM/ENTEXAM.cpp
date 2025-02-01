#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
 
#define MAX 100001
 
int main(){
	long long int T, N, K, E, M, sum[MAX], i, j, x, sum_temp, input_score, total, score;
	scanf("%lld", &T);
	
	while(T--){
		scanf("%lld%lld%lld%lld", &N, &K, &E, &M);
		score = 0;
		total = 0;
		
		for(i = 0; i < N-1; i++){
			sum_temp = 0;
			
			for(j = 0; j < E; j++){
				scanf("%lld", &input_score);
				sum_temp += input_score;
			}
			
			sum[i] = sum_temp;
		}
		
		sort(sum, sum + (N-1));
		reverse(sum, sum + (N-1));
		
		for(x = 0; x < E-1; x++){
			scanf("%lld", &input_score);
			total += input_score;
		}
		
		score = sum[K - 1] - total + 1;
		if (score <= 0 || N <= K)
			printf("0\n");
		else if (score <= M)
			printf("%lld\n", score);
		else
			printf("Impossible\n");
	}
	return 0;
}    