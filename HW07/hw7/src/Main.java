import java.awt.Color;
import java.awt.EventQueue;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import java.awt.Font;
import java.awt.Graphics;
import javax.swing.JRadioButton;
import javax.swing.ButtonGroup;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JButton;
import java.awt.SystemColor;

public class Main {

	private JFrame frame;
	private Shape mainShape;
	private Shape innerShape;

	/**
	 * Launch the application.
	 * @param args an array of command-line arguments for the application
	 */
	
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Main window = new Main();
					window.frame.setVisible(true);
					testGivenMethods(); // Test given methods called in main for reader. You can check it from terminal.
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Test method for given homework methods.
	 */
	
	public static void testGivenMethods() {	
		Shape rr = new Rectangle(300,200,0,0);
		Shape tt = new Triangle(33);
		
		ComposedShape cs = new ComposedShape(rr,tt);
		cs.optimalFit();
		Shape [] temp;
		TestHomeworkMethods.drawAll(cs.getshapeArr());
		
		temp = TestHomeworkMethods.convertAll(cs.getshapeArr());	//Converting all shapes to polygon.
		TestHomeworkMethods.printAreas(temp);	//Printing areas on the console .
		System.out.println("Sorting shape areas increasingly..");
		TestHomeworkMethods.sortShapes(temp);	//Sorting areas increasingly..
		TestHomeworkMethods.printAreas(temp);	//Printing areas on the console .
	
	}
	
	/**
	 * Create the application.
	 */
	public Main() {
		
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setResizable(false);
		frame.setBounds(100, 100, 450, 300);
		frame.setTitle("Draw Composed Shape");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
	
		JLabel lblPleaseSelectThe = new JLabel("  Please Select The Container Shape:");
		lblPleaseSelectThe.setFont(new Font("Tahoma", Font.BOLD, 12));
		lblPleaseSelectThe.setBounds(21, 22, 336, 23);
		frame.getContentPane().add(lblPleaseSelectThe);
		
		/**
		 * Creating draw button
		 */
		final JButton NewJButton = new JButton("DRAW");
		NewJButton.setBackground(new Color(173, 216, 230));
		NewJButton.setForeground(Color.BLACK);
		NewJButton.setEnabled(false);
		NewJButton.setFont(new Font("Tahoma", Font.BOLD, 25));
		NewJButton.setBounds(25, 204, 148, 46);
		frame.getContentPane().add(NewJButton);
		
		/**
		 * Creating buttongroup for upper radiobuttons.
		 */
		final ButtonGroup containergroups = new ButtonGroup();
		
		final JRadioButton rdbtnRectangle = new JRadioButton("Rectangle");
		rdbtnRectangle.setFont(new Font("Tahoma", Font.PLAIN, 12));
		final JRadioButton rdbtnTriangle = new JRadioButton("Triangle");
		rdbtnTriangle.setFont(new Font("Tahoma", Font.PLAIN, 12));
		final JRadioButton rdbtnCircle = new JRadioButton("Circle");
		rdbtnCircle.setFont(new Font("Tahoma", Font.PLAIN, 12));
		
		//Adding upper buttons to same group.
		containergroups.add(rdbtnRectangle);
		containergroups.add(rdbtnTriangle);
		containergroups.add(rdbtnCircle);
		
		/**
		 * Creating buttongroup for upper radiobuttons.
		 */
		final ButtonGroup innergroups = new ButtonGroup();
		
		
		final JRadioButton rdbtnInnerRect = new JRadioButton("Rectangle");
		rdbtnInnerRect.setFont(new Font("Tahoma", Font.PLAIN, 12));
		final JRadioButton rdbtnInnerTri = new JRadioButton("Triangle");
		rdbtnInnerTri.setFont(new Font("Tahoma", Font.PLAIN, 12));
		final JRadioButton rdbtnInnerCircle = new JRadioButton("Circle");
		rdbtnInnerCircle.setFont(new Font("Tahoma", Font.PLAIN, 12));
		
		//Adding buttom buttons to same group.
		innergroups.add(rdbtnInnerRect);
		innergroups.add(rdbtnInnerTri);
		innergroups.add(rdbtnInnerCircle);
		
		/**
		 * Action Listener for upper rectangle radiobutton.
		 */
		rdbtnRectangle.addActionListener(new ActionListener() {	//Defining action for Container radiobutton rectangle.
			public void actionPerformed(ActionEvent e) {
				try {
					String selectionWidth = JOptionPane.showInputDialog("Please enter the width of Rectangle:");
					if(selectionWidth == null) {
						containergroups.clearSelection();
						NewJButton.setEnabled(false);
					}
					else {
						double width = Double.parseDouble(selectionWidth);
						String selectionHeight = JOptionPane.showInputDialog("Please enter the height of Rectangle:");
						if(selectionHeight == null) {
							containergroups.clearSelection();
							NewJButton.setEnabled(false);
						}
						else {
							
							double height  = Double.parseDouble(selectionHeight);
							mainShape = new Rectangle(width,height,0,0);
							if(rdbtnInnerRect.isSelected() || rdbtnInnerTri.isSelected() ||  rdbtnInnerCircle.isSelected() ) {
								NewJButton.setEnabled(true);
							}
							
						}
					}
				}
				catch(IllegalArgumentException e2) {
					JOptionPane.showMessageDialog(null ,"\nPlease enter a  valid number.", "ERROR", JOptionPane.ERROR_MESSAGE);
					containergroups.clearSelection();
					NewJButton.setEnabled(false);
				}
			}
		});
		rdbtnRectangle.setBounds(31, 68, 109, 23);
		frame.getContentPane().add(rdbtnRectangle);
		
		/**
		 * Action listener for upper triangle radiobutton.
		 */
		rdbtnTriangle.addActionListener(new ActionListener() {		//Defining action for Container radiobutton triangle.
			public void actionPerformed(ActionEvent e) {
				try {
					String selectionEdge = JOptionPane.showInputDialog("Please enter the edge of Triangle:");
					if(selectionEdge == null) {
						containergroups.clearSelection();
						NewJButton.setEnabled(false);
					}
					else {
						double edge = Double.parseDouble(selectionEdge);
						mainShape = new Triangle(edge);
						if(rdbtnInnerRect.isSelected() || rdbtnInnerTri.isSelected() ||  rdbtnInnerCircle.isSelected() ) {
							NewJButton.setEnabled(true);
						}
					}
				}
				catch(IllegalArgumentException e2) {
					JOptionPane.showMessageDialog(null ,"\nPlease enter a valid number.", "ERROR", JOptionPane.ERROR_MESSAGE);
					containergroups.clearSelection();
					NewJButton.setEnabled(false);
				}
			}
		});
		rdbtnTriangle.setBounds(140, 68, 109, 23);
		frame.getContentPane().add(rdbtnTriangle);
	
		/**
		 * Action Listener for upper Circle radiobutton.
		 */
		rdbtnCircle.addActionListener(new ActionListener() { //Defining action for Container radiobutton circle.
			public void actionPerformed(ActionEvent e) {
				try {
					String selectionRadius = JOptionPane.showInputDialog("Please enter the radius of Circle:");
					if(selectionRadius == null) {
						containergroups.clearSelection();
						NewJButton.setEnabled(false);
					}
					else {
						double radius = Double.parseDouble(selectionRadius);
						mainShape = new Circle(radius);
						if(rdbtnInnerRect.isSelected() || rdbtnInnerTri.isSelected() ||  rdbtnInnerCircle.isSelected() ) {
							NewJButton.setEnabled(true);
						}
					}
				}
				catch(IllegalArgumentException e2) {
					JOptionPane.showMessageDialog(null ,"Please enter a valid number.", "ERROR", JOptionPane.ERROR_MESSAGE);
					containergroups.clearSelection();
					NewJButton.setEnabled(false);
				}
			}
		});
		rdbtnCircle.setBounds(251, 68, 120, 23);
		frame.getContentPane().add(rdbtnCircle);
		
		
		/**
		 * Creating label for buttom buttons.
		 */
		JLabel lblPleaseSelectThe_1 = new JLabel("  Please Select The Inner Shape:");
		lblPleaseSelectThe_1.setFont(new Font("Tahoma", Font.BOLD, 12));
		lblPleaseSelectThe_1.setBounds(21, 114, 336, 23);
		frame.getContentPane().add(lblPleaseSelectThe_1);
		
		
		
		/**
		 * ActionListener for buttom rectangle radio button.
		 */
		rdbtnInnerRect.addActionListener(new ActionListener() { //Defining action for innerShape radiobutton rectangle.
			public void actionPerformed(ActionEvent e) {
				try {
					String selectionWidth = JOptionPane.showInputDialog("Please enter the width of Rectangle:");
					if(selectionWidth == null) {
						innergroups.clearSelection();
						NewJButton.setEnabled(false);
					}
					else {
						double width = Double.parseDouble(selectionWidth);
						String selectionHeight = JOptionPane.showInputDialog("Please enter the height of Rectangle:");
						if(selectionHeight == null) {
							innergroups.clearSelection();
							NewJButton.setEnabled(false);
						}
						else {
							double height  = Double.parseDouble(selectionHeight);
							innerShape = new Rectangle(width,height,0,0);
							if(rdbtnRectangle.isSelected() || rdbtnTriangle.isSelected() || rdbtnCircle.isSelected()) {
								NewJButton.setEnabled(true);
							}
						}
					}
				
				}
				catch(IllegalArgumentException e2) {
					JOptionPane.showMessageDialog(null ,"\nPlease enter valid number.", "ERROR", JOptionPane.ERROR_MESSAGE);
					innergroups.clearSelection();
					NewJButton.setEnabled(false);
				}
			}
		});
		rdbtnInnerRect.setBounds(31, 164, 109, 23);
		frame.getContentPane().add(rdbtnInnerRect);
		
		
		/**
		 * ActionListener for buttom triangle radiobutton.
		 */
		rdbtnInnerTri.addActionListener(new ActionListener() {	//Defining action for innerShape radiobutton triangle.
			public void actionPerformed(ActionEvent e) {
				try {
					String selectionEdge = JOptionPane.showInputDialog("Please enter the edge of Triangle:");
					if(selectionEdge == null) {
						innergroups.clearSelection();
						NewJButton.setEnabled(false);
					}
					else {
						double edge = Double.parseDouble(selectionEdge);
						innerShape = new Triangle(edge);
						if(rdbtnRectangle.isSelected() || rdbtnTriangle.isSelected() || rdbtnCircle.isSelected()) {
							NewJButton.setEnabled(true);
						}
					}
				}
				catch(IllegalArgumentException e2) {
					JOptionPane.showMessageDialog(null ,"\nPlease enter a valid number.", "ERROR", JOptionPane.ERROR_MESSAGE);
					innergroups.clearSelection();
					NewJButton.setEnabled(false);
				}
			}
		});
		rdbtnInnerTri.setBounds(140, 164, 109, 23);
		frame.getContentPane().add(rdbtnInnerTri);
		
		
		/**
		 * ActionListener for buttom circle radiobutton. 
		 */
		rdbtnInnerCircle.addActionListener(new ActionListener() {	//Defining action for innerShape radiobutton circle.
			public void actionPerformed(ActionEvent e) {
				try {
					String selectionRadius = JOptionPane.showInputDialog("Please enter the radius of Circle:");
					if(selectionRadius == null) {
						innergroups.clearSelection();
						NewJButton.setEnabled(false);
					}
					else {
						double radius = Double.parseDouble(selectionRadius);
						innerShape = new Circle(radius);
						if(rdbtnRectangle.isSelected() || rdbtnTriangle.isSelected() || rdbtnCircle.isSelected()) {
							NewJButton.setEnabled(true);
						}
					}
				}
				catch(IllegalArgumentException e2) {
					JOptionPane.showMessageDialog(null ,"Please enter a valid number.", "ERROR", JOptionPane.ERROR_MESSAGE);
					innergroups.clearSelection();
					NewJButton.setEnabled(false);
				}
			}
		});
		rdbtnInnerCircle.setBounds(251, 164, 120, 23);
		frame.getContentPane().add(rdbtnInnerCircle);
	
		/**
		 * creating  Clear Selections button
		 */
		JButton btnNewButton = new JButton("Clear Selections");
		/**
		 * Action Listener for Clear Selections Button
		 */
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				containergroups.clearSelection();
				innergroups.clearSelection();
				NewJButton.setEnabled(false);
			}
		});
		btnNewButton.setForeground(new Color(255, 255, 255));
		btnNewButton.setBackground(SystemColor.activeCaption);
		btnNewButton.setFont(new Font("Tahoma", Font.PLAIN, 15));
		btnNewButton.setBounds(224, 214, 200, 31);
		frame.getContentPane().add(btnNewButton);
		
		/**
		 * Action Listener for DRAW button.
		 */
		NewJButton.addActionListener(new ActionListener() {	//This is an action for JBUTTON ( DRAW ) .
			public void actionPerformed(ActionEvent e) {
				try {
					if((rdbtnCircle.isSelected() && rdbtnInnerTri.isSelected()) || (rdbtnCircle.isSelected() && rdbtnInnerRect.isSelected())) {
						JOptionPane.showMessageDialog(null ,"These two shapes cannot combine!!", "ERROR", JOptionPane.ERROR_MESSAGE); // Triangle in Circle and Rectangle in Circle not supported in my code.
					}
					else {
						final ComposedShape cs = new ComposedShape(mainShape,innerShape);
						cs.optimalFit();
						JFrame shapeframe = new JFrame();
						shapeframe.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
						shapeframe.setTitle("Composed Shape");
						if(cs.getshapeArr()[0] instanceof Rectangle) {
							Rectangle r = (Rectangle) cs.getshapeArr()[0];
							shapeframe.setSize((int)r.getWidth()+25,(int)r.getHeight()+45);
							
						}
						else if(cs.getshapeArr()[0] instanceof Triangle) {
							Triangle t = (Triangle) cs.getshapeArr()[0];
							shapeframe.setSize((int)t.getEdge_of_Triangle()+20,(int)t.getEdge_of_Triangle());
						}
						else if(cs.getshapeArr()[0] instanceof Circle) {
							Circle c = (Circle) cs.getshapeArr()[0];
							shapeframe.setSize((int)c.getRadius()*2+20,(int)c.getRadius()*2+40);
						}
						
						shapeframe.setVisible(true);
						/**
						 * Creating drawing panel.
						 */
						JPanel drawingpanel = new JPanel(true) {
							/**
							 * 
							 */
							private static final long serialVersionUID = 1L;

							@Override
							public void paintComponent(Graphics g) {
								super.paintComponent(g);
								cs.draw(g);
				            }
						};
						
						shapeframe.getContentPane().add(drawingpanel);
					}
				}
				catch(IllegalArgumentException e2) {
					JOptionPane.showMessageDialog(null ,e2.getMessage() , "ERROR", JOptionPane.ERROR_MESSAGE);
				}
				
			}
		});
		
	}
}
