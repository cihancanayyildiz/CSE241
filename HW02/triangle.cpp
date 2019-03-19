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

