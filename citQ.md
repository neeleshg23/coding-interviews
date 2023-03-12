Triplets

Given an array of n distinct integers, and an integer threshold, how many (a,b,c) index triplets exists that satisfy both of the following conditions?

    arr[a] < arr[b] < arr[c]
    arr[a] + arr[b] + arr[c] <= t

Parameter

    arr: an array of integers
    t: an integer threshold

Result

    An integer that denotes the number of (a,b,c) triplets that satisfy the given conditions.

Example

Input: arr = [1, 2, 3, 4, 5], t = 8

The following 4 triplets satisfy the constraints: (1,2,3), (1,2,4), (1,2,5), (1,3,4).

Output: 4

## Ways to Sum

An automated packaging system is responsible for packing boxes. A box is certified to hold a certain weight. Given an integer total, calculate the number of possible ways to achieve total as a sum of weights of items weighing integer from 1 to k, inclusive.

Parameter

    total: the value to sum to
    k: the maximum of the range of integers to consider when summing to total

Result

    the number of ways to sum to the total; the number might be very large, so return the integer modulo 1000000007(10^9+7)

Example

Input: total = 8, k = 2

To reach a weight of 8, there are 5 different ways that items with weights between 1 and 2 can be combined:

    [1,1,1,1,1,1,1,1]
    [1,1,1,1,1,1,2]
    [1,1,1,1,2,2]
    [1,1,2,2,2]
    [2,2,2,2]

Output: 5
Constraints

    1 <= total <= 1000
    1 <= k <= 100

## Disk Space Analysis

A company is performing an analysis on the computers at its main office. The computers are spaced along a single row.

The analysis is performed in the following way:

    Choose a contiguous segment of a certain number of computers, starting from the beginning of the row.
    Analyze the available hard disk space on each of the computers.
    Determine the minimum available disk space within this segment.

After performing these steps for the first segment, it is then repeated for the next segment, continuing this procedure until the end of the row (for example, if the segment size is 4, computers 1 to 4 would be analyzed, then 2 to 5, etc.) Given this analysis procedure, find the maximum available disk space among all the minima that are found during the analysis.

Input

    space: the available hard disk space on each of the computers
    x: the segment length to analyze

Output

the maximum of the minimum values available
Examples
Example 1:

Input:

space = [8,2,4]

x = 2

Output: 2

Explanation:

In this array of computers, the subarrays of size 2 are [8, 2] and [2, 4]. Thus, the initial analysis returns 2 and 2 because those are the minimal for the segments. Finally, the maximum of these values is 2. Therefore, the answer is 2.
Constraints

    1<=n<=10^6
    1<=x<=n
    1<=space[i]<=10^9


Do They Belong?

A triangle is formed by the three points a(x1, y1), b(x2, y2) and c(x3, y3) is a non-degenerate triangle if the following rules are respected (`|ab| is the length of the line between points a and b):

    |ab| + |bc| > |ac|
    |bc| + |ac| > |ab|
    |ab| + |ac| > |bc|

A point belongs to a triangle if it lies somewhere on or inside the triangle. Given two points p = (xp, yp) and q = (xq, yq), return the correct scenario number:

    0. If the triangle abc does not form a valid non-degenerative triangle.
    1. If point p belongs to the triangle but point q does not.
    2. If point q belongs to the triangle but point p does not.
    3. If both points p and q belong to the triangle.
    4. If neither point p nor point q belong to the triangle.

Input

    x1: see statement
    y1: see statement
    x2: see statement
    y2: see statement
    x3: see statement
    y3: see statement
    xp: see statement
    yp: see statement
    xq: see statement
    yq: see statement

Output

an integer value represents the scenario
Examples
Example 1:

Input:

x1 = 2

y1 = 2

x2 = 7

y2 = 2

x3 = 5

y3 = 4

xp = 4

yp = 3

xq = 7

yq = 4

Output: 7

Explanation:

The point p(5, 4) belongs to the triangle and the point q(7, 4) does not.

Global Maximum

Consider an array of distinct positive integers where elements are sorted in ascending order. We want to find all the subsequences of array consisting of exactly m elements. For example, given array a=[1,2,3,4], the subsequences consisting m=3 elements are [1,2,3], [1,2,4], [1,3,4], and [2,3,4]. Once we have all of the m-element subsequences, we find the value of globalMaximum using the following pseudocode:

globalMaximum = 0


for each subsequence, s, consisting of m elements {

    currentMinimum = 10^18


    for each (x,y) pair of elements in subsequence s {

        absoluteDifference = abs(x - y)


        if absoluteDifference < currentMinimum {

            currentMinimum = absoluteDifference

        }

    }


    if currentMinimum > globalMaximum {

        globalMaximum = currentMinimum

    }

}

Input

    arr: a sorted array of distinct integers
    m: an integer, the subsequences' length

Output

the global maximum calculated per the pseudocode
Examples
Example 1:

Input:

arr = [2,3,5,9]

m = 3

Output: 3

Explanation:

First find all subsequences of length m.

[2,3,5]

[2,3,9]

[2,5,9]

[3,5,9]

The final answer is globalMaximum=3 for subsequence [2,5,9].
Constraints

    2<=n<=10^5
    1<=a[i]<=10^9
    The array consists of distinct positive integers sorted in ascending order.
    2<=m<=n


Initial Public Offering

A company registers an IPO on a website sellshares.com. All the shares on this website are available for bidding for a particular time frame called the bidding window. At the end of the bidding window an auction logic is used to decide how many of the available shares go to which bidder until all the shares that are available have been allotted, or all the bidders have received the shares they bid for, whichever comes earlier.

The bids arrive from the users in the form of <user Id, number of shares, bidding price, timestamp> until the bidding window is closed.

The auction logic assigns shares to the bidders as follows:

    The bidder with the highest price gets the number of shares they bid for
    If multiple bidders have bid at the same price, the bidders are assigned shares as follows: Each bidder in the same price group gets assigned one share each consecutively, with each bidder being arranged inside the group based on their timestamp. Once a bidder gets the number of shares they bid for, they will be removed from the above iterative process and the process which then continues until all bidders are removed or the shares get exhausted, whichever comes first.

List the user Id's of all users who did not get even one share after the shares have been allocated.

Input

    bids: a 2D array of arrays of integers, Id, shares, price, timestamp named u, sc, bp, ts going forward
    total_shares: an integer, the total shares to allocate

Output

a list of integers, each an Id for those bidders who receive no shares, sorted ascending
Examples
Example 1:

Input:

bids = [[1, 5, 5, 0], [2, 7, 8, 1], [3, 7, 5, 1], [4, 10, 3, 3]]

total_shares = 18

Output: 4

Explanation:

The highest price bid is for user Id 2 for 7 shares at a price of 8, so that user gets 7 shares leaving 11 to allocate to lower prices. Users with Id's 1 and 3 each bid 5 for 5 and 7 shares, with bidder 1 having the earlier timestamp. After 5 iterations, 10 shares have been allocated with 5 shares going to each of these two bidders. Bidder 1 has the full allotment, bidder 3 has 2 more shares to buy and there is 1 share left to allocate. It goes to bidder 3 and all shares have been allotted. Bidder 4 is the only bidder who gets no shares.
Constraints

    1<=n<=10^4
    1<=u, sc, bp, ts, total_shares<=10^9

Inversions 

A subsequence is created by deleting zero or more elements from a list while maintaining the order. For example, the subsequences of [1,2,3] are [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]. An inversion is a strictly decreasing subsequence of length 3. More formally, given an array p=p[n] an inversion in the array is any time some p[i]>p[j]>p[k] and i<j<k.

Determine the number of inversions within a given array.

Input

    arr: a array of integers

Output

a long integer denoting the number of inversions in the array
Examples
Example 1:

Input:

arr = [5,3,4,2,1]

Output: 7

Explanation:

The array inversions are:

[5,3,2]

[5,3,1]

[5,4,2]

[5,4,1]

[5,2,1]

[3,2,1]

[4,2,1]

Example 2:

Input:

arr = [4,4,2,1]

Output: 2

Explanation:

The array inversions are:

[4,2,1]

[4,2,1]

Constraints

    1<=n<=5000
    1<=arr[i]<=10^6

Portfolio Balance

An investor opens a new account and wants to invert in a number of assets. Each asset begins with a balance of 0, and its value is stored in an array using 1-based indexing. Periodically, a contribution is received and equal investments are made in a subset of the portfolio. Each contribution will be given by investment amount, start index, end index. Each investment in that range will receive the contribution amount. Determine the maximum amount invested in any one investment after all contributions.

Input

    n: the number of investments available
    rounds: an [k][3] array of integers, each rounds[i] contains 3 integers, [left, right, contribution]

Output

the maximum invested in any one asset
Examples
Example 1:

Input:

n = 5

rounds = [[1, 2, 10], [2, 4, 5], [3, 5, 12]]

Output: 17

Explanation:

For example, start with an array of 5 elements: investments = [0,0,0,0,0]*. The variables left and right represent the starting and ending indices, inclusive. Another varible, contribution, is the new funds to invest per asset. The first investment is at index 1.
left	right	contribution	investments
			[0,0,0,0,0]
1	2	10	[10,10,0,0,0]
2	4	5	[10,15,5,5,0]
3	5	12	[10,15,17,17,12]

In the first round, a contribution of 10 is made to investment 1 and 2. In the second round, a contribution of 5 is made to assets 2,3 and 4. Finally, in the third round, a contribution of 12 is added to investments 3, 4 and 5.The maximum inverted in any one asset is 17.

*Note: The investments array is not provided in the function. It is to be created after the number of assets available is known.
Constraints

    3<=n<=10^7
    `1<=o<=2*10^5
    1<=left<=right<=n
    0<=contribution<=10^9




