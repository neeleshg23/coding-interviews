#include<bits/stdc++.h>
using namespace std;

int consecutiveNumbersSum(int n){
    int res = 0;
    for (int k=1; pow(k,2) < 2*n; k++){
        if ((n - k*(k-1)/2) % k == 0){
            res++;
        }
    }
    return res;
}

int main(){
    cout << consecutiveNumbersSum(5) << endl;
    cout << consecutiveNumbersSum(9) << endl;
    cout << consecutiveNumbersSum(15) << endl;
    return 0;
}