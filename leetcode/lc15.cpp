#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
    
}

int main(){
    vector<int> n{-1,0,1,2,-1,-4};
    vector<vector<int>> res = threeSum(n);
    for(auto e: res){
        for(auto el: e) cout << el << " ";
    }
}

