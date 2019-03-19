
import java.awt.Graphics;
import java.util.ArrayList;
import java.awt.Color;
/**
*This is the polygonvect class
*Extends from Polygon class 
*Uses ArrayList collection for holding points.
*@author Cihan Can Ayyıldız.
*/
public class PolygonVect extends Polygon{

	/**
	*Arraylist field of PolygonVect
	*This field holds polygonvect's points.
	*/
	private ArrayList<Point2D> points;

	/**
	*No parameter constructor for PolygonVect
	*/
	public PolygonVect(){
		points = new ArrayList<Point2D>();
		color = Color.RED;
	}

	/**
	*1 parameter constructor for PolygonVect
	*@param newpoints This is the new ArrayList object.It holds point2D
	*adding all objects of newpoints to end of our ArrayList.
	*/
	public PolygonVect(ArrayList<Point2D> newpoints){
		points = new ArrayList<Point2D>();
		points.addAll(newpoints);
		color = Color.RED;
	}

	/**
	*1 parameter constructor for PolygonVect
	*@param p new point2D object.
	*adding this point into our arraylist.
	*/
	public PolygonVect(Point2D p){
		points = new ArrayList<Point2D>();
		points.add(p);
		color = Color.RED;
	}

	/**
	*Conversion constructor for PolygonVect
	*@param circle this is an circle object.
	*Converting circle to polygonvect object.
	*/
	public PolygonVect(Circle circle){
		points = new ArrayList<Point2D>(100);
		for(int i=0;i<100;i++) {
			Point2D p = new Point2D();
	  		p.setX((circle.getCx() + circle.getRadius() * Math.cos(i * 2 * Math.PI / 100)));	// X-axis for polygon.
	  		p.setY((circle.getCy() + circle.getRadius() * Math.sin(i * 2 * Math.PI / 100)));	// Y-axis for polygon.
	  		points.add(p);
		}

		color = circle.getColor();
	}

	/**
	*Conversion constructor for PolygonVect
	*@param rect this is an rectangle object.
	*Converting rectangle to polygonvect object.
	*/
	public PolygonVect(Rectangle rect){
		points = new ArrayList<Point2D>();

		Point2D p = new Point2D();
		p.setX(rect.getX());
		p.setY(rect.getY());
		points.add(p);
		Point2D p1 = new Point2D();
		p1.setX(rect.getX());
		p1.setY(rect.getY()+rect.getHeight());
		points.add(p1);
		Point2D p2 = new Point2D();
		p2.setX(rect.getX()+rect.getWidth());
		p2.setY(rect.getY()+rect.getHeight());
		points.add(p2);
		Point2D p3 = new Point2D();
		p3.setX(rect.getX()+rect.getWidth());
		p3.setY(rect.getY());
		points.add(p3);
		
		color = rect.getColor();
	}

	/**
	*Conversion constructor for PolygonVect
	*@param tri this is an triangle object.
	*Converting  triangle to polygonvect object.
	*/
	public PolygonVect(Triangle tri){
		points = new ArrayList<Point2D>(3);

		Point2D p = new Point2D();
		p.setX(tri.get_x_axis_of_Point1());
		p.setY(tri.get_y_axis_of_Point1());
		points.add(p);
		Point2D p2 = new Point2D();
		p2.setX(tri.get_x_axis_of_Point2());
		p2.setY(tri.get_y_axis_of_Point2());
		points.add(p2);
		Point2D p3 = new Point2D();
		p3.setX(tri.get_x_axis_of_Point3());
		p3.setY(tri.get_y_axis_of_Point3());
		points.add(p3);

		color = tri.getColor();
	}

	/**
	*This is the Area method for PolygonVect
	*Overriding the area method.
	*Extends from Polygon class
	*@return area of polygonvect.
	*/
	public double Area(){
		double area = 0;

		for(int i=0 ; i<points.size()-1 ; i++){
			area += (points.get(i).getX() * points.get(i+1).getY() - points.get(i).getY() * points.get(i+1).getX() );
		}
		area += (points.get(points.size()-1).getX()*points.get(0).getY() - points.get(points.size()-1).getY() * points.get(0).getX() );
		area = Math.abs(area)/2.0;
	
		return area;
	}

	/**
	*This is the Perimeter method for PolygonVect
	*Overriding the perimeter method.
	*Extends from Polygon class
	*@return perimeter of polygonvect.
	*/
	public double Perimeter(){
		double perimeter = 0;

		for(int i=0 ; i<points.size()-1 ; i++){
			perimeter += Math.sqrt(Math.pow(points.get(i).getX()-points.get(i+1).getX(),2) + Math.pow(points.get(i).getY() - points.get(i+1).getY(),2));
		}
		perimeter += Math.sqrt(Math.pow(points.get(points.size()-1).getX()-points.get(0).getX(),2) + Math.pow(points.get(points.size()-1).getY() - points.get(0).getY(),2));

		return perimeter;
	}

	/**
	*Overriding compareTo method for comparing Areas.
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
		Point2D p;
		for(int i=0 ; i<points.size() ; i++){
			p = points.get(i);
			p.setX(p.getX()+1);
			p.setY(p.getY()+1);
			points.set(i,p);
		}
	}

	/**
	*Decrementing position of PolygonVect 1.0
	*/
	public void decrement(){
		Point2D p;
		for(int i=0 ; i<points.size() ; i++){
			p = points.get(i);
			p.setX(p.getX()-1);
			p.setY(p.getY()-1);
			points.set(i,p);
		}
	}


	public void draw(Graphics g){
		
		int[] x_axis = new int[points.size()];
		for(int i=0;i<points.size();i++){
			x_axis[i] = (int)(points.get(i).getX());
		}
		int[] y_axis = new int[points.size()];
		for(int i=0;i<points.size();i++){
			y_axis[i] = (int)(points.get(i).getY());
		}

		g.setColor(getColor());
		g.fillPolygon( x_axis , y_axis , points.size());
		g.setColor(Color.BLACK);
		g.drawPolygon( x_axis , y_axis , points.size());
			
	}

}