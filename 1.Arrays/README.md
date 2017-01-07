# Arrays

**self-check**: What's the difference between normal array and resizable array? [answer](https://en.wikipedia.org/wiki/Dynamic_array)

First we need to know the difference between Array Resizable Array. In the interveiw
problems we recommand you to use resizable array when solving array problem, they are as 
fast as native array, and you don't have to worry about memory management.
* [C++ vector vs. array](http://stackoverflow.com/questions/381621/using-arrays-or-stdvectors-in-c-whats-the-performance-gap)
* [Java Array vs. List](http://stackoverflow.com/questions/716597/array-or-list-in-java-which-is-faster)

## Basic Operations:
* Look up by index **O(1)**
* Update **O(1)**
    - Swap **O(1)**
* Insert **O(n)** 
    - Insert from the back **O(1)**
* Deletion **O(n)**
    - Delete from the back **O(1)**

**self-check**: Why is it so expensive to perform insertion and deletion?

## Tricks:
**Be really careful with off by one error**
* **EPI** 6.4. Advancing Through an array

**self-check**: What's the result of the following code?
```C++
int i, counter = 0, n = 10;
for (i = 0; i < n; ++i) {
    ++counter;
}

print(counter);
print(i);

int j, n = 10, counter2 = n;
for (j = n; j <= 0; --j) {
    --counter2;
}

print(counter2);
print(j);
```
**Learn to use multiple pointers**
* **Leetcode** *1. Two Sum (sorted)* (lecture)
* Sort an array has only 1 and 0 (lecture)
* **EPI:** *6.5. Delete Duplicates From a Sorted Array* (hands on)
* **EPI** *6.1. The Dutch National Flag Problem*

**Solving a problem using constant space, when using extra sotrage makes the problem trival**
* Marking on the input:
    - **CTCI** *1.8 Zero Matrix* (lecture)
    - **Leetcode** *Game of Life* (hands on)

**Using memoization to optimize time complexity**
* **Leetcode** *1. Two Sum (not sorted)* (lecture)
* **Leetcode** *454. 4Sum II* (hands on)

**Instead of deleting an element from an array, try to overwrite it**
* **EPI:** *6.5. Delete Duplicates From a Sorted Array*

**If it is sorted, take advantage of it.**
* **Leetcode** *1. Two Sum (sorted)*

**Dynamic Programming**
* **EPI** *6.19. Compute rows in Pascal's triangle*
* **EPI** *6.8. Enumerate All Primes to n*

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
- [ ] 289. Game of Life Question

### Geeks for Geeks
- [x] [Find Maximum Sum Strictly Increasing Subarray](http://www.geeksforgeeks.org/find-maximum-sum-strictly-increasing-subarray/)
- [ ] [Sum of maximum elements of all subsets](http://www.geeksforgeeks.org/sum-maximum-elements-subsets/)
- [x] [Rearrange positive and negative numbers](http://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers-publish/)

### Others
- [ ] [How to Find Top Two Maximum Number from Integer array in Java](http://www.java67.com/2014/03/how-to-find-top-two-maximum-number-from-integer-array-java.html)
- [ ] [Cound Negative Intergers in Sorted Matrix](https://www.youtube.com/watch?v=5dJSZLmDsxk)


## Hard
