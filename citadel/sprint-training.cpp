#include <bits/stdc++.h>

using namespace std;

int get_most_visited(int n, vector<int>& sprints){
    int m = sprints.size();
    vector<int> cnts(n+2,0);
    for(int i=1; i<m; i++){
        int small = min(sprints[i], sprints[i-1]);
        int large = max(sprints[i], sprints[i-1]);
        cnts[small]++;
        cnts[large+1]--;
    }
    
    int curr = 0;
    for (int i=1; i<n+1; i++){
        curr += cnts[i];
        cnts[i] = curr;
    }

    int resCnt = -1;
    int res = -1;
    for (int i=1; i<n+1; i++){
        if (cnts[i] > resCnt){
            resCnt = cnts[i];
            res = i;
        }
    }
    return res;
}

int main(){
    vector<int> sp{2,4,1,3};
    cout << get_most_visited(5, sp) << endl;
    sp = {1,5,10,3};
    cout << get_most_visited(10, sp) << endl;
    sp = {1,5};
    cout << get_most_visited(5, sp) << endl;
    sp = {9,7,3,1};
    cout << get_most_visited(9, sp) << endl;
}