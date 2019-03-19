#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "composedshape.h"
#include "enum.h"

int main(){
	//Defining variables...
	Shapes Mainshape,Smallshape;
	char SelectionofSmall,SelectionofMain;
	Rectangle LargerRect;
	Triangle LargerTri;
	Circle LargerCircle;

	//Opening svg file.
	ofstream file("output.svg");
	file << "<svg " << "version=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=" << "\"http://www.w3.org/2000/svg\">\n" ;

	//Taking main selection from user.
	
	cout << "Please enter the main container shape (R, C, T)";
	cin >> SelectionofMain;

	if(SelectionofMain == 'R' || SelectionofMain == 'r' ){
		Mainshape = Shapes::Rectangle;
		
	}
	if(SelectionofMain == 'C' || SelectionofMain == 'c' ){
		Mainshape = Shapes::Circle;
		
	}
	if(SelectionofMain == 'T' || SelectionofMain == 't' ){
		Mainshape = Shapes::Triangle;

	}

	//Taking small shape  selection from user.

	cout << "Please enter the small shape ( R, C, T)";
	cin >> SelectionofSmall;

	
	if(SelectionofSmall == 'R' || SelectionofSmall == 'r'){
		Smallshape = Shapes::Rectangle;

	}
	if(SelectionofSmall == 'C' || SelectionofSmall == 'c'){

		Smallshape = Shapes::Circle;
		
	}
	if(SelectionofSmall == 'T' || SelectionofSmall == 't'){

		Smallshape = Shapes::Triangle;
		
	}

	//Calling functions for every combination..

	if(Mainshape == Shapes::Rectangle && Smallshape == Shapes::Circle){

		ComposedShape circleinrect(LargerRect);
		LargerRect.draw(file);
		circleinrect.optimalFit(LargerRect,Mainshape,Smallshape);
		circleinrect.draw(file,Mainshape,Smallshape);
		
	}
	if(Mainshape == Shapes::Rectangle && Smallshape == Shapes::Rectangle){
		ComposedShape rectangleinrect(LargerRect);
		LargerRect.draw(file);
		rectangleinrect.optimalFit(LargerRect,Mainshape,Smallshape);
		rectangleinrect.draw(file,Mainshape,Smallshape);
	}
	if(Mainshape == Shapes::Rectangle && Smallshape == Shapes::Triangle){
		ComposedShape triangleinrect(LargerRect);
		LargerRect.draw(file);
		triangleinrect.optimalFit(LargerRect,Mainshape,Smallshape);
		triangleinrect.draw(file,Mainshape,Smallshape);
		
	}
	if(Mainshape == Shapes::Triangle && Smallshape == Shapes::Rectangle){
		ComposedShape rectinTriangle(LargerTri);
		LargerTri.draw(file);
		rectinTriangle.optimalFit(LargerTri,Mainshape,Smallshape);
		rectinTriangle.draw(file,Mainshape,Smallshape);
	}
	if(Mainshape == Shapes::Triangle && Smallshape == Shapes::Triangle){
		ComposedShape  TriangleinTriangle(LargerTri);
		LargerTri.draw(file);
		TriangleinTriangle.optimalFit(LargerTri,Mainshape,Smallshape);
		TriangleinTriangle.draw(file,Mainshape,Smallshape);
	}

	if(Mainshape == Shapes::Triangle && Smallshape == Shapes::Circle){
		ComposedShape  CircleinTriangle(LargerTri);
		LargerTri.draw(file);
		CircleinTriangle.optimalFit(LargerTri,Mainshape,Smallshape);
		CircleinTriangle.draw(file,Mainshape,Smallshape);
	}

	if(Mainshape == Shapes::Circle && Smallshape == Shapes::Circle){
		ComposedShape  CircleinCircle(LargerCircle);
		LargerCircle.draw(file);
		CircleinCircle.optimalFit(LargerCircle,Mainshape,Smallshape);
		CircleinCircle.draw(file,Mainshape,Smallshape);

	}
	

	file << "</svg>" ;

	return 0;
}
