

/**
 * This is an helper iterator class for collection hierarchy.
 * @author Cihan
 * @param <E> the type of elements in this iterator.
 */
public abstract class MyIterator<E>{
	
	/**
	 * Returns true if the iteration has more elements.
	 * @return true if there is elements else false.
	 */
	abstract public boolean hasNext();
	
	/**
	 * the next element in the iteration.
	 * @return the next element in the iteration.
	 */
	abstract public E next();
	
	/**
	 * Removes from the underlying collection the last element returned by this iterator (optional operation).
	 */
	abstract public void remove();
	
	/**
	 * the previous element in the iteration.
	 * @return the previous element in the iteration.
	 */
	abstract public E previous();
	
	/** 
	 * Current position of iterator.
	 * @return position of iterator.
	 */
	abstract public int position();
	
}
