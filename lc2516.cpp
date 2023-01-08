#include<iostream>
#include<string>
using namespace std;

void takeHelper(string s, int k, int (&letters)[3], int& res, int& count)
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
    takeHelper(s, k, arr, res, );
    return res;
}

int takeCharacters(string s, int k)
{
    // two pointer solution
}

int main()
{
    string s="aabaaaacaabc";
    int k=2;
    takeCharacters(s, k);
    return 0;
}
