#include "circle.h"

//Default constructor for circle.
Circle::Circle(){
	radius=100;
	cx=100;
	cy=100;
}

Circle::Circle(double r){
	radius = r;
	cx=r;
	cy=r;
}

Circle::Circle(double r,double x,double y){
	radius = r;
	cx=x;
	cy=y;
}

//Setter function for x-axis
void Circle::setCx(double x){

	if(x>=0){
		cx = x;
	}
	else{
		cout << "X-axis can not be negative. " << endl ;
		exit(EXIT_FAILURE);
	}

}

//Setter function for y-axis
void Circle::setCy(double y){

	if(y>=0){
		cy = y;
	}
	else{
		cout << "Y-axis can not be negative. " << endl ;
		exit(EXIT_FAILURE);
	}

}

//Setter function for radius
void Circle::setRadius(double r){

	if(r>0){
		radius = r;
	}
	else{
		cout << "Radius can not be negative or zero. " << endl ;
		exit(EXIT_FAILURE);
	}

}

//Draw function for main circle
void Circle::draw(ofstream &file){
	file << "<circle cx=\"" << cx << "\"" << " cy=\"" << cy << "\"" << " r=\"" << radius << "\" fill=\"red\"/>\n" ;
}


ostream& operator <<(ostream& outputStream,const Circle& circle){

	outputStream << "<circle cx=\"" << circle.cx << "\"" << " cy=\"" << circle.cy << "\"" << " r=\"" << circle.radius << "\" fill=\"green\"/>\n" ;

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
		cout << "Radius can not be negative.";
		exit(EXIT_FAILURE);
	}
	return Circle(circle.radius-value,circle.cx,circle.cy);
}
