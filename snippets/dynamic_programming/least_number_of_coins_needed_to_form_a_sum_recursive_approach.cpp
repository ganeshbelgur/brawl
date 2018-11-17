#include <bits/stdc++.h>
using namespace std;
#define INF 2147483646
#define MAX 10000


/*
 * Problem:
 * Given a set of coins, find the least number of coins required to 
 * form a sum N using a recursive dynamic programming approach.
 * 
 * Note:
 * Using a greedy approach does not work in all cases, that's when dynamic
 * programming steps in. This solutions also shows the concept of memoization.
 */


int value[MAX];
bool ready[MAX];
int coins[3] = {1, 3, 4};

int solve_coins(int x)
{
    if(x < 0) return INF;
    if(x == 0) return 0;
    if(ready[x]) return value[x];

    int best = INF;
    for (auto c : coins)
    {
        best = min(best, solve_coins(x-c)+1);
    }

    ready[x] = true;
    value[x] = best;

    return best;
}

int main()
{
    cout << "Value is -1, number of coins: " << solve_coins(-1) << endl;
    cout << "Value is 0, number of coins: " << solve_coins(0) << endl;
    cout << "Value is 1, number of coins: " << solve_coins(1) << endl;
    cout << "value is 2, number of coins: " << solve_coins(2) << endl;
    cout << "Value is 10, number of coins: " << solve_coins(10) << endl;
    cout << "Value is 20, number of coins: " << solve_coins(20) << endl;
    cout << "Value is " << MAX << ", number of coins: " << solve_coins(MAX) << endl;

    return 0;
}