#include "polygondyn.h"


namespace GtuObjects{

PolygonDyn::PolygonDyn() : Polygon() {	//Default constructor for PolygonDyn.
	size=5;
	points = new Point2D[size];
}

PolygonDyn::PolygonDyn(int _size) throw(PolyLessThanZero) : Polygon() {
	if(_size<=0){
		throw PolyLessThanZero(); //Throwing exception.
	}
	else{
		size=_size;
		points = new Point2D[size];
	}
}

//Sending a vector.
PolygonDyn::PolygonDyn(const std::vector<Point2D> &v) throw(EmptyVectorException) : Polygon() {
	if(v.size()==0){
		throw EmptyVectorException(); //Throwing exception.
	}
	else{
		size = v.size();
		points = new Point2D[size];

		for(int i=0;i<size;i++){
			points[i] = v[i];
		}
	}
}

//Sending a point.
PolygonDyn::PolygonDyn(const Point2D &point)  : Polygon() {
	size = 1;
	points = new Point2D[size];
	
}

//Copy Constructor.
PolygonDyn::PolygonDyn(const PolygonDyn &poly){
	size = poly.size;

	points = new Point2D[size];
	
	for(int i=0;i<size;i++){
		points[i] = poly.points[i];
	}

	color = poly.color;

}

//Conversion constructor polygondyn to triangle.
PolygonDyn::PolygonDyn(const Triangle &tri){	//conversion constructor

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

//Conversion constructor polygondyn to rectangle.
PolygonDyn::PolygonDyn(const Rectangle &rect){	//conversion constructor
	
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

//Conversion constructor polygondyn to circle.
PolygonDyn::PolygonDyn(const Circle &circle){		//conversion constructor

	size = 100; // Interval count given 100 in homework description

	points = new Point2D[size];
	
	for(int i=0;i<size;i++) {
  		points[i].setX((circle.getCx() + circle.getRadius() * cos(i * 2 * M_PI / size)));	// X-axis for PolygonDyn.
  		points[i].setY((circle.getCy() + circle.getRadius() * sin(i * 2 * M_PI / size)));	// Y-axis for PolygonDyn.
	}

	color = circle.getColor();

}

//implementing virtual area function.
double PolygonDyn::Area() const {
	double area = 0;

	// looping until the end of size.
	for(int i=0 ; i<size-1 ; i++){
		area += (points[i].getX() * points[i+1].getY() - points[i].getY() * points[i+1].getX() );
	}
	// and combining  last point and first point.
	area += (points[size-1].getX()*points[0].getY() - points[size-1].getY() * points[0].getX() );
	area = fabs(area)/2.0;
	
	return area;
	
}

//implementing virtual perimeter  function.
double PolygonDyn::Perimeter() const {
	double perimeter = 0;

	// looping until the end of size.
	for(int i=0 ; i<size-1 ; i++){
		perimeter += sqrt(pow(points[i].getX()-points[i+1].getX(),2) + pow(points[i].getY() - points[i+1].getY(),2));
	}

	// and combining  last point and first point.
	perimeter += sqrt(pow(points[size-1].getX()-points[0].getX(),2) + pow(points[size-1].getY() - points[0].getY(),2));

	return perimeter;

}

//Implementing virtual  helper draw function.
std::ostream& PolygonDyn::draw(std::ostream& output) const {

	output<< "<polygon points=\"";
	for(int i=0;i<size;i++){
		output << points[i].getX() << "," << points[i].getY() << " ";
	}
	
	output<< "\" style=\"fill:" << color << "\" />" << std::endl ;
	
	return output;

}

//Implementation of prefix and postfix operators.

Shape& PolygonDyn::operator++() {

	for(int i=0 ; i<size ; i++){
		points[i].setX(points[i].getX()+1);
		points[i].setY(points[i].getY()+1);
	}
	return *this;
}

Shape& PolygonDyn::operator++(int){
	PolygonDyn  *temp = new PolygonDyn(*this);
	++*this;

	return *temp;

}

Shape& PolygonDyn::operator--(){
	for(int i=0 ; i<size ; i++){
		points[i].setX(points[i].getX()-1);
		points[i].setY(points[i].getY()-1);
	}
	return *this;
}

Shape& PolygonDyn::operator--(int){
	PolygonDyn  *temp = new PolygonDyn(*this);
	--*this;

	return *temp;
}



// left shift operator overloading for PolygonDyn.

std::ostream& operator<<(std::ostream &outputStream,const PolygonDyn &poly){

	outputStream<< "<PolygonDyn points=\"";
	for(int i=0;i<poly.size;i++){
		outputStream << poly.points[i].getX() << "," << poly.points[i].getY() << " ";
	}
	
		outputStream<< "\" style=\"fill:" << poly.color << "\" />" << std::endl ;
	
	
	
	return outputStream;
}


bool PolygonDyn::operator==(const PolygonDyn &other)const{

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

bool PolygonDyn::operator!=(const PolygonDyn &other)const{
	
	return !(*this==other);
	
}

// Index operator overloading for PolygonDyn

const PolygonDyn::Point2D& PolygonDyn::operator[](int index)const throw(OutOfBoundsException){
	if(index<0 || index>=size ){
		throw OutOfBoundsException();
	}
	else{
		return points[index];
	}
	
}
// Index operator overloading for PolygonDyn

PolygonDyn::Point2D& PolygonDyn::operator[](int index) throw(OutOfBoundsException){
	if(index<0 || index>=size ){
		throw OutOfBoundsException();
	}
	else{
		return points[index];
	}
}

// + operator overload for adding two PolygonDyn.

const PolygonDyn operator+(const PolygonDyn &p1,const PolygonDyn &p2){

	PolygonDyn temp(p1.size+p2.size);

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

PolygonDyn& PolygonDyn::operator=(const PolygonDyn &other){
	if(size != other.size){	//Looking for size
		delete [] points;	//deleting 
		points = new  Point2D[other.size];	//allocating new memory
	}

	size = other.size;

	for(int i=0;i<size;i++){
		points[i] = other.points[i];	//assigning other's points.
	}

	return *this;
}

PolygonDyn::~PolygonDyn(){	//Destructor for freeing allocated memory.
	
	delete [] points;
}

}
