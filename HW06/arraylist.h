#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "list.h"

namespace MyCollection{

template<typename E,typename container=std::vector<E> >
class ArrayList : public List<E,container> {
public:

	// This function returns a container iterator for us.
	Iterator<E,container> iterator() override;

	// Adds the element in this arraylist. Arraylist can have duplicate elements.
	bool add(const E &e) override;

	// Adding all incoming collection's elements to our collection.If we can add all of them then returns true.Otherwise returns false.
	bool addAll(Collection<E,container> &c) override;

	//Clearing the container.
	void clear() override;

	//Returns true if this collection contains the specified element.
	bool contains(const E &e) override;

	//Returns true if this collection contains all of the elements in the specified collection.
	bool containsAll(Collection<E,container> &c) override;
	//Returns true if this collection contains no elements
	bool isEmpty() override;

	//Removes a single instance of the specified element from this collection.
	void remove(const E &e) override;

	//Removes all of this collection's elements that are also containedin the specified collection
	void removeAll(Collection<E,container> &c) override;

	//Retains only the elements in this collection that are contained in the specified collection
	void retainAll(Collection<E,container> &c) override;
	//Returns the size.
	int size() override;

private:
	container _c;

};
}

#endif