#ifndef POLYGON_H
#define POLYGON_H
#include <cmath>
#include <vector>
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

namespace GtuObjects {

// This is an abstract polygon class.Inherits from shape class.
class Polygon : public Shape {
public:
	// nested point2d class.
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

	Polygon();


	void setColor(std::string);	//Setter

	inline std::string getColor()const { //Getter
		return color;
	}

	virtual ~Polygon() = default;

protected:
	std::string color;
};

}

#endif