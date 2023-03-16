#include <bits/stdc++.h>

int main(){
    cout << consecutiveSum(5) << endl;
    cout << consecutiveSum(9) << endl;
    cout << consecutiveSum(15) << endl;
    return 0;
}

int consecutiveSum(int n) {
    int res = 0;
    int sqrtN = sqrt(2*n);
    for (int k=1; k <= sqrtN ; k++){
        if ((n - k*(k-1)/2) % k == 0){
            res++;
        }
    }
    return res;
}