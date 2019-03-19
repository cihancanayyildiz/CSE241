#include "composedshape.h"

	//Main shape is rectangle
	ComposedShape::ComposedShape(Rectangle &MainRectangle){

		double width,height;
		cout<< "Please enter the width of main rectangle";
		cin >> width;
		
		cout<< "Please enter the height of main rectangle";
		cin >> height;
		
		MainRectangle.setWidth(width);
		MainRectangle.setHeight(height);
	}

	//Main shape is triangle
	ComposedShape::ComposedShape(Triangle &MainTriangle){
		double triangle_edge;

		cout << "Please enter the edge of main triangle";
		cin >> triangle_edge;
		MainTriangle.setEdge_of_Triangle(triangle_edge);
	}

	//Main shape is circle
	ComposedShape::ComposedShape(Circle &MainCircle){
		double radius;

		cout << "Please enter the radius of main circle";
		cin >> radius;
		MainCircle.setRadius(radius);
		MainCircle.setCx(radius);
		MainCircle.setCy(radius);
	}

	/*Optimal Fit function for main rectangle.*/
	void ComposedShape::optimalFit(Rectangle &MainRectangle,Shapes Mainshape,Shapes Smallshape){
		double radius,cx,cy;
		double i,j;
		double rect2_width,rect2_height;
		double triangle_edge;
		double emptyarea;
		
		//Smaller circles within a larger rectangle
		if(Mainshape == Shapes::Rectangle && Smallshape == Shapes::Circle ){	
			cout << "Please enter the radius of circle";
			cin >>radius;
			
			for(cx=radius;cx<=MainRectangle.getWidth()-radius;cx+=2*radius){
				for(cy=radius;cy<=MainRectangle.getHeight()-radius;cy+=2*radius){
					circle.setRadius(radius);
					circle.setCx(cx);					
					circle.setCy(cy);
					circlev.push_back(circle);	//sending object to vector
				}
			}

			emptyarea =	(MainRectangle.getHeight()*MainRectangle.getWidth())-(circlev.size()*M_PI*radius*radius);
			cout << "I can fit at most " << circlev.size()
			<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << endl;
			
			
		}

		// Smaller rectangles within a larger rectangle
		if(Mainshape == Shapes::Rectangle && Smallshape == Shapes::Rectangle){	

			cout << "Please enter the width of small shape";
			cin >> rect2_width;
			cout << "Please enter the height of small shape";
			cin >> rect2_height;

			/*Using this loop for horizontal rectangle.*/
			for(i=0;i<=MainRectangle.getWidth(); i += rect2_width){	

				if(!(i+rect2_width > MainRectangle.getWidth())){	/* for x-axis the condition that the rectangle does not overflow the rectangle*/

					for(j=0;j<=MainRectangle.getWidth(); j += rect2_height){
						
						if(!(j+rect2_height>MainRectangle.getHeight())){
							
							rectangle.setX(i);
							rectangle.setY(j);
							rectangle.setWidth(rect2_width);
							rectangle.setHeight(rect2_height);
							rectanglev.push_back(rectangle);	//sending object to vector
							
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
							rectangle.setHeight(rect2_width);
							rectanglev.push_back(rectangle);	//sending object to vector

						}
							
					}
				}
			}

			emptyarea = (MainRectangle.getWidth()*MainRectangle.getHeight())-rectanglev.size()*(rect2_width*rect2_height);
			cout << "I can fit at most " <<  rectanglev.size()
			<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << endl;
			
		}

		//Smaller triangles within a larger rectangle
		if(Mainshape == Shapes::Rectangle && Smallshape == Shapes::Triangle){	
			
			cout << "Please enter the edge of triangle";
			cin >> triangle_edge;

			double innerheight;
			innerheight = (triangle_edge/2)*sqrt(3); /*height of triangle*/
			/*triangle points*/
			double point1X=0,point1Y=innerheight,point2X=triangle_edge/2,point2Y=0,point3X=triangle_edge,point3Y=innerheight;	
			double point12X=triangle_edge/2,point12Y=0,point22X=triangle_edge+triangle_edge/2,point22Y=0,point32X=triangle_edge,point32Y=innerheight;




			/*Using this loop for flat triangles*/
			for(i=0;i<MainRectangle.getWidth();i+=triangle_edge){
			
				if(!(i+triangle_edge > MainRectangle.getWidth())){	/* for x-axis the condition that the triangle does not overflow the rectangle*/
					
					for(j=0;j< MainRectangle.getHeight();j+=innerheight){
						
						if(!(j+innerheight > MainRectangle.getHeight())){	/* for y-axis the condition that the triangle does not overflow the rectangle*/
							triangle.setEdge_of_Triangle(triangle_edge);
							triangle.set_x_axis_of_Point1(point1X+i);
							triangle.set_y_axis_of_Point1(point1Y+j);
							triangle.set_x_axis_of_Point2(point2X+i);
							triangle.set_y_axis_of_Point2(point2Y+j);
							triangle.set_x_axis_of_Point3(point3X+i);
							triangle.set_y_axis_of_Point3(point3Y+j);
							trianglev.push_back(triangle);	//sending object to vector
							
						}
					}
				}
			}

			/*Using this loop for inverted triangles*/
			for(i=0;i<MainRectangle.getWidth();i+=triangle_edge){
				if(!(i+triangle_edge+triangle_edge/2 > MainRectangle.getWidth())){

					for(j=0;j<MainRectangle.getHeight();j+=innerheight){
						if(!(j+innerheight > MainRectangle.getHeight())){
							triangle.setEdge_of_Triangle(triangle_edge);
							triangle.set_x_axis_of_Point1(point12X+i);
							triangle.set_y_axis_of_Point1(point12Y+j);
							triangle.set_x_axis_of_Point2(point22X+i);
							triangle.set_y_axis_of_Point2(point22Y+j);
							triangle.set_x_axis_of_Point3(point32X+i);
							triangle.set_y_axis_of_Point3(point32Y+j);
							trianglev.push_back(triangle);	//sending object to vector
							
						}
					}
				}
			}
			
			emptyarea = (MainRectangle.getHeight()*MainRectangle.getWidth())-trianglev.size()*((triangle_edge*triangle_edge)*sqrt(3)/4);
			cout << "I can fit at most " << trianglev.size()
			<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << endl;
					
		}

	}

	/*Optimal Fit function for main triangle.*/
	void ComposedShape::optimalFit(Triangle &MainTriangle,Shapes Mainshape,Shapes Smallshape){
		double i,j,k;
		double innerheight=(MainTriangle.getEdge_of_Triangle()/2)*sqrt(3); /*Height of main triangle.*/
		double rect_width,rect_height;
		double emptyarea;

		if(Mainshape == Shapes::Triangle && Smallshape == Shapes::Rectangle){

			cout << "Please enter the width of the inner rectangle";
			cin >> rect_width;
			cout << "Please enter the height of the inner rectangle";
			cin >> rect_height;

			double a = rect_width/sqrt(3); /* Distance of small pieces.*/

			for(i=rect_width/sqrt(3),j=innerheight-rect_width;i<=MainTriangle.getEdge_of_Triangle()/2,j>=0;i += rect_width/sqrt(3),j-=rect_width){ /*Determining first position and starting the loop.*/

				for(k=i;k<=MainTriangle.getEdge_of_Triangle()-a;k+=rect_height){
					if(!(k+rect_height > MainTriangle.getEdge_of_Triangle()-a)){
						rectangle.setWidth(rect_height);
						rectangle.setHeight(rect_width);
						rectangle.setX(k);
						rectangle.setY(j);
						rectanglev.push_back(rectangle);	//sending object to vector
					}
				}
				a = a +	rect_width/sqrt(3); /* We are carrying our position to upper line.*/
			}


			emptyarea = (MainTriangle.getEdge_of_Triangle()*MainTriangle.getEdge_of_Triangle()*sqrt(3)/4) - rectanglev.size()*(rect_width*rect_height);
			cout << "I can fit at most " <<  rectanglev.size()
			<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << endl;
			
		}

		if(Mainshape == Shapes::Triangle && Smallshape == Shapes::Triangle){
			
			double Sinnerheight,small_t_edge;
			
			cout << "Please enter the edge of small triangle";
			cin >> small_t_edge;

			Sinnerheight = (small_t_edge/2)*sqrt(3);	/*Height of smaller triangle .*/
			double a = small_t_edge/2;
			double b = 0;
			double point1X=a,point1Y=innerheight-Sinnerheight,point2X=0,point2Y=innerheight,point3X=small_t_edge,point3Y=innerheight;	/*First position.*/
			
		
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
						trianglev.push_back(triangle);	//sending object to vector

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
						trianglev.push_back(triangle);	//sending object to vector
	
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

			emptyarea = (MainTriangle.getEdge_of_Triangle()*MainTriangle.getEdge_of_Triangle()*sqrt(3)/4)-(trianglev.size()*small_t_edge*small_t_edge*sqrt(3)/4);
			cout << "I can fit at most " <<  trianglev.size()
			<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << endl;
			
		}

		if(Mainshape == Shapes::Triangle && Smallshape == Shapes::Circle){

			double radius;
			cout << "Please enter the radius of small circles";
			cin >> radius;

			double a = radius*sqrt(3); /*Distance of small pieces*/
			int b=0;

			for(j=innerheight-radius;j>=0+radius-innerheight;j-=a){	/* for y-axis the condition that the circle does not overflow the larger triangle*/
				
				for(i=a+b*radius;i<=MainTriangle.getEdge_of_Triangle()-a-b*radius;i+=2*radius){	/* for x-axis the condition that the circle does not overflow the larger triangle*/
					circle.setCx(i);
					circle.setCy(j);
					circle.setRadius(radius);
					circlev.push_back(circle);	//sending object to vector
				}

				b+=1;
			}


			emptyarea = (MainTriangle.getEdge_of_Triangle()*MainTriangle.getEdge_of_Triangle()*sqrt(3)/4)-(circlev.size()*M_PI*radius*radius);
			cout << "I can fit at most " <<  circlev.size()
			<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << endl;

		}

	}
		//OptimalFit function for Main Circle..
	void ComposedShape::optimalFit(Circle &MainCircle,Shapes Mainshape,Shapes Smallshape){

		double i,j,emptyarea;

		if(Mainshape == Shapes::Circle && Smallshape == Shapes::Circle){
			double small_radius;
			double formula=0;
			cout << "Please enter the radius of small circles";
			cin >> small_radius;

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
					circlev.push_back(circle);	//sending object to vector
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
					circlev.push_back(circle);	//sending object to vector
					i-=2*small_radius;
					formula = sqrt(pow(MainCircle.getRadius()-i,2)+pow(MainCircle.getRadius()-j,2));
				}	
			}

			emptyarea = (MainCircle.getRadius()*MainCircle.getRadius()*M_PI)-(circlev.size()*M_PI*small_radius*small_radius);
			cout << "I can fit at most " <<  circlev.size()
			<< " small shapes into the main container. The empty are (red) in container is " << emptyarea << endl;
		}

	}

	//Draw function to draw small objects..
	void ComposedShape::draw(ofstream &file,Shapes Mainshape,Shapes Smallshape){

		int i;
		
		if(Mainshape == Shapes::Rectangle && Smallshape == Shapes::Circle ){
			for(i=0;i<=circlev.size();i++){
				file << "<circle cx=\"" << circlev[i].getCx() << "\"" << " cy=\"" << circlev[i].getCy() << "\"" << " r=\"" << circlev[i].getRadius() << "\" fill=\"green\"/>\n" ;
			}
			
		}

		if(Mainshape == Shapes::Rectangle && Smallshape == Shapes::Rectangle){

			for(i=0;i<=rectanglev.size();i++){
				file << "<rect x=\"" << rectanglev[i].getX() << "\"" << " y=\"" << rectanglev[i].getY() << "\"" << " width=\"" << rectanglev[i].getWidth() << "\"" << " height=\"" << rectanglev[i].getHeight() << "\"" << " style=\"fill:green \"/>\n" ;
			}
		}

		if(Mainshape == Shapes::Rectangle && Smallshape == Shapes::Triangle){

			for(i=0;i<=trianglev.size();i++){
				file << "<polygon points=\"" << trianglev[i].get_x_axis_of_Point1() << " " << trianglev[i].get_y_axis_of_Point1() << "," << trianglev[i].get_x_axis_of_Point2() << " " << trianglev[i].get_y_axis_of_Point2() << "," << trianglev[i].get_x_axis_of_Point3() << " " << trianglev[i].get_y_axis_of_Point3() << "\" fill=\"green\"/>\n" ;
			}
			
			
		}
		if(Mainshape == Shapes::Triangle && Smallshape == Shapes::Rectangle){

			for(i=0;i<=rectanglev.size();i++){
				file << "<rect x=\"" << rectanglev[i].getX() << "\"" << " y=\"" << rectanglev[i].getY() << "\"" << " width=\"" << rectanglev[i].getWidth() << "\"" << " height=\"" << rectanglev[i].getHeight() << "\"" << " style=\"fill:green \"/>\n" ;
			}
			
		}
		if(Mainshape == Shapes::Triangle && Smallshape == Shapes::Triangle){

			for(i=0;i<=trianglev.size();i++){
				file << "<polygon points=\"" << trianglev[i].get_x_axis_of_Point1() << " " << trianglev[i].get_y_axis_of_Point1() << "," << trianglev[i].get_x_axis_of_Point2() << " " << trianglev[i].get_y_axis_of_Point2() << "," << trianglev[i].get_x_axis_of_Point3() << " " << trianglev[i].get_y_axis_of_Point3() << "\" fill=\"green\"/>\n" ;
			}
			
		}

		if(Mainshape == Shapes::Triangle && Smallshape == Shapes::Circle){
			for(i=0;i<=circlev.size();i++){
				file << "<circle cx=\"" << circlev[i].getCx() << "\"" << " cy=\"" << circlev[i].getCy() << "\"" << " r=\"" << circlev[i].getRadius() << "\" fill=\"green\"/>\n" ;
			}
		}

		if(Mainshape == Shapes::Circle && Smallshape == Shapes::Circle){
			for(i=0;i<=circlev.size();i++){
				file << "<circle cx=\"" << circlev[i].getCx() << "\"" << " cy=\"" << circlev[i].getCy() << "\"" << " r=\"" << circlev[i].getRadius() << "\" fill=\"green\"/>\n" ;
			}

		}

	}