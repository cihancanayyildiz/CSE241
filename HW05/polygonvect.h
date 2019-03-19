#ifndef POLYGONVECT_H
#define POLYGONVECT_H
#include "polygon.h"

namespace GtuObjects{
class PolygonVect : public Polygon {
public:
	
	//Constructors.
	PolygonVect();
	PolygonVect(const std::vector < Point2D > &v) throw(EmptyVectorException);
	PolygonVect(const Circle &circle);
	PolygonVect(const Rectangle &rect);
	PolygonVect(const Triangle &tri);
	PolygonVect(const Point2D &p);

	//Operator overloads..

	double Area() const override ;
	double Perimeter() const override ;
	std::ostream& draw(std::ostream& output) const override;

	Shape& operator++() override ;
	Shape& operator++(int) override ;
	Shape& operator--() override ;
	Shape& operator--(int) override ;

	bool operator==(const PolygonVect &other)const;
	bool operator!=(const PolygonVect &other)const;
	Point2D& operator[](int index) throw(OutOfBoundsException);
	const Point2D& operator[](int index)const throw(OutOfBoundsException);

	friend const PolygonVect operator+(const PolygonVect &p1,const PolygonVect &p2);

	friend std::ostream& operator<<(std::ostream &output,const PolygonVect &poly);

private:
	std::vector < Point2D > points;
};
}
#endif