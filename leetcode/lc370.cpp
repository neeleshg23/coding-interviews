#include <bits/stdc++.h>
using namespace std;

vector<int> rangeSum(int length, vector<vector<int>>& arr){
    vector<int> res(length, 0);
    for(int i=0; i<arr.size(); i++){
        res[arr[i][0]] += arr[i][2];
        if (arr[i][1] < length-1){
            res[arr[i][1]+1] -= arr[i][2];
        }
    }
    for (int i=1; i<length; i++){
        res[i] += res[i-1];
    }
    return res;
}

int main(){
    vector<int> q1{1,3,2};
    vector<int> q2{2,4,3};
    vector<int> q3{0,2,-2};
    vector<vector<int>> queries;
    queries.push_back(q1);
    queries.push_back(q2);
    queries.push_back(q3);
    vector<int> res = rangeSum(5, queries);
    for(auto e: res){
        cout << e << " ";
    }
    return 0;
}
