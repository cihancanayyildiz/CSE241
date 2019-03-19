
import java.awt.Graphics;
import java.awt.Color;
/**
*This is the Polygon shape abstract class
*@author Cihan.
*/
public abstract class Polygon implements Shape{
	/**
	*This is the Point2D inner class
	*This class holding x and y coordinate for polygons.
	*@author Cihan
	*/
	public static class Point2D{
		/**
		*Point2D x coordinate field.
		*/
		private double x;

		/**
		*Point2D y coordinate field.
		*/
		private double y;

		/**
		*No parameter constructor for point2d class.
		*/
		public Point2D(){
			x=0;
			y=0;
		}

		/**
		*Double parameter constructor for point2d class.
		*@param xvalue new x coordinate.
		*@param yvalue new y coordinate.
		*/
		public Point2D(double xvalue,double yvalue) throws IllegalArgumentException{
			if( xvalue < 0 || yvalue < 0){
				throw new IllegalArgumentException("Point2D : x or y has an invalid value.");
			}
			else{
				x = xvalue;
				y = yvalue;
			}
		}

		/**
		*Setter for x coordinate of point2D
		*@param xvalue new x coordinate.
		*/

		public void setX(double xvalue) throws IllegalArgumentException{
			if(xvalue < 0){
				throw new IllegalArgumentException("Point2D : x  has an invalid value.");
			}
			else{
				x = xvalue;
			}
		}

		/**
		*Setter for y coordinate of point2D
		*@param yvalue new y coordinate.
		*/
		public void setY(double yvalue) throws IllegalArgumentException{
			if(yvalue < 0){
				throw new IllegalArgumentException("Point2D :  y has an invalid value.");
			}
			else{
				y = yvalue;
			}
		}

		/**
		*Getter for x coordinate of point2D
		*@return x value of point2d.
		*/
		public double getX(){
			return x;
		}

		/**
		*Getter for y coordinate of point2D
		*@return y value of point2d.
		*/
		public double getY(){
			return y;
		}

		/**
		*Overriding toString function for this class
		*For getting information about point.
		*/
		public String toString(){
			return String.format("(%.2f,%.2f)",x,y);
		}

	}

	/**
	 * Color of polygon.
	 */
	protected Color color;
	
	/**
	 * Getter function for color of polygon.
	 * @return color of polygon.
	 */
	protected Color getColor(){
		return color;
	}

	/**
	 * Setter function for polygon color.
	 * @param newColor polygon's new color.
	 */
	protected void setColor(Color newColor){
		color = newColor;
	}
	
	/**
	 * No parameter constructor for polygon abstract class.
	 */
	public Polygon(){
		color = Color.RED;
	}

	@Override
	abstract public double Area();

	@Override
	abstract public double Perimeter();
	
	@Override
	abstract public int compareTo(Shape s);
	
	@Override
	abstract public void increment();

	@Override
	abstract public void decrement();

	@Override
	abstract public void draw(Graphics g);


}