#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int coinChangeGreedy(vector<int>& coins, int amt)
{
    // Base Case
    sort(coins.begin(), coins.end());
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

int coinChange(vector<int>& c, int t)
{
    return 0;
}

int main()
{
    vector<int> v{186,419,83,408};
    int t=6249;
    cout<<coinChange(v,t)<<endl;
 
    return 0;
}
