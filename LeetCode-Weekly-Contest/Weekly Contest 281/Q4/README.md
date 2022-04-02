# Q4 Count Array Pairs Divisible by K

Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) such that:

- 0 <= i < j <= n - 1 and
- nums[i] * nums[j] is divisible by k.

Example:

Input: nums = [1,2,3,4,5], k = 2

Output: 7

Explanation: 

The 7 pairs of indices whose corresponding products are divisible by 2 are
- (0, 1), (0, 3), (1, 2), (1, 3), (1, 4), (2, 3), and (3, 4).

Their products are 2, 4, 6, 8, 10, 12, and 20 respectively.

Other pairs such as (0, 2) and (2, 4) have products 3 and 15 respectively, which are not divisible by 2.  
