#include "circle.h"
namespace GtuObjects{

//Default constructor for circle.
Circle::Circle(){
	radius=100;
	cx=100;
	cy=100;
	color = "red";
}

Circle::Circle(double r) throw(CircleLessThanZero){
	if(r<0){
		throw CircleLessThanZero();
	}
	else{
		radius = r;
		cx=r;
		cy=r;
		color = "red";
	}	
}

Circle::Circle(double r,double x,double y) throw(CircleLessThanZero){
	if(r<0 || x<0 || y<0){
		throw CircleLessThanZero();
	}
	else{
		cx=x;
		cy=y;
		color = "red";
	}
}

//Setter function for x-axis
void Circle::setCx(double x) throw(CircleLessThanZero){

	if(x>=0){
		cx = x;
	}
	else{
		throw CircleLessThanZero();
	}

}

//Setter function for y-axis
void Circle::setCy(double y) throw(CircleLessThanZero){

	if(y>=0){
		cy = y;
	}
	else{
		throw CircleLessThanZero();
	}

}

//Setter function for radius
void Circle::setRadius(double r) throw(CircleLessThanZero){

	if(r>0){
		radius = r;
	}
	else{
		throw CircleLessThanZero();
	}

}

void Circle::setColor(std::string newColour){
	color = newColour;
}

std::ostream& operator <<(std::ostream& outputStream,const Circle& circle){

	outputStream << "<circle cx=\"" << circle.cx << "\"" << " cy=\"" << circle.cy << "\"" << " r=\"" << circle.radius << "\" fill=\"red\"/>\n" ;

	return outputStream;

}

Shape& Circle::operator++(){
	cx++;
	cy++;
	return *this;
}

Shape& Circle::operator++(int){
	Circle *temp = new Circle(*this);
	++*this;
	return *temp;
}

Shape& Circle::operator--(){
	cx--;
	cy--;
	return *this;
}

Shape& Circle::operator--(int){
	Circle *temp = new Circle(*this);
	--*this;
	return *temp;
}

std::ostream& Circle::draw(std::ostream& output) const{
	output << "<circle cx=\"" << cx << "\"" << " cy=\"" << cy << "\"" << " r=\"" << radius << "\" fill=\"" <<  color << "\"/>\n" ;

	return output;
}


bool Circle::operator==(const Circle &other) const{
	return (Area()==other.Area());
}
bool Circle::operator!=(const Circle &other) const{
	return !(Area()==other.Area());
}
bool Circle::operator>(const Circle &other) const{
	return (Area()>other.Area());
}
bool Circle::operator<(const Circle &other) const{
	return (Area()<other.Area());
}
bool Circle::operator>=(const Circle &other) const{

	if(Area()>other.Area() || Area() == other.Area()){
		return true;
	}
	else{
		return false;
	}

}
bool Circle::operator<=(const Circle &other) const{

	if(Area()<other.Area() || Area() == other.Area()){
		return true;
	}
	else{
		return false;
	}

}

Circle operator+(const Circle &circle, double value){
 	
	return Circle(circle.radius+value,circle.cx,circle.cy);
}

Circle operator-(const Circle &circle, double value) throw (CircleLessThanZero){
	
	if(circle.radius-value<0){
		throw CircleLessThanZero();
	}
	return Circle(circle.radius-value,circle.cx,circle.cy);
}

}
