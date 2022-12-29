#include<iostream>
#include<string>
using namespace std;

int appendCharacters(string s, string t)
{
    int tIdx=0;
    while(tIdx<t.length())
    {
        char ch=t[tIdx];
        if(s.find(ch)<s.length()) 
        {
            t.erase(t.begin());
        }
        else
        {
            return t.length();
        }
    }
    return 0;
}

int main()
{
    string s="coaching";
    string t="coding";
    cout<<appendCharacters(s,t)<<endl;
    s="abcde";
    t="a";
    cout<<appendCharacters(s,t)<<endl;
    s="z";
    t="abcde";
    cout<<appendCharacters(s,t)<<endl;
    return 0;
}
