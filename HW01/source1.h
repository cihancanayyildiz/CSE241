/*Header file*/
#ifndef _SOURCE1_H_
#define _SOURCE1_H_

#define PI 3.14159265358979323
using namespace std;

/*Defining the enum.*/

enum Shapes{
	Rectangle,
	Circle,
	Triangle
};


/* Defining the functions.*/

int smallerCircles_within_largerRectangle(ofstream& file,float rect_width,float rect_height,float radius);

int smallerRectangles_within_largerRectangle(ofstream& file,float rect1_width,float rect1_height,float rect2_width,float rect2_height);

int smallerTriangles_within_largerRectangle(ofstream& file,float triangle_edge,float rect_width,float rect_height);

int smallerRectangles_within_largerTriangle(ofstream& file,float triangle_edge,float rect_width,float rect_height);

int smallerTriangles_within_LargerTriangle(ofstream& file,float small_t_edge,float larger_t_edge);

int smallerCircles_within_largerTriangle(ofstream& file,float radius,float t_edge);

int smallerCircles_within_LargerCircle(ofstream& file,float large_radius,float small_radius);


#endif