#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isValid(vector<int>& price, int min, int k, int n);

int maximumTastiness(vector<int>& price, int k)
{
    int n=price.size();
    sort(price.begin(), price.end());
    int low=0;
    int high=price[n-1];
    int res=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(isValid(price, mid, k, n))
        {
            low=mid+1;
            res=mid;
        }else
        {
            high=mid-1;
        }
    }
    return res;
}

bool isValid(vector<int>& price, int min, int k, int n)
{
    int candies=1;
    int recentCandy=price[0];
    for(int i=1;i<n;i++)
    {
        if(price[i]-recentCandy>=min)
        {
            candies++;
            recentCandy=price[i];
            if(candies>=k) return true;
        }
    }
    return false;
}

int main()
{
    vector<int> price{13,5,1,8,21,2};
    int k=3;
    cout<<maximumTastiness(price,k)<<endl;
    vector<int> p{1,3,1};
    k=2;
    cout<<maximumTastiness(p,k)<<endl;
    vector<int> a{7,7,7,7};
    k=2;
    cout<<maximumTastiness(a,k)<<endl;
    return 0;
}
