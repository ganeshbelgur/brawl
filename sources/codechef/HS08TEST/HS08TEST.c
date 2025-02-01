/*
Author : Ganesh Belgur
Program has been successfully executed
*/

#include <stdio.h>

int main()
{
    int w;
    float b;

    scanf("%d", &w);
    scanf("%f", &b);

    if(w % 5 != 0)
        printf("%f", b);
    else if(w >= b)
        printf("%f", b);
    else if(b - w - 0.5 < 0)
        printf("%f", b);
    else{
        b = b - w - 0.5;
        printf("%f", b);
    }

return 0;
}
