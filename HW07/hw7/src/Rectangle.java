
import java.awt.Graphics;
import java.awt.Color;
/**
*	This is the Rectangle shape class.
*	This class contains all necessary
*	fields and methods for Rectangle.
*	@author Cihan.
*/

public class Rectangle implements Shape{
	/**
	*Width of Rectangle.
	*/
	private double width;
	/**
	*Height of Rectangle.
	*/
	private double height;
	/**
	*X coordinate  of Rectangle.
	*/
	private double x;
	/**
	*Y coordinate  of Rectangle.
	*/
	private double y;

	/**
	*Color of Rectangle.
	*/
	private Color c;

	/**
	*No parameter constructor of Rectangle.
	*/

	public Rectangle(){
		width=100;
		height=100;
		x=0;
		y=0;
		c = Color.RED;
	}

	/**
	*4 parameter constructor of Rectangle.
	*Setting all fields of rectangle in this constructor.
	*@param w New width.
	*@param h New width.
	*@param newX New x coordinate.
	*@param newY New y coordinate.
	*/
	public Rectangle(double w,double h,double newX,double newY) throws IllegalArgumentException{
		if(w<=0 || h<= 0 || newX<0 || newY<0){
			throw new IllegalArgumentException("Width,height,x or y has an invalid value.");
		}
		else{
			width=w;
			height=h;
			x=newX;
			y=newY;
			c = Color.RED;
		}
	}

	/**
	*Setter for width
	*@param w new width.
	*/

	void setWidth(double w) throws IllegalArgumentException{
		if(w <= 0){
			throw new IllegalArgumentException("Width has an invalid value.");
		}
		else{
			width=w;
		}
	}

	/**
	*Setter for height.
	*@param h new height.
	*/
	void setHeight(double h) throws IllegalArgumentException{
		if(h <= 0){
			throw new IllegalArgumentException("Height has an invalid value.");
		}
		else{
			height=h;
		}
	}

	/**
	*Setter for X coordinate.
	*@param newX new X coordinate.
	*/
	void setX(double newX) throws IllegalArgumentException{
		if( newX < 0){
			throw new IllegalArgumentException("Rectangle X-axis has an invalid value.");
		}
		else{
			x = newX;
		}
	}

	/**
	*Setter for Y coordinate.
	*@param newY new Y coordinate.
	*/

	void setY(double newY) throws IllegalArgumentException{
		if( newY < 0){
			throw new IllegalArgumentException("Rectangle Y-axis has an invalid value.");
		}
		else{
			y = newY;
		}
	}

	/**
	*Setter for color of Rectangle
	*@param newColor new color.
	*/
	public void setColor(Color newColor){
		c = newColor;
	}

	/**
	*Getter for rectangle width.
	*@return width of rectangle.
	*/
	public double getWidth(){
		return width;
	}

	/**
	*Getter for rectangle height.
	*@return height of rectangle.
	*/
	public double getHeight(){
		return height;
	}

	/**
	*Getter for rectangle X coordinate.
	*@return x coordinate of rectangle.
	*/

	public double getX(){	
		return x;
	}

	/**
	*Getter for rectangle Y coordinate.
	*@return y coordinae of rectangle.
	*/

	public double getY(){
		return y;
	}

	/**
	*Getter for color of Rectangle.
	*@return color of rectangle.
	*/
	public Color getColor(){
		return c;
	}

	/**
	*Method for getting Area of Rectangle.
	*@return area of rectangle.
	*/
	public double Area(){
		return width*height;
	}

	/**
	*Method for getting Perimeter of Rectangle.
	*@return perimeter of rectangle.
	*/
	public double Perimeter(){
		return 2*(width+height);
	}

	/**
	*This method compares shapes with respect to their areas.
	*@param s shape object
	*@return a negative integer, zero, or a positive integer as this object is less than, equal to, or greater than the specified object
	*/
	public int compareTo(Shape s){
		return Double.compare(Area(),s.Area());
	}

	/**
	*This method for incrementing the shape positions by 1.0.
	*/
	public void increment(){
		x++;
		y++;
	}

	/**
	*This method for decrementing the shape positions by 1.0.
	*/
	public void decrement(){
		x--;
		y--;
	}

	 /**
	 *This method for drawing the shape on the frame.
	 * @param g graphics object.
	 * This function draws the polygon to panel
	 * We will call this function in paintcomponent.
	 */
	public void draw(Graphics g){
		g.setColor(getColor());
		g.fillRect((int)getX(),(int)getY(),(int)getWidth(),(int)getHeight());
		g.setColor(Color.BLACK);
		g.drawRect((int)getX(),(int)getY(),(int)getWidth(),(int)getHeight());

	}
	

}