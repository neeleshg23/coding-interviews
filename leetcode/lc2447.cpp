#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Recursive Sliding Window 
 */
//void helper(vector<int>& nums, int l, int r, int n, int k, int res, bool leftNew);
//
//int subarrayGCD(vector<int>& nums, int k) {
    //int N = nums.size();
    //int L = 0;
    //int R = 0;
    //int res = 0;
    //helper(nums, L, R, N, k, res, false);
    //return res;
//}
//
//void helper(vector<int>& nums, int l, int r, int n, int k, int res, bool leftNew)
//{
    //if (l == n && r == n) return;
    //if (l < 0) return;
    //if (l == r && nums[l] == k)
    //{
        //res++;
        //helper(nums, l-1, r, n, k, res, true);
        //helper(nums, l, r+1, n, k, res, false);
    //} else if (l!=r)
    //{
        //if (nums[l]%k==0 && leftNew) 
        //{
            //res++;
            //helper(nums, l-1, r, n, k, res, true);
        //} else if (nums[r]%k==0 && !leftNew)
        //{
            //res++;
            //helper(nums, l, r+1, n, k, res, false );
        //}
    //}
    //while(l!=r) l++;
    //helper(nums, r+1, l+1, n, k, res, false);
//}

/**
 * Euclid'd GCD
 */
int euclidGcd(int a, int b)
{
    int r=a%b;
    if(r==0) return b;
    return euclidGcd(b, r);
}
/**
 * Brute Force Solution
 */
int subarrayGCD_brute(vector<int>& nums, int k)
{
    int res=0;
    for(int i=0;i<nums.size();i++)
    {
        for (int j=i;j<nums.size(); j++)
        {
            if (nums[j]%k) break;    
            nums[i] = euclidGcd(nums[i], nums[j]);
            res+=nums[i]==k;
        }
   }
   return res;
}

int subarrayGCD(vector<int>& nums, int k)
{
    int res=0;
    unordered_map<int, int> gcd;

    for(auto num: nums){
        if (!(num%k))
        {
           unordered_map<int, int> next;
           next[num]=1;
           for (auto [prevGCD, cnt]:gcd)
           {
               next[euclidGcd(prevGCD, num)]+=cnt;
           }
           res+=next[k];
           gcd=move(next);
        }
        else
        {   // GCD Streak Stops
            gcd.clear();
        }
    }
    return res;
}
int main(int argc, char** argv){
    vector <int> v{9,3,1,2,6,3};
    int k=3;
    int res = subarrayGCD(v, k);
    cout << res << endl;
    return 0;
}
