#include<iostream>
#include<cstdio>
using namespace std;
 
#define MAX 100001
 
int main(){
	int T, N, minIndex;
	long long int sum, min, A[MAX], B[MAX], C[MAX];
	scanf("%d", &T);
 
	while(T--){
		scanf("%d", &N);
 
		sum = 0;
		for(int i = 1; i <= N; i++){
			scanf("%lld", &A[i]);
			sum += A[i];
			B[i] = sum;
		}
		
		sum = 0;
		for(int i = N; i >= 1; i--){
			sum += A[i];
			C[N-i+1] = sum;
		}
 
		min = 9223372036854775807;
		minIndex = 0;
 
		for(int i = 1; i <= N; i++){
			long long int temp = B[i] + C[N-i+1];
 
			if (temp < min){
				min = temp;
				minIndex = i;
			}
		}
		
		printf("%d\n", minIndex);
	}
return 0;
}

