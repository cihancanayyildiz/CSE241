#include "iterator.h"

namespace MyCollection{
	template<typename E,typename container>
	Iterator<E,container>::Iterator(container &c){ // Taking container for begin iterator and end iterator.
		iteratorBegin = c.begin();
		iteratorEnd = c.end();
	}
	template<typename E,typename container>
	bool Iterator<E,container>::hasNext(){	//Returns true if the iteration has more elements.
		return iteratorBegin!=iteratorEnd;
	}
	template<typename E,typename container>
	E Iterator<E,container>::Next() throw(NoElementException){ // Returns the next element in the iteration.
		if(hasNext()){
			return *(iteratorBegin)++;
		}
		else{
			throw NoElementException();
		}
	}
	template<typename E,typename container>
	/*We dont need this remove function. Actually this is an optional function in java collection hierarcihy and we are writing a 
	*java collection hierarchiy so
	*in my algorithm I dont need this remove function and I'm throwing an exception.*/ 
	void Iterator<E,container>::remove() throw(UnsupportedOperationException){	
		throw UnsupportedOperationException();
	}
	template<typename E,typename container>
	//Getters for our iterators.
	typename container::iterator Iterator<E,container>::getIteratorBegin(){
		return iteratorBegin;
	}
	template<typename E,typename container>
	typename container::iterator Iterator<E,container>::getIteratorEnd(){
		return iteratorEnd;
	}

	template<typename E,typename container>
	//Increment and decrement operator overloads for iterators.
	typename container::iterator Iterator<E,container>::operator--(){
		iteratorBegin--;
		return iteratorBegin;
	}
	template<typename E,typename container>
	typename container::iterator Iterator<E,container>::operator--(int){
		typename container::iterator temp=iteratorBegin;
		iteratorBegin--;
		return temp;
	}
	template<typename E,typename container>
	typename container::iterator Iterator<E,container>::operator++(){
		iteratorBegin++;
		return iteratorBegin;
	}
	template<typename E,typename container>
	typename container::iterator Iterator<E,container>::operator++(int){
		typename container::iterator temp=iteratorBegin;
		iteratorBegin++;
		return temp;
	}
}
