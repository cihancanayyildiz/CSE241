#include "circle.h"
namespace GtuObjects{

//Default constructor for circle.
Circle::Circle(){
	radius=100;
	cx=100;
	cy=100;
	color = "red";
}

Circle::Circle(double r){
	if(r<0){
		std::cout << "Invalid value!" << std::endl;
		exit(1);
	}
	radius = r;
	cx=r;
	cy=r;
	color = "red";
}

Circle::Circle(double r,double x,double y){
	if(r<0 || x<0 || y<0){
		std::cout << "Invalid value!" << std::endl;
		exit(1);
	}
	radius = r;
	cx=x;
	cy=y;
	color = "red";
}

//Setter function for x-axis
void Circle::setCx(double x){

	if(x>=0){
		cx = x;
	}
	else{
		std::cout << "Invalid value!" << std::endl ;
		exit(1);
	}

}

//Setter function for y-axis
void Circle::setCy(double y){

	if(y>=0){
		cy = y;
	}
	else{
		std::cout << "Invalid value!" << std::endl ;
		exit(1);
	}

}

//Setter function for radius
void Circle::setRadius(double r){

	if(r>0){
		radius = r;
	}
	else{
		std::cout << "Invalid value!" << std::endl ;
		exit(1);
	}

}

void Circle::setColor(std::string newColour){
	color = newColour;
}

std::ostream& operator <<(std::ostream& outputStream,const Circle& circle){

	outputStream << "<circle cx=\"" << circle.cx << "\"" << " cy=\"" << circle.cy << "\"" << " r=\"" << circle.radius << "\" fill=\"red\"/>\n" ;

	return outputStream;

}

//prefix version
Circle& Circle::operator ++(){	
	cx++;
	cy++;
	return *this;
}

//postfix version
Circle Circle::operator ++(int){ 
	
	return Circle(radius,cx++,cy++);
}

//prefix version
Circle& Circle::operator --(){	
	cx--;
	cy--;
	return *this;
}

//postfix version
Circle Circle::operator --(int){ 
	
	return Circle(radius,cx--,cy--);
}

//Operator Overloads..

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

Circle operator-(const Circle &circle, double value){
	
	if(circle.radius-value<0){
		std::cout << "Radius can not be negative.";
		exit(1);
	}
	return Circle(circle.radius-value,circle.cx,circle.cy);
}

}
