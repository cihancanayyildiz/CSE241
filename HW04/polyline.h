#ifndef POLYLINE_H
#define POLYLINE_H

#include <vector>
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"

namespace GtuObjects{

class Point2D;

class Polyline{
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

	Polyline();	//Default constructor of Polyline.
	Polyline(int size);
	Polyline(const std::vector<Point2D> &v);	//Conversion constructor for incoming vector.
	Polyline(const Point2D &point);	//Conversion constructor for incoming one point.
	
	//Converting objects their types to Polyline.

	Polyline(const Circle &circle);	//Conversion constructor for circle.
	Polyline(const Rectangle &rect);	//Conversion constructor for rectangle.
	Polyline(const Triangle &tri);	//Conversion constructor for triangle.

	inline std::string getColor()const { //Getter
		return color;
	}

	void setColor(std::string);	//Setter

	//Operator overloads..

	bool operator==(const Polyline &other)const;
	bool operator!=(const Polyline &other)const;
	Point2D& operator[](int index);
	const Point2D& operator[](int index)const;

	friend const Polyline operator+(const Polyline &p1,const Polyline &p2);

	friend std::ostream& operator<<(std::ostream &outputStream,const Polyline &poly);

	//Big Three..

	Polyline(const Polyline &poly);	//Copy constructor.

	Polyline& operator=(const Polyline &other);	//Assingment operator overload.

	~Polyline();	//Destructor.

private:
	Point2D *points;	//Holding points with this pointer.
	int size;
	std::string color;

};

}

#endif