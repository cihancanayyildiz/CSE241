#include <iostream>
#include <fstream>
#include <cmath>
#include "source1.h"

using namespace std;

int main(){
	/*Defining variables.*/
	Shapes Mainshape,Smallshape;
	char SelectionofMain,SelectionofSmall;
	
	float R1width,R1height,mainradius,Tedge1,R2width,R2height,smallradius,Tedge2;
	int trianglecount,circlecount,rectanglecount;
	int emptyarea;

	ofstream file("output.svg");	/*Opening the file.*/
	
	file << "<svg " << "version=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=" << "\"http://www.w3.org/2000/svg\">\n" ;

	
	cout << "Please enter the main container shape (R, C, T)";
	cin >> SelectionofMain;
	/*Determining the enums and taking the inputs from user.*/
	if(SelectionofMain == 'R' || SelectionofMain == 'r' ){
		Mainshape = Shapes::Rectangle;
		cout << "Please enter the width";
		cin >> R1width;
		cout << "Please enter the height";
		cin >> R1height;
	}
	if(SelectionofMain == 'C' || SelectionofMain == 'c' ){
		Mainshape = Shapes::Circle;
		cout << "Please enter the radius";
		cin >> mainradius;
	}
	if(SelectionofMain == 'T' || SelectionofMain == 't' ){
		Mainshape = Shapes::Triangle;
		cout << "Please enter the edge of triangle";
		cin >> Tedge1;
	}
	

	cout << "Please enter the small shape ( R, C, T)";
	cin >> SelectionofSmall;

	/*Determining the enums and taking the inputs from user.*/
	if(SelectionofSmall == 'R' || SelectionofSmall == 'r'){
		Smallshape = Shapes::Rectangle;
		cout << "Please enter the width";
		cin >> R2width;
		cout << "Please enter the height";
		cin >> R2height;
	}
	if(SelectionofSmall == 'C' || SelectionofSmall == 'c'){
		Smallshape = Shapes::Circle;
		cout << "Please enter the radius";
		cin >> smallradius;
	}
	if(SelectionofSmall == 'T' || SelectionofSmall == 't'){
		Smallshape = Shapes::Triangle;
		cout << "Please enter the edge of triangle";
		cin >> Tedge2;
	}
	

	/*Calling the all functions .*/
	if(Mainshape == Shapes::Rectangle && Smallshape == Shapes::Circle ){
		circlecount = smallerCircles_within_largerRectangle(file,R1width,R1height,smallradius);
		emptyarea =	(R1height*R1width)-(circlecount*PI*smallradius*smallradius);
		cout << "I can fit at most " << circlecount
		<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << endl;
	}
	if(Mainshape == Shapes::Rectangle && Smallshape == Shapes::Rectangle){
		rectanglecount = smallerRectangles_within_largerRectangle(file,R1width,R1height,R2width,R2height);
		emptyarea = (R1height*R1width)-rectanglecount*(R2height*R2width);
		cout << "I can fit at most " <<  rectanglecount
		<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << endl;
	}
	if(Mainshape == Shapes::Rectangle && Smallshape == Shapes::Triangle){

		trianglecount=smallerTriangles_within_largerRectangle(file,Tedge2,R1width,R1height);
		emptyarea = (R1width*R1height)-trianglecount*((Tedge2*Tedge2)*sqrt(3)/4);
		
		cout << "I can fit at most " << trianglecount 
		<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << endl;
	}
	if(Mainshape == Shapes::Triangle && Smallshape == Shapes::Rectangle){
		rectanglecount = smallerRectangles_within_largerTriangle(file,Tedge1,R2width,R2height);
		emptyarea = (Tedge1*Tedge1*sqrt(3)/4) - rectanglecount*(R2width*R2height);
		cout << "I can fit at most " <<  rectanglecount
		<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << endl;
	}
	if(Mainshape == Shapes::Triangle && Smallshape == Shapes::Triangle){
		trianglecount = smallerTriangles_within_LargerTriangle(file,Tedge2,Tedge1);
		emptyarea = (Tedge1*Tedge1*sqrt(3)/4)-(trianglecount*Tedge2*Tedge2*sqrt(3)/4);
		cout << "I can fit at most " <<  trianglecount
		<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << endl;
		
	}
	if(Mainshape == Shapes::Circle && Smallshape == Shapes::Circle){

		circlecount = smallerCircles_within_LargerCircle(file,mainradius,smallradius);
		emptyarea = (mainradius*mainradius*PI)-(circlecount*PI*smallradius*smallradius);
		cout << "I can fit at most " <<  circlecount
		<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << endl;
	}
	if(Mainshape == Shapes::Triangle && Smallshape == Shapes::Circle){
		circlecount = smallerCircles_within_largerTriangle(file,smallradius,Tedge1);;
		emptyarea = (Tedge1*Tedge1*sqrt(3)/4)-(circlecount*PI*smallradius*smallradius);
		cout << "I can fit at most " <<  circlecount
		<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << endl;
		
	}


	file << "</svg>" ;
	file.close();
	return 0;
}