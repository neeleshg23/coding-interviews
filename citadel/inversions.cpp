# include <bits/stdc++.h>

using namespace std;

int max_inversion(vector<int>& arr){
    int n = arr.size();
    int res = 0;
    for (int i=0; i<n-1; i++){
        int small = 0;
        for (int j=i+1; j<n; j++){
            if (arr[i] > arr[j]) small++;
        }

        int great = 0;
        for (int j=i-1; j>=0; j--){
            if (arr[i] < arr[j]) great++;
        }

        res += small*great;
    }
    return res;
}

/* EXPECT:
* 2
* 1
* 7
* 2635
*/
int main(){
    vector<int> v{4,4,2,1};
    cout << max_inversion(v) << endl;
    v = {4,1,3,2,5};
    cout << max_inversion(v) << endl;
    v = {5,3,4,2,1};
    cout << max_inversion(v) << endl;
    v = {615,368,260,115,944,873,353,893,961,333,527,803,474,143,469,555,918,378,147,488,349,899,191,566,695,253,741,191,903,105,363,164,749,835,181,334,212,379,859,358,869,714,318,815,730,501,760,856,411,931};
    cout << max_inversion(v) << endl;
}

