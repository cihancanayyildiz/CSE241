#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

//Defining triangle class.
class Triangle{

public:
	//constructors
	Triangle();

	Triangle(double edge_of_triangle);

	Triangle(double edgge_of_triangle,double x_axis_of_Point1,double y_axis_of_Point1,double x_axis_of_Point2,double y_axis_of_Point2,double x_axis_of_Point3,double y_axis_of_Point3);

	//Setter functions
	void setEdge_of_Triangle(double);
	void set_x_axis_of_Point1(double);
	void set_y_axis_of_Point1(double);
	void set_x_axis_of_Point2(double);
	void set_y_axis_of_Point2(double);
	void set_x_axis_of_Point3(double);
	void set_y_axis_of_Point3(double);
	
	//Getter functions
	const inline double  getEdge_of_Triangle() const{
		return edge_of_triangle;
	}
	const inline double  get_x_axis_of_Point1() const{
		return x_axis_of_Point1;
	}
	const inline double  get_y_axis_of_Point1() const{
		return y_axis_of_Point1;
	}
	const inline double  get_x_axis_of_Point2() const{
		return x_axis_of_Point2;
	}
	const inline double  get_y_axis_of_Point2() const{
		return y_axis_of_Point2;
	}
	const inline double  get_x_axis_of_Point3() const{
		return x_axis_of_Point3;
	}
	const inline double  get_y_axis_of_Point3() const{
		return y_axis_of_Point3;
	}

	const inline double PerimeterLength() const{
		return 3*edge_of_triangle;
	}

	const inline double Area() const{
		return pow(edge_of_triangle,2)*sqrt(3)/4;
	}

	friend ostream& operator <<(ostream& outputStream,const Triangle& tri);

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

	void draw(ofstream &file);

private:
	
	double edge_of_triangle;
	double x_axis_of_Point1;
	double y_axis_of_Point1;
	double x_axis_of_Point2;
	double y_axis_of_Point2;
	double x_axis_of_Point3;
	double y_axis_of_Point3;


};

#endif
