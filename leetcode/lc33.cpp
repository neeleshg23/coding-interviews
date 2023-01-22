#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target)
{
    int l=0;
    int r=nums.size()-1;
    int m=0;

    while(l<=r)
    {
        m=(r-l)/2 + l;
#if DEBUG
        cout<< "L-"<<l<<" M-"<<m<<" R-"<<r<<endl;
#endif 

        if(nums[m]==target) return m;
        
        //left sorted portion
        if(nums[l]<=nums[m])
        {
           if(target<nums[l])
           {
              //search right
              l=m+1;
           }else if(target>nums[m])
           {
              l=m+1;
           }else if(target<nums[m]){
              r=m-1;
           }
        } else
        {
            if(target>nums[r])
            {
                r=m-1;
            }else if(target<nums[m])
            {
                r=m-1;
            }else if(target>nums[m])
            {
                l=m+1;
            }
        }
    }   

    return -1;    
}

int main(){
    vector<int> v{4,5,6,7,0,1,2};
    int target=3;
    cout<<search(v,target)<<endl;
    return 0;
}
