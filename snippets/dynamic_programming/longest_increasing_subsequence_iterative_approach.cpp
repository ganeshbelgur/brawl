#include <bits/stdc++.h>
using namespace std;
#define MAX 10000


/*
 * Problem:
 * Given an array of random integers, find the length of the longest
 * subsequence in the array using iterative dynamic programming appraoch.
 *
 */


int lengthSubSequence[MAX];

void construction(int array[], int size)
{
    for(int x = 0; x < size; x++)
    {
        lengthSubSequence[x] = 1;
        for(int y = 0; y < x; y++)
        {
            if(array[y] < array[x])
            {
                lengthSubSequence[x] = max(lengthSubSequence[x], lengthSubSequence[y] + 1);
            }
        }
    }
}

void max_subsequence_length(int size)
{
    int max = 0;
    for(int i = 0; i < size; i++)
    {
        if(lengthSubSequence[i] > max)
            max = lengthSubSequence[i];
    }

    cout << "Length of the longest subsequence is " << max << endl;
}

int main()
{
    int array[8] = {6, 2, 5, 1, 7, 4, 8, 3};

    cout << "Array elements are: " << endl;
    for(auto i : array)
    {
        cout << i << " ";
    }
    cout << endl;

    construction(array, 8);
    max_subsequence_length(8);

    return 0;
}
