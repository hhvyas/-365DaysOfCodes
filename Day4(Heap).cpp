/* Today I learnt about Heaps, and heap sort from https://www.youtube.com/watch?v=g9YK6sftDi0 it's very introductory video for learning about heap, and heap sort
  After that to clear my doubts I refered to 
  https://www.youtube.com/watch?v=B7hVxCmfPtM&t=113s&ab_channel=MITOpenCourseWare (MIT) and https://www.geeksforgeeks.org/heap-data-structure/.
  And further-more I solved some problems.. not many*
*/
/*A heap is one maximally efficient implementation of a priority queue.

We can have:
-) a min heap: min element can be peeked in constant time.
-) or a max heap: max element can be peeked in constant time.

The name of the heap indicates what we can peek in O(1) time.

We insert the item to the "end" of the complete binary tree (bottom right of the tree).

We "bubble up" the item to restore the heap. We keep bubbling up while there is a parent to compare against and that parent is greater than (in the case of a min heap) or less than (in the case of a max heap) the item. In those cases, the item we are bubbling up dominates its parent.

Removal from a binary heap:

We give the caller the item at the top of the heap and place the item at the "end" of the heap at the very "top".

We then "bubble the item down" to restore the heap property.

Min Heap: We keep swapping the value with the smallest child if the smallest child is less than the value we are bubbling down.

Max Heap: We keep swapping the value with the largest child if the largest child is greater than the value we are bubbling down.

In this manner, we restore the heap ordering property.

Insertion - O(log(n))
Deletion - O(log(n))
Peek - O(1).
-------------------------------------------
Heap Sort (O(n*log(n));
https://www.youtube.com/watch?v=B7hVxCmfPtM&t=113s&ab_channel=MITOpenCourseWare

Heap is tree representation of array..
root of tree:- first element of array.
parent(i) = i/2;
left(i) = 2*i
right = 2*i+1;
Max-Hip: If all parents node has value greater than or equal to all of his children..
used in priority queue --> take it, and delete it
if we continuesly take one by one element then, it will be in descending order.
Max-Heapify :-
Tree rooted at left(i) and right(i) are max-heaps.

Max_Heapify(2) -> both of it's child must be Max_Heap.
--> Will work bottom-up
Exchanege A


		      12
	       /  \
	      4    5
	     / \  / \
	    10  8,9  11

Max_Heapify(1->index) call --> both of it's children's heapify property will be checked.. now
Max_Heapify(2-->(4)) isn't correct so, one of it's children will be on-place of parent.. so 4 and 8 will be leaf nodes.. same goes now for 5.. 11 will be in-place of 5. and recursive condition will end. (Stop when you reach at leaf nodes).

Psudo Code for max_heap->

for i = n/2 down to 1
   do max_heapify(A, i)  --> n/2 coz [n/2,..n] will be leaves.
1 4 5 10 8 9 11
n = 7;
n/2 = 3;
so max_heap(3) -> 12 10 5 4 8 9 11
Max_heap(2) -> 12 10 11 4 8 9 5 (Children value is more)
Max_heap(1) -> 12 10 11 4 8 9 5 -> Max_heap is built.
*/
https://atcoder.jp/contests/abc177/tasks/abc177_c
https://ideone.com/sRmhSj

https://codeforces.com/contest/27/problem/B
https://ideone.com/XKlXrR

   

