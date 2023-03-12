
    Triplets
    Ways to Sum
    Consecutive Sum
    Disk Space Analysis
    Do They Belong?
    Global Maximum
    Initial Public Offering
    Inversions
    Portfolio Balances
    Prime Factor Visitation
    Profit Targets
    Sprint Training
    Throttling Gateway
    Birthday Card Collection


Triplets

Question description: Given an array of integers, find all unique triplets that sum up to a target value.

    Start by sorting the array in ascending order to simplify the problem.
    Use a nested loop to iterate over all possible pairs of numbers in the array.
    For each pair, check if the target value minus the sum of the pair exists in the array. If it does, you have found a valid triplet.

Ways to Sum

Question description: Given a target value and a list of positive integers, find all possible unique combinations of the integers that sum up to the target value.

    Use recursion to generate all possible combinations of the integers. At each step, you can either include the current integer or skip it.
    To avoid generating duplicate combinations, always start the next recursion at the current index in the array.
    Use memoization to cache the results of previous function calls to avoid redundant calculations.

Consecutive Sum

Question description: Given an integer n, find the number of ways to express n as the sum of consecutive positive integers.

    Use algebraic manipulation to simplify the problem. We can express n as (x + 1) + (x + 2) + ... + (x + k) for some integers x and k. This simplifies to k * (2x + k + 1) / 2 = n.
    Iterate over all possible values of k and solve for x using the simplified equation. If x is an integer, then there exists a valid consecutive sum that adds up to n.
    Since we are only interested in counting the number of valid consecutive sums, we can stop iterating once k exceeds the square root of 2n.

Disk Space Analysis

Question description: Given a list of integers representing the sizes of files and the total amount of disk space, determine the minimum contiguous subarray of files that can be deleted to free up enough space.

    Use a sliding window approach to iterate over all possible contiguous subarrays of the list.
    For each subarray, keep track of the sum of its elements and the indices of its start and end points.
    When the sum exceeds the total disk space, move the start index of the subarray to the right until the sum is less than the total disk space again. This will minimize the length of the subarray while still freeing up enough space.

Do They Belong?

Question description: Given two lists of integers A and B, determine which elements of A are present in B and which are not.

    Use a set to store the elements of B for efficient membership testing.
    Iterate over the elements of A and check if each element is in the set of B. Keep track of which elements are present and which are not.
    Return the two lists of present and absent elements.

Global Maximum

Question description: Given an array of integers, find the global maximum value and the index at which it occurs.

    Use a linear scan of the array to find the maximum value and its index. Initialize the maximum value and index to the first element of the array.
    Iterate over the remaining elements of the array and update the maximum value and index if a larger value is found.
    Return the maximum value and index.

Initial Public Offering

Question description: Given a list of positive integers representing the prices of stocks on different days, determine the maximum profit that can be made by buying and selling a single share of stock.

    Use a linear scan of the list to keep track of the minimum price seen so far and the maximum profit that can be made by selling at the current price.
    For each price, update the minimum price seen so far and calculate the profit that can be made by selling at the current price minus the minimum price. Update the maximum profit if this profit is greater
    Return the maximum profit.

Inversions

Question description: Given an array of integers, find the number of inversions in the array. An inversion occurs when two elements i and j in the array satisfy i < j but a[i] > a[j].

    Use a modified merge sort algorithm to count the number of inversions. Divide the array into two halves and recursively count the inversions in each half.
    When merging the two sorted halves, keep track of the number of inversions between the two halves. Since the two halves are already sorted, any inversion involving elements from both halves will be detected during the merge.
    Add up the number of inversions in the left half, the right half, and the merged halves to get the total number of inversions in the array.

Portfolio Balances

Question description: Given a list of transactions in the format (name, amount), determine the final balance of each person in the list.

    Use a dictionary to store the balance of each person. Iterate over the list of transactions and update the balance of each person accordingly.
    If a person's balance becomes zero, remove them from the dictionary to simplify the final output.
    Sort the dictionary by person name and return the final balances as a list of (name, balance) pairs.

Prime Factor Visitation

Question description: You are given a starting number n and a list of prime factors. Each second, you can either multiply n by one of the prime factors or divide n by one of the prime factors. Determine the minimum number of seconds required to reach a target number t.

    Use a breadth-first search algorithm to explore all possible sequences of operations that can be applied to n to reach t.
    At each step of the search, generate all possible operations (multiply or divide by each prime factor) and add the resulting numbers to a queue to be explored in the next step.
    Stop the search when the target number is reached and return the number of steps taken to reach it.

Profit Targets

Question description: You are given a list of stock prices and a profit target. Determine whether there exists a pair of prices in the list such that selling at the higher price and buying at the lower price yields a profit greater than or equal to the profit target.

    Use a two-pointer approach to iterate over all possible pairs of prices. Initialize two pointers to the first element of the list.
    While the difference between the prices pointed to by the two pointers is less than the profit target, move the higher pointer to the right.
    If the difference between the prices pointed to by the two pointers is greater than or equal to the profit target, return True. If the higher pointer reaches the end of the list, move the lower pointer to the right and repeat the process until all pairs have been checked.

Sprint Training

Question description: You are given an array of n integers representing the running times of sprint training sessions. You want to schedule k sprint training sessions such that the maximum total running time is minimized. Determine the minimum value of the maximum total running time.

    Use binary search to find the minimum value of the maximum total running time. Initialize the search range to [0, sum(times)].
    At each step of the search, use a greedy algorithm to schedule the training sessions such that no session exceeds the current maximum total running time. If it is possible to schedule all sessions within the time limit, the search range can be lowered to [minimum time, current time].
    When the search range has converged to a single value, return that value as the minimum maximum total running time.

Throttling Gateway

Question description: You are given an array of n integers representing the number of API requests made at different times. Determine the maximum number of API requests that can be made in any given minute, subject to the following constraints:
    No more than 3 requests can be made in any 1 second time interval.

    No more than 20 requests can be made in any 1 minute time interval.

    Iterate over the array of request times and count the number of requests made in each second.

    Iterate over the counts and for each second, calculate the number of requests that need to be throttled in order to meet the 3 requests per second constraint.

    Iterate over the counts again and for each minute, calculate the number of requests that need to be throttled in order to meet the 20 requests per minute constraint.

    Return the maximum count of requests that can be made in any given minute, taking into account the throttling that needs to be applied in each second and minute.

