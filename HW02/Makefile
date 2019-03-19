all: HW02

HW02: 161044051_main.o composedshape.o circle.o rectangle.o triangle.o
	g++ 161044051_main.o composedshape.o circle.o rectangle.o triangle.o -o HW02

161044051_main.o: 161044051_main.cpp
	g++ -std=c++11 -c 161044051_main.cpp

circle.o: circle.cpp
	g++ -std=c++11 -c circle.cpp

triangle.o: triangle.cpp
	g++ -std=c++11 -c triangle.cpp

rectangle.o: rectangle.cpp
	g++ -std=c++11 -c rectangle.cpp

composedshape.o: composedshape.cpp
	g++ -std=c++11 -c composedshape.cpp

clean:
	rm -rf *o HW02


