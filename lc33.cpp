#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target)
{
    int lo=0;
    int hi=nums.size()-1;
    int m=0;
    while(lo<hi)
    {
        m=(lo+hi)/2;
        if(nums[lo]>nums[m])
        {
            lo=m+1;
        }
        else
        {
            hi=m;
        }
    }
    //smallest element is now held index lo and hi
    
    cout<<"p idx="<<hi<<endl;
    return 1;    
}

int main(){
    vector<int> v{4,5,6,7,0,1,2};
    int target=0;
    cout<<search(v,target)<<endl;
    return 0;
}
