# include <bits/stdc++.h>

using namespace std;

int numPairsDivisibleBy60(vector<int>& times){
    int ans = 0;
    vector<int> count(60);

    for (auto e: times) {
        int rem = e % 60;
        ans += count[(60 - rem) % 60];
        count[rem]++;
    }

    return ans;
}

int main(){
    vector<int> v{1,2,58,59,30,150,118,62};
    cout << numPairsDivisibleBy60(v) << endl;
    return 0;
}