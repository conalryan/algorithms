Sorting Algorithms
================================================================================

Numerous computations and tasks become simple by properly sorting information in advance.
Indeed, much of the early research in algorithms focused on sorting collections of data
that were too large for the computers of the day to store in memory.

Representation
--------------------------------------------------------------------------------
The colelction may already be stored in the coputer's random access memory (RAM),
but it might simply exist in a file on the filesystem, known as secondary storage.
The collection may be archived in part on tertiary storage, which may require extra
processing time just to locate the information; in addition, the information may need
to be copied to secondary storage (such as hard disk drives) before it can be processed.

Information stored in RAM typically take one of two forms:
1. Pointer-based: 
An array or information contains pointers to the actual information rather than storing the information itself.
Such an approach enables arbitrarily complex records to be stored and sorted.

2. Value-based:
An array of values themselves.

Information is usually written to secondary storage as a value-based continuous collection of bytes.
Merge sort is particularly well-suited for sorting data in secondary storage.

Compariable Elements
--------------------------------------------------------------------------------
The elements in the collection must exhibit a total ordering.
Exactly one of three predicates must be true:
1. p = q
2. p < q
3. p > q

Commonly sorted primitives types include integers, floating point values, and characters.
When composite elements are sorted (such as string of characters) lexographical ordering
is imposed on each indivdual element of the composite, thus reducing a complex sort into
individual sorts on primitiex types.
 e.g. "alphabet" < "alternate" < "ant" < "anthem"

### Collation Algorithm
[Unicode Consortium](http://www.unicode.org)
has developed a sorting standard.
Handles wide varite of ordering rules found in different languages and cultures.

### Comparator Function
Returns 0 if p = q, a negative number if p < q, and a positive number if p > q.
If elements are complex records, comparator function might only compare a "key" value of the elements.

Stable Sorting
--------------------------------------------------------------------------------
Ai = Aj therfore maintain Ai < Aj in final sort.

Criteria for Choosing a Sorting Algorithm
--------------------------------------------------------------------------------
Only a few items: Insertion Sort O(n^2) Quadratic
Items are mostly sorted already: Insertion Sort O(n^2) Quadratic
Concerned about worst-case-scenarios: Heap Sort O(n log n) Linearithmic
Inserted in a good average-case behavior: Quicksort O(n log n) Linearithmic, worst-case O(n^2) Quadratic
Items are drawn from a uniform dense universe: Bucket Sort O(n) Linear
Desire to write as little code as possible: Insertion Sort O(n^2) Quadratic
Require stable sort: Merge Sort O(n log n)

Transposition Sorting
================================================================================
Early sorting algorithms found elements in the collection A that were out of place and moved them
into their proper position by transposing (or swapping) elements in A e.g. Selection Sort, Bubble Sort.

Insertion Sort O(n^2) Quadratic
================================================================================
Repeatedly invokes an insert helper function to ensure A[0-i] is properly sorted;
eventually, i reaches the rightmost element, sorting A entirely.
Best: O(n), Average, Worst: O(n^2)
```
sort(A)
  for pos = 1 to n - 1 do
    insert(A, pos, A[pos])
end

insert(A, pos, value)
  i = pos - 1
  while i >= 0 and A[i] > value do
    A[i+1] = A[i]
    i = i-1
  A[i+1] = value
end
```

Content
--------------------------------------------------------------------------------
Use Insertion Sort when you have a small nunmber of elements to sort or the elements in the
initial collection are already "nearly sorted.

Solution
--------------------------------------------------------------------------------
```c
/** Execute InsertionSort to sort the pointers in the array. */
void sortPointers (void **ar, int n, int(*cmp)(const void *, const void *)) {
  int j;
  for (j = 1; j < n; j++) {
    int i = j-1;
    void *value = ar[j];
    while (i >= 0 && cmp(ar[i], value)> 0) {
      ar[i+1] = ar[i];
      i--;
    } 
   ar[i+1] = value;
  }
}
```

```c
/** Sort the value-based array using Insertion Sort. */
void sortValues (void *base, int n, int s,
		 int(*cmp)(const void *,const void *)) {
  int j;
  void *saved = malloc (s);
  for (j = 1; j < n; j++) {
    /* start at end, work backward until smaller element or i < 0. */
    int i = j-1;
    void *value = base + j*s;
    while (i >= 0 && cmp(base + i*s, value) > 0) { i--; } 

    /* If already in place, no movement needed. Otherwise save value to be
     * inserted and move as a LARGE block intervening values.  Then insert
     * into proper position. */
    if (++i == j) continue;

    memmove (saved, value, s);
    memmove (base+(i+1)*s, base+i*s, s*(j-i));
    memmove (base+i*s, saved, s);

  }
  free (saved);
}
```

Optimal performance occurs when array is already sorted. And arrays sorted in reverse
order produce the worst performance. If array is mostly sorted than Insertion Sort performs
well because there are fewer transposition of elements.

Analysis
--------------------------------------------------------------------------------
Best case (already sorted) O(n) Linear
Average case and worst case 0(n^2) Quadratic

This may seem to be a trivial point to raise (how often are you going to sort a set of already sorted elements?),
but it is important because Insertion Sort is the only comparison-based sorting algorithm
that has this best-case-behavior.

Much real-world data is already partially-sorted, so optimism and realism might coincide
to make Insertion Sort an effective algorithm to use.

The efficiency of Insertion Sort increases when duplicate items are present, since there are fewer swaps to perform.

Each item starts on average n/3 positions in the array from its final position.

Insertion Sort operates inefficiently for value-based data because of the amount of memory
that must be shifted to make soom for a new value.

When Insertion Sort operatoes over pointer-based input, swapping elements is more efficient;
the compiler can even generate optimized code to minimize costly memory access.

Selection Sort O(n^2) Quadratic, event for best case, use Heap Sort instead
================================================================================
One common sorting strategy is to select the largest value from the range A[0, n]
and swap its location with the rightmost element A[n-1].
The process is repeated, subsequently, on each successive smaller range A[0, n - 1] until A is sorted.

```c
/** Select maximum from ar[left,right] to be used in Selection Sort. */
static int selectMax (void **ar, int left, int right,
		   int (*cmp)(const void *,const void *)) {

  int  maxPos = left;
  int  i = left;
  while (++i <= right) {
    if (cmp(ar[i], ar[maxPos])> 0) {
      maxPos = i;
    }
  } 

  return maxPos;
}

/** Sort using Selection Sort. */
void sortPointers (void **ar, int n, 
		   int(*cmp)(const void *,const void *)) {
  int i;

  /* repeatedly selectmaximum in sub-array and swap with proper position */
  for (i = n-1; i >=1; i--) {
    int maxPos = selectMax (ar, 0, i, cmp);
    if (maxPos != i) {
      void *tmp = ar[i];
      ar[i] = ar[maxPos];
      ar[maxPos] = tmp;
    }
  }
}
```

Selection Sort is the slowest of all the sorting algorithms described in this chapter;
it requires quadratic time even in the best case (i.e., when the array is already sorted).
It repeadely performs almost the same task without learning anything from one iteration to the next.
Instead of presenting more dtails on this poorly performing algorithm, we now consider Heap Sort,
which shows hot to more effectively apply the principle behind Selection Sort.

Heap Sort O(n log n) Linearithmic
================================================================================
Best, Average, Worst: O(n log n)
```
sort(A)
  buildHeap(A)
  for i = n-1 downto 1 do
    swap A[0] with A[i]
    heapify(A, 0 i)
end

buildHeap(A)
  for i = n/2-1 downto 0 do
    heapify(A, 0, i)
end

# Recursively enforce that A[idx, max] is a vaild heap
heapify(A, idx, max)
  largest = idx
  left = 2*idx + 1
  right = 2*idx + 2

  if left < max and A[left] > A[idx] then
    largest = left
  if right < max and A[right] > A[largest] then
    largest = right
  if largest != idx then
    swap A[idx] and A[largest]
    heapify(A, larget, max)
end
```

We always need at least n -1 comparisons to find the largest element in an unordered array.

A heap is a binary tree whose structure ensures two properties
1. Shape Property:
  A leaf node at depth k > 0 can exist only if all 2^k-1 nodes at depth k - 1 exist.
  Additionally, nodes at a partially filled level must be added "from left to right."
  The root node has a depth of 0.
2. Heap Property:
  Each node in the tree in the tree contains a value greater than or equal 
  to either of its two children, if it has any.

Heap Sort shows how to take advantage of the shape property to efficiently sort an array of elements.

The root is labeled 0.
For a node with label i, its left child (should it exist) is labeled 2\*i + 1;
its right child (should it exist) is labeled 2\*i + 2;
Similarly, for a non-root node labeled i, its parent node is labeled (i - 1)/2.

Heap Sort sorts an array, A by first converting that array in place into a heap.

Large numbers are eventually "lifted up" in the resulting heap (which means they are swapped in A with smaller elements to the left(.

Context
--------------------------------------------------------------------------------
Heap Sort is not a stable sort.
Heap Sort avoids many of the nasty (almost embarassing!) cases that cause Quicksort to perform badly.
Nonetheless, in the average case, Quicksort outperforms Heap Sort.

Solution
--------------------------------------------------------------------------------
```c
/** Heapify the subarray ar[0,max). */
static void heapify (void **ar, int(*cmp)(const void *,const void *),
		     int idx, int max) {
  int left = 2*idx + 1;
  int right = 2*idx + 2;
  int largest;

  /* Find largest element of A[idx], A[left], and A[right]. */
  if (left < max && cmp (ar[left], ar[idx]) > 0) {
    largest = left;
  } else {
    largest = idx;
  }

  if (right < max && cmp(ar[right], ar[largest]) > 0) {
    largest = right;
  }

  /* If largest is not already the parent then swap and propagate. */
  if (largest != idx) {
     void *tmp;

     tmp = ar[idx];
     ar[idx] = ar[largest];
     ar[largest] = tmp;
      
     heapify(ar, cmp, largest, max);
   }
}

/** Build the heap from the given array by repeatedly invoking heapify. */
static void buildHeap (void **ar, int(*cmp)(const void *,const void *),
		       int n) {
  int i;
  for (i = n/2-1; i>=0; i--) {
    heapify (ar, cmp, i, n);
  }
}

/** Sort the array using Heap Sort implementation. */
void sortPointers (void **ar, int n, 
		   int(*cmp)(const void *,const void *))
{
  int i;
  buildHeap (ar, cmp, n);
  for (i = n-1; i >= 1; i--) {
   void *tmp;
   tmp = ar[0];
   ar[0] = ar[i];
   ar[i] = tmp;

   heapify (ar, cmp, 0, i);
  }
}
```

Analysis
--------------------------------------------------------------------------------
`heapify` i the central operation in Heap Sort. In `buildHeap`, it is called n/2 -1 times,
and during the actual sort it is called n - 1 times, for a total of (3\*n/2) - 2 times.
Because of the *shape property*, the depth of the heap will always be log n
where n is the number of elements in the heap.

It is a recursive operation with no more than log n recursive calls until the heap is corrected or the end of the heap is reached.
However, `heapify` will stop prematurely once the heap is corrected:
as it turns out, no more than 2\*n comparisons are needed in total, which means that `buildHeap` behaves in linear time of O(n).

Variations
--------------------------------------------------------------------------------
Eliminating recursion does improve the performance, however, the difference reduces as n increases.

| n | Nonrecursive Heap Sort | Recursive Heap Sort |
| - | - | - |
| 16,384 | 0.0048 | 0.0064 |
| 32,768 | 0.0113 | 0.0147 |
| 65,536 | 0.0263 | 0.0336 |
| 131,072 | 0.0762 | 0.0893 |
| 262,144 | 0.2586 | 0.2824 |
| 524,288 | 0.7251 | 0.7736 |
| 1,048,576 | 1,8603 | 1.9582 |
| 2,097,152 | 4.566 | 4.7426 |

Partition-Based Sorting
================================================================================
A *Divide and Conquer* strategy solves a problem by divding it into two independenct subproblems,
each about half the size of the original problem.

You can apply this strategy to sorting as follows:
find the *median* element in the collection A and swap it with the middle element of A.

Now swap elements in the left half that are greater than A[mid] with elements in the right half that are less than or equal to A[mid].

This subdivides the original array into two distinct subarrays that can be recursively sorted in place to sort the original collecttion A.

It turns out you can use any element in A to partition A into two subarrays; if you choosely "wisely" each time,
then both subarrays will be more or less the same size and you will achieve an efficient implementation.

Quicksort
================================================================================
Best, Average: O(n log n) Linearithmic, Worst: O(n^2) Quadratic

The Quicksort algorithm introduced by C.A.R. Hoarse in 1960 selects and element in the collection
(sometime randomly, sometimes the leftmost, sometimes the middle one) to partition an array into two subarrays.
Thus, Quicksort has two steps:
1. Partition the array.
2. Each subarray is recursively sorted.

```
sort(A)
  quicksort(A, 0, n-1)
end

quicksort(A, left, right)
  if left < right then
    pi = partition(A, left, right)
    quicksort(A, left pi-1)
    quicksort(A, pi+1, right)
end
```

Content
--------------------------------------------------------------------------------
Quicksort exhibits worst-case quadratic behvaior if the partitioning at each recursive step
only divides a collection of n elements into an "empty" and "large" set.

Solution
--------------------------------------------------------------------------------
A standard optimization is to use Insertion Sort with the size of the subarray to be sorted falls below a predetermined minimum size.

```c
/** Problem size below which to use insertion sort. */
extern int minSize;

/** Code to select a pivot index around which to partition ar[left, right]. */
extern int selectPivotIndex (void **vals, int left, int right);

int partition (void **ar, int(*cmp)(const void *,const void *),
	       int left, int right, int pivotIndex) {
  int idx, store;

  void *pivot = ar[pivotIndex];

  /*  move pivot to the end of the array*/
  void *tmp = ar[right];
  ar[right] = ar[pivotIndex];
  ar[pivotIndex] = tmp;
  
  /* all values <= pivot are moved to front of array and pivot inserted
   * just after them. */
  store = left;
  for (idx = left; idx < right; idx++) {
    if (cmp(ar[idx], pivot) <= 0) {

      tmp = ar[idx];
      ar[idx] = ar[store];
      ar[store] = tmp;
      store++;
    }
  }
  
  tmp = ar[right];
  ar[right] = ar[store];
  ar[store] = tmp;
  return store;
}

void do_qsort (void **ar, int(*cmp)(const void *,const void *),
	       int left, int right) {
  int pivotIndex;
  if (right <= left) { return; }
  
  /* partition */
  pivotIndex = selectPivotIndex (ar, left, right);
  pivotIndex = partition (ar, cmp, left, right, pivotIndex);
  
  if (pivotIndex-1-left <= minSize) {
    insertion (ar, cmp, left, pivotIndex-1);
  } else {
    do_qsort (ar, cmp, left, pivotIndex-1);
  }
  if (right-pivotIndex-1 <= minSize) {
    insertion (ar, cmp, pivotIndex+1, right);
  } else {
    do_qsort (ar, cmp, pivotIndex+1, right);
  }
}

void sortPointers (void **vals, int total_elems, 
	       int(*cmp)(const void *,const void *)) {

  do_qsort (vals, cmp, 0, total_elems-1);
}
```

Analysis
--------------------------------------------------------------------------------
In the ideal case, partition divides the original array in half and Quciksort exhibits its O(n log n) performance.
In practice, Quicksort, is effective with a randomly selected pivot.

In the worst case, the largest or smallest item is picked as the pivot. When this happens,
Quicksort makes a pass over all elemetns in the array (in linear time) to sort just a single item in the array.
If this process is repeated n - 1 times. It will result in O(n^2) worst-case behavior.

Variations
--------------------------------------------------------------------------------
Quicksort is the sorting method of choice on most systems. 
On Unix-based systems, there is a built-in library function called `qsort`. 
It is instructive that some-versions of the Linux operating systme implement qsort using Heap Sort

Various optimizations include:
- Create a stack that stores the subtasks to be precoessed to eliminate recursion
- Choose the ivot based on median-of-three strategy
- Set the minimum partition size below which to use Insertion Sort instead
which varies by implementation and machine architectures, in JDK 1.8, the threshold value is set to 7
- When processing the two subproblems, minimize the total sie of the recursive stack by solving the smaller subproblem first

However, noen of these optimizations will eleminiate the O(n^2) worst-case behavior of Quicksort.
The only way to ensure an O(n log n) worst-czse performance is to use a partition function that can guarantee
it finds a "reasonable approximation" to the actual median of that set.
The Blum-Floyd-Pratt-Rivest-Tarjan (BFPRT) partition algorith (Blum et al., 1973) is a provably
linear time algorithm, but it has only theoretical value.

Picking a Pivot
--------------------------------------------------------------------------------
Selecting the pivot element from a subarray A[left, left + n) must be an efficient operation;
it shouldn't require checking all n elements of the subarray.
Some alternatives are:
- Select first of last: A[left] or A[left + n - 1]
- Select random element in A[left, left + n - 1]
- Select median-of-k: the middle value of k elements take from A[left, left + n -1]

Often one chooses median-of-three; Sedgewick repors that this approach returns an improvement of 5%.
A median-of-five pivot selection has also been used.
Performing further computation to idetnify the proper pivot rarely provides beneficial results  
because of the extra computational costs.

Processing the partition
--------------------------------------------------------------------------------
One way to reduce the imbalance is to place elements equal to the pivot alternatively in the first and second subarrays.

Processing subarrays
--------------------------------------------------------------------------------
Quicksort yields two recursive invocations of Quicksort on smaller subarrays.
To minimize the possible depth of the stack, process the smaller subarray first.

Using simpler insertion sort technique for small subarrays
--------------------------------------------------------------------------------
On small arrays, Insertion Sort is faster than Quicksort, but even when used on large arrays,
Quicksort ultimately decomposes the problem to require numerous small subarrays to be sorted.
One commonly used technique to imporve the recursive performance of Quicksort is to invoke Quicksort
for large subarrays only, and use Insertion Sort for small ones.

Sedgewick (1978) suggests that a combination of median-of-three and using Insertion Sort for small subarrays
offers a speedup of 20%-25% over pure Quicksort.

IntroSort
--------------------------------------------------------------------------------
Introduced by Musser (1997), monitors recursive depth of Quicksort to ensure efficient processing.
If the depth of Quicksort recursion exceeds log(n) levels, then IntroSort switches to Heap Sort.

Sorting without Comparisons
================================================================================
No comparison-based sorting algorithms can sort n elements in better than O(n log n) performance.
Surprisingly, there are potentially faster ways to sort elements if you know something about those elements in advance.
For example, if you have a fast hashing function that uniformly partitions a collection of elements into distinct ordered buckets,
you can use the follwing Bucket Sort algorithm for linerar O(n) performance.

Bucket Sort
================================================================================
Best, Average, Worst: O(n) Linear

Given a set of n elements, Bucket Sort constructs a set of n ordered buckets into which
the elements of the input set are partitioned.

Bucket Sort reduces its processing costs at the expense of this extra space.

If a hash function, hash(A[i]), can uniformly partition the input set of n elements into these n buckets,
Bucket Sort can sort, in the worst case, in O(n) time.

Use Bucket Sort when the following two properties hold:
1. Uniform distribution: The input data must be uniformly distributed for a given range.
Based on this distributino, n buckets are created to evenly partition the input range.
2. Ordered has function: The buckets are ordered. If i < j, elements inserted into bucket Bi are lexiographically smaller than elements in bucket Bj.

```
sort(A)
  create n buckets B
  for i = 0 to n-1 do
    k = hash(A[i])
    add A[i] to the k-th bucket B[k]
  extract(B, A)
end

extract(B, A)
  idx = 0
  for i = 0 to n-1 do
  insertionSort (B[i])
  foreach element e in B[i]
    A[idx++] = e
end
```

Bucket sort is not appropriate for sorting arbitrary strings, for example, because typically it is
impossible to develop a hash function with the required charactericts.

However, it could be used to sort a set of uniformly distributed floating-point numbers in the range [0,1].

Once all elements to be sorted are inserted into the buckets, Bucket Sort extracts the values from left to right
using Insertion Sort on the contents of each bucket.

This orders the elements in each respective bucket as the values from the buckets are extracted from left to right to repopulate the original array.

Solution
--------------------------------------------------------------------------------
Each bucket stores a linked list of elements that were hashed to the bucket.

```c
extern int hash (void *elt);
extern int numBuckets (int numElements);

/* linked list of elements in bucket. */
typedef struct entry {
  void *element;
  struct entry *next;
} ENTRY;

/* maintain count of entries in each bucket and ;point to its first entry */
typedef struct {
  int size;
  ENTRY *head;
} BUCKET;

/* Allocation of buckets and the number of buckets allocated */
static BUCKET *buckets = 0;
static int num = 0;

/** One by one remove and overwrite ar */
void extract (BUCKET *buckets, int(*cmp)(const void *,const void *),
	      void **ar, int n) {
  int i, low;
  int idx = 0;

  for (i = 0; i < num; i++) {
    ENTRY *ptr, *tmp;
    if (buckets[i].size == 0) continue;   /* empty bucket */

    ptr = buckets[i].head;
    if (buckets[i].size == 1) {
      ar[idx++] = ptr->element;
      free (ptr);
      buckets[i].size = 0;
      continue;
    }

    /* insertion sort where elements are drawn from linked list and 
     * inserted into array. Linked lists are released. */
    low = idx;
    ar[idx++] = ptr->element;
    tmp = ptr;
    ptr = ptr->next;
    free (tmp);
    while (ptr != NULL) {
      int i = idx-1;
      while (i >= low && cmp (ar[i], ptr->element) > 0) {
        ar[i+1] = ar[i];
        i--;
      }
      ar[i+1] = ptr->element;
      tmp = ptr;
      ptr = ptr->next;
      free(tmp);
      idx++;
    }
    buckets[i].size = 0;
  }
}

/**
 * Invoke BucketSort on the given array. 
 */
void sortPointers (void **ar, int n, 
		   int(*cmp)(const void *,const void *)) {
  int i;
  num = numBuckets(n);
  buckets = (BUCKET *) calloc (num, sizeof (BUCKET));

  for (i = 0; i < n; i++) {
    int k = hash(ar[i]);

    /** Insert each element and increment counts */
    ENTRY *e = (ENTRY *) calloc (1, sizeof (ENTRY));
    e->element = ar[i];
    if (buckets[k].head == NULL) {
      buckets[k].head = e;
    } else {
      e->next = buckets[k].head;
      buckets[k].head = e;
    }

    buckets[k].size++;
  }

  /* now read out and overwrite ar. */
  extract (buckets, cmp, ar, n);

  free (buckets);
}
```

The buckets could also be stored using fixed arrays that are reallocated when the buckets become bull,
but the linked list implementation is about 30%-40% faster.

Analysis
--------------------------------------------------------------------------------
The sortPointers function sorts each element from the input into its assocated bucket based upon the provided hash function: this takes O(n) time.

As the values are extracted from the buckets and written back into the input array,
Insertion Sort is used when a bucket contains more than a single element.

It is important to consider the variance because some buckets will be empty, and others may have more than one element;
we need to be sure that no bucket has too many elements.

When we sum up the costs of executing Insertion Sort on all n buckets, the expected performance cost remains O(n).

Variations
--------------------------------------------------------------------------------
Instead of creating n buckets *Hash Sort* creates a suitably large number of buckets k into which the elements are partitinoed;
as k grows in size, the performance of Hash Sort improves.

The key to Hash Sort is a hashing function hash(e) that returns an integer for each element e such that
hash(Ai) \<= hash(Aj) if Ai is lexicographically smaller than Aj.

Summary of performance
Quicksort <= 256
Hash Sort 676 buckets > 512
Hash Sort 17,576 buckets > 8,192

Note that with 17,576 buckets, Hash Sort outperforms Quicksort for n > 8,192
items (and this trend continues with increasing n).

However, with only 676 buckets once n > 32,768 (for an average of 48 elements per bucket),
Hash Sort begins its inevitable slowdown with the accumulated cost of executing Insertion Sort on
increasingly larger sets. Indeed, with only 26 buckets, once n > 256, Hash Sort begins to
quadruple its performance as the problem size doubles, showing how too few buckets leads to O(n^2) performance.

Sorting with Extra Storage
================================================================================
Most sorting algorithms sort a collection in place without requiring any noticeable extra storage.
We now present *Merge Sort*, whithc offers O(n log n) behvior in the worst case while using O(n) extra storage.
It can be used to efficiently sort data that is stored externally in a file.

Merge Sort
================================================================================
Best, Average, Worst: O(n log n) Linearithmic

To sort a collection A, divide it evenly into two smalller collections, each of which is then sorted.
A final phase merges these two sorted collections back into a single collection of size n.

```
sort(A)
  copy = copy of A
  mergeSort(copy, A, 0, n)
end

mergeSort(A, result, start, end)
  if end - start < 2 then return
  if end - start = 2 then
    swap elements of result if out of order
    return

  mid = (start + end)/2
  mergeSort(result, A, start, mid)
  mergeSort(result, A, mid, end)

  merge left and right halves of A into result
end
```

Input/Output
--------------------------------------------------------------------------------
The output of the sort is returned in place within the original collection A.
The internal storage copy is discarded.

Solution
--------------------------------------------------------------------------------
Merge Sort merges the left and right sorted subarrays using two indices i and j to
iterate over the left (and right) elements, always copying the smaller of A[i] and A[j]
into its proper location result[idx].

There are three cases to consider:
1. The right side is exhausted (j >= end), in which case the remaining elements are taken from the left side.
2. The left side is exhausted (i >= mid), in which case the remaining elements are taken from the right side.
3. The left and right side have elements; if A[i] < A[j], insert A[i] otherwise insert A[j].

```python
def sort (A):
    """merge sort A in place."""
    copy = list (A)
    mergesort_array (copy, A, 0, len(A))


def mergesort_array (A, result, start, end):
    """Mergesort array in memory with given range."""
    if end - start < 2:
        return
    if end - start == 2:
        if result[start] > result[start+1]:
            result[start],result[start+1] = result[start+1],result[start]
        return

    mid = (end + start) // 2
    mergesort_array (result, A, start, mid)
    mergesort_array (result, A, mid, end)
    
    # merge A left- and right- side
    i = start
    j = mid
    idx = start
    while idx < end:
        if j >= end or (i < mid and A[i] < A[j]):
            result[idx] = A[i]
           i += 1
        else:
            result[idx] = A[j]
            j += 1
            
        idx += 1
```

Analysis
--------------------------------------------------------------------------------
Merge Sort completes the "merge" phase in O(n) time after recursively sorting the 
left and right half of the range A[start, end], placing properly ordered elements in the array referenced as result.

Because copy is a true copy of the entire array A, the terminating base cases of the recursion will work
because it references the original elements of the array direclty at their repective index locations.

This observation is a sophisticated one and is key to the algorithm.

In addition, the final merge step requires only O(n) operations, which ensures the total performance remains O(n log n).

Because copy is the only extra space used by the algorithm, the total space requirement is O(n).

Variations
--------------------------------------------------------------------------------
Of all the sorting algorithms, Merge Sort is the easiest one to convert to working with external data.

```java
package algs.model.sort;

import java.io.*;
import java.nio.*;
import java.nio.channels.*;

/**
 * Demonstrates efficient merge sort by using the ability to memory map files for rapid access. 
 * 
 * There are some windows-specific code, unfortunately, that is needed to properly release resources.
 *  
 * @author George Heineman
 * @version 2.0, 8/6/15
 * @since 2.0
 */
public class MergeSortFileMapped {

	static void copyFile(File src, File dest) throws IOException {
		FileInputStream fis = new FileInputStream(src);
		FileOutputStream fos = new FileOutputStream (dest);
		byte[] bytes = new byte[4*1048576];
		int numRead;
		while ((numRead = fis.read(bytes)) > 0) {
			fos.write(bytes, 0, numRead);
		}
		fis.close();
		fos.close();
	}

	// inelegant need to manually close on some operating systems (Windows)
	static void closeDirectBuffer(MappedByteBuffer mbb) {
	    try {
	        java.lang.reflect.Method cleaner = mbb.getClass().getMethod("cleaner");
	        cleaner.setAccessible(true);
	        java.lang.reflect.Method clean = Class.forName("sun.misc.Cleaner").getMethod("clean");
	        clean.setAccessible(true);
	        clean.invoke(cleaner.invoke(mbb));
	    } catch(Exception ex) { }	   
	}
	
	public static void mergesort (File A) throws IOException {
		File copy = File.createTempFile("Mergesort", ".bin");
		copyFile (A, copy);

		RandomAccessFile src = new RandomAccessFile(A, "rw");
		RandomAccessFile dest = new RandomAccessFile(copy, "rw");
		FileChannel srcC = src.getChannel();
		FileChannel destC = dest.getChannel();
		MappedByteBuffer srcMap = srcC.map (FileChannel.MapMode.READ_WRITE, 0, src.length());
		MappedByteBuffer destMap = destC.map (FileChannel.MapMode.READ_WRITE, 0, dest.length());

		mergesort (destMap, srcMap, 0, (int) A.length());
		
		// The following two invocations are needed only on Windows Platform:
		closeDirectBuffer (srcMap);
		closeDirectBuffer (destMap);
		src.close();
		dest.close();
		copy.deleteOnExit();
	}

	static void mergesort(MappedByteBuffer A, MappedByteBuffer result, 
			int start, int end) throws IOException {

		if (end - start < 8) { 
			return; 
		}

		if (end - start == 8) {
			result.position(start);
			int left = result.getInt();
			int right = result.getInt();
			if (left > right) {
				result.position (start);
				result.putInt (right);
				result.putInt (left);
			}
			return;
		}

		int mid = (end + start)/8*4;
		mergesort (result, A, start, mid);
		mergesort (result, A, mid, end);

		result.position(start);
		for (int i = start, j = mid, idx=start; idx < end; idx += 4) {
			int Ai = A.getInt (i);
			int Aj = 0;
			if (j < end) { Aj = A.getInt (j); }
			if (j >= end || (i < mid && Ai < Aj)) { 
				result.putInt (Ai);
				i += 4;
			} else {
				result.putInt (Aj);
				j += 4;
			}
		}
	}
}
```

String Bechmark Results
--------------------------------------------------------------------------------
Pay attention to the relative performance of the algorithms on the corresponding data sets;

Analysis Techniques
--------------------------------------------------------------------------------
A fundamental result in computer science is that no algorithm that sorts by comparing elements
can do better than O(n log n) performance in the average or worst case.

Every algorithm that sorts by pairwise comparisons corresponds to a binary search tree.

