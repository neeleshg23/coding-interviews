#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    int res = 0;
    int sum = 0;
    int rem = 0;
    unordered_map<int,int> freqs;
    freqs[0] = 1;

    for (auto e: nums){
        sum += e;
        rem = sum % k;
        if (rem < 0) rem += k;
        if (freqs.find(rem) == freqs.end()){
            freqs[rem] = 1;
        }else{
            res += freqs[rem];
            freqs[rem]++;
        }
    }
    return res;
}

int main(){
    vector<int> v{2,3,5,4,5,3,4};
    cout << subarraysDivByK(v, 7) << endl;
    v = {2,-6,3,1,2,8,2,1};
    cout << subarraysDivByK(v, 7) << endl;
    return 0;
}