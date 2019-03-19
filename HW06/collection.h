#ifndef COLLECTION_H
#define COLLECTION_H
#include "iterator.h"
#include "exceptions.h"
#include <vector>
namespace MyCollection{

template<typename E,typename container=std::vector<E> >
class Collection{	//Base abstract class.

public:

	virtual Iterator<E,container> iterator()  = 0;

	virtual bool add(const E &e) = 0;

	virtual bool addAll(Collection<E,container> &c) = 0;

	virtual void clear() = 0;

	virtual bool contains(const E &e) = 0;

	virtual bool containsAll(Collection<E,container> &c) = 0;

	virtual bool isEmpty() = 0;

	virtual void remove(const E &e) = 0;

	virtual void removeAll(Collection<E,container> &c) = 0;

	virtual void retainAll(Collection<E,container> &c) = 0;

	virtual int size() = 0;

};
}



#endif