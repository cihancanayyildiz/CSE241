#include "hashset.h"

namespace MyCollection{

	template<typename E,typename container>
	Iterator<E,container> HashSet<E,container>::iterator()  { 
		Iterator<E,container> iter(_c);
		return iter; 
	}

	template<typename E,typename container>
	// Adds the element in this set.
	bool HashSet<E,container>::add(const E &e)  {

		Iterator<E,container> iter = iterator();

		while(iter.hasNext()){	// Checking next.
			if(iter.Next() == e){	// Control for duplicate elements.
				return false;
			}
		}

		_c.insert(iter.getIteratorBegin(),e);	// Adding it.
		return true;

	}
	template<typename E,typename container>
	// Adding all incoming collection's elements to our collection.If we can add all of them then returns true.Otherwise returns false.
	bool HashSet<E,container>::addAll(Collection<E,container > &c)  {
	
		Iterator<E,container> otherIter = c.iterator();

		bool res=true;

		while(otherIter.hasNext()){
			if(!(add(otherIter.Next()))){
				res=false;
			}
		}

		return res;

	}
	template<typename E,typename container>
	//Clearing the container.
	void HashSet<E,container>::clear()  {
		_c.clear();
	}
	template<typename E,typename container>
	//Returns true if this collection contains the specified element
	bool HashSet<E,container>::contains(const E &e)  {
		Iterator<E,container> iter = iterator();

		while(iter.hasNext()){
			if(iter.Next() == e){
				return true;
			}
		}

		return false;
		
	}
	template<typename E,typename container>
	//Returns true if this collection contains all of the elements in the specified collection.
	bool HashSet<E,container>::containsAll(Collection<E,container > &c)  {

		if(c.isEmpty()){
			return false;
		}

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
	bool HashSet<E,container>::isEmpty()  {
		return _c.size() == 0;
	}
	template<typename E,typename container>
	//Removes a single instance of the specified element from this collection.
	void HashSet<E,container>::remove(const E &e)  {
		Iterator<E,container> iter = iterator();

		if(*iter.getIteratorBegin() == e){	// If the first element equals to e then removes that.
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
	void HashSet<E,container>::removeAll(Collection<E,container > &c)  {

		Iterator<E,container> otherIter = c.iterator(); // iterator for incoming collection.

		while(otherIter.hasNext()){
			remove(otherIter.Next());
		}
		
	}
	template<typename E,typename container>
	//Retains only the elements in this collection that are contained in the specified collection
	void HashSet<E,container>::retainAll(Collection<E,container > &c)  {
		Iterator<E,container> myIter = iterator();
		HashSet<E,container > temp;	 // creating a temp hashset.

		while(myIter.hasNext()){
			if( !(c.contains(myIter.Next())) ){
				--myIter;
				temp.add((*myIter.getIteratorBegin()));
				myIter.Next();
			}
		}

		removeAll(temp);

	}
	template<typename E,typename container>
	//Returns the size.
	int HashSet<E,container>::size() {
		return _c.size();
	}

}