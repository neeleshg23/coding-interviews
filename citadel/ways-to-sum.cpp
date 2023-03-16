#include <bits/stdc++.h>

using namespace std;

int waysToSum(int total, int k){
    const int MOD = 1e9 + 7;
    vector<int> dp(total+1);
    dp[0] = 1;
    for (int i = 1; i<=k; i++){
        for (int j = i; j <= total; j++){
            dp[j] = (dp[j] + dp[j-i]) % MOD;
        }
    }
    return dp[total];
}

int main(){
    cout << waysToSum(8,2) << endl;
    cout << waysToSum(8,3) << endl;
    cout << waysToSum(20,11) << endl;
    cout << waysToSum(100,8) << endl;
    cout << waysToSum(100,10) << endl;
    cout << waysToSum(500,50) << endl;
    cout << waysToSum(1000,100) << endl;
    return 0;
}
