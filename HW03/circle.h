#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

//Defining circle class
class Circle{
public:

	Circle();

	Circle(double radius);

	Circle(double radius,double cx,double cy);

	void setCx(double);
	void setCy(double);
	void setRadius(double);

	const inline double getCx() const{
		return cx;
	}
	const inline double getCy() const{
		return cy;
	}
	const inline double getRadius() const{
		return radius;
	}

	const inline double PerimeterLength() const{
		return 2*M_PI*radius;
	}
	const inline double Area() const{
		return M_PI*radius*radius;
	}
	const inline int getShapeCount() const{
		return ShapeCount++;
	}
	
	/*
	static TotalArea(static int count);
	static TotalPerimeter(static int count);
	*/

	Circle& operator++(); 										// prefix increment
	Circle operator++(int); 									// postfix increment
	Circle& operator--(); 										// prefix decrement
	Circle operator--(int); 									// postfix decrement
	friend Circle operator+(const Circle &circle,double value);
	friend Circle operator-(const Circle &circle,double value);

	bool operator==(const Circle &other) const;
	bool operator!=(const Circle &other) const;
	bool operator>(const Circle &other) const;
	bool operator<(const Circle &other) const;
	bool operator>=(const Circle &other) const;
	bool operator<=(const Circle &other) const;
	friend ostream& operator <<(ostream& outputStream,const Circle& circle);

	void draw(ofstream &file);

private:

	double cx;
	double cy;
	double radius;
	static int ShapeCount;

};

#endif
