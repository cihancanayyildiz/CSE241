#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "shape.h"

namespace GtuObjects{

//Defining circle class
class Circle : public Shape{
public:

	Circle();	//Default constructor

	Circle(double radius) throw(CircleLessThanZero);

	Circle(double radius,double cx,double cy) throw(CircleLessThanZero) ;

	//Setters..

	void setCx(double) throw(CircleLessThanZero) ;	
	void setCy(double) throw(CircleLessThanZero) ;
	void setRadius(double) throw(CircleLessThanZero) ;
	void setColor(std::string);

	//Getters..

	inline double getCx() const{
		return cx;
	}
	inline double getCy() const{
		return cy;
	}
	inline double getRadius() const{
		return radius;
	}
	double Perimeter() const{
		return 2*M_PI*radius;
	}
	double Area() const{
		return M_PI*radius*radius;
	}
	inline std::string getColor() const{
		return color;
	}

	Shape& operator++();
	Shape& operator++(int);
	Shape& operator--();
	Shape& operator--(int);

	std::ostream& draw(std::ostream& output) const ;
	
	friend Circle operator+(const Circle &circle,double value);	// + operator overload

	friend Circle operator-(const Circle &circle,double value) throw(CircleLessThanZero);	// - operator overload

	//And the other overloads..
	
	bool operator==(const Circle &other) const;
	bool operator!=(const Circle &other) const;
	bool operator>(const Circle &other) const;
	bool operator<(const Circle &other) const;
	bool operator>=(const Circle &other) const;
	bool operator<=(const Circle &other) const;
	friend std::ostream& operator <<(std::ostream& outputStream,const Circle& circle);


private:

	double cx;
	double cy;
	double radius;
	std::string color;

};

}

#endif
