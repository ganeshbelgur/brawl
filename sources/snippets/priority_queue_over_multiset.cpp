#include <bits/stdc++.h>
using namespace std;

// While a multiset provides all the features of priority
// queues, the benefit of using a priority queue is that
// it has smaller "constant factors"

int main()
{
	// By default, the elements in a C++ priority
	// queue is sorted in decreasing order
	priority_queue<int> q;

	q.push(3);
	q.push(5);
	q.push(7);
	q.push(2);

	cout << q.top() << "\n"; // 7
	q.pop();

	cout << q.top() << "\n"; // 5
	q.pop();

	q.push(6);
	cout << q.top() << "\n"; // 6

	// Priority queue for finding and removal of
	// smallest elements
	priority_queue<int, vector<int>, greater<int>> sq;
	
	sq.push(3);
	sq.push(5);
	sq.push(7);
	sq.push(2);

	cout << sq.top() << "\n"; // 2

	sq.pop();
	cout << sq.top() << "\n"; // 3

	return 0;
}

