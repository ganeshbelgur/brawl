#include<stdio.h>
 
int main(){
	int A, B, sub, rem;
 
	scanf("%d", &A);
	scanf("%d", &B);
 
	sub = A - B;
 
	rem = sub % 10;
	sub = sub / 10;
 
	if(rem != 9)
		rem++;
	else if (rem == 9)
		rem--;
 
	sub = sub * 10 + rem;
 
	printf("%d\n", sub);
 
	return 0;
}