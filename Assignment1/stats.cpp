// Provided by:   Phong Nguyen 7807
// The work in this assignment is my own. Any outside sources have been properly cited.
// Email Address: pnguyen003@citymail.cuny.edu
// FILE: stats.cxx
#include <iostream>
#include <assert.h> //ASSERT FOR PRECONDITIONS
#include "stats.h"

namespace main_savitch_2C
{
	// CONSTRUCTOR
	statistician::statistician()
		//     Postcondition: The object has been initialized, and is ready to accept
		//     a sequence of numbers. Various statistics will be calculated about the
		//     sequence.
	{
		count = 0;
		total = 0;
		tinyest = 0;
		largest = 0;
	}

	// MODIFICATION MEMBER FUNCTIONS
	void statistician::next(double r)
		//     The number r has been given to the statistician as the next number in
		//     its sequence of numbers.
	{
		if (count == 0) //If r is first number in sequence
		{
			count = 1;
			total = r;
			tinyest = r;
			largest = r;
			return;
		}

		count += 1;
		total += r;

		if (r < tinyest) //If r is smaller than previous, replace smallest with r
		{tinyest = r;}

		if (r > largest) //If r is larger than previous, replace largest with r
		{largest = r;}
	}

	void statistician::reset()
		//     Postcondition: The statistician has been cleared, as if no numbers had
		//     yet been given to it.
	{
		count = 0; //RESET NUMBERS IN SEQUENCE
		total = 0; //RESET SUM OF NUMBERS IN SEQUENCE
		tinyest = 0; //RESET MIN NUMBER IN SEQUENCE
		largest = 0; //RESET MAX NUMBER IN SEQUENCE
	}

	// CONSTANT MEMBER FUNCTIONS
	int statistician::length() const
		//     Postcondition: The return value is the length of the sequence that has
		//     been given to the statistician (i.e., the number of times that the
		//     next(r) function has been activated).
	{return count;}

	double statistician::sum() const
		//     Postcondition: The return value is the sum of all the numbers in the
		//     statistician's sequence.
	{return total;}

	double statistician::mean() const
		//     Precondition: length( ) > 0
		//     Postcondition: The return value is the arithmetic mean (i.e., the
		//     average of all the numbers in the statistician's sequence).
	{
		assert(length() > 0); //PRECONDITION
		double avg = 0;
		avg = total / count;
		return avg;
	}

	double statistician::minimum() const
		//     Precondition: length( ) > 0
		//     Postcondition: The return value is the tinyest number in the
		//     statistician's sequence.
	{
		assert(length() > 0); //PRECONDITION
		return tinyest;
	}

	double statistician::maximum() const
		//     Precondition: length( ) > 0
		//     Postcondition: The return value is the largest number in the
		//     statistician's sequence.
	{
		assert(length() > 0); //PRECONDITION
		return largest;
	}

	// FRIEND FUNCTIONS
	statistician operator + (const statistician& s1, const statistician& s2)
		//     Postcondition: The statistician that is returned contains all the
		//     numbers of the sequences of s1 and s2.
	{
		statistician s3;
		s3.count = s1.count + s2.count;
		s3.total = s1.total + s2.total;

		if (s1.tinyest < s2.tinyest)
		{s3.tinyest = s1.tinyest;}
		else { s3.tinyest = s2.tinyest; }

		if (s1.largest > s2.largest)
		{s3.largest = s1.largest;}
		else { s3.largest = s2.largest; }
		return s3;
	}

	statistician operator * (double scale, const statistician& s)
		//     Postcondition: The statistician that is returned contains the same
		//     numbers that s does, but each number has been multiplied by the
		//     scale number.
	{
		statistician product; //product of statistician and scale number
		product.count = s.count;
		product.total = s.total * scale;

		if (scale < 0)
		{
			product.tinyest = s.largest * scale;
			product.largest = s.tinyest * scale;
		}

		else 
		{
			product.tinyest = s.tinyest * scale;
			product.largest = s.largest * scale;
		}
		return product;
	}

	// NON-MEMBER functions for the statistician class
	bool operator== (const statistician& s1, const statistician& s2)
		//     Postcondition: The return value is true if s1 and s2 have the zero
		//     length. Also, if the length is greater than zero, then s1 and s2 must
		//     have the same length, the same  mean, the same minimum, 
		//     the same maximum, and the same sum.
	{
		if (s1.length() == 0 && s2.length() == 0) //if s1 and s2 have 0 length, return true
		{return true;}

		return (s1.length() == s2.length());
	}
}