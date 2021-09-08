// Name: Phong Nguyen 7807
// The work in this assignment is my own. Any outside sources have been properly cited.
// FILE: sequence1.cxx
#include <iostream>
#include <cassert>	// ASSERT FOR PRECONDITIONS
#include "sequence1.h"
using namespace std;

namespace main_savitch_3 
{
// TYPEDEFS and MEMBER CONSTANTS for the sequence class:
	typedef double value_type;
	typedef size_t size_type;
	static const size_type CAPACITY = 30;

// CONSTRUCTOR for the sequence class:
	sequence::sequence()
	{
	 used = 0; //the amount of the array used is set to 0
	 current_index = 0; //the current index is set to 0
	 data[current_index] = 0; // array initialized
    }

// MODIFICATION MEMBER FUNCTIONS for the sequence class:
	void sequence::start()
//		Postcondition: The first item on the sequence becomes the current item
//		(but if the sequence is empty, then there is no current item).
	{ current_index = 0; }

	void sequence::advance()
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
	{
	 assert(is_item());
	 current_index++;
	}

	void sequence::insert(const value_type& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been inserted in the sequence
//     before the current item. If there was no current item, then the new entry 
//     has been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
	{
	assert(size() < CAPACITY);
	if (!is_item()) // if there is no current item
	{current_index = 0;}
	for (size_type i = used; i > current_index; --i)
	{data[i] = data[i - 1];}
	data[current_index] = entry;
	++used;
	}
	// REFERENCED FROM Data Structures and Other Objects Using C++ PAGE 131 

	void sequence::attach(const value_type& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has 
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
	{
	assert(size() < CAPACITY);
	if (!is_item()) // if there is no current item
	{ 
	data[current_index] = entry;
	}
	else
	{
		for (size_type i = used; i > current_index; --i)
		{
			data[i] = data[i - 1];
		}
		data[current_index + 1] = entry;
		current_index += 1;
	}

 	++used; 
	}

	void sequence::remove_current()
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and the
//     item after this (if there is one) is now the new current item.
	{
	assert(is_item());
	for (size_type i = current_index;i < used; ++i)
	{ data[i] = data[i + 1]; }
	--used;
	// REFERENCED FROM Data Structures and Other Objects Using C++ PAGE 131 The Sequence Class—Pseudocode for the Implementation
    }

// CONSTANT MEMBER FUNCTIONS for the sequence class:
	size_type sequence::size() const
//     Postcondition: The return value is the number of items in the sequence.
	{
		return used;
    }

	bool sequence::is_item() const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
	{
	return (current_index < used);
	}
	
	value_type sequence::current() const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sequence.
	{
	assert(is_item());
	return data[current_index];
	}

}