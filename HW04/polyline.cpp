#include "polyline.h"

namespace GtuObjects{

Polyline::Point2D::Point2D(){	//Default constructor.
	X=0;
	Y=0;
}
Polyline::Point2D::Point2D(double xValue,double yValue){
	X=xValue;
	Y=yValue;
}

void Polyline::Point2D::setX(double xValue){
	if(xValue<0){
		std::cout << "Invalid value!" << std::endl;
		exit(1);
	}
	X=xValue;
}

void Polyline::Point2D::setY(double yValue){
	if(yValue<0){
		std::cout << "Invalid value!" << std::endl;
		exit(1);
	}	
	Y=yValue;
}

bool Polyline::Point2D::operator==(const Point2D &other)const{
	return (X==other.X && Y == other.Y);	//Comparing the points.
}

bool Polyline::Point2D::operator!=(const Point2D &other)const{
	return !(*this==other);
}

// left shift operator overload for Point2D

std::ostream& operator<<(std::ostream &outputStream,const Polyline::Point2D &p){

	outputStream << "(" << p.getX() << "," << p.getY() << ")" << std::endl;

	return outputStream;
}


Polyline::Polyline(){	//Default constructor for Polyline.
	size=5;
	points = new Point2D[size];
	color = "red";

}

Polyline::Polyline(int _size){
	if(_size<=0){
		std::cout << "Size can not be 0 or negative.";
		exit(1);
	}
	size=_size;
	points = new Point2D[size];
	color = "red";

}

Polyline::Polyline(const std::vector<Point2D> &v){
	if(v.size()==0){
		std::cout << "Vector is empty...";
		exit(1);
	}

	size = v.size();
	points = new Point2D[size];

	for(int i=0;i<size;i++){
		points[i] = v[i];
	}
}

Polyline::Polyline(const Point2D &point){

	size = 1;
	points = new Point2D[size];

	points[0] = point;
	
}

Polyline::Polyline(const Polyline &poly){
	size = poly.size;

	points = new Point2D[size];
	
	for(int i=0;i<size;i++){
		points[i] = poly.points[i];
	}

	color = poly.color;

}

Polyline::Polyline(const Triangle &tri){	//conversion constructor

	size = 3; // We have 3 triangle point so we need size = 3;

	points = new Point2D[size];
	
	points[0].setX(tri.get_x_axis_of_Point1());
	points[0].setY(tri.get_y_axis_of_Point1());
	points[1].setX(tri.get_x_axis_of_Point2());
	points[1].setY(tri.get_y_axis_of_Point2());
	points[2].setX(tri.get_x_axis_of_Point3());
	points[2].setY(tri.get_y_axis_of_Point3());

	color = tri.getColor();
	
}

Polyline::Polyline(const Rectangle &rect){	//conversion constructor
	
	size = 4; // We have 4 rectangle point so we need size = 4;

	points = new Point2D[size];
	
	points[0].setX(rect.getX());
	points[0].setY(rect.getY());
	points[1].setX(rect.getX());
	points[1].setY(rect.getY()+rect.getHeight());
	points[2].setX(rect.getX()+rect.getWidth());
	points[2].setY(rect.getY()+rect.getHeight());
	points[3].setX(rect.getX()+rect.getWidth());
	points[3].setY(rect.getY());
	
	color = rect.getColor();

}


Polyline::Polyline(const Circle &circle){		//conversion constructor

	size = 100; // Interval count given 100 in homework description

	points = new Point2D[size];
	
	for(int i=0;i<size;i++) {
  		points[i].setX((circle.getCx() + circle.getRadius() * cos(i * 2 * M_PI / size)));	// X-axis for Polyline.
  		points[i].setY((circle.getCy() + circle.getRadius() * sin(i * 2 * M_PI / size)));	// Y-axis for Polyline.
	}

	color = circle.getColor();

}


Polyline::~Polyline(){	//Destructor for freeing allocated memory.
	
	delete [] points;
}



void Polyline::setColor(std::string newColor){
	color = newColor;
}



// left shift operator overloading for Polyline.

std::ostream& operator<<(std::ostream &outputStream,const Polyline &poly){

	outputStream<< "<polyline points=\"";
	for(int i=0;i<poly.size;i++){
		outputStream << poly.points[i].getX() << "," << poly.points[i].getY() << " ";
	}
	
		outputStream<< "\" style=\"fill:none;stroke:" << poly.color << ";stroke-width:4" << "\" />" << std::endl ;
	
	
	
	return outputStream;
}


bool Polyline::operator==(const Polyline &other)const{

	//We are not checking if they are the same color. Because we are using the color for svg file.
	if(size != other.size){
		return false;
	}
	else{
		for(int i=0;i<size;i++){
			if(points[i] != other.points[i]){
				return false;
			}
		}
	}
	return true;
}

bool Polyline::operator!=(const Polyline &other)const{
	
	return !(*this==other);
	
}

// Index operator overloading for Polyline

const Polyline::Point2D& Polyline::operator[](int index)const{
	if(index<0){
		std::cout << "Illegal index."<< std::endl;
		exit(1);
	}
	return this->points[index];
}
// Index operator overloading for Polyline

Polyline::Point2D& Polyline::operator[](int index){
	if(index<0){
		std::cout << "Illegal index."<< std::endl;
		exit(1);
	}
	return this->points[index];
}

// + operator overload for adding two Polyline.

const Polyline operator+(const Polyline &p1,const Polyline &p2){

	Polyline temp(p1.size+p2.size);

	for(int i=0;i<p1.size;i++){
		temp.points[i]= p1.points[i];
	}
	int j=0;

	for(int i=p1.size;i<temp.size;i++){
		temp.points[i] = p2.points[j];
		j++;
	}

	return temp;

}

// assignment operator overload

Polyline& Polyline::operator=(const Polyline &other){
	if(this == &other){
		return *this;
	}

	delete [] points;

	size = other.size;

	points = new Point2D[other.size];
	
	for(int i=0;i<other.size;i++){
		points[i] = other.points[i];
	}

	return *this;

}

}
