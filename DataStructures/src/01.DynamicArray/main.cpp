//Implement array list
#include<iostream>
#include "DynamicArray.h"

using namespace std;

int main()
{
	Vector<int> a(3);
	
	a.insert(0, 1);
	a.insert(1, 2);
	a.insert(2, 3);

	//retrieving data
	cout << a.at(0) << endl;
	cout << a.at(1) << endl;
	cout << a.at(2) << endl;
	cout << "the size of vector is : ";
	cout << a.size_of_list() << endl;// getting size
	a.reserve(10);// Increasing capacity

	//erasing and then checking for garbage
	a.erase(2);
	cout << a.at(2) << endl;
	
	return 0;
}