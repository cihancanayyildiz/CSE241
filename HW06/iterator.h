#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include <vector>
#include <set>
#include <list>
#include "exceptions.h"

namespace MyCollection{
template<typename E,typename container=std::vector<E> >
class Iterator{ // Our iterator.
public:
	// Taking container for begin iterator and end iterator.
	Iterator(container &c);
	
	//Returns true if the iteration has more elements.
	bool hasNext();

	// Returns the next element in the iteration.
	E Next() throw(NoElementException);

	/*We dont need this remove function. Actually this is an optional function in java collection hierarcihy and we are writing a 
	*java collection hierarchiy so
	*in my algorithm I dont need this remove function and I'm throwing an exception.*/
	void remove() throw(UnsupportedOperationException);

	//Getters for our iterators.
	typename container::iterator getIteratorBegin();

	typename container::iterator getIteratorEnd();

	//Increment and decrement operator overloads for iterators.
	typename container::iterator operator--();

	typename container::iterator operator--(int);

	typename container::iterator operator++();

	typename container::iterator operator++(int);

private:
	typename container::iterator iteratorBegin;
	typename container::iterator iteratorEnd;
};
}
#endif
