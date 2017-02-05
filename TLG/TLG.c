/*
Author : Ganesh Belgur
Date : 5-12-2014
The program was successfully executed on 5-12-2014
*/

#include<stdio.h>

int main(){
	int rounds, i, add1 = 0, add2 = 0, ply1, ply2, max1 = 0, max2 = 0, lead;

	scanf("%d", &rounds);

	for(i = 0; i < rounds; i++){
		scanf("%d", &ply1);
		scanf("%d", &ply2);

		ply1 = ply1 + add1;
		ply2 = ply2 + add2;

		lead = ply1 - ply2;
		if(lead > max1)
			max1 = lead;
		else if(lead < max2)
			max2 = lead;

		add1 = ply1;
		add2 = ply2;
	}
	max2 = max2 * (-1);
	if(max1 > max2)
		printf("%d %d",1, max1);
	else
		printf("%d %d",2, max2);
	return 0;
}

