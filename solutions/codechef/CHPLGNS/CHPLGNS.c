#include <stdio.h>
#include <limits.h> // Has the macro "INT_MIN" - the least value a signed integer can store 
#define SIZE 100001
 
void merge(int arrX[][SIZE], int min, int mid, int max){
    int temp[2][SIZE], itrLeftPart , itrRightPart, leftEndsFlag, rightEndsFlag, tempsItr, i, k;
 
    itrLeftPart = min; //Iterator for the left partition
    itrRightPart = mid + 1; // Iterator for the right partition
 
    tempsItr = 0; // Iterator for the temp array
    leftEndsFlag = 0; // Sets when left partition gets over first
    rightEndsFlag = 0; // Sets when right partition gets over first
 
//1. Compare the two sorted partitions and merge them by putting them into a temporary array:
    while(leftEndsFlag != 1 && rightEndsFlag != 1){
        if(arrX[0][itrLeftPart] < arrX[0][itrRightPart]){
            temp[0][tempsItr] = arrX[0][itrLeftPart];
            temp[1][tempsItr] = arrX[1][itrLeftPart];
            tempsItr++;
            itrLeftPart++;
            if(itrLeftPart == (mid + 1))
                leftEndsFlag = 1;
        }
        else{
            temp[0][tempsItr] = arrX[0][itrRightPart];
            temp[1][tempsItr] = arrX[1][itrRightPart];
            tempsItr++;
            itrRightPart++;
            if(itrRightPart == (max + 1))
                rightEndsFlag = 1;
        }
    }
//2. The two partitions may not be of equal length during comparisons(the following code handles this condition):
// (leftEndsFlag = 1) => The left partition got over first and the right parition has some items left out.
    if(leftEndsFlag){
        for(k = itrRightPart; k <= max; k++){
            temp[0][tempsItr] = arrX[0][k];
            temp[1][tempsItr] = arrX[1][k];
            tempsItr++; 
        }
    }
// (leftEndsFlag = 1) => The right partition got over first and the left parition has some items left out.
    else if(rightEndsFlag) {
        for(k = itrLeftPart; k <= mid; k++){
            temp[0][tempsItr] = arrX[0][k];
            temp[1][tempsItr] = arrX[1][k];
            tempsItr++; 
        }
    }
 
//3. Return the values stored in the temporary array back to the original array which was passed to this function:
    for(i = 0,k = min; i < tempsItr; i++,k++){
        arrX[0][k] = temp[0][i];
        arrX[1][k] = temp[1][i];
    }
}
 
void partition(int Xarr[][SIZE], int min, int max){
    int mid;
 
    if(min < max){
        mid = (min + max) / 2;
        partition(Xarr, min, mid);
        partition(Xarr, mid + 1, max);
        merge(Xarr, min, mid, max);
    }
}
 
int main(){
    int T, N, M, X, Y, currIndex, maxXCoord, breakFlag, answerSet[SIZE], enclosureSet[2][SIZE], i, j;
 
    scanf("%d", &T);
 
    while(T--){
        scanf("%d", &N);
        currIndex = 1;
 
        for(i = 1; i <= N; i++){
            scanf("%d", &M);
            maxXCoord = INT_MIN;
//1. Finds the maximum X-coordinate value:
                for(j = 0; j < M; j++){
                    scanf("%d", &X);
                    scanf("%d", &Y);
                        if(maxXCoord < X)
                            maxXCoord = X;
                }
//2. Add the values to the enclosure array:
            enclosureSet[0][currIndex] = maxXCoord;
            enclosureSet[1][currIndex] = i;
            currIndex++;
        }
//3. Sort the array using merge sort:
        partition(enclosureSet, 1, N);
 
//4. Creating the array that stores the number of polygons that each polygon encloses:
        for(i = 1; i <= N; i++){
            answerSet[enclosureSet[1][i]] = i - 1;
        }
//5. Printing the values:
        for(i = 1; i <= N; i++){
            printf("%d ", answerSet[i]);
        }
        printf("\n");
    }
    return 0;
}