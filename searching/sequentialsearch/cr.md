Sequential Search
================================================================================
Best: O(1), Average, Worst: O(n) Linear

Also called linear search, is the simplest of all searching algorithms.
It is a brute-force approach to locate a singel target value, t, in a collection, C.
It finds t by starting at the first element fo the collection and examingin each subsequent element until
it runs out of elements or it finds a matching element.

Often the elements of a collection C can be accessed only with a read-only iterator that retrieve each 
element from C, as, for example, a database cursor in response to an SQL query.

Input/Output
--------------------------------------------------------------------------------
The input consists of a nonempty collection, C, of n > 0 elements and a target value, t, that is sought.
The search will return true if C contains t and false otherwise.

```
search(A, t)
  for l = 0 to n - 1 do
    if A[i] = t then
      return true
  return false
end

search(C, t)
  iter = c.begin()
  while iter != c.end() do
    e = iter.next()
    if e = t then
      return true
  return false
end
```

Context
--------------------------------------------------------------------------------
You frequently need to locate an element in a collection that may or may not be ordered.
With no further knowledge about the information that might be in the collection,
Sequential Search gets the job done in a brute-force manner. 

It is the only search algorithm you can use if the collection is accessible only through an iterator.

If the collection is unordered and stored as a linked list, inserting an elementing is a 
constant time operation (simply append it to the end of the list).

Frequent insertions into an array-based collection required dynamic array management,
which is either provided by the underlying programming language or requires specific attention by the programmer.

In both cases, the expected time to find an element is O(n); thus, removing and elements takes at least O(n).

Sequential Search places the fewest restrictions on the type of elements you can search.
The only requirement is the presence of a martch function to determine whether the target element being searched for matches an elementin the collection;

Solution
--------------------------------------------------------------------------------
Often the implementation of Sequential Search is trivial.

```python
def sequentialSearch(collection, t):
  for e in collection:
    if e == t:
      return True
  return False
```

```java
public class SequentialSearch<T> {

  public boolean search(T[] collection, T t) {
    for (T item : collection) {
      if (item.equals(t)) {
        return true;
      }
    }
    return false;
  }

  public boolean search(Iterable<T> collection, T t) {
    Iterator<T> iter = collection.iterator();
    while (iter.next().equals(t)) {
      if (iter.next().equals(t)) {
        return true;
      }
    }
    return false;
}
```
