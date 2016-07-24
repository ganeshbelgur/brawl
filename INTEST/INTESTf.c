/*
Author : Ganesh Belgur
Program has been successfully executed!
*/

#include <stdio.h>

int main()
{
    int n, k, counter, i;

    scanf("%d", &n);
    scanf("%d", &k);

    int m[n];

    for(i = 0; i < n; i++)
    {
        scanf("%d", &m[i]);
    }

    counter = 0;

    for(i = 0; i < n; i++)
    {
        if(m[i] % k == 0)
            counter++;
    }
    printf("%d", counter);
    return 0;
}
