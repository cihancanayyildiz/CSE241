#include "polygonvect.h"

namespace GtuObjects{
	
//Default constructor.
PolygonVect::PolygonVect() : Polygon() { /*Deliberately empty */}

//Sending a vector.
PolygonVect::PolygonVect(const std::vector < Point2D > &v) throw(EmptyVectorException) : Polygon() {
	if(v.size()==0){
		throw EmptyVectorException();
	}
	else{
		points = v;
	}
}

//Sending a point.
PolygonVect::PolygonVect(const Point2D &p) : Polygon() {
	points.push_back(p);
}

//Conversion constructor circle to polygonvect.
PolygonVect::PolygonVect(const Circle &circle) {

	Point2D p;

	for(int i=0;i<100;i++) {
  		p.setX((circle.getCx() + circle.getRadius() * cos(i * 2 * M_PI / 100)));	// X-axis for polygon.
  		p.setY((circle.getCy() + circle.getRadius() * sin(i * 2 * M_PI / 100)));	// Y-axis for polygon.
  		points.push_back(p);
	}

	color = circle.getColor();
}

//Conversion constructor rectangle to polygonvect.
PolygonVect::PolygonVect(const Rectangle &rect){

	Point2D p;

	p.setX(rect.getX());
	p.setY(rect.getY());
	points.push_back(p);
	p.setX(rect.getX());
	p.setY(rect.getY()+rect.getHeight());
	points.push_back(p);
	p.setX(rect.getX()+rect.getWidth());
	p.setY(rect.getY()+rect.getHeight());
	points.push_back(p);
	p.setX(rect.getX()+rect.getWidth());
	p.setY(rect.getY());
	points.push_back(p);
	
	color = rect.getColor();
}

//Conversion constructor triangle to polygonvect.
PolygonVect::PolygonVect(const Triangle &tri){
	Point2D p;

	p.setX(tri.get_x_axis_of_Point1());
	p.setY(tri.get_y_axis_of_Point1());
	points.push_back(p);
	p.setX(tri.get_x_axis_of_Point2());
	p.setY(tri.get_y_axis_of_Point2());
	points.push_back(p);
	p.setX(tri.get_x_axis_of_Point3());
	p.setY(tri.get_y_axis_of_Point3());
	points.push_back(p);

	color = tri.getColor();
}

//Comparison operators for polygonvect.
bool PolygonVect::operator==(const PolygonVect &other)const{

	return points==other.points;
}

bool PolygonVect::operator!=(const PolygonVect &other)const{
		
	return !(*this==other);
		
}


// Index operator overloading for PolygonVect
const Polygon::Point2D& PolygonVect::operator[](int index)const throw(OutOfBoundsException){
	
	if(index<0 || index >= points.size() ){
		throw OutOfBoundsException();	// Throwing exception.
	}
	else{
		return points[index];
	}
}


Polygon::Point2D& PolygonVect::operator[](int index) throw(OutOfBoundsException){

	if(index<0 || index >= points.size() ){
		throw OutOfBoundsException();	// Throwing exception.
	}
	else{
		return points[index];
	}
}

const PolygonVect operator+(const PolygonVect &p1,const PolygonVect &p2){

	PolygonVect temp;

	temp.points.reserve(p1.points.size() + p2.points.size());
	temp.points.insert(temp.points.end(),p1.points.begin(),p1.points.end());
	temp.points.insert(temp.points.end(),p2.points.begin(),p2.points.end());

	return temp;
}

//Virtual area function implementation.
double PolygonVect::Area() const {
	double area = 0;

	for(int i=0 ; i<points.size()-1 ; i++){
		area += (points[i].getX() * points[i+1].getY() - points[i].getY() * points[i+1].getX() );
	}
	area += (points[points.size()-1].getX()*points[0].getY() - points[points.size()-1].getY() * points[0].getX() );
	area = fabs(area)/2.0;

	
	return area;
	
}

//Virtual perimeter function implementation.
double PolygonVect::Perimeter() const {
	double perimeter = 0;


	for(int i=0 ; i<points.size()-1 ; i++){
		perimeter += sqrt(pow(points[i].getX()-points[i+1].getX(),2) + pow(points[i].getY() - points[i+1].getY(),2));
	}
	perimeter += sqrt(pow(points[points.size()-1].getX()-points[0].getX(),2) + pow(points[points.size()-1].getY() - points[0].getY(),2));

	return perimeter;

}

//Virtual helper draw function implementation.
std::ostream& PolygonVect::draw(std::ostream& output) const {

	output<< "<polygon points=\"";
	for(int i=0;i<points.size();i++){
		output << points[i].getX() << "," << points[i].getY() << " ";
	}
	
	output<< "\" style=\"fill:" << color << "\" />" << std::endl ;
	
	return output;

}

//İmplementation of post and prefix operator overloads.
Shape& PolygonVect::operator++() {

	for(int i=0 ; i<points.size() ; i++){
		points[i].setX(points[i].getX()+1);
		points[i].setY(points[i].getY()+1);
	}
	return *this;
}

Shape& PolygonVect::operator++(int){
	PolygonVect  *temp = new PolygonVect(*this);
	++*this;

	return *temp;

}

Shape& PolygonVect::operator--(){
	for(int i=0 ; i<points.size() ; i++){
		points[i].setX(points[i].getX()-1);
		points[i].setY(points[i].getY()-1);
	}
	return *this;
}

Shape& PolygonVect::operator--(int){
	PolygonVect  *temp = new PolygonVect(*this);
	--*this;

	return *temp;
}

std::ostream& operator<<(std::ostream &output,const PolygonVect &poly){

	output<< "<polygon points=\"";
	for(int i=0;i<poly.points.size();i++){
		output << poly.points[i].getX() << "," << poly.points[i].getY() << " ";
	}
	
	output<< "\" style=\"fill:" << poly.color << "\" />" << std::endl ;
	
	return output;

}


}
