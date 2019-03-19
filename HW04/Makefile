all: HW04

HW04: 161044051_main.o composedshape.o circle.o rectangle.o triangle.o polygon.o polyline.o
	g++ 161044051_main.o composedshape.o circle.o rectangle.o triangle.o polygon.o polyline.o -o HW04

161044051_main.o: 161044051_main.cpp
	g++ -std=c++11 -c  161044051_main.cpp

circle.o: circle.cpp
	g++ -std=c++11 -c  circle.cpp

triangle.o: triangle.cpp
	g++ -std=c++11 -c  triangle.cpp

rectangle.o: rectangle.cpp
	g++ -std=c++11 -c  rectangle.cpp

polygon.o: polygon.cpp
	g++ -std=c++11 -c  polygon.cpp

polyline.o: polyline.cpp
	g++ -std=c++11 -c  polyline.cpp

composedshape.o: composedshape.cpp
	g++ -std=c++11 -c  composedshape.cpp

clean:
	rm -rf *o *svg HW04


