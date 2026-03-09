#include<bits/stdc++.h>
using namespace std;

int main()
{
	map<string, int> m;
	
	cout << m.size() << endl; // Prints 0

	// Trying to access an element that doesn't 
	// exist addes that element to the map
	cout << m["hello"] << endl;

	cout << m.size() << endl; // Prints 1

	return 0;
}
