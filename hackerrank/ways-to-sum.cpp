#include <bits/stdc++.h>

using namespace std;

int waysToSum(int total, int k){
    return 1;
}

int main(){
    int n;
    int t;
    int k;
    cin >> n;
    while(n-- > 0){
        cin >> t >> k;
        cout << waysToSum(t,k) << endl;
    }
    return 0;
}
