
public class Main {
	
	public static void  main(String[] args) {
		try {
			TestClass.HashSetTest();
			TestClass.TestArrayList();
			TestClass.TestLinkedList();
		}
		catch(Exception e) {
			System.out.println(e);
		}
		finally {
			System.out.println("Try catch block ended.");
		}
	
	}
}
