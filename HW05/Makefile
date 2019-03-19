all: HW05
HW05:161044051_main.o circle.o triangle.o rectangle.o polygon.o polygonvect.o polygondyn.o composedshape.o shape.o 
	g++ 161044051_main.o circle.o triangle.o rectangle.o polygon.o polygonvect.o polygondyn.o composedshape.o shape.o -o HW05
161044051_main.o:161044051_main.cpp
	g++ -std=c++11 -c 161044051_main.cpp
circle.o: circle.cpp
	g++ -std=c++11 -c circle.cpp
triangle.o: triangle.cpp
	g++ -std=c++11 -c triangle.cpp
rectangle.o: rectangle.cpp
	g++ -std=c++11 -c rectangle.cpp
polygon.o: polygon.cpp
	g++ -std=c++11 -c polygon.cpp
polygonvect.o: polygonvect.cpp
	g++ -std=c++11 -c polygonvect.cpp
polygondyn.o: polygondyn.cpp
	g++ -std=c++11 -c polygondyn.cpp
composedshape.o: composedshape.cpp
	g++ -std=c++11 -c composedshape.cpp
shape.o: shape.cpp
	g++ -std=c++11 -c shape.cpp
clean:
	rm -rf *o *svg HW05


