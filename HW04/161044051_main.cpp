#include <fstream>
#include "composedshape.h"
#include "polyline.h"

using namespace GtuObjects;
using  std::cout;
using  std::endl;
using  std::ofstream;

namespace {	//Using unname namespace.

	void test_creating_objects();

	void test_polygon_class();

	void test_composedshape_class();

	void test_polyline_class();
}

int main(){

	test_creating_objects();    // You can create all 7 svg files with this function.

	test_polygon_class();	//Test for the polygon class.

	test_polyline_class();	//Test for polyline class.

	test_composedshape_class();	//Test for composedshape class.

	return 0;
}

namespace {	//Using unname namespace.

void test_composedshape_class(){
	//Creating variables for testing..
	Rectangle MR(300,200);
	Circle IC(25);

	//Opening our file for testing..
	ofstream file("outputComposedTest.svg");
	file << "<svg " << "version=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=" << "\"http://www.w3.org/2000/svg\">\n" ;

	//We created the objects.
	ComposedShape test(MR);
	test.optimalFit(MR,IC);

	// creating a new object.
	Rectangle newRect(30,20,50,50);
	newRect.setColor("pink");

	//adding it
	test+= newRect;

	// creating a new object.
	Circle newCircle(35,250,100);
	newCircle.setColor("yellow");

	test+= newCircle;

	Triangle newTri(40);
	newTri.setColor("blue");

	test+= newTri;

	file << test;

	file << "</svg>";
	file.close();


	//If we test index operator of composedshape

	Polygon poly = test[10]; //Now we have new poly object and its test's 10th object.
	
}

void test_polygon_class(){	//I have some terminal description here. Writing some explanation on the terminal you can read from there.
	//Opening our file ..
	ofstream file("outputPolyGonTest.svg");
	file << "<svg " << "version=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=" << "\"http://www.w3.org/2000/svg\">\n" ;
	
	//Creating objects.
	Circle c1(50,50,50);
	Rectangle r1(300,200,0,0);
	Triangle t1;

	//Creating 2D points.
	Polygon::Point2D p1(200,10),p2(250,190),p3(160,210),p4(400,500);

	//Creating polygon objects and doing some test with them.
	Polygon poly1(p1),poly2(p2);

	std::vector <GtuObjects::Polygon::Point2D> pointvector;	//we created a vector of 2D points.

	//Pushing our points..
	pointvector.push_back(p1);
	pointvector.push_back(p2);
	pointvector.push_back(p3);
	pointvector.push_back(p4);

	Polygon poly3(pointvector);	//Testing conversion point2d vector to polygon.
	poly3.setColor("yellow");

	file << poly3;	// writing it into file.

	Polygon poly4(r1),poly5(t1),poly6(c1);	// creating another two polygon objects. We are testing our conversion constructors.. 

	Polygon poly7 = poly4+poly5;

	poly7.setColor("pink");

	file << poly7;	// test :::  adding two polygons by concatenating the points and writing them with << operator overload..
	cout << "We are adding two polygons by concatenating the points.." << endl;
	cout << poly7;

	cout << "Testing index operator --> " << poly4[0]  ;	// testing [] index operator.

	poly4 = poly5 ; // testing assignment(=) operator overload.

	//Passing them on the terminal for check. You can check are they assigned.
	cout << "We can see they are equal" << endl;
	cout << poly4;	
	cout << poly5;

	if(poly4 == poly5){	// testing == operator overload.
		cout << "Equal." << endl; 
	}

	if(poly4 != poly3){ // testing != operator overload.
		cout << "Not equal." << endl;
	}

	file << "</svg>";
	file.close();

}

void test_polyline_class(){
	//Opening our file ..
	ofstream file("outputPolyLineTest.svg");
	file << "<svg " << "version=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=" << "\"http://www.w3.org/2000/svg\">\n" ;
	
	Polyline::Point2D p1;
	std::vector <GtuObjects::Polyline::Point2D> pointvector;

	//If we create a shape with points.
	for(int i=0;i<160;i+=40){
		p1.setX(i); p1.setY(i);
		pointvector.push_back(p1);
		p1.setX(i); p1.setY(i+40);
		pointvector.push_back(p1);
	}

	Polyline poly(pointvector);	//we are sending it to polyline.


	poly.setColor("yellow");
	
	file << poly;	//writing it into file.

	file << "</svg>";

	file.close();

}

void test_creating_objects(){	//Creating all  composed  objects with this function..
	Circle MC(500),IC(22);
	Rectangle MR(300,200),IR(50,30);
	Triangle MT(300),IT(35);

	cout<< endl;
	ofstream file("output1.svg");
	file << "<svg " << "version=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=" << "\"http://www.w3.org/2000/svg\">\n" ;
	cout<< "Smaller circles within a larger rectangle in : output1.svg" << endl; 
	ComposedShape circleinrectangle(MR);
	circleinrectangle.optimalFit(MR,IC);
	file << circleinrectangle;
	file << "</svg>";
	file.close();

	cout << "---------------------------------------------------------------------------------------------" << endl<<endl;

	ofstream file2("output2.svg");
	file2 << "<svg " << "version=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=" << "\"http://www.w3.org/2000/svg\">\n" ;
	cout<< "Smaller circles within a larger triangle in : output2.svg" << endl; 
	ComposedShape circleintriangle(MT);
	circleintriangle.optimalFit(MT,IC);
	file2 << circleintriangle;
	file2 << "</svg>";
	file2.close();

	cout << "---------------------------------------------------------------------------------------------" << endl<<endl;

	ofstream file3("output3.svg");
	file3 << "<svg " << "version=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=" << "\"http://www.w3.org/2000/svg\">\n" ;
	cout<< "Smaller circles within a larger circle in : output3.svg" << endl; 
	ComposedShape circleincircle(MC);
	circleincircle.optimalFit(MC,IC);
	file3 << circleincircle;
	file3 << "</svg>";
	file3.close();

	cout << "---------------------------------------------------------------------------------------------" << endl<<endl;

	ofstream file4("output4.svg");
	file4 << "<svg " << "version=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=" << "\"http://www.w3.org/2000/svg\">\n" ;
	cout<< "Smaller rectangles within a larger rectangle in : output4.svg" << endl; 
	ComposedShape rectangleinrectangle(MR);
	rectangleinrectangle.optimalFit(MR,IR);
	file4 << rectangleinrectangle;
	file4 << "</svg>";
	file4.close();

	cout << "---------------------------------------------------------------------------------------------" << endl<<endl;

	ofstream file5("output5.svg");
	file5 << "<svg " << "version=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=" << "\"http://www.w3.org/2000/svg\">\n" ;
	cout<< "Smaller rectangles within a larger triangle in : output5.svg" << endl; 
	ComposedShape rectangleintriangle(MT);
	rectangleintriangle.optimalFit(MT,IR);
	file5 << rectangleintriangle;
	file5 << "</svg>";
	file5.close();

	cout << "---------------------------------------------------------------------------------------------" << endl<<endl;

	ofstream file6("output6.svg");
	file6 << "<svg " << "version=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=" << "\"http://www.w3.org/2000/svg\">\n" ;
	cout<< "Smaller triangles within a larger triangle in : output6.svg" << endl; 
	ComposedShape triangleintriangle(MT);
	triangleintriangle.optimalFit(MT,IT);
	file6 << triangleintriangle;
	file6 << "</svg>";
	file6.close();

	cout << "---------------------------------------------------------------------------------------------" << endl<<endl;

	ofstream file7("output7.svg");
	file7 << "<svg " << "version=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=" << "\"http://www.w3.org/2000/svg\">\n" ;
	cout<< "Smaller triangles within a larger rectangle in : output7.svg" << endl; 
	ComposedShape triangleinrectangle(MR);
	triangleinrectangle.optimalFit(MR,IT);
	file7 << triangleinrectangle;
	file7 << "</svg>";
	file7.close();
	cout << endl;
}
}
