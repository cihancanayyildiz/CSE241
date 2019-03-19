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

Rectangle::Rectangle(double w,double h) throw(RectLessThanZero){
	if(w<=0 || h<=0 ){
		throw RectLessThanZero();
	}
	else {
		height=h;
		width=w;
		x=0;
		y=0;
		color = "red";
	}
}

Rectangle::Rectangle(double w,double h,double xaxis,double yaxis) throw(RectLessThanZero){
	if(w<=0 || h<=0 || xaxis<0 || yaxis <0){
		throw RectLessThanZero();
	}
	else{	
		height=h;
		width=w;
		x = xaxis;
		y = yaxis;
		color = "red";
	}
}

//Setter function for height of rectangle.
void Rectangle::setHeight(double h) throw(RectLessThanZero){
	if(h <= 0){
		throw RectLessThanZero();
	}
	else{
		height=h;
	}
}
//Setter function for width of rectangle.
void Rectangle::setWidth(double w) throw(RectLessThanZero){
	if(w <= 0){
		throw RectLessThanZero();
	}
	else{
		width=w;
	}
}

//Setter function for x-axis.
void Rectangle::setX(double X) throw(RectLessThanZero){
	if(X < 0){
		throw RectLessThanZero();
	}
	else{
		x = X;
	}
	
}

//Setter function for y-axis.
void Rectangle::setY(double Y) throw(RectLessThanZero){
	if(Y < 0){
		throw RectLessThanZero();
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

Shape& Rectangle::operator++(){
	x++;
	y++;
	return *this;
}

Shape& Rectangle::operator++(int){
	Rectangle *temp = new Rectangle(*this);
	++*this;
	return *temp;
}

Shape& Rectangle::operator--(){
	x--;
	y--;
	return *this;
}

Shape& Rectangle::operator--(int){
	Rectangle *temp = new Rectangle(*this);
	--*this;
	return *temp;
}

std::ostream& Rectangle::draw(std::ostream& output) const{

	output << "<rect x=\"" << x << "\"" << " y=\"" << y << "\"" << " width=\"" << width << "\"" << " height=\"" << height << "\" fill=\"" <<  color << "\"/>\n" ;

	return output;
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

Rectangle operator-(const Rectangle &rectangle,double value) throw(RectLessThanZero){
	if(rectangle.width-value<0 || rectangle.height-value<0){
		throw RectLessThanZero();
	}
	return Rectangle(rectangle.x,rectangle.y,rectangle.width-value,rectangle.height-value);
}

}
