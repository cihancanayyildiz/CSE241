#include <fstream>
#include "composedshape.h"
#include "polygon.h"
#include "polygondyn.h"
#include "polygonvect.h"

using namespace GtuObjects;
using  std::cout;
using  std::endl;
using  std::ofstream;
using  std::vector;


namespace {
	//Given global functions in homework description.

	void PrintAll(const vector <Shape*> &ptrvector) throw(EmptyVectorException);
	void PrintPoly(const vector <Shape*> &ptrvector) throw(EmptyVectorException);
	vector<Shape*> ConvertAll(const vector<Shape*> &ptrvector) throw(EmptyVectorException);
	void sortShapes(vector <Shape*> &ptrvector) throw(EmptyVectorException);
}

namespace {
	//Test global functions
	//I separate them in terminal you can check them in terminal.

	void CreatingAllObjects();	//Creating and printing all composed shape posibilities.
	void TestNewComposedShape(); //Testing new composed shape class.
	void TestGivenHomeworkGlobals();	// Testing all given global functions.
	void TestThrowExceptions();	//Testing our throw exceptions as you want.
	void TestShapeClass(); //Testing shape class functions.
	void printAreas(const vector<Shape*> &ptrvector); //For testing sortShapes global function. Created for reader.
	
}

int main(){	

//Also using try catch in main.
try{
	CreatingAllObjects();
	TestGivenHomeworkGlobals();
	TestNewComposedShape();
	TestShapeClass();
	TestThrowExceptions();
}
catch(EmptyVectorException &e){
	cout << e.what() << endl;
}
catch(TriLessThanZero &e){
	cout << e.what() << endl;
}
catch(RectLessThanZero &e){
	cout << e.what() << endl;
}
catch(CircleLessThanZero &e){
	cout << e.what() << endl;
}
catch(PolyLessThanZero &e){
	cout << e.what() << endl;
}
catch(OutOfBoundsException &e){
	cout << e.what() << endl;
}

	return 0;
}

namespace {

void PrintAll(const vector<Shape*> &ptrvector)throw(EmptyVectorException){
	if(ptrvector.size()==0){
		throw EmptyVectorException();
	}

	ofstream file("outputPrintAll.svg");
	file << "<svg " << "version=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=" << "\"http://www.w3.org/2000/svg\">\n" ;
	for(int i=0;i<ptrvector.size();i++){
		file << *ptrvector[i];		//printing every Shape* object of ptrvector.
	}

	file << "</svg>";

	file.close();
}

void PrintPoly(const vector<Shape*> &ptrvector)throw(EmptyVectorException){
	if(ptrvector.size()==0){
		throw EmptyVectorException();
	}
	int count=0;
	ofstream file("outputPrintPoly.svg");
	file << "<svg " << "version=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=" << "\"http://www.w3.org/2000/svg\">\n" ;
	for(auto p : ptrvector){
		PolygonVect *PVptr = dynamic_cast<PolygonVect*>(p);	//downcasting Pvptr and checking if its polygonvect object.
		if(PVptr != nullptr){	//if it is a polygonvect object  then it will not return a nullptr.
			count++;
			file << *p;	//printing the polygonvect into the file.
		}
		PolygonDyn *PDptr = dynamic_cast<PolygonDyn*>(p);	//downcasting Pvptr and checking if its polygondyn object.
		if(PDptr!= nullptr){	//if it is a polygondyn object then it will not return a nullptr.
			count++;
			file << *p;	//printing the polygondyn into the file.
		}
	}
	
	file << "</svg>";
	if(count==0){
		cout << "There is no polygon in this vector..! So outputPrintPoly.svg can not be created." << endl;
	}
	file.close();
}

vector<Shape*> ConvertAll(const vector<Shape*> &ptrvector)throw(EmptyVectorException){

	if(ptrvector.size()==0){
		throw EmptyVectorException();
	}

	vector<Shape*> temp;

	for(auto p : ptrvector){

		Circle *c = dynamic_cast<Circle*>(p);
		if(c != nullptr){
			PolygonDyn *poly = new PolygonDyn(*c); // Converting circle to polygon.
			temp.push_back(poly);
		}
		else {
			Triangle *t = dynamic_cast<Triangle*>(p);
			if(t != nullptr){
				PolygonVect *poly = new PolygonVect(*t); // Converting triangle to polygon.
				temp.push_back(poly);
			}
			else{
				Rectangle *r = dynamic_cast<Rectangle*>(p);
				if(r != nullptr){
					PolygonDyn *poly = new PolygonDyn(*r); // Converting rectangle to polygon.
					temp.push_back(poly);
				}
				else{
					temp.push_back(p);
				}
			}
		}
	}
	return temp;
}


void sortShapes(vector <Shape*> &ptrvector) throw(EmptyVectorException){
	if(ptrvector.size()==0){
		throw EmptyVectorException();
	}

	int min;
	Shape *temp;

	for(int i=0;i<ptrvector.size();i++){
		min = i;
		for(int j=i+1;j<ptrvector.size();j++){
			if(*ptrvector[j] < *ptrvector[min]){
				min = j;
			}
		}
		if(min!=i){
			temp = ptrvector[min];
			ptrvector[min]=ptrvector[i];
			ptrvector[i] = temp;
		}

	}
}


void CreatingAllObjects(){

	cout << "<------------------------------- Creating All Objects >" << endl;
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

	cout <<endl;

	ofstream file2("output2.svg");
	file2 << "<svg " << "version=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=" << "\"http://www.w3.org/2000/svg\">\n" ;
	cout<< "Smaller circles within a larger triangle in : output2.svg" << endl; 
	ComposedShape circleintriangle(MT);
	circleintriangle.optimalFit(MT,IC);
	file2 << circleintriangle;
	file2 << "</svg>";
	file2.close();

	cout << endl;

	ofstream file3("output3.svg");
	file3 << "<svg " << "version=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=" << "\"http://www.w3.org/2000/svg\">\n" ;
	cout<< "Smaller circles within a larger circle in : output3.svg" << endl; 
	ComposedShape circleincircle(MC);
	circleincircle.optimalFit(MC,IC);
	file3 << circleincircle;
	file3 << "</svg>";
	file3.close();

	cout << endl;

	ofstream file4("output4.svg");
	file4 << "<svg " << "version=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=" << "\"http://www.w3.org/2000/svg\">\n" ;
	cout<< "Smaller rectangles within a larger rectangle in : output4.svg" << endl; 
	ComposedShape rectangleinrectangle(MR);
	rectangleinrectangle.optimalFit(MR,IR);
	file4 << rectangleinrectangle;
	file4 << "</svg>";
	file4.close();

	cout << endl;

	ofstream file5("output5.svg");
	file5 << "<svg " << "version=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=" << "\"http://www.w3.org/2000/svg\">\n" ;
	cout<< "Smaller rectangles within a larger triangle in : output5.svg" << endl; 
	ComposedShape rectangleintriangle(MT);
	rectangleintriangle.optimalFit(MT,IR);
	file5 << rectangleintriangle;
	file5 << "</svg>";
	file5.close();

	cout << endl;

	ofstream file6("output6.svg");
	file6 << "<svg " << "version=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=" << "\"http://www.w3.org/2000/svg\">\n" ;
	cout<< "Smaller triangles within a larger triangle in : output6.svg" << endl; 
	ComposedShape triangleintriangle(MT);
	triangleintriangle.optimalFit(MT,IT);
	file6 << triangleintriangle;
	file6 << "</svg>";
	file6.close();

	cout << endl;

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

void TestGivenHomeworkGlobals(){

	cout << "<------------------------------- Testing  Given Homework Globals.. >" << endl;

	//Creating a composed shape

	Triangle MT(500);
	Circle c1(70);
	
	vector<Shape *> testv;

	ComposedShape composed(MT);
	composed.optimalFit(MT,c1);

	testv = composed.getShapeVector();
	
	//Adding some polygons into it.

	Circle c2(50);
	Rectangle r2(30,25,30,40);
	Triangle t2(20);
	PolygonDyn *poly = new PolygonDyn(c2);
	poly->setColor("yellow");
	PolygonVect *poly2 = new PolygonVect(t2);
	poly2->setColor("blue");
	PolygonDyn *poly3 = new PolygonDyn(r2);
	

	testv.push_back(poly);
	testv.push_back(poly2);
	testv.push_back(poly3);
	

	PrintAll(testv);	// printing all objects.
	PrintPoly(testv);	// printing only polygons.

	testv=ConvertAll(testv);
	
	ofstream file("OutputConvertedShapes.svg");	// You can check converted shapes in this file.
	file << "<svg " << "version=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=" << "\"http://www.w3.org/2000/svg\">\n" ;
	for(int i=0;i<testv.size();i++){
		file << *testv[i];				
	}
	file << "</svg>";

	cout << "Before sorting areas.." << endl;
	printAreas(testv);  // Before sorting..
	sortShapes(testv);	// Sorting areas increasingly..
	cout << "Sorting Areas increasingly.." << endl;
	printAreas(testv);	// printing their areas on the terminal.

	delete poly;
	delete poly2;
	delete poly3;
}

void TestNewComposedShape(){

	cout << "<------------------------------- Testing New ComposedShape >" << endl;
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

	// Testing  new  << operator overload..

	file << test;

	file << "</svg>";
	file.close();

	//Testing index operator overload and Area , Perimeter functions.

	cout << test[5]->Area() << endl;
	cout << test[10]->Perimeter() << endl;
}

void TestShapeClass(){
	// I test all shape's functions except comparison overloads.Because i'm already testing them while doing sorting and also you can check them in source code.
	cout << "<------------------------------- Testing Shape Base Class >" << endl;
	Shape *c = new Circle(10);
	Shape *r = new Rectangle(40,50,0,40);
	Circle circ(10);
	Rectangle rect(40,50,0,40);
	Shape *pdyn = new PolygonDyn(circ);
	Shape *pvect = new PolygonVect(rect);

	ofstream file("OutputShapeClassTest.svg");	// You can check  shapes operators  in this file.
	file << "<svg " << "version=\"1.1\"\n" << "baseProfile=\"full\"\n" << "xmlns=" << "\"http://www.w3.org/2000/svg\">\n" ;

	//You can check all these increment and decrements  in  OutputShapeClassTest.svg. In this svg source code you can see coordinates.
	file << (++*c);
	file << (*c)++;
	file << (*c);
	file << (*c)--;
	file << --(*c);
	
	cout << "Circle Area : " << (*c).Area() << endl;
	cout << "Circle Perimeter : " << (*c).Perimeter() << endl;

	file << (++*r);
	file << (*r)++;
	file << (*r);
	file << (*r)--;
	file << --(*r);

	cout << "Rectangle Area : " << (*r).Area() << endl;
	cout << "Rectangle Perimeter : " << (*r).Perimeter() << endl;

	file << (++*pdyn);
	file << (*pdyn)++;
	file << (*pdyn);
	file << (*pdyn)--;
	file << --(*pdyn);

	cout << "PolygonDyn Area : " << (*pdyn).Area() << endl;
	cout << "PolygonDyn Perimeter : " << (*pdyn).Perimeter() << endl;

	file << (++*pvect);
	file << (*pvect)++;
	file << (*pvect);
	file << (*pvect)--;
	file << --(*pvect);

	cout << "PolygonVect Area : " << (*pvect).Area() << endl;
	cout << "PolygonVect Perimeter : " << (*pvect).Perimeter() << endl;


	
	file << "</svg>";
	delete c;
	delete r;
	delete pdyn;
	delete pvect;

}

void TestThrowExceptions(){
	cout << "<------------------------------- Testing Throw Exceptions >" << endl;
	//Testing for polylessthanzero -> This exception say that there is a negative polygondyn member data.
	try{
		PolygonDyn poly(-5);
		
	}
	catch(PolyLessThanZero &e){
		cout << e.what() << endl;
	}


	try{
		Circle circ(-30);

	}
	catch(CircleLessThanZero &e){
		cout << e.what() << endl;
	}

	try{
		Rectangle rect;
		rect.setWidth(-50);
	}
	catch(RectLessThanZero &e){
		cout << e.what() << endl;
	}

	try{
		Triangle tri(0);
	}
	catch(TriLessThanZero &e){
		cout << e.what() << endl;
	}
	
	try{
		Circle c2(50,50,50);
		PolygonDyn *poly = new PolygonDyn(c2);
		poly->setColor("green");
		cout << (*poly)[15123123];
	}
	catch(OutOfBoundsException &e){
		cout << e.what() << endl;
	}

	try{
		vector<PolygonDyn::Point2D> v; // This vector is empty..

		PolygonDyn poly2(v);
	}
	catch(EmptyVectorException &e){
		cout << e.what() << endl;
	}
}

void printAreas(const vector<Shape*> &ptrvector){
	cout << "| " ;
	for(int i=0;i<ptrvector.size();i++){
		cout << ptrvector[i]->Area() << " | " ;
	}

	cout << endl;
}

}


