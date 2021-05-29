// Phong Nguyen 7807
// Email: pnguyen003@citymail.cuny.edu
// The work in this assignment is my own. Any outside sources have been properly cited.
// CSc212 Assignment 5
// File Name: rec_funexam.cpp
// Test file

#include <iostream>
#include "rec_fun.h"
using namespace std;
using namespace rec;
int main()
{
	// Testing Binary Print function
	cout << "Testing Binary Print Function" << endl;
	cout << "n = 0" << endl;
	binary_print(cout, 0);

	cout << endl << endl << "n = 2" << endl;
	binary_print(cout, 2);

	cout << endl << endl << "n = 56" << endl;
	binary_print(cout, 56);

	cout << endl << endl << "n = 182" << endl;
	binary_print(cout, 182);

	// Testing Triangle Function
	cout << endl << "Testing Triangle Function with m=3 and n=5" << endl;
	triangle(cout, 3, 5);

	cout << endl << "m=4 and n=8" << endl;
	triangle(cout, 4, 8);

	// Testing Pow Function
	cout << endl << "Testing Pow Function" << endl;
	cout << "4^0 is equal to " << rec::pow(4, 0) << endl;
	cout << "2^3 is equal to " << rec::pow(2, 3) << endl;
	cout << "5^-4 is equal to " << rec::pow(5, -4) << endl;

	// Testing Indented Sentences Function
	cout << endl << "Testing Indented Sentences Function" << endl;
	indented_sentences(1, 7);
	return 0;
}