#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;

int closestTarget(vector<string>& words, string target, int startIndex)
{
    int res=INT_MAX;
    int n=words.size();
    for(int i=0; i<n; i++)
    {
        if(target == words[i])
        {
            res=min(res,min(abs(startIndex-i), n-abs(startIndex-i)));
        }
    }
    return res==INT_MAX? -1: res;
}

int main()
{
    vector<string> w{"hello","i","am","leetcode", "hello"};
    string t="hello";
    int s=1;
    cout<<closestTarget(w,t,s)<<endl;
    return 0;
}
