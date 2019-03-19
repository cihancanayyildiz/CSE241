
/**
 * An ordered collection (also known as a sequence).
 * @author Cihan
 * @param <E> the type of elements in this collection.
 */
public interface List<E> extends Collection<E> {

	/**
	 * Extends all Collection class's methods.
	 */
	
	public MyIterator<E> iterator();
	
	public boolean add(E e);
	
	public boolean addAll(Collection<E> c);
	
	public void clear();
	
	public boolean contains(E e);
	
	public boolean containsAll(Collection<E> c);
	
	public boolean isEmpty();
	
	public boolean remove(E e);
	
	public boolean removeAll(Collection<E> c);
	
	public boolean retainAll(Collection<E> c);
	
	public int size();
	 
}
