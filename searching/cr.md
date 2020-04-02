Searching
================================================================================

Given a collection C of elements, there are two fundamental queries:
1. Existence: Does C contain a target element?
2. Associatve lookup: Return information associated in collection C with a taret key value k.
A key is usually associated with a complex structure called a value.
The lookup retrieves or replaces this value.

Sorting improves the performance of queries, but there are other costs involved in maintaining a sorted collection,
especially when elements are frequently inserted or deleted.

Algorith guideline:

*Small collections* -> *Sequential Search* 
Sequential Search offers the simplest implementation and is implemented as a basic construct in many programming languages.
Use this algorithm when the collection is available only sequentially, as with an iterator.

*Restricted memory* -> *Binary Search*
When the collection is an array that doesn't change and you want to conserve memory, use Binary Search.

*Dynamic membership* -> *Hash-Based Search* or *Binary Search Tree*
If the elements in the collection change frequently, consider Hash-Based Search
and Binary Search Tree for their ability to spread out the costs assocated with maintaining their data structures.

*Sorted access* -> *Binary Search Tree*
Use Binary Search Tree when you need dynamic membership and the ability to process elements in the collection in sorted order.


Sequential Search

Binary Search

Hash-Based Search

Bloom Filter

Bineary Search Tree
