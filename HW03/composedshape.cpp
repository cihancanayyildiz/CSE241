#include "composedshape.h"

ComposedShape::ComposedShape(Rectangle MainContainer,Triangle InnerShape){
	MainRectangle = MainContainer;
	triangle = InnerShape;
}

ComposedShape::ComposedShape(Rectangle MainContainer,Circle InnerShape){
	MainRectangle = MainContainer;
	circle = InnerShape;
}

ComposedShape::ComposedShape(Rectangle MainContainer,Rectangle InnerShape){
	MainRectangle = MainContainer;
	rectangle = InnerShape;
}

ComposedShape::ComposedShape(Triangle MainContainer,Triangle InnerShape){
	MainTriangle = MainContainer;
	triangle = InnerShape;
}

ComposedShape::ComposedShape(Triangle MainContainer,Rectangle InnerShape){
	MainTriangle = MainContainer;
	rectangle = InnerShape;
}

ComposedShape::ComposedShape(Triangle MainContainer,Circle InnerShape){
	MainTriangle = MainContainer;
	circle = InnerShape;
}

ComposedShape::ComposedShape(Circle MainContainer,Circle InnerShape){
	MainCircle = MainContainer;
	circle = InnerShape;
}

void ComposedShape::optimalFit(Rectangle MainContainer,Triangle InnerShape){
	double i,j;
	double emptyarea;
	double innerheight;
	innerheight = (triangle.getEdge_of_Triangle()/2)*sqrt(3); /*height of triangle*/
	/*triangle points*/
	double point1X=0,point1Y=innerheight,point2X=triangle.getEdge_of_Triangle()/2,point2Y=0,point3X=triangle.getEdge_of_Triangle(),point3Y=innerheight;	
	double point12X=triangle.getEdge_of_Triangle()/2,point12Y=0,point22X=triangle.getEdge_of_Triangle()+triangle.getEdge_of_Triangle()/2,point22Y=0,point32X=triangle.getEdge_of_Triangle(),point32Y=innerheight;
	/*Using this loop for flat triangles*/
	for(i=0;i<MainRectangle.getWidth();i+=triangle.getEdge_of_Triangle()){
	
		if(!(i+triangle.getEdge_of_Triangle() > MainRectangle.getWidth())){	/* for x-axis the condition that the triangle does not overflow the rectangle*/
			
			for(j=0;j< MainRectangle.getHeight();j+=innerheight){
		
				if(!(j+innerheight > MainRectangle.getHeight())){	/* for y-axis the condition that the triangle does not overflow the rectangle*/
					triangle.setEdge_of_Triangle(triangle.getEdge_of_Triangle());
					triangle.set_x_axis_of_Point1(point1X+i);
					triangle.set_y_axis_of_Point1(point1Y+j);
					triangle.set_x_axis_of_Point2(point2X+i);
					triangle.set_y_axis_of_Point2(point2Y+j);
					triangle.set_x_axis_of_Point3(point3X+i);
					triangle.set_y_axis_of_Point3(point3Y+j);
					shape.HoldingTriangle(triangle);
					shapev.push_back(shape);
					
							
				}
			}
		}
	}

	/*Using this loop for inverted triangles*/
	for(i=0;i<MainRectangle.getWidth();i+=triangle.getEdge_of_Triangle()){
		if(!(i+triangle.getEdge_of_Triangle()+triangle.getEdge_of_Triangle()/2 > MainRectangle.getWidth())){

			for(j=0;j<MainRectangle.getHeight();j+=innerheight){
				if(!(j+innerheight > MainRectangle.getHeight())){
					triangle.setEdge_of_Triangle(triangle.getEdge_of_Triangle());
					triangle.set_x_axis_of_Point1(point12X+i);
					triangle.set_y_axis_of_Point1(point12Y+j);
					triangle.set_x_axis_of_Point2(point22X+i);
					triangle.set_y_axis_of_Point2(point22Y+j);
					triangle.set_x_axis_of_Point3(point32X+i);
					triangle.set_y_axis_of_Point3(point32Y+j);
					shape.HoldingTriangle(triangle);
					shapev.push_back(shape);	
					}
				}
			}
		}
		
	emptyarea = (MainRectangle.getHeight()*MainRectangle.getWidth())-shapev.size()*((triangle.getEdge_of_Triangle()*triangle.getEdge_of_Triangle())*sqrt(3)/4);
	cout << "I can fit at most " << shapev.size()
	<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << endl;
}

void ComposedShape::optimalFit(Rectangle MainContainer,Circle InnerShape){
	double cx,cy;
	double emptyarea;
	
	cout << MainRectangle.getWidth() << endl;
	cout << MainRectangle.getHeight() << endl;
	for(cx=circle.getRadius();cx<=MainRectangle.getWidth()-circle.getRadius();cx+=2*circle.getRadius()){
		for(cy=circle.getRadius();cy<=MainRectangle.getHeight()-circle.getRadius();cy+=2*circle.getRadius()){
			circle.setRadius(circle.getRadius());
			circle.setCx(cx);					
			circle.setCy(cy);
			shape.HoldingCircle(circle);
			shapev.push_back(shape);
		}
	}
	
	emptyarea =	(MainRectangle.getHeight()*MainRectangle.getWidth())-(shapev.size()*M_PI*circle.getRadius()*circle.getRadius());
	cout << "I can fit at most " << shapev.size()
	<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << endl;
	
}

void ComposedShape::optimalFit(Rectangle MainContainer,Rectangle InnerShape){
	/*Using this loop for horizontal rectangle.*/
	double i,j;
	double emptyarea;
	double rect2_width = rectangle.getWidth() , rect2_height = rectangle.getHeight();

	for(i=0;i<=MainRectangle.getWidth(); i += rect2_width){	
		if(!(i+rect2_width > MainRectangle.getWidth())){	/* for x-axis the condition that the rectangle does not overflow the rectangle*/
			for(j=0;j<=MainRectangle.getWidth(); j += rect2_height){		
				if(!(j+rect2_height>MainRectangle.getHeight())){		
					rectangle.setX(i);
					rectangle.setY(j);
					rectangle.setWidth(rect2_width);
					rectangle.setHeight(rect2_height);
					shape.HoldingRectangle(rectangle);
					shapev.push_back(shape);
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
					rectangle.setX(i);
					rectangle.setY(j);
					rectangle.setWidth(rect2_height);
					shape.HoldingRectangle(rectangle);
					shapev.push_back(shape);	//sending object to vector
				}				
			}
		}
	}
	emptyarea = (MainRectangle.getWidth()*MainRectangle.getHeight())-shapev.size()*(rect2_width*rect2_height);
	cout << "I can fit at most " <<  shapev.size()
	<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << endl;
}

void ComposedShape::optimalFit(Triangle MainContainer,Triangle InnerShape){
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
				triangle.setEdge_of_Triangle(small_t_edge);
				triangle.set_x_axis_of_Point1(point1X+j);
				triangle.set_y_axis_of_Point1(point1Y);
				triangle.set_x_axis_of_Point2(point2X+j);
				triangle.set_y_axis_of_Point2(point2Y);
				triangle.set_x_axis_of_Point3(point3X+j);
				triangle.set_y_axis_of_Point3(point3Y);
				shape.HoldingTriangle(triangle);
				shapev.push_back(shape);
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

	/*This loop for inverted triangles.*/

	for(i=0;i<=MainTriangle.getEdge_of_Triangle()/2;i+=small_t_edge/2){
		for(j=0;j<MainTriangle.getEdge_of_Triangle()-b;j+=small_t_edge){
			if(!(j+small_t_edge > MainTriangle.getEdge_of_Triangle()-b)){	/* for y-axis the condition that the triangle does not overflow the larger triangle*/

				triangle.setEdge_of_Triangle(small_t_edge);
				triangle.set_x_axis_of_Point1(point1X+j);
				triangle.set_y_axis_of_Point1(point1Y);
				triangle.set_x_axis_of_Point2(point2X+j);
				triangle.set_y_axis_of_Point2(point2Y);
				triangle.set_x_axis_of_Point3(point3X+j);
				triangle.set_y_axis_of_Point3(point3Y);
				shape.HoldingTriangle(triangle);
				shapev.push_back(shape);	//sending object to vector
	
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

	emptyarea = (MainTriangle.getEdge_of_Triangle()*MainTriangle.getEdge_of_Triangle()*sqrt(3)/4)-(shapev.size()*small_t_edge*small_t_edge*sqrt(3)/4);
	cout << "I can fit at most " <<  shapev.size()
	<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << endl;
			
}

void ComposedShape::optimalFit(Triangle MainContainer,Rectangle InnerShape){
	double i,j,k;
	double emptyarea;
	double innerheight = (MainTriangle.getEdge_of_Triangle()/2)*sqrt(3);
	double rect_width = rectangle.getWidth() , rect_height = rectangle.getHeight() ;
	double a = rect_width/sqrt(3); /* Distance of small pieces.*/

	for(i=rect_width/sqrt(3),j=innerheight-rect_width;i<=MainTriangle.getEdge_of_Triangle()/2,j>=0;i += rect_width/sqrt(3),j-=rect_width){ /*Determining first position and starting the loop.*/

		for(k=i;k<=MainTriangle.getEdge_of_Triangle()-a;k+=rect_height){
			if(!(k+rect_height > MainTriangle.getEdge_of_Triangle()-a)){
				rectangle.setWidth(rect_height);
				rectangle.setHeight(rect_width);
				rectangle.setX(k);
				rectangle.setY(j);
				shape.HoldingRectangle(rectangle);
				shapev.push_back(shape);
			}
		}
		a = a +	rect_width/sqrt(3); /* We are carrying our position to upper line.*/
	}


	emptyarea = (MainTriangle.getEdge_of_Triangle()*MainTriangle.getEdge_of_Triangle()*sqrt(3)/4) - shapev.size()*(rect_width*rect_height);
	cout << "I can fit at most " <<  shapev.size()
	<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << endl;
	
}

void ComposedShape::optimalFit(Triangle MainContainer,Circle InnerShape){
	
	double i,j;
	double emptyarea;
	double innerheight = (MainTriangle.getEdge_of_Triangle()/2)*sqrt(3);
	double radius = circle.getRadius();
	double a = radius*sqrt(3); /*Distance of small pieces*/
	int b=0;

	for(j=innerheight-radius;j>=0+radius-innerheight;j-=a){	/* for y-axis the condition that the circle does not overflow the larger triangle*/
			
		for(i=a+b*radius;i<=MainTriangle.getEdge_of_Triangle()-a-b*radius;i+=2*radius){	/* for x-axis the condition that the circle does not overflow the larger triangle*/
			circle.setCx(i);
			circle.setCy(j);
			circle.setRadius(radius);
			shape.HoldingCircle(circle);
			shapev.push_back(shape);
		}
		b+=1;
	}


	emptyarea = (MainTriangle.getEdge_of_Triangle()*MainTriangle.getEdge_of_Triangle()*sqrt(3)/4)-(shapev.size()*M_PI*radius*radius);
	cout << "I can fit at most " <<  shapev.size()
	<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << endl;
		
}

void ComposedShape::optimalFit(Circle MainContainer,Circle InnerShape){
	double i,j,emptyarea;
	double small_radius = circle.getRadius();
	double formula=0;
	circle.setCx(MainCircle.getRadius());
	circle.setCy(small_radius);
	circle.setRadius(small_radius);
	circlev.push_back(circle);
			

	for(j=3*small_radius;j<=2*MainCircle.getRadius()-2*small_radius;j+=2*small_radius){
		i = MainCircle.getRadius();
		formula = 0;
		do{
			circle.setCx(i);
			circle.setCy(j);
			circle.setRadius(small_radius);
			shape.HoldingCircle(circle);
			shapev.push_back(shape);
			i+=2*small_radius;
			formula = sqrt(pow(MainCircle.getRadius()-i,2)+pow(MainCircle.getRadius()-j,2));
		}
		while(formula<=MainCircle.getRadius()-small_radius);
	}
	for(j=3*small_radius;j<=2*MainCircle.getRadius()-2*small_radius;j+=2*small_radius){
			i = MainCircle.getRadius()-2*small_radius;
			formula = 0;
			while(formula<=MainCircle.getRadius()-small_radius){
			circle.setCx(i);
			circle.setCy(j);
			circle.setRadius(small_radius);
			shape.HoldingCircle(circle);
			shapev.push_back(shape);
			i-=2*small_radius;
			formula = sqrt(pow(MainCircle.getRadius()-i,2)+pow(MainCircle.getRadius()-j,2));
		}	
	}

	emptyarea = (MainCircle.getRadius()*MainCircle.getRadius()*M_PI)-(shapev.size()*M_PI*small_radius*small_radius);
	cout << "I can fit at most " <<  shapev.size()
	<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << endl;
		
}

//operator overloading for composedshape...

ostream& operator<<(ostream& outputstream,const ComposedShape& compshape){

	int i;
	ComposedShape tempcomp = compshape;

	for(i=0;i<tempcomp.shapev.size();i++){
		outputstream<<tempcomp[i];
	}

	
}

//operator overloading for shapeelem...

ostream& operator<<(ostream& outputstream,const ComposedShape::ShapeElem &shape){

	if(shape.innershape == ComposedShape::ShapeElem::InnerShape::Rectangle){
		outputstream << shape.innerRect;
	}
	if(shape.innershape == ComposedShape::ShapeElem::InnerShape::Triangle){
		outputstream << shape.innerTri;
	}
	if(shape.innershape == ComposedShape::ShapeElem::InnerShape::Circle){
		outputstream << shape.innerCirc;
	}
	
}

//Holding circle in this func

void ComposedShape::ShapeElem::HoldingCircle(Circle tempCirc){

	innershape = InnerShape::Circle;
	innerCirc = tempCirc;
	perimeter = tempCirc.PerimeterLength();
	area = tempCirc.Area();

}
//Holding rectangle in this func

void ComposedShape::ShapeElem::HoldingRectangle(Rectangle tempRect){

	innershape = InnerShape::Rectangle;
	innerRect = tempRect;
	perimeter = tempRect.PerimeterLength();
	area = tempRect.Area();

}
//Holding  triangle in this func

void ComposedShape::ShapeElem::HoldingTriangle(Triangle tempTri){
	innershape = InnerShape::Triangle;
	innerTri = tempTri;
	perimeter = tempTri.PerimeterLength();
	area = tempTri.Area();
}

//Setter for Enums.
void ComposedShape::ShapeElem::setType(char selection){
	
	if(selection=='C'){
		innershape = ShapeElem::InnerShape::Circle;
	}
	else if(selection=='R'){
		innershape = ShapeElem::InnerShape::Rectangle;
	}
	else if(selection=='T'){
		innershape = ShapeElem::InnerShape::Triangle;
	}
}

// overloading += for creating new object..

ComposedShape ComposedShape::operator+=(const Rectangle& rectangle){
	ComposedShape::ShapeElem temp;
	
	temp.HoldingRectangle(rectangle);

	this->shapev.push_back(temp);

	return *this;
}


ComposedShape ComposedShape::operator+=(const Circle& circle){
	ComposedShape::ShapeElem temp;
	
	temp.HoldingCircle(circle);

	this->shapev.push_back(temp);

	return *this;
}


ComposedShape ComposedShape::operator+=(const Triangle& triangle){
	ComposedShape::ShapeElem temp;
	
	temp.HoldingTriangle(triangle);

	this->shapev.push_back(temp);

	return *this;
}