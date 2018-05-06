#include<iostream>
#include<cstdio>
using namespace std;
 
#define MAX 130
 
int main(){
	int T;
	int S[MAX];
	bool flag;
	char temp;
 
	scanf("%d", &T);
	scanf("%c", &temp);
 
	while(T--){
		scanf("%c", &temp);	
 
		for(int i = 0; i < 130; i++){
			S[i] = 0;
		}
 
		flag = false;
 
		while(temp != '\n'){
			int itemp = (int)temp;
			S[itemp] += 1;
 
			scanf("%c", &temp);
		}
 
		for(int i = 0; i < 130; i++){
			if(S[i] > 1){
				printf("yes\n");
				flag = true;
				break;
			}
		}
 
		if(!flag)
			printf("no\n");
 
	}
return 0;
}

