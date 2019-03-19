#include "composedshape.h"

namespace GtuObjects{

ComposedShape::ComposedShape(Rectangle &MainContainer){
	MainContainer.setColor("red");
	Shapev.push_back(&MainContainer);
}

ComposedShape::ComposedShape(Triangle &MainContainer){
	MainContainer.setColor("red");
	Shapev.push_back(&MainContainer);
}

ComposedShape::ComposedShape(Circle &MainContainer){
	MainContainer.setColor("red");
	Shapev.push_back(&MainContainer);
}


void ComposedShape::optimalFit(const Rectangle &MainRectangle,Triangle &triangle){
	double i,j;
	double emptyarea;
	double innerheight;
	
	innerheight = (triangle.getEdge_of_Triangle()/2)*sqrt(3); //height of triangle
	
	double point1X=0,point1Y=innerheight,point2X=triangle.getEdge_of_Triangle()/2,point2Y=0,point3X=triangle.getEdge_of_Triangle(),point3Y=innerheight;	//triangle points
	double point12X=triangle.getEdge_of_Triangle()/2,point12Y=0,point22X=triangle.getEdge_of_Triangle()+triangle.getEdge_of_Triangle()/2,point22Y=0,point32X=triangle.getEdge_of_Triangle(),point32Y=innerheight;
	//Using this loop for flat triangles
	for(i=0;i<MainRectangle.getWidth();i+=triangle.getEdge_of_Triangle()){
	
		if(!(i+triangle.getEdge_of_Triangle() > MainRectangle.getWidth())){	// for x-axis the condition that the triangle does not overflow the rectangle
			
			for(j=0;j< MainRectangle.getHeight();j+=innerheight){
		
				if(!(j+innerheight > MainRectangle.getHeight())){	// for y-axis the condition that the triangle does not overflow the rectangle
					Triangle *p = new Triangle;
					p->setEdge_of_Triangle(triangle.getEdge_of_Triangle());
					p->set_x_axis_of_Point1(point1X+i);
					p->set_y_axis_of_Point1(point1Y+j);
					p->set_x_axis_of_Point2(point2X+i);
					p->set_y_axis_of_Point2(point2Y+j);
					p->set_x_axis_of_Point3(point3X+i);
					p->set_y_axis_of_Point3(point3Y+j);
					p->setColor("green");
					Shapev.push_back(p);		
				}
			}
		}
	}

	//Using this loop for inverted triangles
	for(i=0;i<MainRectangle.getWidth();i+=triangle.getEdge_of_Triangle()){
		if(!(i+triangle.getEdge_of_Triangle()+triangle.getEdge_of_Triangle()/2 > MainRectangle.getWidth())){

			for(j=0;j<MainRectangle.getHeight();j+=innerheight){
				if(!(j+innerheight > MainRectangle.getHeight())){
					Triangle *p = new Triangle;
					p->setEdge_of_Triangle(triangle.getEdge_of_Triangle());
					p->set_x_axis_of_Point1(point12X+i);
					p->set_y_axis_of_Point1(point12Y+j);
					p->set_x_axis_of_Point2(point22X+i);
					p->set_y_axis_of_Point2(point22Y+j);
					p->set_x_axis_of_Point3(point32X+i);
					p->set_y_axis_of_Point3(point32Y+j);
					p->setColor("green");
					Shapev.push_back(p);	
					}
				}
			}
		}
		
	emptyarea = (MainRectangle.getHeight()*MainRectangle.getWidth())-(Shapev.size()-1)*((triangle.getEdge_of_Triangle()*triangle.getEdge_of_Triangle())*sqrt(3)/4);
	std::cout << "I can fit at most " << Shapev.size()-1
	<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << std::endl;
}

void ComposedShape::optimalFit(const Rectangle &MainRectangle,Circle &circle){
	double cx,cy;
	double emptyarea;
	
	

	for(cx=circle.getRadius();cx<=MainRectangle.getWidth()-circle.getRadius();cx+=2*circle.getRadius()){
		for(cy=circle.getRadius();cy<=MainRectangle.getHeight()-circle.getRadius();cy+=2*circle.getRadius()){
			Circle *p = new Circle;
			p->setRadius(circle.getRadius());
			p->setCx(cx);					
			p->setCy(cy);
			p->setColor("green");
			Shapev.push_back(p);
		}
	}
	
	emptyarea =	(MainRectangle.getHeight()*MainRectangle.getWidth())-((Shapev.size()-1)*M_PI*circle.getRadius()*circle.getRadius());
	std::cout << "I can fit at most " << Shapev.size()-1
	<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << std::endl;
	
}


void ComposedShape::optimalFit(const Rectangle &MainRectangle,Rectangle &rectangle){
	/*Using this loop for horizontal rectangle.*/

	double i,j;
	double emptyarea;
	double rect2_width = rectangle.getWidth() , rect2_height = rectangle.getHeight();


	for(i=0;i<=MainRectangle.getWidth(); i += rect2_width){	
		if(!(i+rect2_width > MainRectangle.getWidth())){	/* for x-axis the condition that the rectangle does not overflow the rectangle*/
			for(j=0;j<=MainRectangle.getWidth(); j += rect2_height){		
				if(!(j+rect2_height>MainRectangle.getHeight())){		
					Rectangle *p = new Rectangle;
					p->setX(i);
					p->setY(j);
					p->setWidth(rect2_width);
					p->setHeight(rect2_height);
					p->setColor("green");
					Shapev.push_back(p);
				}
						
			}
		}
	}
	i -= rect2_width;

	/*Using this loop for vertical rectangle.*/

	for(i;i<=MainRectangle.getWidth();i += rect2_height){
		if(MainRectangle.getWidth()-i >= rect2_height){	/* for x-axis the condition that the rectangle does not overflow the rectangle*/
			for(j=0;j<=MainRectangle.getHeight(); j += rect2_width){
				if(!(j+rect2_width>MainRectangle.getHeight())){	 /* for y-axis the condition that the rectangle does not overflow the rectangle*/
					Rectangle *p = new Rectangle;
					p->setX(i);
					p->setY(j);
					p->setWidth(rect2_height);
					p->setHeight(rect2_width);
					p->setColor("green");
					Shapev.push_back(p);
				}				
			}
		}
	}
	emptyarea = (MainRectangle.getWidth()*MainRectangle.getHeight())-((Shapev.size()-1))*(rect2_width*rect2_height);
	std::cout << "I can fit at most " <<  (Shapev.size()-1)
	<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << std::endl;
}


void ComposedShape::optimalFit(const Triangle &MainTriangle,Triangle &triangle){
	double i,j;
	double emptyarea;
	double small_t_edge = triangle.getEdge_of_Triangle();
	double innerheight = (MainTriangle.getEdge_of_Triangle()/2)*sqrt(3);
	double Sinnerheight = (small_t_edge/2)*sqrt(3);	/*Height of smaller triangle .*/
	double a = small_t_edge/2;
	double b = 0;
	double point1X=a,point1Y=innerheight-Sinnerheight,point2X=0,point2Y=innerheight,point3X=small_t_edge,point3Y=innerheight;	

	/*This loop for flat triangles.*/
	for(i=0;i<=MainTriangle.getEdge_of_Triangle()/2;i+=small_t_edge/2){
		for(j=0;j<MainTriangle.getEdge_of_Triangle()-b;j+=small_t_edge){

			if(!(j+small_t_edge > MainTriangle.getEdge_of_Triangle()-b)){	/* for y-axis the condition that the triangle does not overflow the larger triangle*/
				Triangle *p = new Triangle;
				triangle.setEdge_of_Triangle(small_t_edge);
				triangle.set_x_axis_of_Point1(point1X+j);
				triangle.set_y_axis_of_Point1(point1Y);
				triangle.set_x_axis_of_Point2(point2X+j);
				triangle.set_y_axis_of_Point2(point2Y);
				triangle.set_x_axis_of_Point3(point3X+j);
				triangle.set_y_axis_of_Point3(point3Y);
				triangle.setColor("green");
				*p = triangle;
				Shapev.push_back(p);
			}
						
		}
		point1X += a;
		point1Y -= Sinnerheight;
		point2X += a;
		point2Y -= Sinnerheight;
		point3X += a;
		point3Y -= Sinnerheight;


		b += 2*a ;
	}
	
	point1X=a,point1Y=innerheight-Sinnerheight,point2X=2*a,point2Y=innerheight,point3X=3*a,point3Y=innerheight-Sinnerheight;	/*Preparing the position of inverted triangles.*/
	b=2*a;

	//This loop for inverted triangles.
	
	for(i=0;i<=MainTriangle.getEdge_of_Triangle()/2;i+=small_t_edge/2){
		for(j=0;j<MainTriangle.getEdge_of_Triangle()-b;j+=small_t_edge){
			if(!(j+small_t_edge > MainTriangle.getEdge_of_Triangle()-b)){	// for y-axis the condition that the triangle does not overflow the larger triangle
				Triangle *p = new Triangle;
				triangle.setEdge_of_Triangle(small_t_edge);
				triangle.set_x_axis_of_Point1(point1X+j);
				triangle.set_y_axis_of_Point1(point1Y);
				triangle.set_x_axis_of_Point2(point2X+j);
				triangle.set_y_axis_of_Point2(point2Y);
				triangle.set_x_axis_of_Point3(point3X+j);
				triangle.set_y_axis_of_Point3(point3Y);
				triangle.setColor("green");
				*p=triangle;
				Shapev.push_back(p);
			}
				
		}

		point1X += a;
		point1Y -= Sinnerheight;
		point2X += a;
		point2Y -= Sinnerheight;
		point3X += a;
		point3Y -= Sinnerheight;
		b += 2*a ;
	}
	
	emptyarea = (MainTriangle.getEdge_of_Triangle()*MainTriangle.getEdge_of_Triangle()*sqrt(3)/4)-((Shapev.size()-1)*small_t_edge*small_t_edge*sqrt(3)/4);
	std::cout << "I can fit at most " <<  (Shapev.size()-1)
	<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << std::endl;
			
}

void ComposedShape::optimalFit(const Triangle &MainTriangle,Rectangle &rectangle){
	double i,j,k;
	double emptyarea;
	double innerheight = (MainTriangle.getEdge_of_Triangle()/2)*sqrt(3);
	double rect_width = rectangle.getWidth() , rect_height = rectangle.getHeight() ;
	double a = rect_width/sqrt(3); /* Distance of small pieces.*/

	
	for(i=rect_width/sqrt(3),j=innerheight-rect_width;i<=MainTriangle.getEdge_of_Triangle()/2,j>=0;i += rect_width/sqrt(3),j-=rect_width){ /*Determining first position and starting the loop.*/

		for(k=i;k<=MainTriangle.getEdge_of_Triangle()-a;k+=rect_height){
			if(!(k+rect_height > MainTriangle.getEdge_of_Triangle()-a)){
				Rectangle *p = new Rectangle;
				p->setWidth(rect_height);
				p->setHeight(rect_width);
				p->setX(k);
				p->setY(j);
				p->setColor("green");
				Shapev.push_back(p);
			}
		}
		a = a +	rect_width/sqrt(3); /* We are carrying our position to upper line.*/
	}


	emptyarea = (MainTriangle.getEdge_of_Triangle()*MainTriangle.getEdge_of_Triangle()*sqrt(3)/4) - (Shapev.size()-1)*(rect_width*rect_height);
	std::cout << "I can fit at most " <<  Shapev.size()
	<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << std::endl;
	
}

void ComposedShape::optimalFit(const Triangle &MainTriangle,Circle &circle){
	double i,j;
	double emptyarea;
	double innerheight = (MainTriangle.getEdge_of_Triangle()/2)*sqrt(3);
	double radius = circle.getRadius();
	double a = radius*sqrt(3); //Distance of small pieces
	int b=0;

	for(j=innerheight-radius;j>=0+radius-innerheight;j-=a){	// for y-axis the condition that the circle does not overflow the larger triangle
			
		for(i=a+b*radius;i<=MainTriangle.getEdge_of_Triangle()-a-b*radius;i+=2*radius){	// for x-axis the condition that the circle does not overflow the larger triangle
			Circle *p = new Circle;
			p->setCx(i);
			p->setCy(j);
			p->setRadius(radius);
			p->setColor("green");
			Shapev.push_back(p);

		}
		b+=1;
	}
	emptyarea = (MainTriangle.getEdge_of_Triangle()*MainTriangle.getEdge_of_Triangle()*sqrt(3)/4)-((Shapev.size()-1)*M_PI*radius*radius);
	std::cout << "I can fit at most " <<  (Shapev.size()-1)
	<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << std::endl;
		
}

void ComposedShape::optimalFit(const Circle &MainCircle,Circle &circle){
	double i,j,emptyarea;
	double small_radius = circle.getRadius();
	double formula=0;
	
	Circle *p = new Circle;
	p->setCx(MainCircle.getRadius());
	p->setCy(small_radius);
	p->setRadius(small_radius);
	p->setColor("green");
	Shapev.push_back(p);
			
	for(j=3*small_radius;j<=2*MainCircle.getRadius()-2*small_radius;j+=2*small_radius){
		i = MainCircle.getRadius();
		formula = 0;
		do{
			Circle *p = new Circle;
			p->setCx(i);
			p->setCy(j);
			p->setRadius(small_radius);
			p->setColor("green");
			Shapev.push_back(p);
			i+=2*small_radius;
			formula = sqrt(pow(MainCircle.getRadius()-i,2)+pow(MainCircle.getRadius()-j,2));
		}
		while(formula<=MainCircle.getRadius()-small_radius);
	}
	for(j=3*small_radius;j<=2*MainCircle.getRadius()-2*small_radius;j+=2*small_radius){
			i = MainCircle.getRadius()-2*small_radius;
			formula = 0;
			while(formula<=MainCircle.getRadius()-small_radius){
			Circle *p = new Circle;
			p->setCx(i);
			p->setCy(j);
			p->setRadius(small_radius);
			p->setColor("green");
			Shapev.push_back(p);
			i-=2*small_radius;
			formula = sqrt(pow(MainCircle.getRadius()-i,2)+pow(MainCircle.getRadius()-j,2));
		}	
	}

	emptyarea = (MainCircle.getRadius()*MainCircle.getRadius()*M_PI)-((Shapev.size()-1)*M_PI*small_radius*small_radius);
	std::cout << "I can fit at most " <<  (Shapev.size()-1)
	<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << std::endl;
		
}

double ComposedShape::Area() const{ /* Deliberately empty..*/}
double ComposedShape::Perimeter() const{ /* Deliberately empty..*/}
Shape& ComposedShape::operator++(){ /* Deliberately empty..*/}
Shape& ComposedShape::operator++(int){ /* Deliberately empty..*/}
Shape& ComposedShape::operator--(){ /* Deliberately empty..*/}
Shape& ComposedShape::operator--(int){ /* Deliberately empty..*/}

std::ostream& ComposedShape::draw(std::ostream& output) const{
	for(int i=0;i<Shapev.size();i++){
		output << *Shapev[i]; 
	}
}

ComposedShape::~ComposedShape(){
	for (int i=1;i<Shapev.size();i++) {
    	delete Shapev[i];
    }
}


// Index operator overloads..

Shape* ComposedShape::operator[](int index) throw(OutOfBoundsException){
	if(index < 0 || index >= Shapev.size()){
		throw OutOfBoundsException();
	}
	else{
		return Shapev[index];
	}
}

const Shape* ComposedShape::operator[](int index) const throw(OutOfBoundsException){
	if(index < 0 || index >= Shapev.size()){
		throw OutOfBoundsException();
	}
	else{
		return Shapev[index];
	}
}


//operator overloading for composedshape...

std::ostream& operator<<(std::ostream& output,const ComposedShape &other) {
	return other.draw(output);
}

// If we want to add a shape into our composedshape then we are using this operator overloads..

ComposedShape& ComposedShape::operator+=(const Rectangle& rectangle){
	Rectangle *r = new Rectangle;
	*r = rectangle;
	this->Shapev.push_back(r);
	return *this;
}

ComposedShape& ComposedShape::operator+=(const Circle& circle){
	Circle *c = new Circle;
	*c = circle;
	this->Shapev.push_back(c);
	return *this;
}

ComposedShape& ComposedShape::operator+=(const Triangle& triangle){
	Triangle *t = new Triangle;
	*t = triangle;
	this->Shapev.push_back(t);
	return *this;
}

}
