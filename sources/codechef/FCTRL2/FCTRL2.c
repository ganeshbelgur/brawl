/*
Author : Ganesh Belgur
Program has been successfully executed.
*/

#include<stdio.h>
#include<string.h>

int main(){
    char arr[200];
    int n, k, i, temp = 0, dis, j=0, x, z;

    scanf("%d", &n); //Number of test cases

    for(z = 0; z < n; z++){
        scanf("%d", &k); // Enter the number
        arr[0] = '1';
        arr[1] = '\0';
        for(i = 1; i <= k; i++){
            while(arr[j] != '\0'){
                x = (i * (arr[j] - '0')) + temp;
                arr[j] = (x % 10) + (int)'0';
                temp = x / 10;
                j++;
            }

            while(temp != 0){
                arr[j++] = (temp%10) + (int)'0';
                temp = temp/10;
            }
            arr[j] = '\0';
            temp = 0;
            j = 0;
        }
        dis = strlen(arr);

        //Printing...
        for(i = dis-1; i >= 0; i--){
            printf("%c",arr[i]);
        }
        printf("\n");
    }
    return 0;
}
