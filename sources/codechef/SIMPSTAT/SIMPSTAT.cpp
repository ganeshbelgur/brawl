////////////////////////
//Author: Ganesh B R
//Date: 24-07-2016
//Problem: SIMPSTAT
//Notes: Requires c++11
////////////////////////

#include <iostream>
#include <cstdio> //For printf and scanf
#include <algorithm> // For sort()
using namespace std;

#define MAX 10000

int main(){
	int T, N, K, stat[MAX];
	float avg, sum;
	scanf("%d",&T);

	while(T--){
		scanf("%d%d",&N,&K);
		sum = 0.0; // Initializing sum to zero

		for(int i = 0; i < N; i++){
			scanf("%d", &stat[i]);
		}

		sort(stat, stat + N); // Sorts the entire array

		for(int i = K; i < N - K; i++){
			sum += stat[i];
		}

		avg = sum / (N - 2 * K); //avg and sum are floats so even decimal points will be considered
		printf("%f\n", avg);
	}
	return 0;
}