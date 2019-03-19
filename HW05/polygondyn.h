#ifndef POLYGONDYN_H
#define POLYGONDYN_H
#include "polygon.h"

namespace GtuObjects{
class PolygonDyn : public Polygon {
public:
	
	PolygonDyn(); 
	PolygonDyn(int _size) throw(PolyLessThanZero); 
	PolygonDyn(const std::vector < Point2D > &v) throw(EmptyVectorException); 
	PolygonDyn(const Circle &circle);
	PolygonDyn(const Rectangle &rect);
	PolygonDyn(const Triangle &tri);
	PolygonDyn(const Point2D &p);

	//Operator overloads..

	double Area() const override ;
	double Perimeter() const override ;
	std::ostream& draw(std::ostream& output) const override;

	Shape& operator++() override ;
	Shape& operator++(int) override ;
	Shape& operator--() override ;
	Shape& operator--(int) override ;

	bool operator==(const PolygonDyn &other)const;
	bool operator!=(const PolygonDyn &other)const;

	Point2D& operator[](int index) throw(OutOfBoundsException);
	const Point2D& operator[](int index)const throw(OutOfBoundsException);

	friend const PolygonDyn operator+(const PolygonDyn &p1,const PolygonDyn &p2);

	friend std::ostream& operator<<(std::ostream &output,const PolygonDyn &poly);

	//Big Three

	PolygonDyn(const PolygonDyn &poly);	//Copy constructor.

	PolygonDyn& operator=(const PolygonDyn &other);	//Assingment operator overload.

	~PolygonDyn(); //Destructor.

private:
	Point2D *points;
	int size;
};
}
#endif