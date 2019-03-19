
import java.awt.Graphics;
import java.awt.Color;
/**
*This is composedshape class that composes shapes.
*@author Cihan.
*/
public class ComposedShape implements Shape{
	
	/**
	*Array of shape references.
	*/
	private Shape[] shapeArr;

	/**
	*One parameter constructor.
	*Takes the main shape and innershape and determines the size of array.
	*@param mainShape mainshape of composedshape
	*@param innerShape one of the smallshape of composedshape.
	*/ 
	public ComposedShape(Shape mainShape,Shape innerShape) throws IllegalArgumentException{
		
		shapeArr = new Shape[2];
		shapeArr[0] = mainShape;
		shapeArr[1] = innerShape;
		
	}
	/**
	*This method composes the shapes and gives us the optimal shape.
	*This is main method.
	*/
	public void optimalFit(){
		int index;
		double emptyarea;
		Shape[] tempArr = new Shape[(int)(shapeArr[0].Area() / shapeArr[1].Area()) + 5];	// allocating memory for temp array.
		
		if(shapeArr[0] instanceof Rectangle){
			Rectangle mainRectangle = (Rectangle) shapeArr[0];
			tempArr[0] = mainRectangle;
			if(shapeArr[1] instanceof Circle){
				Circle circle = (Circle)shapeArr[1];
				double cx,cy;
				index = 1;
				for(cx=circle.getRadius();cx<=mainRectangle.getWidth()-circle.getRadius();cx+=2*circle.getRadius()){
					for(cy=circle.getRadius();cy<=mainRectangle.getHeight()-circle.getRadius();cy+=2*circle.getRadius()){
						Circle c = new Circle();
						c.setRadius(circle.getRadius());
						c.setCx(cx);					
						c.setCy(cy);
						c.setColor(Color.GREEN);
						tempArr[index] = c;
						index++;
					}
				}
				shapeArr = new Shape[index];
				for(int i=0; i<index ; i++) {
					shapeArr[i] = tempArr[i] ;
				}
				
				emptyarea =	(mainRectangle.getHeight()*mainRectangle.getWidth())-((index-1)*Math.PI*circle.getRadius()*circle.getRadius());
				System.out.printf("I can fit at most %d small shapes into the main container. The empty are (red) in container is %.2f \n",index-1,emptyarea);
			}

			else if(shapeArr[1] instanceof Rectangle){
				Rectangle rect = (Rectangle)shapeArr[1];
				double i,j;
				double rect2_width = rect.getWidth() , rect2_height = rect.getHeight();
				index=1;
				for(i=0;i<=mainRectangle.getWidth(); i += rect2_width){	
					if(!(i+rect2_width > mainRectangle.getWidth())){	/* for x-axis the condition that the rectangle does not overflow the rectangle*/
						for(j=0;j<=mainRectangle.getWidth(); j += rect2_height){		
							if(!(j+rect2_height>mainRectangle.getHeight())){		
								Rectangle r = new Rectangle();
								r.setX(i);
								r.setY(j);
								r.setWidth(rect2_width);
								r.setHeight(rect2_height);
								r.setColor(Color.GREEN);
								tempArr[index] = r;
								index++;
							}
									
						}
					}
				}
				
				/*Using this loop for vertical rectangle.*/

				for(i -= rect2_width;i<=mainRectangle.getWidth();i += rect2_height){
					if(mainRectangle.getWidth()-i >= rect2_height){	/* for x-axis the condition that the rectangle does not overflow the rectangle*/
						for(j=0;j<=mainRectangle.getHeight(); j += rect2_width){
							if(!(j+rect2_width>mainRectangle.getHeight())){	 /* for y-axis the condition that the rectangle does not overflow the rectangle*/
								Rectangle r = new Rectangle();
								r.setX(i);
								r.setY(j);
								r.setWidth(rect2_height);
								r.setHeight(rect2_width);
								r.setColor(Color.GREEN);
								tempArr[index] = r;
								index++;
							}				
						}
					}
				}
				
				shapeArr = new Shape[index];
				for(int i1=0; i1<index ; i1++) {
					shapeArr[i1] = tempArr[i1] ;
				}
				
				emptyarea = (mainRectangle.getWidth()*mainRectangle.getHeight())-(index-1)*(rect2_width*rect2_height);
				System.out.printf("I can fit at most %d small shapes into the main container. The empty are (red) in container is %.2f \n",index-1,emptyarea);

			}

			else if(shapeArr[1] instanceof Triangle){
				double i,j;
				double innerheight;
				Triangle triangle = (Triangle)shapeArr[1];
				innerheight = (triangle.getEdge_of_Triangle()/2)*Math.sqrt(3); //height of triangle
				
				double point1X=0,point1Y=innerheight,point2X=triangle.getEdge_of_Triangle()/2,point2Y=0,point3X=triangle.getEdge_of_Triangle(),point3Y=innerheight;	//triangle points
				double point12X=triangle.getEdge_of_Triangle()/2,point12Y=0,point22X=triangle.getEdge_of_Triangle()+triangle.getEdge_of_Triangle()/2,point22Y=0,point32X=triangle.getEdge_of_Triangle(),point32Y=innerheight;
				//Using this loop for flat triangles
				index = 1;
				for(i=0;i<mainRectangle.getWidth();i+=triangle.getEdge_of_Triangle()){
				
					if(!(i+triangle.getEdge_of_Triangle() > mainRectangle.getWidth())){	// for x-axis the condition that the triangle does not overflow the rectangle
						
						for(j=0;j< mainRectangle.getHeight();j+=innerheight){
					
							if(!(j+innerheight > mainRectangle.getHeight())){	// for y-axis the condition that the triangle does not overflow the rectangle
								Triangle t = new Triangle();
								t.setEdge_of_Triangle(triangle.getEdge_of_Triangle());
								t.set_x_axis_of_Point1(point1X+i);
								t.set_y_axis_of_Point1(point1Y+j);
								t.set_x_axis_of_Point2(point2X+i);
								t.set_y_axis_of_Point2(point2Y+j);
								t.set_x_axis_of_Point3(point3X+i);
								t.set_y_axis_of_Point3(point3Y+j);
								t.setColor(Color.GREEN);
								tempArr[index] = t;
								index++;		
							}
						}
					}
				}

				//Using this loop for inverted triangles
				for(i=0;i<mainRectangle.getWidth();i+=triangle.getEdge_of_Triangle()){
					if(!(i+triangle.getEdge_of_Triangle()+triangle.getEdge_of_Triangle()/2 > mainRectangle.getWidth())){
						for(j=0;j<mainRectangle.getHeight();j+=innerheight){
							if(!(j+innerheight > mainRectangle.getHeight())){
								Triangle t = new Triangle();
								t.setEdge_of_Triangle(triangle.getEdge_of_Triangle());
								t.set_x_axis_of_Point1(point12X+i);
								t.set_y_axis_of_Point1(point12Y+j);
								t.set_x_axis_of_Point2(point22X+i);
								t.set_y_axis_of_Point2(point22Y+j);
								t.set_x_axis_of_Point3(point32X+i);
								t.set_y_axis_of_Point3(point32Y+j);
								t.setColor(Color.GREEN);
								tempArr[index] = t;
								index++;	
							}
						}
					}
				}
				shapeArr = new Shape[index];
				for(int i1=0; i1<index ; i1++) {
					shapeArr[i1] = tempArr[i1] ;
				}
				
				emptyarea = (mainRectangle.getHeight()*mainRectangle.getWidth())-(index-1)*((triangle.getEdge_of_Triangle()*triangle.getEdge_of_Triangle())*Math.sqrt(3)/4);
				System.out.printf("I can fit at most %d small shapes into the main container. The empty are (red) in container is %.2f \n",index-1,emptyarea);
			}
		}

		else if(shapeArr[0] instanceof Triangle){
			Triangle mainTriangle = (Triangle)shapeArr[0];
			tempArr[0] = mainTriangle;
			if(shapeArr[1] instanceof Triangle){
				Triangle triangle = (Triangle)shapeArr[1];
				double i,j;
				double small_t_edge = triangle.getEdge_of_Triangle();
				double innerheight = (mainTriangle.getEdge_of_Triangle()/2)*Math.sqrt(3);
				double sinnerheight = (small_t_edge/2)*Math.sqrt(3);	/*Height of smaller triangle .*/
				double a = small_t_edge/2;
				double b = 0;
				double point1X=a,point1Y=innerheight-sinnerheight,point2X=0,point2Y=innerheight,point3X=small_t_edge,point3Y=innerheight;	
				index = 1;
				/*This loop for flat triangles.*/
				for(i=0;i<=mainTriangle.getEdge_of_Triangle()/2;i+=small_t_edge/2){
					for(j=0;j<mainTriangle.getEdge_of_Triangle()-b;j+=small_t_edge){

						if(!(j+small_t_edge > mainTriangle.getEdge_of_Triangle()-b)){	/* for y-axis the condition that the triangle does not overflow the larger triangle*/
							Triangle t = new Triangle();
							t.setEdge_of_Triangle(small_t_edge);
							t.set_x_axis_of_Point1(point1X+j);
							t.set_y_axis_of_Point1(point1Y);
							t.set_x_axis_of_Point2(point2X+j);
							t.set_y_axis_of_Point2(point2Y);
							t.set_x_axis_of_Point3(point3X+j);
							t.set_y_axis_of_Point3(point3Y);
							t.setColor(Color.GREEN);
							tempArr[index] = t;
							index++;
						}
									
					}
					point1X += a;
					point1Y -= sinnerheight;
					point2X += a;
					point2Y -= sinnerheight;
					point3X += a;
					point3Y -= sinnerheight;


					b += 2*a ;
				}
				
				point1X=a;point1Y=innerheight-sinnerheight;point2X=2*a;point2Y=innerheight;point3X=3*a;point3Y=innerheight-sinnerheight;	/*Preparing the position of inverted triangles.*/
				b=2*a;

				//This loop for inverted triangles.
				
				for(i=0;i<=mainTriangle.getEdge_of_Triangle()/2;i+=small_t_edge/2){
					for(j=0;j<mainTriangle.getEdge_of_Triangle()-b;j+=small_t_edge){
						if(!(j+small_t_edge > mainTriangle.getEdge_of_Triangle()-b)){	// for y-axis the condition that the triangle does not overflow the larger triangle
							Triangle t = new Triangle();
							t.setEdge_of_Triangle(small_t_edge);
							t.set_x_axis_of_Point1(point1X+j);
							t.set_y_axis_of_Point1(point1Y);
							t.set_x_axis_of_Point2(point2X+j);
							t.set_y_axis_of_Point2(point2Y);
							t.set_x_axis_of_Point3(point3X+j);
							t.set_y_axis_of_Point3(point3Y);
							t.setColor(Color.GREEN);
							tempArr[index] = t;
							index++;
						}
							
					}

					point1X += a;
					point1Y -= sinnerheight;
					point2X += a;
					point2Y -= sinnerheight;
					point3X += a;
					point3Y -= sinnerheight;
					b += 2*a ;
				}
				shapeArr = new Shape[index];
				for(int i1=0; i1<index ; i1++) {
					shapeArr[i1] = tempArr[i1] ;
				}
				emptyarea = (mainTriangle.getEdge_of_Triangle()*mainTriangle.getEdge_of_Triangle()*Math.sqrt(3)/4)-((index-1)*small_t_edge*small_t_edge*Math.sqrt(3)/4);
				System.out.printf("I can fit at most %d small shapes into the main container. The empty are (red) in container is %.2f \n",index-1,emptyarea);
			}

			else if(shapeArr[1] instanceof Rectangle){
				Rectangle rectangle = (Rectangle)shapeArr[1];
				double i,j,k;
				double innerheight = (mainTriangle.getEdge_of_Triangle()/2)*Math.sqrt(3);
				double rect_width = rectangle.getWidth() , rect_height = rectangle.getHeight() ;
				double a = rect_width/Math.sqrt(3); /* Distance of small pieces.*/

				index = 1;
				j=innerheight-rect_width;
				for(i=rect_width/Math.sqrt(3);i<=mainTriangle.getEdge_of_Triangle()/2;i += rect_width/Math.sqrt(3)){ /*Determining first position and starting the loop.*/
					if(j<0){
						break;
					}

					for(k=i;k<=mainTriangle.getEdge_of_Triangle()-a;k+=rect_height){
						if(!(k+rect_height > mainTriangle.getEdge_of_Triangle()-a)){
							Rectangle r = new Rectangle();
							r.setWidth(rect_height);
							r.setHeight(rect_width);
							r.setX(k);
							r.setY(j);
							r.setColor(Color.GREEN);
							tempArr[index] = r;
							index++;
						}
					}
					a = a +	rect_width/Math.sqrt(3); /* We are carrying our position to upper line.*/
					j-=rect_width;
				}
				shapeArr = new Shape[index];
				for(int i1=0; i1<index ; i1++) {
					shapeArr[i1] = tempArr[i1] ;
				}
				emptyarea = (mainTriangle.getEdge_of_Triangle()*mainTriangle.getEdge_of_Triangle()*Math.sqrt(3)/4) - (index-1)*(rect_width*rect_height);
				System.out.printf("I can fit at most %d small shapes into the main container. The empty are (red) in container is %.2f \n",index-1,emptyarea);
			}

			else if(shapeArr[1] instanceof Circle){
				Circle circle = (Circle)shapeArr[1];
				double i,j;
				double innerheight = (mainTriangle.getEdge_of_Triangle()/2)*Math.sqrt(3);
				double radius = circle.getRadius();
				double a = radius*Math.sqrt(3); //Distance of small pieces
				int b=0;
				index=1;
				for(j=innerheight-radius;j>=0+radius-innerheight;j-=a){	// for y-axis the condition that the circle does not overflow the larger triangle
						
					for(i=a+b*radius;i<=mainTriangle.getEdge_of_Triangle()-a-b*radius;i+=2*radius){	// for x-axis the condition that the circle does not overflow the larger triangle
						Circle c = new Circle();
						c.setCx(i);
						c.setCy(j);
						c.setRadius(radius);
						c.setColor(Color.GREEN);
						tempArr[index] = c;
						index++;
					}
					b+=1;
				}
				shapeArr = new Shape[index];
				for(int i1=0; i1<index ; i1++) {
					shapeArr[i1] = tempArr[i1] ;
				}
				emptyarea = (mainTriangle.getEdge_of_Triangle()*mainTriangle.getEdge_of_Triangle()*Math.sqrt(3)/4)-((index-1)*Math.PI*radius*radius);
				System.out.printf("I can fit at most %d small shapes into the main container. The empty are (red) in container is %.2f \n",index-1,emptyarea);
			}
		}

		else if(shapeArr[0] instanceof Circle){
			Circle mainCircle = (Circle)shapeArr[0];
			tempArr[0] = mainCircle;
			if(shapeArr[1] instanceof Circle){
				Circle circle = (Circle)shapeArr[1];
				double i,j;
				double small_radius = circle.getRadius();
				double formula=0;
				
				Circle c = new Circle();
				c.setCx(mainCircle.getRadius());
				c.setCy(small_radius);
				c.setRadius(small_radius);
				c.setColor(Color.GREEN);
				tempArr[1] = c;
				index = 2;
				for(j=3*small_radius;j<=2*mainCircle.getRadius()-2*small_radius;j+=2*small_radius){
					i = mainCircle.getRadius();
					formula = 0;
					do{
						c = new Circle();
						c.setCx(i);
						c.setCy(j);
						c.setRadius(small_radius);
						c.setColor(Color.GREEN);
						tempArr[index] = c;
						index++;
						i+=2*small_radius;
						formula = Math.sqrt(Math.pow(mainCircle.getRadius()-i,2)+Math.pow(mainCircle.getRadius()-j,2));
					}
					while(formula<=mainCircle.getRadius()-small_radius);
				}
				for(j=3*small_radius;j<=2*mainCircle.getRadius()-2*small_radius;j+=2*small_radius){
						i = mainCircle.getRadius()-2*small_radius;
						formula = 0;
						while(formula<=mainCircle.getRadius()-small_radius){
						c = new Circle();
						c.setCx(i);
						c.setCy(j);
						c.setRadius(small_radius);
						c.setColor(Color.GREEN);
						tempArr[index] = c;
						index++;
						i-=2*small_radius;
						formula = Math.sqrt(Math.pow(mainCircle.getRadius()-i,2)+Math.pow(mainCircle.getRadius()-j,2));
					}	
				}
				shapeArr = new Shape[index];
				for(int i1=0; i1<index ; i1++) {
					shapeArr[i1] = tempArr[i1] ;
				}
				emptyarea = (mainCircle.getRadius()*mainCircle.getRadius()*Math.PI)-((index-1)*Math.PI*small_radius*small_radius);
				System.out.printf("I can fit at most %d small shapes into the main container. The empty are (red) in container is %.2f \n",index-1,emptyarea);
			}
		}

	}

	/**
	 * Getter for member shapeArr array.
	 * @return member shapeArr array.
	 */
	public Shape[] getshapeArr(){
		return shapeArr;
	}

	/**
	 * Area of composedShape actually mainshape.
	 */
	public double Area(){
		return shapeArr[0].Area();
	}

	/**
	 * Perimeter of composedShape actually mainshape.
	 */
	public double Perimeter(){
		return shapeArr[0].Perimeter();
	}
	
	/**
	 * comparing two composedshape.
	 */
	public int compareTo(Shape s){
		return Double.compare(Area(),s.Area());
	}

	/**
	 * Incrementing every object's positions.
	 */
	public void increment(){
		
		for(int i=0;i<shapeArr.length;i++) {
			shapeArr[i].increment();
		}
	}

	/**
	 * Decrementing every object's positions.
	 */
	public void decrement(){
		for(int i=0;i<shapeArr.length;i++) {
			shapeArr[i].decrement();
		}
	}
	
	/**
	 * Drawing the composedshape.
	 */
	public void draw(Graphics g){

		for(int i=0;i<shapeArr.length;i++){
			if(shapeArr[i]==null){
				break;
			}
			shapeArr[i].draw(g);
		}

	}



}
