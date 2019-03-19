import java.util.NoSuchElementException;

/**
 * Queues order elements in a FIFO (first-in-first-out) manner. There is no random access with this Collection.
 * Some methods throw exceptions.
 * Extends all collection methods Also it has its methods.
 * @author Cihan
 * @param <E> the type of elements in this collection.
 */
public interface Queue<E> extends Collection<E> {
	
	
	public boolean add(E e);
	
	/**
	 * Retrieves, but does not remove, the head of this queue.
	 * @return  the head of this queue.
	 */
	public E element();
	
	/**
	 * Inserts the specified element into this queue.
	 * @param e the element to add
	 * @return true if the element was added to this queue, else false
	 */
	public boolean offer(E e);
	
	/**
	 * Retrieves and removes the head of this queue, or throws an exception if this queue is empty.
	 * @return the head of this queue.
	 */
	public E poll() throws NoSuchElementException;
	
	public MyIterator<E> iterator();
	
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
