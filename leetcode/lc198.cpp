#include <bits/stdc++.h>
using namespace std;

int robHelper(vector<int>& nums, int i){
    if (i < 0) return 0;
    return max(robHelper(nums, i-2) + nums[i], robHelper(nums, i-1));
}

int rob1(vector<int>& nums){
    int n = nums.size();
    return robHelper(nums, n-1);
}

int robHelper(vector<int>& nums, vector<int>& dp, int i){
    if (i < 0) return 0;
    if (dp[i] > -1) return dp[i];
    int result = max(robHelper(nums,dp, i-2) + nums[i], robHelper(nums, dp, i-1));
    dp[i] = result;
    return result;
}

int rob2(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n+1, -1);
    return robHelper(nums, dp, n-1);
}

int rob3(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = nums[0];
    for(int i=1; i<n; i++){
        dp[i+1] = max(dp[i], dp[i-1] + nums[i]);
    }
    return dp[n];


int rob(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n+1);
    int prevSum = 0;
    int currSum = nums[0];
    for(int i=1; i<n; i++){
        int newSum = max(currSum, prevSum + nums[i]);
        prevSum = currSum;
        currSum = newSum;
    }
    return currSum; 
}

int main(){
    vector<int> n = {1,2,3,1};
    cout << rob(n) << endl;
    vector<int> m = {2,7,9,3,1};
    return 0;
}
