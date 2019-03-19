#ifndef COMPOSEDSHAPE_H
#define COMPOSEDSHAPE_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "enum.h"


using namespace std;

//Defining composed shape class
class ComposedShape{

public:

	ComposedShape(Rectangle &MainRectangle);
	
	ComposedShape(Triangle &MainTriangle);

	ComposedShape(Circle &MainCircle);
	
	void optimalFit(Rectangle &MainRectangle,Shapes Mainshape,Shapes Smallshape);

	void optimalFit(Triangle &MainTriangle,Shapes Mainshape,Shapes Smallshape);

	void optimalFit(Circle &MainCircle,Shapes Mainshape,Shapes Smallshape);

	inline vector<Rectangle> getvector_rect() const{
		return rectanglev;
	}
	inline vector<Triangle> getvector_tri() const{
		return trianglev;
	}
	inline vector<Circle> getvector_circle() const{
		return circlev;
	}


	void draw(ofstream &file,Shapes Mainshape,Shapes Smallshape);


private:

	Circle MainCircle,circle;
	Rectangle MainRectangle,rectangle;
	Triangle MainTriangle,triangle;
	vector<Rectangle> rectanglev;
	vector<Triangle> trianglev;
	vector<Circle> circlev;
	Shapes Smallshape;
	Shapes Mainshape;

};

#endif
