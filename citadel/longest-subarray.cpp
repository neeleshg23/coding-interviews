# include <bits/stdc++.h>
using namespace std;

int maxLength(vector<int>& arr, int k){
    int n = arr.size();
    int sum = 0;
    int cnt = 0;
    int maxCnt = 0;
    for (int i=0; i<n; i++){
        if (sum + arr[i] <= k){
            sum += arr[i];
            cnt++;
        } else if (sum != 0){
            sum = sum - arr[i - cnt] + arr[i];
        }
        maxCnt = max(maxCnt, cnt);
    }
    return maxCnt;
}

int main(){
    vector<int> v{1,2,3};
    cout << maxLength(v, 3) << endl;
}