#include<iostream>
#include<string>
#include<climits>
#include<unordered_map>
using namespace std;

void takeHelper(string s, int k, int (&letters)[3], int& res)
{
    int n=s.length();
    for(int i=0; i<3; i++)
    {     
        if (letters[i]!=0) break;
        else if (letters[i] == 0 && i==2) return;
    }

    if(n == 0) {
        res = -1;
        return;
    }
   
#if DEBUG
    cout<<s<<" a "<<letters[0]<<" b "<<letters[1]<<" c "<<letters[2]<<" t "<<res<<endl;
#endif
    res++;
    string temp = s;
    int whichOne = -1;
    //take from the left
    char front = *(s.begin());
    s.erase(s.begin());
    if(front == 'a') 
    {
        whichOne=0;
        letters[0]--;
    }
    else if(front == 'b') 
    {
        whichOne=1;
        letters[1]--;
    }
   else if(front == 'c') 
    {
        whichOne=2;
        letters[2]--;
    }
    takeHelper(s, k, letters, res);

    letters[whichOne]++;
    char back = *(temp.end());
    temp.erase(temp.end());
    if(back == 'a') letters[0]--;
    else if(back == 'b') letters[1]--;
    else if(back == 'c') letters[2]--;
    takeHelper(temp, k, letters, res);
}

int takeCharactersRecursion(string s, int k)
{
    int arr[3] = {k, k, k};
    int res=0;
    takeHelper(s, k, arr, res);
    return res;
}

void printMp(unordered_map<char,int> mp)
{
    for (const auto &[k, v] : mp)
    {
        cout <<"(" <<k<< ", " <<v<< ") " << endl;
    }
}
int takeCharacters(string s, int k)
{
    // two pointer solution
    int n=s.length();
    unordered_map<char,int> count;
    for(auto ch:s)
        count[ch]++;
    if(count['a']<k||count['b']<k||count['c']<k)
        return -1;
    int windowStart=n-1;
    int windowEnd=n-1;
    int minTimeReq=INT_MAX;
    while(windowStart >= 0)
    {
        count[s[windowStart]]--;
        while(count[s[windowStart]] < k)
        {
            count[s[windowEnd]]++;
            windowEnd--;
        }
        windowStart--;
#if DEBUG
        int i=0;
        for(i=0;i<windowStart;i++)
            cout<<"*";
        for(i=windowStart;i<windowEnd;i++)
            cout<<"+";
        for(i=windowEnd;i<n;i++)
            cout<<"*";
        cout<<endl;
        cout<<s<<endl;
        cout<<"res="<<windowStart-windowEnd+n<<endl;
        printMp(count);
#endif
        minTimeReq = min(minTimeReq,(n-windowEnd)+windowStart);
    }
    return minTimeReq;
}

int main()
{
    string s="aabaaaacaabc";
    int k=2;
    cout<<takeCharacters(s, k)<<endl;
    s="a";
    k=1;
    cout<<takeCharacters(s, k)<<endl;
    return 0;
}
