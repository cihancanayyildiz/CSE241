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