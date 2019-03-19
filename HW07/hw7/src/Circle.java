
import java.awt.Graphics;
import java.awt.Color;
// TODO: Auto-generated Javadoc
/**
*This is the Circle shape class
*This class contains all necessary
*fields and methods for Circle.
*@author Cihan.
*/
public class Circle implements Shape{

	/** Radius of circle. */
	private double radius;
	
	/** X coordinate of circle. */
	private double cx;
	/**
	*Y coordinate of circle.
	*/
	private double cy;	
	
	/** Color of circle. */
	private Color c; 

	/**
	 * No parameter constructor of Circle.
	 */
	public Circle(){
		radius = 100;
		cx = 100;
		cy = 100;
		c = Color.RED;
	}

	/**
	 * 1 parameter constructor of circle.
	 *
	 * @param r  new radius;
	 * @throws IllegalArgumentException the illegal argument exception
	 */

	public Circle(double r) throws IllegalArgumentException{
		if(r<=0){
			throw new IllegalArgumentException("Radius has an invalid value.");
		}
		else{
			radius = r;
			cx=r;
			cy=r;
			c = Color.RED;
		}
	}
	
	/**
	 * 3 parameter constructor of circle.
	 *
	 * @param r new radius.
	 * @param x new x coordinate.
	 * @param y new y coordinate.
	 * @throws IllegalArgumentException the illegal argument exception
	 */

	public Circle(double r,double x,double y) throws IllegalArgumentException{
		if(r<=0 || x<0 || y<0){
			throw new IllegalArgumentException("Radius,x or y has an invalid value.");
		}
		else{
			radius = r;
			cx = x;
			cy = y;
			c = Color.RED;
		}
	}

	/**
	* Setter for radius of circle.
	* @param r new radius.
	*/
	public void setRadius(double r){
		if(r<=0){
			throw new IllegalArgumentException("Radius has an invalid value.");
		}
		else{
			radius = r;
		}
	}
	
	/**
	* Setter for x coordinate of circle object.
	* @param newCX new x coordinate.
	*/
	public void setCx(double newCX){
		if(newCX < 0){
			throw new IllegalArgumentException("X coordinate of Circle has an invalid value.");
		}
		else{
			cx = newCX;
		}
	}

	/**
	* Setter for y coordinate of circle object.
	* @param newCY new y coordinate.
	*/
	public void setCy(double newCY){
		if(newCY < 0){
			throw new IllegalArgumentException("Y coordinate of Circle has an invalid value.");
		}
		else{
			cy=newCY;
		}
	}

	/**
	 * Setter for color of Circle.
	 *
	 * @param newColor new color.
	 */
	public void setColor(Color newColor){
		c = newColor;
	}

	/**
	 * Getter for radius of Circle object.
	 *
	 * @return the radius
	 */
	public double getRadius(){
		return radius;
	}

	/**
	 * Getter for x coordinate of circle object.
	 *
	 * @return the cx
	 */
	public double getCx(){
		return cx;
	}

	/**
	 * Getter for y coordinate of circle object.
	 *
	 * @return the cy
	 */
	public double getCy(){
		return cy;
	}

	/**
	 * Getter for color of Circle.
	 *
	 * @return the color
	 */
	public Color getColor(){
		return c;
	}
	
	/**
	 * Area of Circle object.
	 *
	 * @return the double
	 */
	public double Area(){
		return radius*radius*Math.PI;
	}

	/**
	 * Perimeter of Circle object.
	 *
	 * @return the double
	 */
	public double Perimeter(){
		return 2*Math.PI*radius;
	}

	/**
	 * This method compares shapes with respect to their areas. 
	 * @param s the s
	 * @return a negative integer, zero, or a positive integer as this object is less than, equal to, or greater than the specified object
	 */
	public int compareTo(Shape s){
		return Double.compare(Area(),s.Area());
	}


	/**
	*This method for incrementing the shape positions by 1.0.
	*/
	public void increment(){
		cx++;
		cy++;
	}

	/**
	*This method for decrementing the shape positions by 1.0.
	*/
	public void decrement(){
		cx--;
		cy--;
	}

	/**
	*This method for drawing the shape on the frame.
	*@param g this is an Graphics object. 
	*/
	public void draw(Graphics g){
		g.setColor(getColor());
		g.fillOval((int)cx-(int)radius,(int)cy-(int)radius,2*(int)radius,2*(int)radius);
		g.setColor(Color.BLACK);
		g.drawOval((int)cx-(int)radius,(int)cy-(int)radius,2*(int)radius,2*(int)radius);
	}

}