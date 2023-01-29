#include<iostream>

using namespace std;

void Z(int &n)
{
    n *= 2; 
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
