#include <bits/stdc++.h>
using namespace std;

int minimize(vector<int>& points, int k){
    int n = points.size();
    sort(points.begin(), points.end());
    int res = points[n-1] - points[0];
    int tempMin = points[0];
    int tempMax = points[n-1];
    for (int i=1; i<n; i++){
        tempMin = min(points[0] + k, points[i] - k);
        tempMax = max(points[i-1] + k, points[n-1] - k);
        res = min(res, tempMax - tempMin);
    }
    return res;
}

int main(){
    vector<int> v{0,1,2,3};
    cout << minimize(v, 2) << endl;
    return 0;
}