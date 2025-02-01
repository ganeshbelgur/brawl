#include <bits/stdc++.h>
using namespace std;

vector<int> subset;

void search(int k, int n)
{
	if(k == n+1)
	{
		for(vector<int>::iterator i = subset.begin(); i != subset.end(); i++)
		{
			cout << *i << " ";
		}
		cout << endl;
	}
	else
	{
		subset.push_back(k);
		search(k+1, n);

		subset.pop_back();
		search(k+1, n);
	}
}

int main()
{
	search(1, 3);
	return 0;
}
