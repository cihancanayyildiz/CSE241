
import java.awt.Graphics;

/**
 * Main Shape class for hierarchy
 * @author Cihan
 * Extends from comparable. (In homework description is excepted to be like implement but  a interface can not implement another interface. So i extend it.)
 */
public interface Shape extends Comparable<Shape>{
	
	/**
	 * Area of Shapes
	 * @return area of shape.
	 */
	double Area();

	/**
	 * Area of Shapes
	 * @return area of shape
	 */
	double Perimeter();
	
	/**
	 *@param s Shape object.
	 *@return a negative integer, zero, or a positive integer as this object is less than, equal to, or greater than the specified object
	 */
	int compareTo(Shape s);

	/**
	 * increments positions by 1.
	 */
	void increment();

	/**
	 * Decrements positions by 1.
	 */
	void decrement();

	/**
	 * Drawing function.
	 * @param g Graphics object.
	 */
	void draw(Graphics g);

}