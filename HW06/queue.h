#ifndef QUEUE_H
#define QUEUE_H
#include "collection.h"
namespace MyCollection{

template<typename E,typename container = std::vector<E> >

class Queue : public virtual Collection<E,container> { // this is an virtual inheritence because linked list class inherit this and list class.

	virtual bool add(const E &e) = 0 ;

	virtual E element() = 0;

	virtual void offer(const E &e) = 0;

	virtual E poll() = 0;

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