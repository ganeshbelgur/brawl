#include <bits/stdc++.h>
using namespace std;
#define TOTAL_SUM_OF_WEIGHTS 13
#define NUMBER_OF_WEIGHTS 5

/*
 * Problem:
 * Given a set of weights, find all possible weights using those weights
 * with the help of an iterative dynamic programming approach.
 *
 */

int weights[NUMBER_OF_WEIGHTS] = {0, 1, 3, 3, 5};
bool possible[NUMBER_OF_WEIGHTS][TOTAL_SUM_OF_WEIGHTS];

void construction()
{
    possible[0][0] = true;
    for(int k = 1; k < NUMBER_OF_WEIGHTS; k++)
    {
        for(int x = 0; x < TOTAL_SUM_OF_WEIGHTS; x++)
        {
            if(x-weights[k] >= 0)
            {
                possible[k][x] |= possible[k-1][x-weights[k]];
            }
            possible[k][x] |= possible[k-1][x];
        }
    }
}

void print_solution()
{
    cout << "Array of possibilities: " << endl;
    for(int i = 0; i < NUMBER_OF_WEIGHTS; i++)
    {
        for(int j = 0; j < TOTAL_SUM_OF_WEIGHTS; j++)
        {
            cout << possible[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    construction();
    print_solution();
    
    return 0;
}