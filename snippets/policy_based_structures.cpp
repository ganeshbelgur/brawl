#include <bits/stdc++.h>

// Policy Based Structures are not part of the C++ STL but
// provided by the gcc compiler
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

// Speciality of indexed_set is we have access to the indices in the set
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main()
{
	indexed_set s;

	s.insert(2);
	s.insert(3);
	s.insert(7);
	s.insert(9);
	
	// Returns an iterator to the element at a given position
	auto x = s.find_by_order(2);
	cout << *x << "\n"; // 7

	// Returns the position of a given element
	cout << s.order_of_key(7) << "\n"; // 2
	
	// Returns the possible position if an element doesn't exist
	cout << s.order_of_key(6) << "\n"; // 2
	cout << s.order_of_key(8) << "\n"; // 3

	return 0;
}
