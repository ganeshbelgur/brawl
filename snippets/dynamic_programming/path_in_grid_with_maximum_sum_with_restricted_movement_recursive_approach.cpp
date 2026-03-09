#include <bits/stdc++.h>
using namespace std;

/*
 * Problem:
 * In a N X N array of non-negative numbers, find the sum of numbers in the path from 
 * the top left corner to the bottom right corner that is maximum given that one can 
 * move either one step towards the right or one step down at a time to reach the bottom
 * right corner. Use a recursive dynamic programming appraoch to solve the problem.
 *
 */

int sum[5][5] = {
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1
};

int sum_in_matrix(int array[][5], int x, int y)
{
    if(x < 0 || y < 0) return 0;
    if(x == 0 && y == 0) return array[0][0];
    if(sum[x][y] != -1) return sum[x][y];

    sum[x][y] = max(sum_in_matrix(array, x-1, y), sum_in_matrix(array, x, y-1)) + array[x][y];
    return sum[x][y];
}

int main()
{
    int array[5][5] = { 
        3, 7, 9, 2, 7,
        9, 8, 3, 5, 5,
        1, 7, 9, 8, 5,
        3, 8, 6, 4, 10,
        6, 3, 9, 7, 8 
    };
    
    sum[0][0] = array[0][0];
    cout << "The sum of numbers in the path that is maximum is " << sum_in_matrix(array, 4, 4) << endl;
    
    cout << "Printing the sum array: " << endl;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}