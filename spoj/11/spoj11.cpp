#include<iostream>

using namespace std;

int Z(int &n)
{
    if (n<0) return -1;
    int res=0;
    int i=5;
    while(n/i >= 1){
        res+=n/i;
        i*=5;
    }
    return res;
}

int main()
{
    int T;
    cin >> T;
    while(T-- > 0)
    {
        int N;
        cin >> N;
        cout << Z(N) << endl; 
    }
    return 0;
}
