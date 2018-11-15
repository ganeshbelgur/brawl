#include <bits/stdc++.h>
using namespace std;
#define INF 2147483646
#define MAX 10000

int first[MAX] = {0};
int coins[3] = {1, 3, 4};
int value[MAX] = {0};

void construction()
{
    value[0] = 0;
    first[0] = 0;
    for(int x = 1; x <= MAX; x++)
    {
        value[x] = INF;
        for(auto c : coins)
        {
            if(x-c >= 0 && value[x-c]+1 < value[x])
            {
                value[x] = value[x-c] + 1;
                first[x] = c;
            }
        }
    }
}

void optimal_solution(int x)
{
    if(x <= 0)
    {
        cout << "No optimal solution exists..." << endl;
        return;
    }

    while(x > 0)
    {
        cout << first[x] << " ";
        x -= first[x];
    }
    cout << endl;
}

int main()
{
    construction();

    cout << "Value is -1, the coins are: " << endl;
    optimal_solution(-1);

    cout << "Value is 0, the coins are: " << endl;
    optimal_solution(0);

    cout << "Value is 1, the coins are: " << endl;
    optimal_solution(1);

    cout << "Value is 2, the coins are: " << endl;
    optimal_solution(2);

    cout << "Value is 3, the coins are: " << endl;
    optimal_solution(3);
    
    cout << "Value is 10, the coins are: " << endl;
    optimal_solution(10);

    cout << "Value is 20, the coins are: " << endl;
    optimal_solution(20);

    cout << "Value is " << MAX << ", the coins are: " << endl;
    optimal_solution(MAX);

    return 0;
}