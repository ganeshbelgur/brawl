/*
Author : Ganesh Belgur
Program successfully executed! 
*/

#include<stdio.h>
#include<string.h>

int main(){
	//Declarations:
	char ch[100];
	int n, i, k=0, count=0, z=0;

	//Number of test cases:
	scanf("%d", &n);

	//Declare array
	int arr[n];

	//Program:
	for(i = 0; i < n; i++){
		scanf("%s", &ch);
		while(ch[k] != '\0'){
			switch(ch[k]){
				case 'A':
				case 'D':
				case 'O':
				case 'P':
				case 'Q':
				case 'R':
						count++;
						break;
				case 'B':
						count = count + 2;
						break;
			}
			k++;
		}
		arr[z++] = count;
		count = 0;
		k = 0;
		strcpy(ch,"");
	}

	//Display:
	for(i = 0; i<z; i++){
		printf("%d\n", arr[i]);
	}
	
	return 0;
}