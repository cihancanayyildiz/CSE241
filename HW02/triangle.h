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
