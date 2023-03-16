#include <bits/stdc++.h>

using namespace std;

int triplets(vector<int> arr, int t){
    int n = arr.size();
    int res = 0;
    sort(arr.begin(), arr.end());
    for (int i=0; i< n-2; i++){
        int j = i+1;
        int k = n-1;
        while (j<k){
            if (arr[i] + arr[j] + arr[k] > t){
                k--;
            } else {
                res += (k-j);
                j++;
            }
        }
    }
    return res;
}

int main(){
    vector<int> a{1,2,3,4,5};
    cout << triplets(a,8) << endl;
}