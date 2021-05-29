// Phong Nguyen 7807
// Email: pnguyen003@citymail.cuny.edu
// The work in this assignment is my own. Any outside sources have been properly cited.
// CSc212 Assignment 5
// File Name: rec_fun.cpp
// Implementation file
#include <iostream>
#include "rec_fun.h"
#include <cassert>

void rec::binary_print(ostream& outs, unsigned int n)
{
    if (n < 2)
    {
        outs << n;
        return; 
    }
    else
    {
        binary_print(outs, n / 2);
        outs << n % 2;
    }
}

void rec::triangle(ostream& outs, unsigned int m, unsigned int n)
{
    if (m <= n)
    {
        for (int i = 0; i < m; i++)
        {
            outs << "*";
        }

        outs << endl;

        triangle(cout, m + 1, n);

        for (int i = 0; i < m; i++)
        {
            outs << "*";
        }

        outs << endl;
    }
}

double rec::pow(double x, int n)
{
    if(x == 0)
    { 
        assert(n > 0); // precondition
        return 0;
    }
    else if(n == 0)
    { return 1; } // any number (besides 0) raised to the 0 power is 1
    else if ((n % 2) == 0)
    { return pow(x, n/2) * pow(x, n/2); }
    else if (n < 0)
    { return 1 / pow(x, -n); }
    else
    { return x * pow(x,n-1); }
}


void rec::indented_sentences(size_t m, size_t n) 
{
    if (m <= n)
    {
        string indents = "";
        for (size_t i = 0; i < m; i++)
        {
            indents += " ";
        }
        std::cout << indents << "This was written by calling number " << m << "." << endl;

        indented_sentences(m+1, n);
        indents = "";
        for (size_t i = 0; i < m; i++)
        {
            indents += " ";
        }
        std::cout << indents << "This was ALSO written by calling number " << m << "." << endl;
    }
}