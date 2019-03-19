#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "queue.h"
#include "list.h"
namespace MyCollection{
template<typename E,typename container=std::vector<E> >
class LinkedList : public Queue <E,container> ,public List <E,container> {

public:
	// This function returns a container iterator for us.
	Iterator<E,container> iterator() override;
	// Adds the element in this arraylist. Arraylist can have duplicate elements.
	bool add (const E &e) override;

	//Retrieves, but does not remove, the head of this linkedlist.
	E element() override;

	//Inserts the specified element into this linkedlist.
	void offer(const E &e) override;

	//Retrieves and removes the head of this queue, or throws if this queue is empty.
	E poll()  throw(NoSuchElementException);

	// Adding all incoming collection's elements to our collection.If we can add all of them then returns true.Otherwise returns false.
	bool addAll(Collection<E,container> &c) override;
	//Clearing the container.
	void clear()  override;

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