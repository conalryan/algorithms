Binary Search
================================================================================
Best: O(1), Average, Worst: O(log n)

Binary Search delivers better performance than Sequential Search because it starts with a collection whose elements are already sorted.
i
Binary Search divides the sorted collection in half until the sought-for itme is found,
or until it is determined that the item does not exist in the collection.

Input/Output
--------------------------------------------------------------------------------
The input to Binary Search is an indexed collection A whose elements are totally ordered,
which means that given two index positions, i and j, A[i] < A[j] if and only if i < j.

We construct a data structure that holds the elements (or pointers to the elements)
and preserve the ordering of the keys.

The output to Binary Search is either true or false.

Context
--------------------------------------------------------------------------------
When searching through the ordered collection, a logarithmic number of probes is necessary in the worst case.

Different types of data structures support binary searching. If the collection never changes,
the elemetns should be placed into an array. This makes it easy to navigate through the collection.
However, if you need to add or remove elements from the collection, the approach becomes unwieldy.
There are several structures we can use; one of the best known is the binary search tree.

```
search(A, t)
  low = 0
  high = n-1
  while low <= high do
    mid = (low + high)/2
    if t < A[mid] then
      high = mid - 1
    else if t > A[mid] then
      low = mid + 1
    else
      return true
  return false
end
```

```java
public class BinarySearch<T extends Comparable<T>> {
  if (target == null) { return false; }

  int low = 0, high = collection.length - 1;
  while (low <= high) {
    int mid = (low + high)/2;
    int rc = target.compareTo(collection[mid]);
    if (rc < 0) {
      high = mid - 1;
    } else if (rc > 0) {
      low = mid + 1;
    } else {
      return true;
    }
  }
  return false;
}
```

Solution
--------------------------------------------------------------------------------
Binary Search adds a small amount of complexity for large performance gains.

The complexity can increase when the collection is not stored in a simple in-memory data strucutre, such as an array.

A large collection might need to be kept in secondary storage, such as a file on a disk.

In such a case, the ith element is accessed by its offset location within the file.

Using secondary storage, the time required to search for an element is dominated by the costs to access the storage;
other solutinos related to Binary Search may be appropriate.

Analysis
--------------------------------------------------------------------------------
Binary Search divides the problem size approximately in half every time it executes the loop.
The maximum number of times the collectin of size n is cut in half is 1 + log(n).
If we use a single operation to determine wheher two items are equal, lesser than,
or greater than (as is made possible by the Comparable interface(,
only 1 + log(n) comparisons are needed, resulting in a classification of O(log n).

Note the performance of the search increases by a fixed amount as n doulbes in size,
a clear indication that the performance of Binary Search is O(log n)

Variations
--------------------------------------------------------------------------------
To support a "search-or-insert" operation, observe that all valid array indices are non-negative.
Some alternatives will return a negative number p if searching for a target element not contained in the ordered array,.

The value -(p + 1) is the index position where target should be inserted.

Python search-or-insert variation
```python
def bs_contains(ordered, target):
    """Return index of target in ordered or -(p+1) where to insert it."""

    low = 0
    high = len(ordered)-1
    while low <= high:
        mid = (low + high) // 2
        if target < ordered[mid]:
            high = mid-1
        elif target > ordered[mid]:
            low = mid+1
        else:
            return mid

    return -(low + 1)

def bs_insert(ordered, target):
    """Inserts target into it proper location if not already present."""
    idx = bs_contains(ordered, target)
    if idx < 0: 
        ordered.insert(-(idx + 1), target)
```

Inserting into or deleting from an ordered array becomes inefficient as the size of the array grows,
because every array entry must contain a valid element.

Therefore, inserting involves extending the array (physically or logically) and pushing, on average,
half of the elements ahead one index position.

Deletion requires shrinking the array and moving half of the elements one index position lower.

