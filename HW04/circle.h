#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <cmath>
#include <cstdlib>

namespace GtuObjects{

//Defining circle class
class Circle{
public:

	Circle();	//Default constructor

	Circle(double radius);

	Circle(double radius,double cx,double cy);

	//Setters..

	void setCx(double);	
	void setCy(double);
	void setRadius(double);
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
	inline double PerimeterLength() const{
		return 2*M_PI*radius;
	}
	inline double Area() const{
		return M_PI*radius*radius;
	}
	inline std::string getColor() const{
		return color;
	}
	
	Circle& operator++(); 										// prefix increment
	Circle operator++(int); 									// postfix increment
	Circle& operator--(); 										// prefix decrement
	Circle operator--(int); 									// postfix decrement
	friend Circle operator+(const Circle &circle,double value);	// + operator overload

	friend Circle operator-(const Circle &circle,double value);	// - operator overload

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
