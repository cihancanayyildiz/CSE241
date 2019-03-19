#include "polygon.h"

namespace GtuObjects{

Polygon::Polygon(){	//Default constructor for polygon.

	color = "red"; // default color.

}

void Polygon::setColor(std::string newColor){
	color = newColor;
}

Polygon::Point2D::Point2D(){	//Default constructor.
	X=0;
	Y=0;
}
Polygon::Point2D::Point2D(double xValue,double yValue){
	X=xValue;
	Y=yValue;
}

void Polygon::Point2D::setX(double xValue){	
	if(xValue<0){
		std::cout << "Invalid value!" << std::endl;
		exit(1);
	}

	X=xValue;
}

void Polygon::Point2D::setY(double yValue){	
	if(yValue<0){
		std::cout << "Invalid value!" << std::endl;
		exit(1);
	}

	Y=yValue;
}

bool Polygon::Point2D::operator==(const Point2D &other)const{
	return (X==other.X && Y == other.Y);	//Comparing the points.
}

bool Polygon::Point2D::operator!=(const Point2D &other)const{
	return !(*this==other);
}

// left shift operator overload for Point2D

std::ostream& operator<<(std::ostream &outputStream,const Polygon::Point2D &p){

	outputStream << "(" << p.getX() << "," << p.getY() << ")" << std::endl;

	return outputStream;
}

}