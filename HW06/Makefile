all: HW06
HW06:161044051_main.o iterator.o collection.o set.o list.o hashset.o arraylist.o linkedlist.o
	g++ 161044051_main.o iterator.o collection.o set.o list.o hashset.o arraylist.o linkedlist.o -o HW06
161044051_main.o:161044051_main.cpp
	g++ -std=c++11 -c 161044051_main.cpp
iterator.o: iterator.cpp
	g++ -std=c++11 -c iterator.cpp
collection.o : collection.cpp
	g++ -std=c++11 -c collection.cpp
set.o : set.cpp
	g++ -std=c++11 -c set.cpp
list.o : list.cpp
	g++ -std=c++11 -c list.cpp
hashset.o : hashset.cpp
	g++ -std=c++11 -c hashset.cpp
arraylist.o : arraylist.cpp
	g++ -std=c++11 -c arraylist.cpp
linkedlist.o : linkedlist.cpp
	g++ -std=c++11 -c linkedlist.cpp
clean:
	rm -rf *o  HW06
