#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isValid(int n, int c, int minDistance, vector<int>& stalls)
{
    int cows=1;
    int smallestDistance=stalls[0];
    for(int i=1; i<n; i++)
    {
        if(stalls[i]-smallestDistance>=minDistance)
        {
            cows++;
            smallestDistance=stalls[i];
            if(cows>=c) return true;
        }
    }
    return false;
}
int aggressiveCows(int n, int c, vector<int>& st)
{
    sort(st.begin(), st.end());
    int low=1;
    int high=st[n-1]-st[0];
    int res=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
#if DEBUG
        cout<<"l "<<low<<" m "<<mid<<" h "<<high<<endl;
#endif
        if (isValid(n, c, mid, st))
        {
            res=mid;
            low=mid+1;
        }else
        {
            high=mid-1;
        }
    }
    return res;
}


int main() {
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, c;
        cin >> n >> c;
        vector<int> stalls;
        for(int i=0; i<n; i++)
        {
            int temp;
            cin >> temp;
            stalls.push_back(temp);
        }
        cout << aggressiveCows(n, c, stalls) << endl;
    } 
    return 0;
}
