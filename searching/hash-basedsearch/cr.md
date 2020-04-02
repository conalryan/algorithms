Hash-Based Search
================================================================================
Best, Average: O(1) Worst: O(n)

The previous sections on searching are appropriate when there are a small number of elements (Sequental Search) or
the collection is already ordered (Binary Search).

We need more powerful techniques for searching larger collections that are not necessarily ordered.
One of the most common approaches is to use a `hash function` to transform one or more characters
of the searched-for iterm into an index into a hash table.

*Hash-Based Search* hash better average-case performance than the other search algorithms described in this chapter.

Hash-Based Search often covered under `hash tables` or data strucutes and hash tables.

In Hash-Based Search the n elements of a collection C  are filrst loaded into a hash table H with b bins strucuted as an array.

This preprocessing step has O(n) performance, but improves the performance of future searches.

A `hash function` is deterministic function that maps each element Ci to an integer value Hi.
Once all elements have been inserted, searching for an item t becomes a search for t within H[hash(t)].

A hash function guarantees only that if two elements Ci and Cj are equal, hash(Ci) = hash(Cj).
It can happen that multiple elements in C have the same hash value; this is known as a collision
and the hash table needs a strategy to deal with these situations.
the most common solution is to store a linked list at each hash index (even though many of these
linked lists may contain only one element), so all colliding values can be stored in the hash table.
The linked liss have to be searched linearly, but this will be quick because each is likely to store at most a few elements.

Components of Hash-Based Search:
- A set U that defines the set of possible hash values. Each element e in C collection maps to a hash value h ~ U
- A hash table, H, containing b bins that store the n elements from the original collection C
- The has function, hash, which computes an integer value h for every element e, where O <= h < b

The information is stored in memory using arrays and linked lists.

Hash-Based Search raises two main converns: the design of the hash function and how to handle collisions.
A poorly chosen hash function can leave keys poorly distributed in the primary storage, with consequences:
(a) many bins in the hash table may be unused, wasting space
(b) there will be collisions that force many keys into the same bin, which worsens search performance.

Input/Output
--------------------------------------------------------------------------------
Unlike Binary Search, the original collection C does not need to be ordered for Hash-Based Search.
Indeed, even if the elements in C were ordered in some way, the hashing method that inserts elements into
the hash table H does not attempt to replicate this ordering within H.

The input to Hash-Based Search is the computed hash table, H, and the target element t being sought.
The algorithm returns true if t exists in the linked list stored by H[h] where h = hash(t).
If t does not exist within the linked list stored by H[h], false is returned to indicate t is not present in H
and thus, does not exist in C.

Context
--------------------------------------------------------------------------------
With Hash-Based Search the number of string comparisons is based on the length of the linked lists
rather than the size of teh collection.

We first need to define the hash function. One goal is to produce as many different values as possible,
but not all values need to be unique.

Special hash functions are essential for cryptography. For searching, a hash function should have good distribution
and should be quick to computre with respect to machine cycles.

```
loadTable(size, C)
  H = new array of given size
  foreach e in C do
    h = hash(e)
    if H[h] is empty then
      H[h] = new Linked List
    add e to H[h]
  return A
end

search(H, t)
  h = hash(t)
  list = H[h]
  if list is empty then
    return false
  if list contains t then
    return true
  return false
end
```

For efficiency, this hashCode method caches the value of the computed hash to avoid 
recomputation (i.e., it computes the value only if hash is 0).
Observe that this function returns very large integers and sometimes negative values 
because the int type in Java can store only 32 bits of information.

To compute the integer bin for a given element, define hash(s) as:
`hash(s) = abs(hashCode(s)) % b`
where `abs` is the absolute value function add % is the modulo operator that returns
the remainder when dividing by b. Doing so ensures the computed integer is in the range[0,b].

Storage space poses another design issues.

Instead, we try to define a hash table that will contain as few empty bins as possible.
If our hash function distributes the keys evenly, we can achieve reasonable success
by selecting an array size approximately as large as the collection.

The size of H is typically chosen to be a prime number to ensure that using the % modulo operator
efficiently distributes the computed bin numbers.

A good choice in practice is 2^k - 1, even though this vlaue ins't always prime.

The elements stored in the hash table have direct effect on memory.
Since each bin stores elements in a linked list, the elemtns of the list are pointers to ojbects on the heap.
Each list has overhead storage that continas pointers to the first and last elements of the list
and, if you use the LinkedList class from the Java JDK, a significant amount of additional fields.
We could write a much simpler linked list class that provides only the necessary capabilities,
but this certainly additional cost to the implementation of Hash-Based Search.

Any an example Java hashing function waste about 500KB of memorey (assuming the size of a pointer is four bytes).
An example of 213,557 words, we require 5,005,488 bytes of memory beyond the actual string storage.
It requires approximately 3.6 times the space required for the characters in the strings.

Most of this overhead is the price fof using classes in the JDK.
The engineering trade-off must weigh the simplicity and reuse of teh classes compared to a more
complex implementation that reduces the memory usage.

When memory is at a premium, you can use one of several variations discussed later to optimzie memory usage.

The major force affecting the implementation is whether the collection is static or dynamic.
If we have a dynamic collection that requires many additions and deletions of elements,
we must choose a data structure for the hash table that optimizes these operations.

Solution
--------------------------------------------------------------------------------

