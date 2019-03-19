#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include <cstdlib>
#include "shape.h"

namespace GtuObjects{

//Defining rectangle class

class Rectangle : public Shape{

public:
	
	Rectangle();	//Default constructor.

	Rectangle(double width, double height) throw(RectLessThanZero);

	Rectangle(double width, double height,double x,double y) throw(RectLessThanZero);

	void setWidth(double) throw(RectLessThanZero);

	void setHeight(double) throw(RectLessThanZero);

	void setX(double) throw(RectLessThanZero);

	void setY(double) throw(RectLessThanZero);

	void setColor(std::string);
	
	//Getter inline  functions 
	inline double getWidth() const{
		return width;
	}
	inline double getHeight() const{
		return height;
	}

	inline double getX() const{	//getting x-axis position.
		return x;
	}

	inline double getY() const{	//getting x-axis position.
		return y;
	}

	double Perimeter() const override{
		return 2*width+2*height;
	}

	double Area() const override{
		return width*height;
	}
	inline std::string getColor() const{
		return color;
	}

	friend std::ostream& operator <<(std::ostream& outputStream,const Rectangle& rect);

	Shape& operator++() override;
	Shape& operator++(int) override;
	Shape& operator--() override;
	Shape& operator--(int) override;

	std::ostream& draw(std::ostream& output) const override;

	bool operator==(const Rectangle &other) const;
	bool operator!=(const Rectangle &other) const;
	bool operator>(const Rectangle &other) const;
	bool operator<(const Rectangle &other) const;
	bool operator>=(const Rectangle &other) const;
	bool operator<=(const Rectangle &other) const;
	friend Rectangle operator+(const Rectangle &rectangle,double value);
	friend Rectangle operator-(const Rectangle &rectangle,double value) throw(RectLessThanZero);

private:

	double width;

	double height;

	double x;	// x-axis position for rectangle.

	double y;	// y-axis position for rectangle.

	std::string color;
};

}

#endif
