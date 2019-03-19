
/**
 * The root interface in the collection hierarchy.
 * @author Cihan
 *
 * @param <E> the type of elements in this collection.
 */
public interface Collection<E> {
	
	/**
	 * Returns an iterator over the elements in this collection.
	 * @return  iterator over the elements in this collection.
	 */
	public MyIterator<E> iterator();
	
	/**
	 * Ensures that this collection contains the specified element.
	 * @param e element whose presence in this collection is to be ensured.
	 * @return true if this element added to this collection.
	 */
	public boolean add(E e);
	
	/**
	 * Adds all of the elements in the specified collection to this collection.
	 * @param c  collection containing elements to be added to this collection.
	 * @return true if all c elements added to this collection.
	 */
	public boolean addAll(Collection<E> c);
	
	/**
	 * Removes all of the elements from this collection.
	 */
	public void clear();
	
	/**
	 * Returns true if this collection contains the specified element.
	 * @param e element whose presence in this collection is to be tested.
	 * @return true if this collection contains the specified element.
	 */
	public boolean contains(E e);
	
	/**
	 * Returns true if this collection contains all of the elements in the specified collection.
	 * @param c collection whose presence in this collection is to be tested.
	 * @return true if this collection contains all of the elements in the specified collection.
	 */
	public boolean containsAll(Collection<E> c);
	
	/**
	 * Returns true if this collection contains no elements.
	 * @return true if this collection contains no elements.
	 */
	public boolean isEmpty();
	
	/**
	 * Removes a single instance of the specified element from this collection, if it is present.
	 * @param e element to be removed from this collection, if present.
	 * @return true if an element was removed as a result of this call.
	 */
	public boolean remove(E e);
	
	/**
	 * Removes all of this collection's elements that are also contained in the specified collection.
	 * @param c collection containing elements to be removed from this collection.
	 * @return true if this collection changed as a result of the call.
	 */
	public boolean removeAll(Collection<E> c);
	
	/**
	 * Retains only the elements in this collection that are contained in the specified collection
	 * @param c collection containing elements to be retained in this collection
	 * @return true if this collection changed as a result of the call
	 */
	public boolean retainAll(Collection<E> c);
	
	/**
	 * Returns the number of elements in this collection.
	 * @return the number of elements in this collection.
	 */
	public int size();
	
}
