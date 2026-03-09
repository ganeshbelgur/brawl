#include <stdio.h>
 
int main(){
    int in,out, i = 0;
    
    scanf("%d", &in);
    for(i = 0; i < in; i++){
        scanf("%d", &out);
        if(out%2 == 0)
            printf("%d\n", out);
        else
            printf("%d\n", out - 1);
    }
    
return 0;
}