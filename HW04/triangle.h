#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include <cmath>
#include <cstdlib>

namespace GtuObjects{

//Defining triangle class.
class Triangle{

public:
	//constructors
	Triangle();

	Triangle(double edge_of_triangle);

	Triangle(double edge_of_triangle,double x_axis_of_Point1,double y_axis_of_Point1,double x_axis_of_Point2,double y_axis_of_Point2,double x_axis_of_Point3,double y_axis_of_Point3);

	//Setter functions
	void setEdge_of_Triangle(double);
	void set_x_axis_of_Point1(double);
	void set_y_axis_of_Point1(double);
	void set_x_axis_of_Point2(double);
	void set_y_axis_of_Point2(double);
	void set_x_axis_of_Point3(double);
	void set_y_axis_of_Point3(double);
	void setColor(std::string color);
	
	//Getter functions
	inline double  getEdge_of_Triangle() const{
		return edge_of_triangle;
	}
	inline double  get_x_axis_of_Point1() const{
		return x_axis_of_Point1;
	}
	inline double  get_y_axis_of_Point1() const{
		return y_axis_of_Point1;
	}
	inline double  get_x_axis_of_Point2() const{
		return x_axis_of_Point2;
	}
	inline double  get_y_axis_of_Point2() const{
		return y_axis_of_Point2;
	}
	inline double  get_x_axis_of_Point3() const{
		return x_axis_of_Point3;
	}
	inline double  get_y_axis_of_Point3() const{
		return y_axis_of_Point3;
	}
	inline std::string getColor() const {
		return color;
	}

	inline double PerimeterLength() const{
		return 3*edge_of_triangle;
	}

	inline double Area() const{
		return pow(edge_of_triangle,2)*sqrt(3)/4;
	}

	friend std::ostream& operator <<(std::ostream& outputStream,const Triangle& tri);

	Triangle& operator ++();		//prefix version

	Triangle operator ++(int);		//postfix version

	Triangle& operator --(); 		//prefix version

	Triangle operator --(int);		//postfix version

	bool operator==(const Triangle &other) const;
	bool operator!=(const Triangle &other) const;
	bool operator>(const Triangle &other) const;
	bool operator<(const Triangle &other) const;
	bool operator>=(const Triangle &other) const;
	bool operator<=(const Triangle &other) const;
	friend Triangle operator+(const Triangle &triangle,double value);
	friend Triangle operator-(const Triangle &triangle,double value);

	
private:
	
	double edge_of_triangle;
	double x_axis_of_Point1;
	double y_axis_of_Point1;
	double x_axis_of_Point2;
	double y_axis_of_Point2;
	double x_axis_of_Point3;
	double y_axis_of_Point3;
	std::string color;	//Color data.

};

}

#endif
