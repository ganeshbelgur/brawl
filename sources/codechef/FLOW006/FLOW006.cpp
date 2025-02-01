#include <iostream>
#include <cstdio>
using namespace std;
 
int main()
{
	int N, T, sum, nos;
	scanf("%d", &T);
 
	while(T--)
	{
		sum = 0;
		scanf("%d", &N);
		nos = N;
 
		while(nos)
		{
			sum += nos % 10;
			nos /= 10;
		}
		
		printf("%d\n", sum);
	}
 
return 0;
}

