# Arrays
First we need to know the difference between Array Resizable Array. In the interveiw
problems we recommand you to use resizable array when solving array problem, especially
in C++ (vector), it is as fast as native array, as you don't have to worry about memory
management.

## Basic Operations:
* Look up by index **O(1)**
* Overwrite **O(1)**
* Insertion **worst case O(n)**
    - Insert from the back **O(1)**
* Deletion **worst case O(n)**
    - Delete from the back **O(1)**

## Tricks:
* **Be really careful with off by one error**
    - **EPI** *6.4. Advancing Through an array*
* **Solving a problem using constant space, when using extra sotrage makes the problem trival**
    - **CTCI** 1.8 Zero Matrix
* **Using memoization to optimize time complexity**
    - **Leetcode** *454. 4Sum II*
    - **Leetcode** *1. Two Sum (not sorted)*
* **Instead of deleting an element from an array, try to overwrite it**
    - **EPI:** *6.5. Delete Duplicates From a Sorted Array*
* **Learn to use multiple pointers**
    - **EPI** *6.1. The Dutch National Flag Problem*
* **If it is sorted, take advantage of it.**
    - **Leetcode** *1. Two Sum (sorted)*
* **Dynamic Programming**
    - **EPI** *6.19. Compute rows in Pascal's triangle*
    - **EPI** *6.8. Enumerate All Primes to n*

## Problem set
Check box indicate if a solution is availible
### Elements of Programming Interviews 2015
- [X] 6.1. The Dutch National Flag Problem
- [X] 6.2. Increment An Arbitrary Precision Interger
- [X] 6.3. Multiply Two Arbitrary Precision Intergers
- [X] 6.4. Advancing Through an array
- [X] 6.5. Delete Duplicates From a Sorted Array
- [X] 6.6. Buy and sell a strock once
- [X] 6.7. Buy and sell a strock Twice
- [X] 6.8. Enumerate All Primes to n  
- [ ] 6.9. Permute The Elements of An Array **Hard**
- [X] 6.10. Compute the next permutation 
- [X] 6.11. Sample Offline data
- [X] 6.12. Sample Online data
- [X] 6.16. The Sudoku Checker Problem
- [X] 6.17. Compute the spiral ordering of a 2D array
- [ ] 6.18. Rotate a 2D array
- [X] 6.19. Compute rows in Pascal's triangle

### Cracking the code interviews 6e
- [x] 1.8 Zero Matrix

### Leetcode
- [x] 228. Summary Ranges 
- [x] 169. Majority Element **Moore Voting Algorithm**
- [x] 442. Find All Duplicates in an Array 
- [x] 80. Remove Duplicates from Sorted Array II 
- [x] 238. Product of Array Except itself 
- [x] 59. Spiral Matrix II 
- [x] 1. Two Sum
- [x] 167. Two Sum II
- [x] 15. 3Sum
- [x] 16. 3Sum Closest 
- [x] 18. 4Sum 
- [x] 454. 4Sum II
- [x] 122. Best Time to Buy and Sell Stock II
- [x] 11. Container With Most Water 

### Geeks for Geeks
- [x] [Find Maximum Sum Strictly Increasing Subarray](http://www.geeksforgeeks.org/find-maximum-sum-strictly-increasing-subarray/)
- [ ] [Sum of maximum elements of all subsets](http://www.geeksforgeeks.org/sum-maximum-elements-subsets/)
- [x] [Rearrange positive and negative numbers](http://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers-publish/)

### Others
- [ ] [How to Find Top Two Maximum Number from Integer array in Java](http://www.java67.com/2014/03/how-to-find-top-two-maximum-number-from-integer-array-java.html)
- [ ] [Cound Negative Intergers in Sorted Matrix](https://www.youtube.com/watch?v=5dJSZLmDsxk)


## Hard
