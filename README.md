# Algorithms-Assignment-2

## Algorithms/Data Structures HW 2

Greedy Scheduling
The array of tasks should have n elements
If n == 0, return
Sort all tasks T, start times S, and finish times F,  by their finish times F in a non-decreasing order. T, S, and F should stay aligned
Create a new collection called schedule with a size n
Add the first task, T[0], in that sorted list T to schedule
j=0
For each i in T, from T[1…n-1], 
Add it to the schedule if the start time S[i] is greater than or equal to F[j].
If the T[i] is added to the schedule, j = i
Proof:

Invariant: The set of tasks chosen so far is always non-conflicting, and holds as the maximum number of tasks that can be completed by the current time. (the current time being the finish time of the most recently completed task)

Initialization:
Before any task is chosen, the set is empty; therefore, by default, the set is non-conflicting and optimal for time = 0.

Before the loop:
Immediately before the loop, the first task is scheduled. This task is chosen based only on its finish time, and as the only task in the schedule, it is by default non-conflicting. Because it is the task with the earliest finish time, it is optimal for the current time.

Maintenance:
In each loop, the next task is only chosen if it does not overlap with the task before; it is only chosen if its start time is after the previous task's end time. Therefore, the set remains non-conflicting.
By the greedy choice property, an optimal set of tasks will result when choosing the optimal next task in each loop; the optimal next task being the one with the soonest finish time.

Termination:
After all tasks have been scheduled, the final set is non-conflicting and contains the maximum number of tasks possible for the amount of time that has passed.

## Dynamic Program run time
2: O(1)
3: outer loop, i =1…n				;runs n times
4: O(1) each outer loop			;O(n) total
5: Inner loop, j = 1…i				;runs i-1 times for each i, or n(n-1)/2 times
6: if statement comparison O(1) each IL	;O(n^2) total
7: conditional operation, O(1)			;O(n^2) total 


Worst case: line 7 runs every time
O(n) + (2*O(n^2)) 
=O(n) + O(n^2) 

= O(n^2)

Best case: line 7 never runs
O(n) + O(n^2) 

= O(n^2)

## Optimal substructure property with rod cut problem and cut cost

R(n) is the maximum possible revenue from a rod of length n. p(n) is the price of the entire rod without cuts.
To find the maximum revenue, we first decide whether or not to make a cut. If we do not make a cut, then the revenue, R(n) is p(n). If we do make a cut, the revenue, R(n), is p(i) + R(n-i) - c, where i is the best position/length we can cut, and c is the cost of making the cut. R(n-i) recursively finds the revenue of n-i. 

R(0) = 0
R(n) = max( p(n), max over all possible i (p(i) + R(n-i) - c) )

It is the job of each recursion to decide whether or not a cut is optimal. 
If a first cut at i is necessary to solve the problem optimally, the remainder, n-i, must also be solved optimally.

The optimal revenue for a rod of length n depends on the optimal revenue of the recursive sub-problem, so the problem obeys the optimal substructure property, even when each cut has a cost.

## BST
The solution for problem 4 and 5 can be found in the file "BST.cpp". 

I decided to combine them into one file. The insert and delete functions can be used from the same menu as the traversal and search functions.