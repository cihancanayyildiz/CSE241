
import java.awt.Graphics;
import java.awt.Color;
/**
*This is the PolygonDyn class.
*Extend from Polygon class.
*Uses Java Arrays to hold points.
*@author Cihan.
*/
public class PolygonDyn extends Polygon{
	
	/**
	*Java Array define for holding points.
	*This is a field.
	*/
	private Point2D[] points;

	/**
	*No parameter constructor for PolygonDyn
	*/
	public PolygonDyn(){
		points = new Point2D[5];	//Allocating 5 size for default.
		color = Color.RED;
	}

	/**
	*One parameter constructor for PolygonDyn
	*@param size The size that user's want.
	*/
	public PolygonDyn(int size){
		points = new Point2D[size];
		color = Color.RED;
	}

	/**
	*One parameter constructor for PolygonDyn
	*We will add this array to end of our array.
	*@param newArr This is the newArr.
	*/
	public PolygonDyn(Point2D[] newArr){
		points = new Point2D[newArr.length];
		for(int i=0;i<points.length;i++){
			points[i] = newArr[i];
		}
		color = Color.RED;
	}

	/**
	*One parameter constructor for PolygonDyn
	*We will add this point into our Array.
	*@param p this is a single point.
	*/
	public PolygonDyn(Point2D p){
		points = new Point2D[1];
		points[0] = p;
		color = Color.RED;
	}

	/**
	*Conversion constructor for PolygonDyn
	*Converting circle to PolygonDyn.
	*@param circle this is a Circle object.
	*/
	public PolygonDyn(Circle circle){

		points = new Point2D[100];	//We have 100 point on circle.(Homework Description)
		
		for(int i=0;i<points.length;i++){
			Point2D p = new Point2D();
			p.setX((circle.getCx() + circle.getRadius() * Math.cos(i * 2 * Math.PI / points.length)));
			p.setY((circle.getCy() + circle.getRadius() * Math.sin(i * 2 * Math.PI / points.length)));
	 		points[i] = p;
		}
		color = circle.getColor();
	}

	/**
	*Conversion constructor for PolygonDyn.
	*Converting rectangle to PolygonDyn.
	*@param rect this is a Rectangle object.
	*/
	public PolygonDyn(Rectangle rect){

		points = new Point2D[4];	//We have 4 point on rectangle.
		
		Point2D p = new Point2D();
		p.setX(rect.getX());
		p.setY(rect.getY());
		points[0] = p;
		Point2D p1 = new Point2D();
		p1.setX(rect.getX());
		p1.setY(rect.getY()+rect.getHeight());
		points[1] = p1;
		Point2D p2 = new Point2D();
		p2.setX(rect.getX()+rect.getWidth());
		p2.setY(rect.getY()+rect.getHeight());
		points[2] = p2;
		Point2D p3 = new Point2D();
		p3.setX(rect.getX()+rect.getWidth());
		p3.setY(rect.getY());
		points[3] = p3;
		
		color = rect.getColor();
	}

	/**
	*Conversion constructor for PolygonDyn.
	*Converting triangle to PolygonDyn.
	*@param tri this is a Triangle object.
	*/
	public PolygonDyn(Triangle tri){

		points = new Point2D[3]; //We have 3 points on Triangle.
		
		Point2D p = new Point2D();
		p.setX(tri.get_x_axis_of_Point1());
		p.setY(tri.get_y_axis_of_Point1());
		points[0] = p;
		Point2D p2 = new Point2D();
		p2.setX(tri.get_x_axis_of_Point2());
		p2.setY(tri.get_y_axis_of_Point2());
		points[1] = p2;
		Point2D p3 = new Point2D();
		p3.setX(tri.get_x_axis_of_Point3());
		p3.setY(tri.get_y_axis_of_Point3());
		points[2] = p3;

		color = tri.getColor();
	}

	/**
	*Area of PolygonDyn
	*Overriding area method.
	*@return area of polygon.
	*/
	public double Area(){
		double area = 0;

		// looping until the end of length.
		for(int i=0 ; i<points.length-1 ; i++){
			area += (points[i].getX() * points[i+1].getY() - points[i].getY() * points[i+1].getX() );
		}
		// and combining  last point and first point.
		area += (points[points.length-1].getX()*points[0].getY() - points[points.length-1].getY() * points[0].getX() );
		area = Math.abs(area)/2.0;
		
		return area;	
	}

	/**
	*Perimeter of PolygonDyn
	*Overriding perimeter method
	*@return perimeter of polygon.
	*/
	public double Perimeter(){
		double perimeter = 0;

		// looping until the end of length.
		for(int i=0 ; i<points.length-1 ; i++){
			perimeter += Math.sqrt(Math.pow(points[i].getX()-points[i+1].getX(),2) + Math.pow(points[i].getY() - points[i+1].getY(),2));
		}

		// and combining  last point and first point.
		perimeter += Math.sqrt(Math.pow(points[points.length-1].getX()-points[0].getX(),2) + Math.pow(points[points.length-1].getY() - points[0].getY(),2));

		return perimeter;
	}

	/**
	*Overriding compareTo method for compareing Areas.
	*@param s Shape object.
	*@return a negative integer, zero, or a positive integer as this object is less than, equal to, or greater than the specified object
	*/
	public int compareTo(Shape s){
		return Double.compare(Area(),s.Area());
	}

	/**
	*İncrementing position of PolygonVect 1.0
	*/
	public void increment(){
		for(int i=0 ; i<points.length ; i++){
			points[i].setX(points[i].getX()+1);
			points[i].setY(points[i].getY()+1);
		}
	}

	/**
	*Decrementing position of PolygonVect 1.0
	*/
	public void decrement(){
		for(int i=0 ; i<points.length ; i++){
			points[i].setX(points[i].getX()-1);
			points[i].setY(points[i].getY()-1);
		}
	}
	/**
	 * Draw function for PolygonDyn
	 * @param g graphics object
	 * This function draws the polygon to panel
	 * We will call this function in paintcomponent.
	 */
	public void draw(Graphics g){
		
		int[] x_axis = new int[points.length];
		for(int i=0;i<points.length;i++){
			x_axis[i] = (int)(points[i].getX());
		}
		int[] y_axis = new int[points.length];
		for(int i=0;i<points.length;i++){
			y_axis[i] = (int)(points[i].getY());
		}

		g.setColor(getColor());
		g.fillPolygon( x_axis , y_axis , points.length);
		g.setColor(Color.BLACK);
		g.drawPolygon( x_axis , y_axis , points.length);
	}


}