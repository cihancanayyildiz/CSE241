#include <iostream>

#include "iterator.cpp"
#include "hashset.cpp"
#include "arraylist.cpp"
#include "linkedlist.cpp"

using namespace MyCollection;
using std::cout;
using std::endl;
using std::set;
using std::vector;
using std::list;
using std::string;


template<typename T,typename container >
void printcontainer(Iterator<T,container> iter);	// Print function for containers.
void testHashSet();	// hashset test function.
void testArrayList();	// arraylist test function.
void testLinkedList();	// linkedlist test function.

int main(){

	// Using try catch in client code.
	try{
		testHashSet();
		testArrayList();
		testLinkedList();
	}
	catch(UnsupportedOperationException &e){
		cout << e.what() << endl;
	}
	catch(NoElementException &e){
		cout << e.what() << endl;
	}
	catch(NoSuchElementException &e){
		cout << e.what() << endl;
	}
	
	return 0;
}

template<typename T,typename container >
void printcontainer(Iterator<T,container> iter){

	while(iter.hasNext())
	{
		cout << iter.Next() << " , " ;
	}
	cout << endl;
}

void testHashSet(){

	cout << "<-------------------------------------------------------Testing HashSet -- >" << endl;
	HashSet<int,set<int> > MySet;	// you can add an another container vector,list ..
	cout << "is it added ? : " << MySet.add(50) << endl;
	cout << "is it added ? : " << MySet.add(100) << endl;
	cout << "We cant add duplicated elements : " << MySet.add(100) << endl;
	cout << "We cant add duplicated elements : " << MySet.add(50) << endl;
	cout << "We cant add duplicated elements : " << MySet.add(100) << endl;

	HashSet<int,set<int> > OtherSet;
	cout << "is it added ? : " << OtherSet.add(150) << endl;
	cout << "is it added ? : " << OtherSet.add(200) << endl;

	cout << "is it all added ? : " << MySet.addAll(OtherSet) << endl;

	cout << "Myset : " ; printcontainer(MySet.iterator());

	cout << "Otherset : " ; printcontainer(OtherSet.iterator());

	cout << "is it contains ? : " << MySet.contains(50) << endl;
	cout << "is it contains ? : " << MySet.contains(35) << endl;

	cout << "MySet contains all members of otherset ? : " << MySet.containsAll(OtherSet) << endl;

	cout << "is Myset Empty ? :" << MySet.isEmpty() << endl;

	cout << "Removed 50 from myset : " ; MySet.remove(50) ; printcontainer(MySet.iterator());

	cout << "Removed all otherset from myset : " ; MySet.removeAll(OtherSet) ; printcontainer(MySet.iterator());

	cout << "is it added ? : " << MySet.add(52) << endl;
	cout << "is it added ? : " << MySet.add(53) << endl;
	cout << "is it added ? : " << MySet.add(150) << endl;
	cout << "is it added ? : " << MySet.add(200) << endl;

	cout << "MySet : " ; printcontainer(MySet.iterator());
	cout << "Otherset : " ; printcontainer(OtherSet.iterator());
	cout << "Retain All that are contained in the OtherSet : " ; MySet.retainAll(OtherSet) ; printcontainer(MySet.iterator());

	cout << "Size of MySet : " << MySet.size() << endl;

	MySet.clear();
	OtherSet.clear();

	cout << " HashSet string test ..." << endl;

	HashSet<string,set<string> > MyStringSet;

	MyStringSet.add("cihan");
	MyStringSet.add("can");

	HashSet<string,set<string> > OtherStringSet;

	OtherStringSet.add("ayyildiz");

	MyStringSet.addAll(OtherStringSet);

	cout << "is it contains 'cihan' ? : " << MyStringSet.contains("cihan") << endl;

	cout << "is it contains all elements of other set ? :" << MyStringSet.containsAll(OtherStringSet) << endl;

	printcontainer(MyStringSet.iterator());

	MyStringSet.retainAll(OtherStringSet);

	printcontainer(MyStringSet.iterator());

}

void testArrayList(){
	cout << "<-------------------------------------------------------Testing ArrayList -- >" << endl;
	ArrayList<int,vector<int> > MyList;	// you can add an another container list,set ..
	cout << "is it added ? : " << MyList.add(5) << endl;
	cout << "is it added ? : " << MyList.add(10) << endl;
	cout << "is it added ? : " << MyList.add(13) << endl;
	cout << "it it added ? : " << MyList.add(15) << endl;
	cout << "We can add duplicated elements : " << MyList.add(10) << endl;
	cout << "We can add duplicated elements : " << MyList.add(5) << endl;
	

	ArrayList<int,vector<int> > OtherList;
	cout << "is it added 15 ? : " << OtherList.add(15) << endl;
	cout << "is it added 20 ? : " << OtherList.add(20) << endl;

	cout << "is it all added ? : " << MyList.addAll(OtherList) << endl;

	cout << "MyList : " ; printcontainer(MyList.iterator());

	cout << "OtherList : " ; printcontainer(OtherList.iterator());

	cout << "is it contains 5 ? : " << MyList.contains(5) << endl;
	cout << "is it contains 3 ? : " << MyList.contains(3) << endl;

	cout << "MyList contains all members of OtherList ? : " << MyList.containsAll(OtherList) << endl;

	cout << "is MyList Empty ? :" << MyList.isEmpty() << endl;

	cout << "Removed 13 from MyList : " ; MyList.remove(13) ; printcontainer(MyList.iterator());

	cout << "Removed all OtherList from MyList: " ; MyList.removeAll(OtherList) ; printcontainer(MyList.iterator());

	cout << "is it added 52 ? : " << MyList.add(52) << endl;
	cout << "is it added 53? : " << MyList.add(53) << endl;
	cout << "is it added 150? : " << MyList.add(150) << endl;
	cout << "is it added 200? : " << MyList.add(200) << endl;

	cout << "MyList : " ; printcontainer(MyList.iterator());
	cout << "OtherList : " ; printcontainer(OtherList.iterator());
	cout << "Retain All that are contained in the OtherList : " ; MyList.retainAll(OtherList) ; printcontainer(MyList.iterator());

	cout << "Size of MyList : " << MyList.size() << endl;

	MyList.clear();
	OtherList.clear();

	cout << " ArrayList string test ..." << endl;

	ArrayList<string,vector<string> > MyStringList;

	MyStringList.add("cihan");
	MyStringList.add("can");

	ArrayList<string,vector<string> > OtherStringList;

	OtherStringList.add("ayyildiz");

	MyStringList.addAll(OtherStringList);

	cout << "is it contains 'cihan' ? : " << MyStringList.contains("cihan") << endl;

	cout << "is it contains all elements of other set ? :" << MyStringList.containsAll(OtherStringList) << endl;

	printcontainer(MyStringList.iterator());
	
	MyStringList.retainAll(OtherStringList);

	printcontainer(MyStringList.iterator());
}


void testLinkedList(){
	cout << "<-------------------------------------------------------Testing LinkedList -- >" << endl;
	LinkedList<int,list<int> > MyList;	// you can add an another container vector,set ..
	cout << "is it added ? : " << MyList.add(5) << endl;
	cout << "is it added ? : " << MyList.add(10) << endl;
	MyList.offer(13);
	MyList.offer(15);
	cout << "We can add duplicated elements : " << MyList.add(10) << endl;
	cout << "We can add duplicated elements : " << MyList.add(5) << endl;
	

	LinkedList<int,list<int> > OtherList;
	cout << "is it added 15 ? : " << OtherList.add(15) << endl;
	cout << "is it added 20 ? : " << OtherList.add(20) << endl;

	cout << "is it all added ? : " << MyList.addAll(OtherList) << endl;

	cout << "MyList : " ; printcontainer(MyList.iterator());

	cout << "OtherList : " ; printcontainer(OtherList.iterator());

	cout << "is it contains 5 ? : " << MyList.contains(5) << endl;
	cout << "is it contains 3 ? : " << MyList.contains(3) << endl;

	cout << "MyList contains all members of OtherList ? : " << MyList.containsAll(OtherList) << endl;

	cout << "is MyList Empty ? :" << MyList.isEmpty() << endl;

	cout << "Removed 13 from MyList : " ; MyList.remove(13) ; printcontainer(MyList.iterator());

	cout << "Using element function , getting head of list and not removing it : " << MyList.element() << endl;	printcontainer(MyList.iterator());

	cout << "Using poll function , getting head of list and removing it : " << MyList.poll()  << endl; printcontainer(MyList.iterator());

	cout << "Removed all OtherList from MyList: " ; MyList.removeAll(OtherList) ; printcontainer(MyList.iterator());

	cout << "is it added 52 ? : " << MyList.add(52) << endl;
	cout << "is it added 53? : " << MyList.add(53) << endl;
	cout << "is it added 150? : " << MyList.add(150) << endl;
	cout << "is it added 200? : " << MyList.add(200) << endl;

	cout << "MyList : " ; printcontainer(MyList.iterator());
	cout << "OtherList : " ; printcontainer(OtherList.iterator());
	cout << "Retain All that are contained in the OtherList : " ; MyList.retainAll(OtherList) ; printcontainer(MyList.iterator());

	cout << "Size of MyList : " << MyList.size() << endl;

	MyList.clear();
	OtherList.clear();

	cout << " ArrayList string test ..." << endl;

	LinkedList<string,list<string> > MyStringList;

	MyStringList.add("cihan");
	MyStringList.add("can");

	LinkedList<string,list<string> > OtherStringList;

	OtherStringList.add("ayyildiz");

	MyStringList.addAll(OtherStringList);

	cout << "is it contains 'cihan' ? : " << MyStringList.contains("cihan") << endl;

	cout << "is it contains all elements of other set ? :" << MyStringList.containsAll(OtherStringList) << endl;

	cout << "Using element function , getting head of list and not removing it : " << MyStringList.element() << endl;	printcontainer(MyStringList.iterator());

	cout << "Using poll function , getting head of list and removing it : " << MyStringList.poll()  << endl; 

	cout << "MyStringList : " ; printcontainer(MyStringList.iterator());

	
	cout << "After retain all : " ; MyStringList.retainAll(OtherStringList);

	printcontainer(MyStringList.iterator());
}
