#include<iostream>
#include<vector>
using namespace std;

int coinChange(vector<int>& coins, int amt)
{
    // Base Case
    if(amt==0) return 0;

    int res=0;
    int maxCoinIdx=coins.size()-1;
    while(amt>0)
    {
#if DEBUG
        cout<<"t-"<<amt<<" curC-"<<coins[maxCoinIdx]<<endl; 
#endif 
        if(amt>=coins[maxCoinIdx])
        {
            amt-=coins[maxCoinIdx];
            res++;
        }
        else
        {
            maxCoinIdx--;
            if(maxCoinIdx==-1) return -1;
        }
    }
    return amt==0? res: -1;
}

int main()
{
vector<int> v{1,2,5};
int t=11;
cout<<coinChange(v,t)<<endl;
    v.clear();
    v.push_back(2);
    t=3;
    cout<<coinChange(v,t)<<endl;
    
    v.clear();
    v.push_back(1);
    t=0;
    cout<<coinChange(v,t)<<endl;
 
    return 0;
}
