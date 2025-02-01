#include<bits/stdc++.h>
using namespace std;

vector<int> permutation;
bool chosen[4];

void search(int n)
{
	if(permutation.size() == n)
	{
		for (vector<int>::iterator i = permutation.begin(); i != permutation.end(); i++)
		{
			cout << *i << " ";
		}
		cout << endl;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if(chosen[i]) continue;

			chosen[i] = true;
			permutation.push_back(i);
			search(n);
			chosen[i] = false;
			permutation.pop_back();
		}
	}
}

int main()
{
	search(3);
	return 0;
}
