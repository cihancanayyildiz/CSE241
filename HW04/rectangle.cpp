#include "rectangle.h"

namespace GtuObjects{
//Default constructor.
Rectangle::Rectangle(){
	height=100;
	width=100;
	x=0;
	y=0;
	color = "red";
}

Rectangle::Rectangle(double w,double h){
	if(w<=0 || h<=0 ){
		std::cout << "Invalid value!" << std::endl;
		exit(1);
	}
	height=h;
	width=w;
	x=0;
	y=0;
	color = "red";
}

Rectangle::Rectangle(double w,double h,double xaxis,double yaxis){
	if(w<=0 || h<=0 || xaxis<0 || yaxis <0){
		std::cout << "Invalid value!" << std::endl;
		exit(1);
	}
	height=h;
	width=w;
	x = xaxis;
	y = yaxis;
	color = "red";
}

//Setter function for height of rectangle.
void Rectangle::setHeight(double h){
	if(h <= 0){
		std::cout << "Invalid value!" << std::endl ;
		exit(1);
	}
	else{
		height=h;
	}
}
//Setter function for width of rectangle.
void Rectangle::setWidth(double w){
	if(w <= 0){
		std::cout << "Invalid value!" << std::endl ;
		exit(1);
	}
	else{
		width=w;
	}
}

//Setter function for x-axis.
void Rectangle::setX(double X){
	if(X < 0){
		std::cout << "Invalid value" << std::endl;
		exit(1);
	}
	else{
		x = X;
	}
	
}

//Setter function for y-axis.
void Rectangle::setY(double Y){
	if(Y < 0){
		std::cout << "Invalid value" << std::endl;
		exit(1);
	}
	else{
		y = Y;
	}

}

void Rectangle::setColor(std::string newColor){

	color = newColor;
}


//left shift operator overload for rectangle..
std::ostream& operator <<(std::ostream& outputStream,const Rectangle& rect){

	outputStream << "<rect x=\"" << rect.x << "\"" << " y=\"" << rect.y << "\"" << " width=\"" << rect.width << "\"" << " height=\"" << rect.height << "\"" << " style=\"fill:red \"/>\n" ;

	return outputStream;

}

//prefix version
Rectangle& Rectangle::operator ++(){	
	x++;
	y++;
	return *this;
}

//postfix version
Rectangle Rectangle::operator ++(int){ 
	
	return Rectangle(x++,y++,width,height);
}

//prefix version
Rectangle& Rectangle::operator --(){	
	x--;
	y--;
	return *this;
}

//postfix version
Rectangle Rectangle::operator --(int){ 
	
	return Rectangle(x--,y--,width,height);
}

bool Rectangle::operator==(const Rectangle &other) const{
	return (Area()==other.Area());
}
bool Rectangle::operator!=(const Rectangle &other) const{
	return !(Area()==other.Area());
}
bool Rectangle::operator>(const Rectangle &other) const{
	return (Area()>other.Area());
}
bool Rectangle::operator<(const Rectangle &other) const{
	return (Area()<other.Area());
}
bool Rectangle::operator>=(const Rectangle &other) const{

	if(Area()>other.Area() || Area() == other.Area()){
		return true;
	}
	else{
		return false;
	}

}
bool Rectangle::operator<=(const Rectangle &other) const{

	if(Area()<other.Area() || Area() == other.Area()){
		return true;
	}
	else{
		return false;
	}
	
}

Rectangle operator+(const Rectangle &rectangle,double value){
	return Rectangle(rectangle.x,rectangle.y,rectangle.width+value,rectangle.height+value);
}

Rectangle operator-(const Rectangle &rectangle,double value){
	if(rectangle.width-value<0 || rectangle.height-value<0){
		std::cout << "Width or height can not be negative";
		exit(1);
	}
	return Rectangle(rectangle.x,rectangle.y,rectangle.width-value,rectangle.height-value);
}

}
