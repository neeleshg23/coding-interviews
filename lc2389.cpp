#include<iostream>
#include<vector>
using namespace std;

vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    int m=queries.size();
    sort(nums.begin(), nums.end());
    vector<int> res(m,0);
    for (int i=0; i<m; i++)
    {
        int runningSum=0;
        for (auto n: nums)
        {
            runningSum += n;
            if (runningSum <= queries[i])
            {
                res[i]++;
            }else
            {
                break;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> n{4,5,2,1};
    vector<int> q{3,10,21};
    vector<int> res=answerQueries(n,q);
    for(auto e:res)
    {
        cout<<e<<" ";
    }
    cout<<endl;
}
