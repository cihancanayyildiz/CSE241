#include "triangle.h"

//Default constructor
Triangle::Triangle(){

	edge_of_triangle=100;
	
	x_axis_of_Point1=edge_of_triangle/2;
	y_axis_of_Point1=0;
	x_axis_of_Point2=0;
	y_axis_of_Point2=(edge_of_triangle/2)*sqrt(3);
	x_axis_of_Point3=edge_of_triangle;
	y_axis_of_Point3=(edge_of_triangle/2)*sqrt(3);

}

Triangle::Triangle(double edge){

	edge_of_triangle=edge;

	x_axis_of_Point1=edge_of_triangle/2;
	y_axis_of_Point1=0;
	x_axis_of_Point2=0;
	y_axis_of_Point2=(edge_of_triangle/2)*sqrt(3);
	x_axis_of_Point3=edge_of_triangle;
	y_axis_of_Point3=(edge_of_triangle/2)*sqrt(3);

}

Triangle::Triangle(double edge,double x1,double y1,double x2,double y2,double x3,double y3){

	x_axis_of_Point1=x1;
	y_axis_of_Point1=y1;
	x_axis_of_Point2=x2;
	y_axis_of_Point2=y2;
	x_axis_of_Point3=x3;
	y_axis_of_Point3=y3;
	edge_of_triangle = edge;

}

//Setter functions for edge and points.
void Triangle::setEdge_of_Triangle(double edge){
	if(edge > 0){
		edge_of_triangle=edge;
	}
	else{
		cout << "Edge can not be negative or zero. " << endl ;
		exit(EXIT_FAILURE);
	}
}

void Triangle::set_x_axis_of_Point1(double X){
	x_axis_of_Point1 = X;
}
void Triangle::set_y_axis_of_Point1(double Y){
	y_axis_of_Point1 = Y;
}
void Triangle::set_x_axis_of_Point2(double X){
	x_axis_of_Point2 = X;
}
void Triangle::set_y_axis_of_Point2(double Y){
	y_axis_of_Point2 = Y;
}
void Triangle::set_x_axis_of_Point3(double X){
	x_axis_of_Point3 = X;
}
void Triangle::set_y_axis_of_Point3(double Y){
	y_axis_of_Point3 = Y;
}

//Draw function for main triangle.
void Triangle::draw(ofstream &file){
	x_axis_of_Point1=edge_of_triangle/2;
	y_axis_of_Point1=0;
	x_axis_of_Point2=0;
	y_axis_of_Point2=(edge_of_triangle/2)*sqrt(3);
	x_axis_of_Point3=edge_of_triangle;
	y_axis_of_Point3=(edge_of_triangle/2)*sqrt(3);
	file << "<polygon points=\"" << x_axis_of_Point1 << " " << y_axis_of_Point1 << "," << x_axis_of_Point2 << " " << y_axis_of_Point2 << "," << x_axis_of_Point3 << " " << y_axis_of_Point3 << "\" fill=\"red\"/>\n" ;
}

ostream& operator <<(ostream& outputStream,const Triangle& tri){

	
	outputStream << "<polygon points=\"" << tri.x_axis_of_Point1 << " " << tri.y_axis_of_Point1 << "," << tri.x_axis_of_Point2 << " " << tri.y_axis_of_Point2 << "," << tri.x_axis_of_Point3 << " " << tri.y_axis_of_Point3 << "\" fill=\"green\"/>\n" ;

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

Triangle operator+(const Triangle &triangle,double value){
	return Triangle(triangle.edge_of_triangle+value,triangle.x_axis_of_Point1,triangle.y_axis_of_Point1,triangle.x_axis_of_Point2,triangle.y_axis_of_Point2,triangle.x_axis_of_Point3,triangle.y_axis_of_Point3);
}

Triangle operator-(const Triangle &triangle,double value){
	if(triangle.edge_of_triangle-value<0){
		cout << "The edge can not be negative.";
		exit(EXIT_FAILURE);
	}

	return Triangle(triangle.edge_of_triangle-value,triangle.x_axis_of_Point1,triangle.y_axis_of_Point1,triangle.x_axis_of_Point2,triangle.y_axis_of_Point2,triangle.x_axis_of_Point3,triangle.y_axis_of_Point3);
}

