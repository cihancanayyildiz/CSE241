#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "composedshape.h"
#include "enum.h"

int main(){
	
	//Defining variables...
	Shapes Mainshape,Smallshape;
	char SelectionofSmall,SelectionofMain;
	double width,height,radius,edge;
	Rectangle MainRect,SmallRect;
	Circle MainCircle,SmallCircle;
	Triangle MainTri,SmallTri;

	//Opening svg file.
	ofstream file("output.svg");
	file << "<svg " << "version=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=" << "\"http://www.w3.org/2000/svg\">\n" ;

	//Taking main selection from user.
	
	cout << "Please enter the main container shape (R, C, T)";
	cin >> SelectionofMain;

	if(SelectionofMain == 'R' || SelectionofMain == 'r' ){

		Mainshape = Shapes::Rectangle;

		cout << "Please enter the width of main rectangle";
		cin >> width;
		
		cout << "Please enter the height of main rectangle";
		cin >> height;
		MainRect.setWidth(width);
		MainRect.setHeight(height);
		
	}
	if(SelectionofMain == 'C' || SelectionofMain == 'c' ){

		Mainshape = Shapes::Circle;

		cout << "Please enter the radius of the main circle";
		cin >> radius;
		MainCircle.setRadius(radius);
		MainCircle.setCx(radius);
		MainCircle.setCy(radius);

		
	}
	if(SelectionofMain == 'T' || SelectionofMain == 't' ){

		Mainshape = Shapes::Triangle;

		cout << "Please enter the edge of the main triangle";
		cin >> edge;
		MainTri.setEdge_of_Triangle(edge);
	}

	//Taking small shape  selection from user.

	cout << "Please enter the small shape ( R, C, T)";
	cin >> SelectionofSmall;

	
	if(SelectionofSmall == 'R' || SelectionofSmall == 'r'){

		Smallshape = Shapes::Rectangle;
	
		cout << "Please enter the width of small rectangle";
		cin >> width;
		
		cout << "Please enter the height of small rectangle";
		cin >> height;

		SmallRect.setWidth(width);
		SmallRect.setHeight(height);


	}
	if(SelectionofSmall == 'C' || SelectionofSmall == 'c'){

		Smallshape = Shapes::Circle;


		cout << "Please enter the radius of the small circle";
		cin >> radius;

		SmallCircle.setRadius(radius);
		
	}
	if(SelectionofSmall == 'T' || SelectionofSmall == 't'){

		Smallshape = Shapes::Triangle;

		cout << "Please enter the edge of the small triangle";
		cin >> edge;

		SmallTri.setEdge_of_Triangle(edge);
		
	}

	//Calling functions for every combination..

	if(Mainshape == Shapes::Rectangle && Smallshape == Shapes::Circle){

		ComposedShape circleinrect(MainRect,SmallCircle);
		MainRect.draw(file);
		circleinrect.optimalFit(MainRect,SmallCircle);
		file << circleinrect; 
	}

	if(Mainshape == Shapes::Rectangle && Smallshape == Shapes::Rectangle){
		ComposedShape rectangleinrect(MainRect,SmallRect);
		MainRect.draw(file);
		rectangleinrect.optimalFit(MainRect,SmallRect);
		file<< rectangleinrect;
	}
	if(Mainshape == Shapes::Rectangle && Smallshape == Shapes::Triangle){
		ComposedShape triangleinrect(MainRect,SmallTri);
		MainRect.draw(file);
		triangleinrect.optimalFit(MainRect,SmallTri);
		file << triangleinrect;
		
	}
	if(Mainshape == Shapes::Triangle && Smallshape == Shapes::Rectangle){
		ComposedShape rectinTriangle(MainTri,SmallRect);
		MainTri.draw(file);
		rectinTriangle.optimalFit(MainTri,SmallRect);
		file << rectinTriangle;
	}
	if(Mainshape == Shapes::Triangle && Smallshape == Shapes::Triangle){
		ComposedShape  TriangleinTriangle(MainTri,SmallTri);
		MainTri.draw(file);
		TriangleinTriangle.optimalFit(MainTri,SmallTri);
		file << TriangleinTriangle;
	}

	if(Mainshape == Shapes::Triangle && Smallshape == Shapes::Circle){
		ComposedShape  CircleinTriangle(MainTri,SmallCircle);
		MainTri.draw(file);
		CircleinTriangle.optimalFit(MainTri,SmallCircle);
		file << CircleinTriangle;
	}

	if(Mainshape == Shapes::Circle && Smallshape == Shapes::Circle){
		ComposedShape  CircleinCircle(MainCircle,SmallCircle);
		MainCircle.draw(file);
		CircleinCircle.optimalFit(MainCircle,SmallCircle);
		file << CircleinCircle;
	}	

	file << "</svg>" ;

	return 0;
}
