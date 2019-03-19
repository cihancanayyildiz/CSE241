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
	void draw(ofstream &file);
private:

	double cx;
	double cy;
	double radius;

};

#endif
