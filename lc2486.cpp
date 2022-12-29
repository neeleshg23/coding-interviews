#include<iostream>
#include<string>
using namespace std;

int makeSubsequence(string s, string t)
{
    int prevS=-1;
    for(auto ch: t)
    {
        cout<<"prev "<<prevS<<" new "<<s.find(ch,0)<<endl;
        cout<<s.find(ch,0)<<endl;
        if(s.find(ch,0)<s.length() && prevS < s.find(ch,0))
        {
            t.erase(t.begin());
            prevS=s.find(ch,0);
        }
        else
        {
            return t.length();
        }
    }
    return 666;
}

int main()
{
    string s="coaching";
    string t="coding";
    cout<<makeSubsequence(s,t)<<endl;
    return 0;
}
