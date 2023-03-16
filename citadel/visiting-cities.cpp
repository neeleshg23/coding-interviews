#include <bits/stdc++.h>
using namespace std;

vector<long> minimumCost(vector<int>& red, vector<int>& blue, int blueCost){
    int n = red.size() + 1;
    vector<long> res(n, LONG_MAX);

    vector<long> dp_red(n, LONG_MAX);
    vector<long> dp_blue(n, LONG_MAX);
    dp_red[0] = 0;
    dp_blue[0] = blueCost;

    for (int i = 1; i < n; i++) {
        dp_red[i] = min(dp_red[i-1] + red[i-1], dp_blue[i-1] + red[i-1]);
        dp_blue[i] = min(dp_blue[i-1] + blue[i-1], dp_red[i-1] + blueCost + blue[i-1]);
    }

    for (int i = 0; i < n; i++) {
        res[i] = min(dp_red[i], dp_blue[i]);
    }

    return res;
}


int main(){
    vector<int> r{2,3,4};
    vector<int> b{3,1,1};
    vector<long> res = minimumCost(r,b,2);
    for (auto e: res) cout << e << " ";
    cout << endl;
    return 0;
}
