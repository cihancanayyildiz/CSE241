#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <exception>
#include "exceptions.h"

//This class for our shape hierarcihy.

namespace GtuObjects{

//Defining shape class.

class Shape{
public:
	//Defining our virtual functions and operator overloads.
	virtual double Area() const  = 0;
	virtual double Perimeter() const = 0;

	virtual Shape& operator++() = 0;
	virtual Shape& operator++(int) = 0;
	virtual Shape& operator--() = 0;
	virtual Shape& operator--(int) = 0;

	virtual std::ostream& draw(std::ostream& output) const = 0; // This function is a helper function.Using this function for helping << operator overload.

	friend std::ostream& operator<<(std::ostream &output,const Shape &other) ;

	//comparison operator overloads for shape class.
	bool operator==(const Shape &other) const;
	bool operator!=(const Shape &other) const;
	bool operator>(const Shape &other) const;
	bool operator<(const Shape &other) const;
	bool operator>=(const Shape &other) const;
	bool operator<=(const Shape &other) const;

	virtual ~Shape() = default;	// default virtual shape destructor.
	
};
}

#endif
