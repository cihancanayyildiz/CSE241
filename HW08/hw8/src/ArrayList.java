/**
 * ArrayList class.
 * @author Cihan
 * @param <E> the type of elements in this collection.
 */
public class ArrayList<E> implements List<E> {
	/**
	 * Array of elements E;
	 */
	private E[] elements;
	/**
	 * Size of array that includes element.
	 */
	private int size=0;
	
	private double sizeFactor = 0.75;
	
	/**
	 * No parameter constructor.
	 */
	@SuppressWarnings("unchecked")
	public ArrayList(){
		elements = (E[]) new Object[8];
	}
	/**
	 * One parameter constructor.
	 * @param capacity capacity of array.
	 */
	@SuppressWarnings("unchecked")
	public ArrayList(int capacity) {
		elements = (E[]) new Object[capacity];
	}
	
	@Override
	public MyIterator<E> iterator() {
		return new MyIterator<E>() {
			int index = 0;
			
			@Override
			public boolean hasNext() {
				if(index < size) {
					return true;
				}
				return false;
			}
			
			@Override
			public E next() {
				return elements[index++];
			}
			
			@Override
			public E previous() {
				return elements[index--];
			}
			
			@Override
			public int position() {
				return index;
			}
			
			@Override
			public void remove() {
				ArrayList.this.remove(elements[index]);
			}
		};
	}

	@Override
	public boolean add(E e) {
		MyIterator<E> myiter = this.iterator();
		
		while(myiter.hasNext()) { // Checking next.
			myiter.next();
		}
		
		if(shouldGrowArrayList(elements)) {	//Checking for size and growing up the set.
				growArray();
		}
		elements[size] = e;
		size++;
		
		return true;
	}

	@Override
	public boolean addAll(Collection<E> c) {
		MyIterator<E> otherIter = c.iterator();

		if(c.isEmpty()){
			return false;
		}

		while(otherIter.hasNext()){
			add(otherIter.next());
		}

		return true;
	}

	@Override
	public void clear() {
		size = 0;
	}

	@Override
	public boolean contains(E e) {
		MyIterator<E> iter = iterator();

		while(iter.hasNext()){
			if(iter.next()== e){
				return true;
			}
		}

		return false;
	}

	@Override
	public boolean containsAll(Collection<E> c) {
		MyIterator<E> otherIter = c.iterator();

		boolean res=true;

		while(otherIter.hasNext()){
			if(!(contains(otherIter.next()))){
				res = false;
			}
		}

		return res;
	}

	@Override
	public boolean isEmpty() {
		return size==0;
	}

	@Override
	public boolean remove(E e) {
		MyIterator<E> removeIt = this.iterator();
		
		boolean res = false;
		
		while(removeIt.hasNext()) {
			if(removeIt.next().equals(e)) {
				res = true;
				break;
			}
		}
		
		if(res) {
			for(int i=removeIt.position();i<size;i++) {
				elements[i-1] = elements[i];
			}
			size--;
		}
		return res;
	}

	@Override
	public boolean removeAll(Collection<E> c) {
		
		if(c.isEmpty()){
			return false;
		}
		boolean res=true;
		
		MyIterator<E> otherIter = c.iterator(); // iterator for incoming collection.

		while(otherIter.hasNext()){
			if(!(remove(otherIter.next()))){
				res=false;
			}
		}
		
		return res;
	}

	@Override
	public boolean retainAll(Collection<E> c) {
		MyIterator<E> myIter = iterator();
		HashSet<E> temp = new HashSet<E>();	 // creating a temp hashset.

		while(myIter.hasNext()){
			if( !(c.contains(myIter.next())) ){
				myIter.previous();
				temp.add(elements[myIter.position()]);
				myIter.next();
			}
		}

		if(removeAll(temp)) {
			return true;
		}
		return false;
	}

	@Override
	public int size() {
		return size;
	}
	
	
	/**
	 * Checks if the arraylist needs to grow.
	 * @param elementarray
	 * @return true if it need grow else false.
	 */
	private boolean shouldGrowArrayList(E[] elementarray) {
		if(size > elementarray.length * sizeFactor) {
			return true;
		}
		return false;
	}
	
	/**
	 * Growing up the arraylist.
	 */
	@SuppressWarnings("unchecked")
	private void growArray() {
		
		E[] newElements = (E[]) new Object[2*elements.length];
		
		for(int i = 0 ; i<size ; i++) {
			
			newElements[i] = elements[i];
			
		}
		
		elements = (E[]) new Object[2*elements.length];
		
		for(int i = 0 ; i<size ; i++) {
			
			elements[i] = newElements[i];
			
		}
	}
	

}
