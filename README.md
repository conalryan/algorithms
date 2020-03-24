algorithms
================================================================================
https://github.com/heineman/algorithms-nutshell-2ed

Thinking in Alogrithms
--------------------------------------------------------------------------------
The first step in designing an algorithm is to understand the problem you want to solve.
Approaches to take:

### Greedy
One piece at a time.

### Divide and Conquer
Divide the problem in half.

### Parallel
Divide subproblems among a number of processors to speed up the overall solution.

### Approximation
Instead of computing the exact answer, perhaps you would be satisified witha an approxiamte answer 
that can be computed quickly and showe error can be accurately determined.

### Generalization
It is often possbile to solve a more general problem whose solution can be readily converted to solve your specific problem.

### Summary
An efficient algorithm is often not at all obvious to discover, and very different algorithms
may be the bes ones to choose for different data sets, different processing environments 
(such as where you can exploit parallelism), and different goals.

The Mathematics of Algorithms
--------------------------------------------------------------------------------
One of the most important factors for choosing an algorithm is the speed with wich it is likely to complete.

### Size of a Problem Instance
An instance of a problems is a particular input data set given to a program.
In most problems, the execution time of a program increases with the size of this data set.
At the same time, overly compact representations (possibly using compression techniques)
may unnecessarily slow down the execution of a program.
It is surprisingly difficult to define the optimal way to encode an instance in the real world due to varying constraints.

Your representation of a problem instance should depend ust on the type and variety of oeprations that need to be performed.
Designing efficient algorithms often start by selecting the propert data strucutres in which to represent the problem.

Algorithmic researches accept that they are unable to computed with pinpoint accuracy the cost involved in using
a particular encoding in an implementation.

Therefer, they assert that perfomance costs that differ by a multiplicative constant are asymptotically equivalent,
or in other words, will not matter as the problem size continues to grow.

This asymptotically approach is useful since it can predict the perfomance of an algorithm on a large problem instance
based on the performance on small problem instances.

It helps determine the largest problem instance that can be handled by a particular algorithm implementation (Bentley, 1999).

### Rate of Growth of Functions
We describe the behavior of an algoritm by representing the rate of growth of its execution time
as a function of the size of the input problem instance.

When using the abstraction of the rate of growth to choose between algorithms, remeber that:
- Constants matter: That's why we use supercomputers and upgrade our computers on a regular basis.
- Size of n is not always large: E.g. rate of growth of execution time of Quicksort is less than the
rate of growth of the execution time of Insertion Sort. Yest Insertion Sort outperforms Quicksort for small arrays on the same platform.

An algorithms rate of growth determines how it will perform on increasingly large problem sets.

The "fitness" of a trend line to the actual data is based on a value between - and 1, know as the R2 value,
R2 values near 1 indicate high fitness.

### Analysis in the Best, Average, and Worst Cases
The data could contain large runs of elements already in sorted order.
The input could contain duplicate values
Regardless of the size n of the input set, the elements could be drawn from a much smaller set
and contain a significant number of duplicative values.

The conclusion to draw is that for many problems, no single optimal algorithm exists.
Choosing an algoritm depends on understanding the problem being solved and the underlying probability
distribution of the instances likely to be treated, as well as the behavior of the algorithms being considered.

### Worst case
Defines a class of problem instances for which an algorithm exhibits its worst runtime behvaior.
Instead of trying to identify the specific input, algorithm designers typically describe properties of the input
that prevent an algorithm from running efficiently.

For a given program and a given value n, the worst-case execution time is the maximum execution time,
where the maximum is taken over all instances of size n.

We are interested in the worst-case behavior of an algorithm because it is often the easiest case to analyze.
It also explains how slow the program could be in any situation.

### Average case
Defines the expected behavior when executing the algorithm on random problem instances.
This measure describes the expectation an average user of the algorithm should have.
cr. Law of Big Numbers.

In reality, the probabily of maximum load/capacity is rare, and the cost to maintain a sufficiently large
system to always provide maximum load/capacity is prohibitive.
Instead we could design a system that is cheaper to build and use mathematical tools to consider
the probability of crash due to overload.

For the set of instances of size n, we associate a probability distribution Pr(s),
which assigns a probability between 0 and 1 to each instance of Si such that the sum of
the probabilities over all instances of size n is 1.

### Best case
Defines a class of problem instances for which an algorithm exhibits its best runtime behavior.
In reality, the best case rarely occurs.

Knowing the best case for an algorithm is useful even though the situation rarely occurs in practice.
In many cases, it provides insight into the optimal circumstance for an algorithm.

### Lower and Upper Bounds
We simplify the presentation of the "Big O" notation in this book.
The goal is to classify the behavior of an algorithm as it solves problem instances of increasing size n.
the classification is stated as O(f(n)) whern f(n) is most commonly a function such as n, n^3, or 2^n.

To summarize, the actual formal notation is as follows:
- The lower bound for the execution time of an algorithm is classified as Omega(f(n)) and corresponds to the best-case scenario.
- The uppper bound for the execution time is classified as O(f(n)) and corresponds to the worst-case-scenario.
- Tight bound: When the lower bound is determined to be Omega(f(n)) and the upper bound is also O(f(n)) for teh same classification f(n).

### Performance Families
We compare algorithms by evaluating their performance on problem instances of size n.
This methodology is the standar means developed over the past half-century for comparing algorithms.
By doing so, we can determine which algorithms scae to solve problems of a notrivial size by evaluating
the running time needed by the algorithm in relation to the size of the provided input.
A secondary performance evaluation is to consider how much memory or stoarge an algorithm needs.

- Constant: O(1)
- Logarithmic: O(log n)
- Sublinear: O(n^d) for d < 1
- Linear: O(n)
- Linearithmic: O(n log n)
- Quadratic: O(n^2)
- Exponential: O(2^n)

We evaluate the performance of an algoritm, keep in mind that you must identify
the most expensize computation within an algorithm to determin its classification.
For example, consider an algorithm that is subdived into two tasks, a linear task
followed by a quadratic task. The overall performance is quadratic.

### Constant Behavior O(1)
When analyzing the performance of the algorithms in this book, we frequently claim that
some primitive oeprations provide constant performance. Clearly this claim is not an absolute.
A constant operation is defined to have O(1) performance.

### Log n Behavior O(log n)
Reduce the problem size by about half each time.

Logarithmic algorithms are extremely efficient because they rapidly converge on a solution.
These algorithms succeed becaue they reduce the size of the problem by about half each time.

### Sublinear O(n^d) Behavior for d < 1 O(n^d)
In some cases, the behavior of an algoritm is better than linear, yet not as efficient as logarithmic.
k-d tree in multiple dimensions can partition a set of n d-dimensional points efficiently.

### Linear Performance O(n)
Classify algorithm as being linear with respect to its inputs size n.
That is there is some constant c > 0 such that t(n) <= c\*n for "large enough" n, or more precisely, all n > n[0]

When considering differences in algorithms, the constant c is not as important as knowing the rate of growth of the algorithm.
Seemingly inconsequential differences result in different perfomance.

cr. Side not how expensive is modulus operator (%)?

### Linearithmic Perfomance O(n log n)
Divide and conquer is an efficient way to solve a problem in which a problem of size n is dived into
(roughly equal) subproblems of size n/2, which are solved recursively.
The solutions of these subproblems are combined together in linear time to slve the original problem of size n.

t(n) = 2\*t(n/2)+c\*n

That is, t(n) includes the cost of the two subporbolems together with no more than a linear time cost (i.e., c\*n) to merge the result.

### Quadratic Performance O(n^2)
Primary indicator of quadratic performance is a nested for loop structure.

### Exponential Performance O(2n)
Exponential algorithms are practical only for very small values of n.
Some algorithms might have a worst-case behavior that is exponential, yet still are heavily used
in practice becuase of their average-case behavior. A good example is the *Simplex* algorithm
for solving linear programming problems.

### Summary of Asymptotic Growth
An algoritm with better asymptotic growth will eventually execute faster than one with worse asymptotic growth,
regardless of the actual constants.
The actual breakpoint will differ based on teh actual constants, but it exists and can be empirically evaluated.
In addition, during aasymptotic analysis we only need to be converned with the fastest-growing term of the t(n) function.
For this reason, if the number of operations for an algorithm can be computed as c\*n^3+d\*n\*log(n),
we could classify this algorithm as O(n^3) becuase that is the dominant term that grows far more rapidly than n\*log(n)

Algorithm Building Blocks
--------------------------------------------------------------------------------

### Algorithm Template Format
- Name
- Input/Output: Expected format of input data to the algoritm and the resulting values computed.
- Context: A description of a problem that illustrates when an algorithm is useful and when it will perform at its best.
- Solution: Real working code with documentation found in the associated code repository.
- Analysis: A synopsis of the analysis of the algorithm, including performance data and information
to help you understand the behavior of the algorithm.
- Variations

### Floating-Point Computation
Computers perform basic computation on values stored in registers by a central processing unit (CPU).
These registers have grown in size as computer architectures have evolved from the 8-bit Intel Processors of 1970s to todays 64-bit processors.
The CPU often supports basic operations such as ADD, MULT, DIVIDE, and SUB over integer values stored within these registers.
Floating-point units (FPUs) can efficiently process floating-point computations according to the IEEE Standard for Binary Floating-Point Arthmetic (IEEE 754).
Mathematical computations over integer-based values (such as Booleans, 8-bit shorts, and 16- and 32-bit integers)
have traditionally been the most efficient CPU computations.
Programs are often optimized to take advantage of this historic perfomance differential between integer and floating-point calculations.

### Performance
It is commonly accepted that computations over integer values will be more efficient thatn their floating-point counterparts.

### Rounding Error
Any computations using floating-oint values may introduce rounding errors because of the nature of the floating-point representation.
In general, a floating point number is a finite representation designed to approximate a real number whose representation may be infinite.
In a 32-bit floating-point value, one bit is used for the sign, 8 bits form teh exponent,
and 23 bits form the manissa (also known as the significand).

The most common way of describing floating-oint error is to use the term relative error,
which computes the ratio of the absolute error with the desired value.
It is quite common for these relative errros to be less than 1 part per million.

### Comparing Floating-Point Values
Because floating-oint values are only approxiate, the simplest oeprations in floating-oint become suspect
`if (x === y) { ... }`
The value of the expression (c-a)\*(f-b)-(d-b)\*(e-a) can determine whether these two line segments are collinear
(i.e. on the same line). If the value is:
- 0 then the segments are collinear
- < 0 then the segments are turning to the left (or counterclockwise)
- > 0 then the segments are turning to the right (or clockwise)

Thus a small rounding error can cause a false positive. Both 32-bit and 64-bit floating-point
representations fail to capture the true mathematical value of the computations.

One common solution to this situation is to introduce a small value to determien the approximate equality
between two floatin-oint values. However, won't solve the collinearity problem and it makes it
difficult to write correct code.

### Greedy
A Greedy strategy completes a task of size n by incrementally solving the problem in steps.

At each step, a Greedy algorithm will make the best local decision it can given the available information,
typically reducitn the size of the problem being solved by one. Once all n steps are completed,
the algorithm returns the computed solution.

Example *Selection Sort* will locate the larget value in A[0, n-1] and swaps it with element in A[n-1].

You can identify a Greedy strategy by the way that subproblems being solved shrink very slowly as an algorithm processes the input.
When a subproblem can be conpleted in O(log n) then a Greedy strategy will exhibit O(n log n) performance.
If the subproblem requires O(n) behavior, as it does here with *Selection Sort*, then the overall performance will be O(n^2).

### Divide and Conquer
A Divide and Conquer strategy solves a problem of size n by dividing it inot two independent subproblems,
each about havld the size fo teh original problem.

Quite often the solution is recursive, terminating with a base case that can be solved trivially.

### Dynamic Programming
Dynamic Programming is a variation on Divide and Conquer that solves a problem by subdividing it into
a number of simpler subporblems that are solved in a specific order.

It solves each smaller problem just once and stores the reulsts for future use to avoid unnecessary recomputation.
It then solves problems of increasing size, composing together solutions from the results fo these smalelr subproblems.

Dynamic Programming works by storing the results of simpler subproblems.
The trick in Dynamic Programming is an optimization loop that shows how to compose the results of these
subproblems to solve larger ones.
Dynamic programming must evaluate the subproblems in the proper order (i.e., from top row to bottom row, left to right).

Sorting
--------------------------------------------------------------------------------

Searching
--------------------------------------------------------------------------------

Graph Algorithms
--------------------------------------------------------------------------------

Path Finding in AI
--------------------------------------------------------------------------------

Network Flow Algorithms
--------------------------------------------------------------------------------

Computational Geometry
--------------------------------------------------------------------------------

Spatial Tree Structures
--------------------------------------------------------------------------------

Emerging Algorithm Categories
--------------------------------------------------------------------------------

Epilogue: Principles of Algorithms
--------------------------------------------------------------------------------
