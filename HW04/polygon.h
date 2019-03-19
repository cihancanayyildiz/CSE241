#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"

namespace GtuObjects{

class Point2D;

class Polygon{
public:

	class Point2D{
	public:
		Point2D();	//Default constructor of Point2D
		Point2D(double xValue,double yValue);

		//Getters.

		inline double getX() const { return X;}
		inline double getY() const { return Y;}

		//Setters.

		void setX(double xValue);
		void setY(double yValue);

		//Operator overloads.

		bool operator==(const Point2D &other)const;
		bool operator!=(const Point2D &other)const;
		friend std::ostream& operator<<(std::ostream &outputStream,const Point2D &p);

	private:
		double X;
		double Y;
	};

	Polygon();	//Default constructor of Polygon.
	Polygon(int size);
	Polygon(const std::vector<Point2D> &v);	//Conversion constructor for incoming vector.
	Polygon(const Point2D &point);	//Conversion constructor for incoming one point.
	
	//Converting objects their types to polygon.

	Polygon(const Circle &circle);	//Conversion constructor for circle.
	Polygon(const Rectangle &rect);	//Conversion constructor for rectangle.
	Polygon(const Triangle &tri);	//Conversion constructor for triangle.

	inline std::string getColor()const { //Getter
		return color;
	}

	void setColor(std::string);	//Setter

	//Operator overloads..

	bool operator==(const Polygon &other)const;
	bool operator!=(const Polygon &other)const;
	Point2D& operator[](int index);
	const Point2D& operator[](int index)const;

	friend const Polygon operator+(const Polygon &p1,const Polygon &p2);

	friend std::ostream& operator<<(std::ostream &outputStream,const Polygon &poly);

	//Big Three..

	Polygon(const Polygon &poly);	//Copy constructor.

	Polygon& operator=(const Polygon &other);	//Assingment operator overload.

	~Polygon();	//Destructor.

private:
	Point2D *points;	//Holding points with this pointer.
	int size;
	std::string color;

};

}

#endif