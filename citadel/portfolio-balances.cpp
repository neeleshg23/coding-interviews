#include <bits/stdc++.h>
using namespace std;

int max_value(int n, vector<vector<int>> rounds){
    vector<int> cnts(n+2, 0);
    for (auto r: rounds){
        cnts[r[0]] += r[2];
        cnts[r[1]+1] -= r[2];
    }
    int curr = 0;
    for (int i=1; i<n+1; i++){
        curr += cnts[i];
        cnts[i] = curr;
    }
    int res = INT_MIN;
    for (auto e: cnts){
        res = max(res, e);
    }
    return res;
}

int main(){
    vector<vector<int>> v{{1,2,10},{2,4,5},{3,5,12}};
    cout << max_value(5, v) << endl;
    return 0;
}