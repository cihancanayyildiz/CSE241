#ifndef COMPOSEDSHAPE_H
#define COMPOSEDSHAPE_H
#include <vector>
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "shape.h"

namespace GtuObjects{

//Defining composed shape class
class ComposedShape : public Shape {

public:

	// Our overloaded constructors.

	ComposedShape(Rectangle &MainRectangle);

	ComposedShape(Triangle &MainTriangle);
	
	ComposedShape(Circle &MainCircle);

	// Our overloaded functions.
	void optimalFit(const Rectangle &MainRectangle,Triangle &triangle);
	void optimalFit(const Rectangle &MainRectangle,Circle &circle);
	void optimalFit(const Rectangle &MainRectangle,Rectangle &rectangle);
	void optimalFit(const Triangle &MainTriangle,Circle &circle);
	void optimalFit(const Triangle &MainTriangle,Rectangle &rectangle);
	void optimalFit(const Triangle &MainTriangle,Triangle &triangle);
	void optimalFit(const Circle &MainCircle,Circle &circle);

	double Area() const;
	double Perimeter() const;

	Shape& operator++();
	Shape& operator++(int);
	Shape& operator--();
	Shape& operator--(int) ;

	std::ostream& draw(std::ostream& output) const;

	friend std::ostream& operator<<(std::ostream& output,const ComposedShape &other);

	ComposedShape& operator+=(const Rectangle& rectangle);
	ComposedShape& operator+=(const Circle& circle);
	ComposedShape& operator+=(const Triangle& triangle);

	Shape* operator[](int index) throw(OutOfBoundsException);
	const Shape* operator[](int index) const throw(OutOfBoundsException);

	std::vector<Shape*> getShapeVector() { return Shapev;}

	~ComposedShape();

//Our private data.
private:
	std::vector<Shape*> Shapev;	
};

}

#endif
