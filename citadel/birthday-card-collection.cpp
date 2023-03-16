# include <bits/stdc++.h>
using namespace std;

vector<int> hacker_cards(vector<int>& collection, int d){
    unordered_set<int> nums;
    for(auto e: collection) nums.insert(e);
    vector<int> res;
    int curSum = 0;
    for (int i=1; i<d+1; i++){
        if (nums.find(i) != nums.end()) continue;
        if (curSum + i > d) break;
        curSum += i;
        res.push_back(i);
    }
    return res;
}

int main(){
    vector<int> v{2,4,5};
    vector<int> res = hacker_cards(v, 7);
    for (auto e: res) cout << e << " ";
    cout << endl;
    v = {1,3,4};
    res = hacker_cards(v, 7);
    for (auto e: res) cout << e << " ";
    cout << endl;
}