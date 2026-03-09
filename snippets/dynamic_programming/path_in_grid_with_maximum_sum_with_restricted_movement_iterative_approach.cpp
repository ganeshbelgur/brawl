#include <bits/stdc++.h>
using namespace std;

/*
 * Problem:
 * In a N X N array of non-negative numbers, find the sum of numbers in the path from 
 * the top left corner to the bottom right corner that is maximum given that one can 
 * move either one step towards the right or one step down at a time to reach the bottom
 * right corner. Use a iterative dynamic programming appraoch to solve the problem.
 *
 */

int sum[5][5];

void construction(int array[][5], int N)
{
    sum[0][0] = array[0][0];
    int sumx = array[0][0];
    int sumy = array[0][0];

    // Update the sum array with the sums in row 0 and column 0
    for(int i = 1; i < N; i++)
    {
        sumx += array[0][i];
        sumy += array[i][0];

        sum[0][i] = sumx;
        sum[i][0] = sumy;
    }

    // Compute the sums for the rest of the array
    for(int x = 1; x < N; x++)
    {
        for(int y = 1; y < N; y++)
        {
            sum[x][y] = max(sum[x][y-1], sum[x-1][y]) + array[x][y];
        }
    }
}

void print_solution()
{
    cout << "Printing the sum array: " << endl;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
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
    
    construction(array, 5);
    print_solution();

    return 0;
}