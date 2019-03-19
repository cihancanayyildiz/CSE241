#include "rectangle.h"

//Default constructor.
Rectangle::Rectangle(){
	height=100;
	width=100;
	x=0;
	y=0;
}

Rectangle::Rectangle(double w,double h){
	height=h;
	width=w;
	x=0;
	y=0;
}

Rectangle::Rectangle(double xaxis,double yaxis,double w,double h){
	height=h;
	width=w;
	x = xaxis;
	y = yaxis;
}

//Setter function for height of rectangle.
void Rectangle::setHeight(double h){
	if(h <= 0){
		cout << "Height can not be negative or zero. " << endl ;
		exit(EXIT_FAILURE);
	}
	else{
		height=h;
	}
}
//Setter function for width of rectangle.
void Rectangle::setWidth(double w){
	if(w <= 0){
		cout << "Width can not be negative or zero. " << endl ;
		exit(EXIT_FAILURE);
	}
	else{
		width=w;
	}
}

//Setter function for x-axis.
void Rectangle::setX(double X){

	x = X;

}

//Setter function for y-axis.
void Rectangle::setY(double Y){

	y = Y;

}

//draw function for main rectangle.
void Rectangle::draw(ofstream &file){
	file << "<rect x=\"" << x << "\"" << " y=\"" << y << "\"" << " width=\"" << width << "\"" << " height=\"" << height << "\"" << " style=\"fill:red \"/>\n" ;
}
