#include "arraylist.h"

namespace MyCollection{
	
	template<typename E,typename container>
	// This function returns a container iterator for us.
	Iterator<E,container> ArrayList<E,container>::iterator()  {
		Iterator<E,container> iter(_c);
		return iter;
	}
	template<typename E,typename container>
	// Adds the element in this arraylist. Arraylist can have duplicate elements.
	bool ArrayList<E,container>::add(const E &e)   {
		Iterator<E,container> iter = iterator();

		for(int i=0; i<size();i++){
			iter.Next();
		}
		_c.insert(iter.getIteratorBegin(),e);
		return true;
	}
	template<typename E,typename container>
	// Adding all incoming collection's elements to our collection.If we can add all of them then returns true.Otherwise returns false.
	bool ArrayList<E,container>::addAll(Collection<E,container> &c)  {
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
	void ArrayList<E,container>::clear()  {
		_c.clear();
	}

	template<typename E,typename container>
	//Returns true if this collection contains the specified element.
	bool ArrayList<E,container>::contains(const E &e)  {
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
	bool ArrayList<E,container>::containsAll(Collection<E,container> &c)  {

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
	bool ArrayList<E,container>::isEmpty()  {
		return _c.size() == 0;
	}
	template<typename E,typename container>
	//Removes a single instance of the specified element from this collection.
	void ArrayList<E,container>::remove(const E &e)  {

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
	void ArrayList<E,container>::removeAll(Collection<E,container> &c)  {

		Iterator<E,container> otherIter = c.iterator();

		while(otherIter.hasNext()){
			remove(otherIter.Next());
		}

	}
	template<typename E,typename container>
	//Retains only the elements in this collection that are contained in the specified collection
	void ArrayList<E,container>::retainAll(Collection<E,container> &c)  {
		Iterator<E,container> myIter = iterator();
		ArrayList<E,container > temp;

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
	int ArrayList<E,container>::size()  {
		return _c.size();
	}

}
