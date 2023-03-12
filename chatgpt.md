Triplets
Approach

    First of all, we will sort the given array.
    After that, we will use three nested loops and do the following
        Fix the first index 'a' to the index at the outer loop.
        Fix the second index 'b' to the index next to the first index 'a' in the middle loop.
        In the innermost loop, iterate from the index next to the second index 'b' to the end of the array.
        In this loop, check the condition that arr[a] + arr[b] + arr[c] should be less than or equal to 't' and arr[b] should be less than arr[c].
        If the above condition is true, then increment the count of triplets.

Complexity

    Time Complexity: O(n^3)
    Space Complexity: O(1)

Ways to Sum
Approach

    We can solve this problem using Dynamic Programming
    We will create an array 'dp' of size 'total + 1' and initialize it with 0.
    For each index i from 0 to k, we will do the following:
        Set dp[i] = 1
        For each index j from i+1 to total, we will do the following:
            dp[j] += dp[j-i] % 1000000007
    Finally, return dp[total]

Complexity

    Time Complexity: O(total * k)
    Space Complexity: O(total)

Disk Space Analysis
Approach

    We will start by initializing the 'max_min' variable to the minimum of the first 'x' elements of the 'space' array.
    After that, we will iterate from the index '1' to the index 'n - x + 1' of the 'space' array.
    In each iteration, we will do the following:
        Find the minimum value of the subarray starting at the current index and having length 'x'.
        Update the 'max_min' variable if the minimum value found above is greater than the current value of 'max_min'.
    Finally, we will return the 'max_min' variable.

Complexity

    Time Complexity: O(n)
    Space Complexity: O(1)

Do They Belong?
Approach

    We will calculate the distance between the points and check if the given points form a valid triangle or not.
    If the given points form a valid triangle, then we will check if the points belong to the triangle using the following method:
        We will find the area of the triangle formed by the three given points.
        We will find the area of the three triangles formed by replacing one point of the original triangle with the given point.
        If the sum of the areas of the three triangles is equal to the area of the original triangle, then the given point belongs to the triangle.
        If the sum of the areas of the three triangles is less than the area of the original triangle, then the given point does not belong to the triangle.
    Using the above method, we will check for both points 'p' and 'q' and return the scenario accordingly.

Complexity

    Time Complexity: O(1)
    Space Complexity: O(1)

Global Maximum
Approach

    We will first find the maximum element of the given array.
    After that, we will iterate through the array and for each element, we will do the following:
        Calculate
    Initialize two variables globalMax and localMax to zero.
    Iterate through the input array and for each element, do the following:
        If the element is greater than globalMax, update globalMax to the element.
        If the element is greater than localMax, update localMax to the element.
        If the element is less than localMax, reset localMax to zero.
    Return the globalMax.

The time complexity of this algorithm is O(n), where n is the length of the input array. This is because we iterate through the input array only once.
