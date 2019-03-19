#include "linkedlist.h"

namespace MyCollection{
	template<typename E,typename container>
	// This function returns a container iterator for us.
	Iterator<E,container> LinkedList<E,container>::iterator()  {
		Iterator<E,container> iter(_c);
		return iter;
	}
	template<typename E,typename container>
	// Adds the element in this arraylist. Arraylist can have duplicate elements.
	bool LinkedList<E,container>::add (const E &e)  {
		Iterator<E,container> iter = iterator();

		for(int i=0; i<size();i++){
			iter.Next();
		}
		_c.insert(iter.getIteratorBegin(),e);
		return true;
	}
	template<typename E,typename container>
	//Retrieves, but does not remove, the head of this linkedlist.
	E LinkedList<E,container>::element()  {
		Iterator<E,container> iter = iterator();

		return iter.Next();
	}
	template<typename E,typename container>
	//Inserts the specified element into this linkedlist.
	void LinkedList<E,container>::offer(const E &e)  {
		
		Iterator<E,container> iter = iterator();

		for(int i=0; i<size();i++){
			iter.Next();
		}
		_c.insert(iter.getIteratorBegin(),e);

	}
	template<typename E,typename container>
	//Retrieves and removes the head of this queue, or throws if this queue is empty.
	E LinkedList<E,container>::poll()  throw(NoSuchElementException){

		if(isEmpty()){
			throw NoSuchElementException();
		}
		else{
			Iterator<E,container> iter = iterator();
			E temp = *iter.getIteratorBegin();

			 _c.erase(iter.getIteratorBegin());

			return temp;
		}
		
	}
	template<typename E,typename container>
	// Adding all incoming collection's elements to our collection.If we can add all of them then returns true.Otherwise returns false.
	bool LinkedList<E,container>::addAll(Collection<E,container> &c)  {
		Iterator<E,container> otherIter = c.iterator();

		if(c.isEmpty()){
			return false;
		}

		while(otherIter.hasNext()){
			add(otherIter.Next());
		}

		return true;
	}
	template<typename E,typename container>
	//Clearing the container.
	void LinkedList<E,container>::clear()   {
		_c.clear();
	}
	template<typename E,typename container>
	//Returns true if this collection contains the specified element.
	bool LinkedList<E,container>::contains(const E &e)  {
		Iterator<E,container> iter = iterator();

		while(iter.hasNext()){
			if(iter.Next()== e){
				return true;
			}
		}

		return false;
	}
	template<typename E,typename container>
	//Returns true if this collection contains all of the elements in the specified collection.
	bool LinkedList<E,container>::containsAll(Collection<E,container> &c)  {
		Iterator<E,container> otherIter = c.iterator();

		bool res=true;

		while(otherIter.hasNext()){
			if(!(contains(otherIter.Next()))){
				res = false;
			}
		}

		return res;

	}
	template<typename E,typename container>
	//Returns true if this collection contains no elements
	bool LinkedList<E,container>::isEmpty()  {
		return _c.size() == 0;
	}

	template<typename E,typename container>
	//Removes a single instance of the specified element from this collection.
	void LinkedList<E,container>::remove(const E &e)  {
		Iterator<E,container> iter = iterator();

		if(*iter.getIteratorBegin() == e){
			_c.erase(iter.getIteratorBegin());
			return;
		}
		else{
			while(iter.hasNext()){
				if(iter.Next() == e){
					_c.erase(--iter.getIteratorBegin());
					return;
				}
			}
		}
	}
	template<typename E,typename container>
	//Removes all of this collection's elements that are also containedin the specified collection
	void LinkedList<E,container>::removeAll(Collection<E,container> &c)  {
		Iterator<E,container> otherIter = c.iterator();

		while(otherIter.hasNext()){
			remove(otherIter.Next());
		}
	}
	template<typename E,typename container>
	//Retains only the elements in this collection that are contained in the specified collection
	void LinkedList<E,container>::retainAll(Collection<E,container> &c)  {
		Iterator<E,container> myIter = iterator();
		LinkedList<E,container > temp;

		while(myIter.hasNext()){
			if( !(c.contains(myIter.Next())) ){
				--myIter;
				temp.add(myIter.Next());
			}
		}

		removeAll(temp);
	}
	template<typename E,typename container>
	//Returns the size.
	int LinkedList<E,container>::size()  {
		return _c.size();
	}
}


