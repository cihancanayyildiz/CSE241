#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include <cstdlib>

namespace GtuObjects{

//Defining rectangle class

class Rectangle{

public:
	
	Rectangle();	//Default constructor.

	Rectangle(double width, double height);

	Rectangle(double width, double height,double x,double y);

	void setWidth(double);

	void setHeight(double);

	void setX(double);

	void setY(double);

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

	inline double PerimeterLength() const{
		return 2*width+2*height;
	}

	inline double Area() const{
		return width*height;
	}
	inline std::string getColor() const{
		return color;
	}

	friend std::ostream& operator <<(std::ostream& outputStream,const Rectangle& rect);

	// Operator Overloads
	Rectangle& operator ++();		//prefix version

	Rectangle operator ++(int);		//postfix version

	Rectangle& operator --(); 		//prefix version

	Rectangle operator --(int);		//postfix version

	bool operator==(const Rectangle &other) const;
	bool operator!=(const Rectangle &other) const;
	bool operator>(const Rectangle &other) const;
	bool operator<(const Rectangle &other) const;
	bool operator>=(const Rectangle &other) const;
	bool operator<=(const Rectangle &other) const;
	friend Rectangle operator+(const Rectangle &rectangle,double value);
	friend Rectangle operator-(const Rectangle &rectangle,double value);

private:

	double width;

	double height;

	double x;	// x-axis position for rectangle.

	double y;	// y-axis position for rectangle.

	std::string color;
};

}

#endif
