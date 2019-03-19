
/**
 * Includes test methods for reader.
 * Includes driver methods.
 * @author Cihan.
 */
public class TestClass {
	
	/**
	 * Test method for HashSet.
	 */
	public static void HashSetTest() {
		
			System.out.println("<------------------------------------------Testing String HashSet--------> ");
			HashSet<String> hs = new HashSet<String>();
			System.out.println(hs.add("cihan"));
			System.out.println(hs.add("10"));
			System.out.println(hs.add("20"));
			System.out.println("Is 'cihan' added again ? " + hs.add("cihan"));
			System.out.println("Is '10' added again ? " + hs.add("10"));
			
			HashSet<String> hs2 = new HashSet<String>();
			
			System.out.println(hs2.add("can"));
			System.out.println(hs2.add("1"));
			System.out.println(hs2.add("2"));
			
			System.out.println("Is it all added ? " + hs.addAll(hs2));
			
			System.out.println("Is hs contains 'cihan' ? " + hs.contains("cihan"));
			System.out.println("Is hs contains all  hs2 ? " + hs.containsAll(hs2));
			
			System.out.println( "Size : " + hs.size() + " (Removing 'cihan' from hs : " + hs.remove("cihan")  + ") Size : " + hs.size() );
			System.out.println("Is hs still contains 'cihan' ? " + hs.contains("cihan"));
			
			System.out.println("Retaining all hs2 elements from hs " + hs.retainAll(hs2));
			
			printContainer(hs);
			
			System.out.println("Removing all hs2 elements from hs " + hs.removeAll(hs2));
			
			printContainer(hs);
			
			System.out.println("Printing nothing because there is no element in hs." + "Size of hs : " + hs.size());
			
			hs.clear();

			System.out.println("<------------------------------------------Testing Integer HashSet--------> ");
			HashSet<Integer> intHS = new HashSet<Integer>();
			
			System.out.println(intHS.add(10));
			System.out.println(intHS.add(20));
			System.out.println(intHS.add(30));
			System.out.println(intHS.add(40));
			System.out.println("Is '40' added again ? (No duplicate) : " + intHS.add(40));
			System.out.println("Is '30' added again ? (No duplicate) : " + intHS.add(30));
			
			
			HashSet<Integer> intHS2 = new HashSet<Integer>();
			
			System.out.println(intHS2.add(50));
			System.out.println(intHS2.add(40));
			System.out.println(intHS2.add(70));
			System.out.println(intHS2.add(20));
			System.out.println(intHS2.add(10));
			System.out.println(intHS2.add(80));
			
			System.out.println("Adding all hs2 : " + intHS.addAll(intHS2));
			printContainer(intHS);
			System.out.println("Retaining all hs2 : " + intHS.retainAll(intHS2));
			
			printContainer(intHS);
			
			System.out.println( "Size : " + intHS.size() + " (Removing '40' from intHS : " + intHS.remove(40)  + ") Size : " + intHS.size() );
			
			printContainer(intHS);
			
			System.out.println("Removing all hs2 from hs if it can remove all hs2 elements from hs then it returns true else false : " + intHS.removeAll(intHS2));
			
			printContainer(intHS);
			
			System.out.println("Printing nothing because there is no element in hs." + "Size of hs : " + intHS.size());
			
			intHS.clear();
			
	}
	/**
	 * Test method for ArrayList
	 */
	public static void TestArrayList() {
			System.out.println("<------------------------------------------Testing String ArrayList--------> ");
			ArrayList<String> strArr = new ArrayList<String>();
			
			System.out.println("Creating strArr.");
			strArr.add("cihan"); strArr.add("can"); strArr.add("ayyildiz"); strArr.add("CSE"); strArr.add("241"); strArr.add("CSE"); strArr.add("241"); 
			System.out.println("We can add Duplicate element in ArrayList..");
			printContainer(strArr);
			
			ArrayList<String> strArr2 = new ArrayList<String>();
			System.out.println("Creating strArr2.");
			strArr2.add("cihan"); strArr2.add("is"); strArr2.add("testing"); strArr2.add("the"); strArr2.add("CSE"); strArr2.add("241"); strArr2.add("HW8"); 
			
			printContainer(strArr2);
			
			System.out.println("Retaining all strarr2 elements : " + strArr.retainAll(strArr2));
			
			printContainer(strArr);
			
			System.out.println("Removing all strarr2 elements from strArr : " + strArr.removeAll(strArr2));
			
			printContainer(strArr);
			
			System.out.println("Adding all strarr2 elements to strArr : " + strArr.addAll(strArr2));
			
			printContainer(strArr);
			
			System.out.println("Removing 'CSE' and 'CSE241'  from strArr : " + strArr.remove("CSE") + strArr.remove("241"));
			
			printContainer(strArr);
			
			System.out.println("strArr contains all elements of strArr2 ?  " + strArr.containsAll(strArr2));
			
			strArr.clear(); strArr2.clear();
		
			
			System.out.println("<------------------------------------------Testing Integer ArrayList--------> ");
			ArrayList<Integer> intArr = new ArrayList<Integer>();
			
			System.out.println("Creating intArr.");
			intArr.add(10); intArr.add(20); intArr.add(30); intArr.add(40); intArr.add(50); 
			System.out.println("We can add Duplicate element in ArrayList..");
			printContainer(intArr);
			
			ArrayList<Integer> intArr2 = new ArrayList<Integer>();
			intArr2.add(60); intArr2.add(70); intArr2.add(20); intArr2.add(30); intArr2.add(90);
			System.out.println("Creating intArr2.");
			printContainer(intArr2);
			
			System.out.println("AddingAll intArr2 to intArr " + intArr.addAll(intArr2));
			printContainer(intArr);
			
			System.out.println("RetainingAll intArr2 from intArr " + intArr.retainAll(intArr2));
			printContainer(intArr);
			
			System.out.println("RemoveAll intArr2 from intArr " + intArr.removeAll(intArr2));
			printContainer(intArr);
			
			System.out.println(" intArr containsAll intArr2 ?" + intArr.containsAll(intArr2));
			
			System.out.println("Removing 20 and 30 from the intArr " + intArr.remove(20) + intArr.remove(30));
			printContainer(intArr);
			
			System.out.println("Printing nothing because there is no element in arraylist." + "Size of intArr : " + intArr.size());
			
			intArr.clear();
	}
	
	/**
	 * Test method for LinkedList.
	 */
	public static void TestLinkedList() {
		System.out.println("<------------------------------------------Testing String LinkedList--------> ");
		
		LinkedList<String> list1 = new LinkedList<String>();
		System.out.println("Creating list1..");
		list1.add("cihan");	 list1.add("10");	list1.add("can");	list1.add("20");
		printContainer(list1);
		
		LinkedList<String> list2 = new LinkedList<String>();
		System.out.println("Creating list2..");
		list2.offer("cihan");	 list2.offer("300");	list2.offer("can");	list2.offer("400");
		printContainer(list2);
		
		System.out.println("Adding all list2 to list1 : " + list1.addAll(list2));
		printContainer(list1);
		
		System.out.println("What is the first element ? : " + list1.element());
		System.out.println("Retrieve first element and delete it : " + list1.poll());
		printContainer(list1);
		
		System.out.println("Retaining all list2 to list1 : " + list1.retainAll(list2));
		printContainer(list1);
		
		System.out.println("Removing all list2 from list1 : " + list1.removeAll(list2));
		printContainer(list1);
		
		System.out.println("list 1 containsAll list 2 ? " + list1.containsAll(list2));
		
		System.out.println("list1 contains 'can' ?  " + list1.contains("can"));
		
		System.out.println("Remove 'can' from list1 : " + list1.remove("can"));
		printContainer(list1);
		
		System.out.println("<------------------------------------------Testing Integer LinkedList--------> ");
		
		LinkedList<Integer> intlist1 = new LinkedList<Integer>();
		System.out.println("Creating intlist1..");
		intlist1.add(10);	 intlist1.add(20);	intlist1.add(30);   intlist1.add(40); intlist1.add(50);
		printContainer(intlist1);
		
		LinkedList<Integer> intlist2 = new LinkedList<Integer>();
		System.out.println("Creating intlist2..");
		intlist2.offer(60);	 intlist2.offer(70);	intlist2.offer(80);   intlist2.offer(90); intlist2.offer(50);
		printContainer(intlist2);
		
		System.out.println("Adding all list2 to list1 : " + intlist1.addAll(intlist2));
		printContainer(intlist1);
		
		System.out.println("What is the first element ? : " + intlist1.element());
		System.out.println("Retrieve first element and delete it : " + intlist1.poll());
		printContainer(intlist1);
		
		System.out.println("Retaining all list2 to list1 : " + intlist1.retainAll(intlist2));
		printContainer(intlist1);
		
		System.out.println("Removing all list2 from list1 : " + intlist1.removeAll(intlist2));
		printContainer(intlist1);
		
		System.out.println("list 1 containsAll list 2 ? " + intlist1.containsAll(intlist2));
		
		System.out.println("list 1 contains 50 ? " + intlist1.contains(50));
		

	}

	
	/**
	 * This method prints elements of container.
	 * @param c a container.
	 */
	public static <E> void printContainer(Collection<E> c) {
		
		MyIterator<E> printit = c.iterator();

		System.out.print(" - Printing Container - :  ");
		while(printit.hasNext()) {
			System.out.print(printit.next() + " ");
		}
		System.out.println();
	}
	
	
}
