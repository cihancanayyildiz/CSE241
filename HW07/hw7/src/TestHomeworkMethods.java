
import java.awt.Graphics;
import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 * This class includes given homework methods..
 * @author Cihan.
 */
public class TestHomeworkMethods{
	
	
	/**
	 * This method converts all shapes to Polygons.
	 * @param newArr current shape array.
	 * @return new shape array.
	 */

	public static Shape[] convertAll(Shape[] newArr){

		Shape [] temparr = new Shape[newArr.length];

		for(int i=0 ; i<newArr.length ;i++){
			if(newArr[i]==null){
				break;
			}
			if(newArr[i] instanceof Circle){
				Circle circle = (Circle)newArr[i];
				PolygonDyn p = new PolygonDyn(circle);
				temparr[i] = p;
			}
			else if(newArr[i] instanceof Rectangle){
				Rectangle rect = (Rectangle)newArr[i];
				PolygonVect p = new PolygonVect(rect);
				temparr[i] = p;
			}
			else if(newArr[i] instanceof Triangle){
				Triangle tri = (Triangle)newArr[i];
				PolygonDyn p = new PolygonDyn(tri);
				temparr[i] = p;
			}
		}

		return temparr;
	}
	
	/**
	 * This method draws all shapes that in newArr.
	 * @param newArr Current shape array.
	 */

	public static void drawAll(final Shape[] newArr){

		JPanel panel = new JPanel(true) {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			@Override
			public void paintComponent(Graphics g) {
				super.paintComponent(g);
				for(int i=0;i<newArr.length;i++){
					if(newArr[i]==null){
						break;
					}
					newArr[i].draw(g);
				}	
            }
		};

		JFrame mainframe = new JFrame();
		
		mainframe.setTitle("drawAll method frame");

		mainframe.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

		/**
		 * Setting size for mainframe.
		 */
		if(newArr[0] instanceof Rectangle) {
			Rectangle r = (Rectangle) newArr[0];
			mainframe.setSize((int)r.getWidth()+25,(int)r.getHeight()+45);
		}
		else if(newArr[0] instanceof Triangle) {
			Triangle t = (Triangle) newArr[0];
			mainframe.setSize((int)t.getEdge_of_Triangle()+20,(int)t.getEdge_of_Triangle());
		}
		else if(newArr[0] instanceof Circle) {
			Circle c = (Circle) newArr[0];
			mainframe.setSize((int)c.getRadius()*2+20,(int)c.getRadius()*2+40);
		}

		mainframe.add(panel);

		mainframe.setVisible(true);

	}
	
	/**
	 * This method sorts areas of shapes that in newArr increasingly.
	 * @param newArr Current shape array.
	 */
	
	public static void sortShapes(Shape[] newArr) {
		int min;
		Shape temp;

		for(int i=0;i<newArr.length;i++){
			
			min = i;
			for(int j=i+1;j<newArr.length;j++){
				if(newArr[j].compareTo(newArr[min]) < 0 ){
					min = j;
				}
			}
			if(min!=i){
				temp = newArr[min];
				newArr[min]=newArr[i];
				newArr[i] = temp;
			}

		}

	}
	
	/**
	 * This method prints areas of shapes that in newArr.
	 * Created for checking areas.
	 * @param newArr Current shape array.
	 */
	public static void printAreas(Shape[] newArr) {
		for(int i=0;i<newArr.length;i++) {
			System.out.printf(" %.2f ,",newArr[i].Area());
		}
		System.out.println();
	}

}