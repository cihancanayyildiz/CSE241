#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

//Defining rectangle class

class Rectangle{

public:
	
	Rectangle();

	Rectangle(double width, double height);

	Rectangle(double x,double y,double width, double height);

	void setWidth(double);

	void setHeight(double);

	void setX(double);

	void setY(double);

	const inline double getWidth() const{
		return width;
	}
	const inline double getHeight() const{
		return height;
	}

	const inline double getX() const{	//getting x-axis position.
		return x;
	}

	const inline double getY() const{	//getting x-axis position.
		return y;
	}

	void draw(ofstream &file);

private:

	double width;

	double height;

	double x;	// x-axis position for rectangle.

	double y;	// y-axis position for rectangle.
};

#endif
