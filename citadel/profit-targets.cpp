#include <bits/stdc++.h>
using namespace std;

int stock_pairs(vector<int> stocks, int target){
    unordered_set<int> set;
    unordered_set<int> seen;
     
    int count = 0;
     
    for(int num : stocks) {
        if(set.find(target-num) != set.end() && seen.find(num) == seen.end() ) {
            count++;
            seen.insert(num);
            seen.insert(target-num);
        }
        set.insert(num);
    }
    return count;
}

int main(){
    vector<int> v{5,7,9,13,11,6,6,3,3};
    cout << stock_pairs(v, 12) << endl;
}