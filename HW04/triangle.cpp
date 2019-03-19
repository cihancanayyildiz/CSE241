#include "triangle.h"

namespace GtuObjects{

//Default constructor
Triangle::Triangle(){

	edge_of_triangle=100;
	
	x_axis_of_Point1=edge_of_triangle/2;
	y_axis_of_Point1=0;
	x_axis_of_Point2=0;
	y_axis_of_Point2=(edge_of_triangle/2)*sqrt(3);
	x_axis_of_Point3=edge_of_triangle;
	y_axis_of_Point3=(edge_of_triangle/2)*sqrt(3);
	color = "red";

}

Triangle::Triangle(double edge){
	if(edge<0){
		std::cout << "Invalid value!" << std::endl;
		exit(1);
	}

	edge_of_triangle=edge;

	x_axis_of_Point1=edge_of_triangle/2;
	y_axis_of_Point1=0;
	x_axis_of_Point2=0;
	y_axis_of_Point2=(edge_of_triangle/2)*sqrt(3);
	x_axis_of_Point3=edge_of_triangle;
	y_axis_of_Point3=(edge_of_triangle/2)*sqrt(3);
	color = "red";

}

Triangle::Triangle(double edge,double x1,double y1,double x2,double y2,double x3,double y3){

	if(edge<0 || x1<0 || y1<0 || x2<0 || y2<0 || x3<0 || y3<0){
		std::cout << "Invalid value!" << std::endl;
		exit(1);
	}

	x_axis_of_Point1=x1;
	y_axis_of_Point1=y1;
	x_axis_of_Point2=x2;
	y_axis_of_Point2=y2;
	x_axis_of_Point3=x3;
	y_axis_of_Point3=y3;
	edge_of_triangle = edge;
	color = "red";

}

//Setter functions for edge and points.
void Triangle::setEdge_of_Triangle(double edge){
	if(edge > 0){
		edge_of_triangle=edge;
	}
	else{
		std::cout << "Invalid value!" << std::endl ;
		exit(1);
	}
}

void Triangle::set_x_axis_of_Point1(double X){
	if(X<0){
		std::cout << "Invalid value" << std::endl;
		exit(1);
	}
	x_axis_of_Point1 = X;
}
void Triangle::set_y_axis_of_Point1(double Y){
	if(Y<0){
		std::cout << "Invalid value" << std::endl;
		exit(1);
	}
	y_axis_of_Point1 = Y;
}
void Triangle::set_x_axis_of_Point2(double X){
	if(X<0){
		std::cout << "Invalid value" << std::endl;
		exit(1);
	}
	x_axis_of_Point2 = X;
}
void Triangle::set_y_axis_of_Point2(double Y){
	if(Y<0){
		std::cout << "Invalid value" << std::endl;
		exit(1);
	}
	y_axis_of_Point2 = Y;
}
void Triangle::set_x_axis_of_Point3(double X){
	if(X<0){
		std::cout << "Invalid value" << std::endl;
		exit(1);
	}
	x_axis_of_Point3 = X;
}
void Triangle::set_y_axis_of_Point3(double Y){
	if(Y<0){
		std::cout << "Invalid value" << std::endl;
		exit(1);
	}
	y_axis_of_Point3 = Y;
}

void Triangle::setColor(std::string newColour){
	color = newColour;
}


// left shift operator overload for triangle ..

std::ostream& operator <<(std::ostream& outputStream,const Triangle& tri){

	
	outputStream << "<polygon points=\"" << tri.x_axis_of_Point1 << " " << tri.y_axis_of_Point1 << "," << tri.x_axis_of_Point2 << " " << tri.y_axis_of_Point2 << "," << tri.x_axis_of_Point3 << " " << tri.y_axis_of_Point3 << "\" fill=\"red\"/>\n" ;

	return outputStream;

}


//Prefix increment
Triangle& Triangle::operator ++(){
	x_axis_of_Point1++;
	y_axis_of_Point1++;
	x_axis_of_Point2++;
	y_axis_of_Point2++;
	x_axis_of_Point3++;
	y_axis_of_Point3++;
	return *this;
}

//Postfix increment
Triangle Triangle::operator ++(int){
	
	return Triangle(edge_of_triangle,x_axis_of_Point1++,y_axis_of_Point1++,x_axis_of_Point2++,y_axis_of_Point2++,x_axis_of_Point3++,y_axis_of_Point3++);
}

//Prefix decrement
Triangle& Triangle::operator --(){
	x_axis_of_Point1--;
	y_axis_of_Point1--;
	x_axis_of_Point2--;
	y_axis_of_Point2--;
	x_axis_of_Point3--;
	y_axis_of_Point3--;
	return *this;
}

//Postfix decrement
Triangle Triangle::operator --(int){
	
	return Triangle(edge_of_triangle,x_axis_of_Point1--,y_axis_of_Point1--,x_axis_of_Point2--,y_axis_of_Point2--,x_axis_of_Point3--,y_axis_of_Point3--);
}


//Operator overloads

bool Triangle::operator==(const Triangle &other) const{
	return (Area()==other.Area());
}
bool Triangle::operator!=(const Triangle &other) const{
	return !(Area()==other.Area());
}
bool Triangle::operator>(const Triangle &other) const{
	return (Area()>other.Area());
}
bool Triangle::operator<(const Triangle &other) const{
	return (Area()<other.Area());
}
bool Triangle::operator>=(const Triangle &other) const{

	if(Area()>other.Area() || Area() == other.Area()){
		return true;
	}
	else{
		return false;
	}

}
bool Triangle::operator<=(const Triangle &other) const{

	if(Area()<other.Area() || Area() == other.Area()){
		return true;
	}
	else{
		return false;
	}
	
}


// adding the given value to triangle's data

Triangle operator+(const Triangle &triangle,double value){
	return Triangle(triangle.edge_of_triangle+value,triangle.x_axis_of_Point1,triangle.y_axis_of_Point1,triangle.x_axis_of_Point2,triangle.y_axis_of_Point2,triangle.x_axis_of_Point3,triangle.y_axis_of_Point3);
}


Triangle operator-(const Triangle &triangle,double value){
	if(triangle.edge_of_triangle-value<0){
		std::cout << "The edge can not be negative.";
		exit(1);
	}

	return Triangle(triangle.edge_of_triangle-value,triangle.x_axis_of_Point1,triangle.y_axis_of_Point1,triangle.x_axis_of_Point2,triangle.y_axis_of_Point2,triangle.x_axis_of_Point3,triangle.y_axis_of_Point3);
}

}