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

using namespace std;

class ShapeElem;
//Defining composed shape class
class ComposedShape{

public:
	class ShapeElem{
	public:
		
		enum class InnerShape{
			Rectangle,
			Circle,
			Triangle
		};
		

		void HoldingCircle(Circle innerCirc);

		void HoldingRectangle(Rectangle innerRect);

		void HoldingTriangle(Triangle innerTri);

		void setType (char selection);

		//Our getters..
		const inline Rectangle getRectangle() const { return innerRect; }

		const inline Circle getCircle() const { return innerCirc; }

		const inline Triangle getTriangle() const { return innerTri; }

		const inline InnerShape getType(InnerShape innershape){ return innershape; }

		const inline double getArea() { return area; }

		const inline double getPerimeter() { return perimeter; }	

		friend ostream& operator<<(ostream& outputstream,const ComposedShape::ShapeElem &shape);	//Friend global functions for access private member data and overloading << operator.
		

	private:
		double perimeter;
		double area;
		Rectangle innerRect;
		Circle innerCirc;
		Triangle innerTri;
		InnerShape innershape;
		void *p;
	};

	// Our constructors.

	ComposedShape(Rectangle MainRectangle,Triangle triangle);
	ComposedShape(Rectangle MainRectangle,Circle circle);
	ComposedShape(Rectangle MainRectangle,Rectangle rectangle);
	ComposedShape(Triangle MainTriangle,Circle circle);
	ComposedShape(Triangle MainTriangle,Rectangle rectangle);
	ComposedShape(Triangle MainTriangle,Triangle triangle);
	ComposedShape(Circle MainCircle,Circle circle);

	// Our overload functions.
	void optimalFit(Rectangle MainRectangle,Triangle triangle);
	void optimalFit(Rectangle MainRectangle,Circle circle);
	void optimalFit(Rectangle MainRectangle,Rectangle rectangle);
	void optimalFit(Triangle MainTriangle,Circle circle);
	void optimalFit(Triangle MainTriangle,Rectangle rectangle);
	void optimalFit(Triangle MainTriangle,Triangle triangle);
	void optimalFit(Circle MainCircle,Circle circle);


	inline vector<Rectangle> getvector_rect() const{
		return rectanglev;
	}
	inline vector<Triangle> getvector_tri() const{
		return trianglev;
	}
	inline vector<Circle> getvector_circle() const{
		return circlev;
	}


	ShapeElem operator[](int value) {return this->shapev[value];}	//Defining operator [] with its index..

	ComposedShape operator+=(const Rectangle& rectangle);
	ComposedShape operator+=(const Circle& circle);
	ComposedShape operator+=(const Triangle& triangle);


	friend ostream& operator<<(ostream& outputstream,const ComposedShape& compshape);	//Friend global functions for access private member data and overloading << operator.
//Our private data.
private:

	Circle MainCircle,circle;
	Rectangle MainRectangle,rectangle;
	Triangle MainTriangle,triangle;

	vector<Rectangle> rectanglev;
	vector<Triangle> trianglev;
	vector<Circle> circlev;

	ShapeElem shape;
	vector<ShapeElem> shapev;
	
};

#endif
