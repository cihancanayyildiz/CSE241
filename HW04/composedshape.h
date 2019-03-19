#ifndef COMPOSEDSHAPE_H
#define COMPOSEDSHAPE_H
#include <vector>
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "polygon.h"

namespace GtuObjects{

//Defining composed shape class
class ComposedShape{

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

	
	const Polygon& operator[](int index) const;

	Polygon& operator[](int index);

	ComposedShape& operator+=(const Rectangle& rectangle);
	ComposedShape& operator+=(const Circle& circle);
	ComposedShape& operator+=(const Triangle& triangle);

	friend std::ostream& operator<<(std::ostream& outputstream,const ComposedShape& compshape);	//Friend global functions for access private member data and overloading << operator.


//Our private data.
private:
	std::vector<Polygon> polyvector;	//Polygon vector.
};

}

#endif
