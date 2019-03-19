
import java.awt.Graphics;
import java.awt.Color;
/**
*This is the Triangle shape class
*This class contains all necessary
*fields and methods for Triangle.
*@author Cihan.
*/
public class Triangle implements Shape{
	/**
	*Private fields of triangle.
	*/
	private double edge_of_triangle;
	private double x_axis_of_Point1;
	private double y_axis_of_Point1;
	private double x_axis_of_Point2;
	private double y_axis_of_Point2;
	private double x_axis_of_Point3;
	private double y_axis_of_Point3;
	private Color c;


	/**
	*No parameter  constructor of triangle class.
	*/
	public Triangle(){
		edge_of_triangle=100;
		x_axis_of_Point1=edge_of_triangle/2;
		y_axis_of_Point1=0;
		x_axis_of_Point2=0;
		y_axis_of_Point2=(edge_of_triangle/2)* Math.sqrt(3.0);
		x_axis_of_Point3=edge_of_triangle;
		y_axis_of_Point3=(edge_of_triangle/2)* Math.sqrt(3.0);
		c = Color.RED;
	}

	/**
	*1 parameter  ructor of triangle class.
	*@param edge new edge of triangle.
	*/
	public Triangle(double edge) throws IllegalArgumentException{
		if(edge<=0){
			throw new  IllegalArgumentException("Edge of triangle has an invalid value.");
		}
		else{
			edge_of_triangle=edge;
			x_axis_of_Point1=edge_of_triangle/2;
			y_axis_of_Point1=0;
			x_axis_of_Point2=0;
			y_axis_of_Point2=(edge_of_triangle/2)* Math.sqrt(3.0);
			x_axis_of_Point3=edge_of_triangle;
			y_axis_of_Point3=(edge_of_triangle/2)* Math.sqrt(3.0);
			c = Color.RED;
		}
	}
	/**
	*7 parameter  constructor of triangle class.
	*@param edge new edge of triangle.
	*@param x1 new x coordinate of point 1
	*@param y1 new y coordinate of point 1
	*@param x2 new x coordinate of point 2
	*@param y2 new y coordinate of point 2
	*@param x3 new x coordinate of point 3
	*@param y3 new y coordinate of point 3
	*/

	public Triangle(double edge,double x1,double y1,double x2,double y2,double x3,double y3) throws IllegalArgumentException{

		if(edge<=0 || x1<0 || y1<0 || x2<0 || y2<0 || x3<0 || y3<0){
			throw new  IllegalArgumentException("One of the field of Triangle has an invalid value.");
		}
		else{
			x_axis_of_Point1=x1;
			y_axis_of_Point1=y1;
			x_axis_of_Point2=x2;
			y_axis_of_Point2=y2;
			x_axis_of_Point3=x3;
			y_axis_of_Point3=y3;
			edge_of_triangle = edge;
			c = Color.RED;
		}
	}

	/**
	*Setter for edge of triangle
	*@param edge new edge of triangle.
	*/
	public void setEdge_of_Triangle(double edge) throws IllegalArgumentException{
		if(edge > 0){
			edge_of_triangle=edge;
		}
		else{
			throw new  IllegalArgumentException("Triangle edge has an invalid value.");
		}
	}
	/**
	*Setter for x coordinate of point1.
	*@param x new x coordinate of point1.
	*/
	public void set_x_axis_of_Point1(double x){
		
			x_axis_of_Point1 = x;
	
	}

	/**
	*Setter for y coordinate of point1
	*@param y new y coordinate of point1
	*/
	public void set_y_axis_of_Point1(double y){
		
			y_axis_of_Point1 = y;
		
		
	}

	/**
	*Setter for x coordinate of point2
	*@param x new x coordinate of point2
	*/
	public void set_x_axis_of_Point2(double x) throws IllegalArgumentException{
		if(x<0){
				throw new  IllegalArgumentException("Triangle x coordinate of point 2 has an invalid value.");
		}
		else{
			x_axis_of_Point2 = x;
		}
	}

	/**
	*Setter for y coordinate of point2
	*@param y new y coordinate of point2
	*/
	public void set_y_axis_of_Point2(double y) throws IllegalArgumentException{
		if(y<0){
				throw new  IllegalArgumentException("Triangle y coordinate of point 2 has an invalid value.");
		}
		else{
			y_axis_of_Point2 = y;
		}
		
	}

	/**
	*Setter for x coordinate of point3
	*@param x new x coordinate of point3
	*/
	public void set_x_axis_of_Point3(double x) throws IllegalArgumentException{
		if(x<0){
				throw new  IllegalArgumentException("Triangle x coordinate of point 3 has an invalid value.");
		}
		else{
			x_axis_of_Point3 = x;
		}	
	}

	/**
	*Setter for y coordinate of point3
	*@param y new y coordinate of point3
	*/
	public void set_y_axis_of_Point3(double y) throws IllegalArgumentException{
		if(y<0){
				throw new  IllegalArgumentException("Triangle y coordinate of point 3 has an invalid value.");
		}
		else{
			y_axis_of_Point3 = y;
		}
	}

	/**
	*Setter for color of triangle.
	*@param newColour new color of triangle.
	*/
	public void setColor(Color newColour){
		c = newColour;
	}

	/**
	*Getter for edge of triangle.
	*@return edge of triangle.
	*/
	public double  getEdge_of_Triangle(){
		return edge_of_triangle;
	}
	/**
	*Getter for x coordinate of point1.
	*@return x coordinate of point1.
	*/
	public double  get_x_axis_of_Point1(){
		return x_axis_of_Point1;
	}
	/**
	*Getter for y coordinate of point1.
	*@return y coordinate of point1.
	*/
	public double  get_y_axis_of_Point1(){
		return y_axis_of_Point1;
	}

	/**
	*Getter for x coordinate of point2.
	*@return x coordinate of point2.
	*/
	public double  get_x_axis_of_Point2(){
		return x_axis_of_Point2;
	}
	/**
	*Getter for y coordinate of point2.
	*@return y coordinate of point2.
	*/
	public double  get_y_axis_of_Point2(){
		return y_axis_of_Point2;
	}
	/**
	*Getter for x coordinate of point3.
	*@return x coordinate of point3.
	*/
	public double  get_x_axis_of_Point3(){
		return x_axis_of_Point3;
	}
	/**
	*Getter for y coordinate of point3.
	*@return y coordinate of point3.
	*/
	public double  get_y_axis_of_Point3(){
		return y_axis_of_Point3;
	}
	/**
	*Getter for color of Triangle.
	*@return color of triangle.
	*/
	public Color getColor(){
		return c;
	}

	/**
	*Area of triangle.
	*@return area of triangle.
	*/
	public double Area(){
		return Math.pow(edge_of_triangle,2)* Math.sqrt(3.0)/4;
	}

	/**
	*Perimeter of triangle.
	*@return perimeter of circle.
	*/
	public double Perimeter(){
		return 3*edge_of_triangle;
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
	*This method for incrementing the shape positions by 1.0.
	*/
	public void increment(){
		x_axis_of_Point1++;
		y_axis_of_Point1++;
		x_axis_of_Point2++;
		y_axis_of_Point2++;
		x_axis_of_Point3++;
		y_axis_of_Point3++;
	}

	/**
	*This method for decrementing the shape positions by 1.0.
	*/
	public void decrement(){
		x_axis_of_Point1--;
		y_axis_of_Point1--;
		x_axis_of_Point2--;
		y_axis_of_Point2--;
		x_axis_of_Point3--;
		y_axis_of_Point3--;
	}

	/**
	*This method for drawing the shape on the frame.
	*@param g this is an Graphics object. 
	*/
	public void draw(Graphics g){
		g.setColor(getColor());
		g.fillPolygon(new int[] {(int)x_axis_of_Point1, (int)x_axis_of_Point2, (int)x_axis_of_Point3}, new int[] {(int)y_axis_of_Point1, (int)y_axis_of_Point2, (int)y_axis_of_Point3}, 3);
		g.setColor(Color.BLACK);
		g.drawPolygon(new int[] {(int)x_axis_of_Point1, (int)x_axis_of_Point2, (int)x_axis_of_Point3}, new int[] {(int)y_axis_of_Point1, (int)y_axis_of_Point2, (int)y_axis_of_Point3}, 3);
	}


}