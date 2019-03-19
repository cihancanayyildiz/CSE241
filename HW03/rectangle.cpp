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

ostream& operator <<(ostream& outputStream,const Rectangle& rect){

	outputStream << "<rect x=\"" << rect.x << "\"" << " y=\"" << rect.y << "\"" << " width=\"" << rect.width << "\"" << " height=\"" << rect.height << "\"" << " style=\"fill:green \"/>\n" ;

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
		cout << "Width or height can not be negative";
		exit(EXIT_FAILURE);
	}
	return Rectangle(rectangle.x,rectangle.y,rectangle.width-value,rectangle.height-value);
}