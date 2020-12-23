#include <iostream>
#include<utility>

using namespace std;

int main()
{
	pair<char, int>pair1 = make_pair('B', 1);
	pair<char, int>pair2 = make_pair('C', 2);

	cout << "Before swapping:\n " ;
	cout << "Contents of pair1 = "
		<< pair1.first << " " << pair1.second ;
	cout << "Contents of pair2 = "
		<< pair2.first << " " << pair2.second ;
	pair1.swap(pair2);

	cout << "\nAfter swapping:\n ";
	cout << "Contents of pair1 = "
		<< pair1.first << " " << pair1.second ;
	cout << "Contents of pair2 = "
		<< pair2.first << " " << pair2.second ;

	return 0;
}
