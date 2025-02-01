#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
#define m 1000000007


/*
 * Problem:
 * Given a set of coins, find the total number of ways to form a 
 * sum N using those coins with an iterative dynamic programming
 * appraoch. Since the solution can become too long, use modulo 
 * of 10 ^ 9 + 7 for the generated solution.
 *
 */


long long int counter[MAX];
int coins[3] = {1, 3, 4};

void construction()
{
    counter[0] = 1;
    for(int x = 1; x <= MAX; x++)
    {
        for(auto c : coins)
        {
            if(x - c >= 0)
            {
                counter[x] += counter[x - c];
                counter[x] %= m;
            }
        }
    }
}

void number_of_ways(int x)
{
    if(x < 0)
    {
        cout << "0";
    }
    else
    {
        printf("%lld", counter[x]);
    }

    cout << endl;
}

int main()
{   
    construction();
    cout << "Value is -1, number of ways: " << endl;
    number_of_ways(-1);

    cout << "Value is 0, number of ways: " << endl;
    number_of_ways(0);

    cout << "Value is 1, number of ways: " << endl;
    number_of_ways(1);

    cout << "value is 2, number of ways: " << endl;
    number_of_ways(2);

    cout << "value is 5, number of ways: " << endl;
    number_of_ways(5);

    cout << "Value is 10, number of ways: " << endl;
    number_of_ways(10);

    cout << "Value is 20, number of ways: " << endl;
    number_of_ways(20);

    cout << "Value is " << MAX << ", number of ways: " << endl;
    number_of_ways(MAX);

    return 0;
}