// Phong Nguyen 7807
// Email: pnguyen003@citymail.cuny.edu
// The work in this assignment is my own. Any outside sources have been properly cited.
// CSc212 Assignment 5
// File Name: rec_fun.h
// Header File

// FUNCTION DOCUMENTATION:

// void binary_print(ostream& outs, unsigned int n);
// Postcondition: The function prints the value of n as binary. If n is 0 then a single 0 is printed. Else, there is no leading 0s printed.

// void triangle(ostream& outs, unsigned int m, unsigned int n);
// Precondition: m <= n
// Postcondition: The function has printed a pattern of 2*(n-m+1) lines
// to the output stream outs. The first line contains m asterisks, the next 
// line contains m+1 asterisks, and so on up to a line with n asterisks.
// Then the pattern is repeated backwards, going n back down to m.
/* Example output:
   triangle(cout, 3, 5) will print this to cout:
   ***
   ****
   *****
   *****
   ****
   ***
*/

// double pow(double x, int n);
// Precondition: If x is zero, then n must be positive.
// Postcondition: The value returned is x raised to the power n.

// void indented_sentences(size_t m, size_t n);
// Precondition: m <=n;
// Postcondition: print out the above pattern by calling number from m to n

#ifndef REC_FUN_H
#define REC_FUN_H
#include <iostream>
using namespace std;

namespace rec 
{
	void binary_print(ostream& outs, unsigned int n);
	void triangle(ostream& outs, unsigned int m, unsigned int n);
	double pow(double x, int n);
	void indented_sentences(size_t m, size_t n);
}
#endif