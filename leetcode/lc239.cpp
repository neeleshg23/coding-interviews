#include <bits/stdc++.h>

using namespace std;


void print_deque(deque<int>& d, vector<int>& nums){
    for (auto e: d){
        cout << e <<" ("<< nums[e] << ") ";
    }
    cout << endl;
}
/**
 * @brief Given an array nums, return the maximum of each sliding window
 * 
 * Use a deque that maps indexes to values
 * 
 * Create a decreasing monotonic deque which pop's values that are
 * - out of range (too far to the left)
 * - less than the a valid possible max ()
 * 
 * Front of deque will hold max, end of deque 
 * 
 * @param nums array of numbers
 * @param k window size which you see
 * @return vector<int> 
 */
vector<int> slidingWindowMax(vector<int>& nums, int k){    
    int n = nums.size();
    vector<int> res;
    deque<int> dq;

    for (int i=0; i<n; i++){
        /**
         * Remove elements which were in range and maximal but now out of range
         */
        if (!dq.empty() && dq.front() == i-k){
            dq.pop_front();
        }
        /**
         * Remove elements which are minimal to the current element
         */
        while (!dq.empty() && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        /**
         * Only after we have read k elements, can we append max values to the res
         */
        if (i>=k-1) res.push_back(nums[dq.front()]);
    }
    return res;
}

int main(){
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    vector<int> res = slidingWindowMax(nums,3);
    for (auto e: res){
        cout << e << " ";
    }
    return 0;
}