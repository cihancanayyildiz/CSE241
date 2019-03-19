#ifndef LIST_H
#define LIST_H
#include "collection.h"

namespace MyCollection{

template<typename E,typename container = std::vector<E> >
class List : public virtual Collection<E,container> { // this is an virtual inheritence because linked list class inherit this and queue class.

	/*
	*
	*
	*
	* Takes all collection functions with inheritance.
	*
	*
	*
	*
	*/
};

}

#endif