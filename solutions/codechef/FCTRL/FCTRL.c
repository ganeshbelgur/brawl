/*
Author : Ganesh Belgur
Program has been successfully executed
*/

#include <stdio.h>

int main()
{
    int n, i, sum = 0;
    scanf("%d", &n);
    int m[n];

    for(i = 0; i < n; i++)
    {
        scanf("%d", &m[i]);
    }

    printf("\n");

    for(i = 0; i < n; i++)
    {
        while(m[i] >= 5)
        {
            m[i] = (m[i] - (m[i] % 5))/5;
            sum = sum + m[i];
        }
        printf("%d\n", sum);
        sum = 0;
    }
    return 0;
}
