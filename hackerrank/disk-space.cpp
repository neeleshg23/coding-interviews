#include<bits/stdc++.h>
using namespace std;

int diskSpace(vector<int> space, int x){
    int n = space.size();
    priority_queue<int> res;
    deque<int> dq; //increasing monotonic queue

    for (int i=0; i<n; i++){
        // remove elements that were in range and minimal but now not
        if (!dq.empty() && dq.front() == i-x){
            dq.pop_front();
        }
        // remove elements which are larger than the current min
        while (!dq.empty() && space[dq.back()] > space[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        // only after reading x values, can we append to max heap
        if (i >= x-1) res.push(space[dq.front()]);
    }
    return res.top();
}

int main(){
    vector<int> space{8,2,4,4,5,6,1,4,5,3};
    cout << diskSpace(space, 2) << endl;
    cout << diskSpace(space, 3) << endl;
    space = {9,2,1,5,3,5,3,5,2,101,99,1};
    cout << diskSpace(space,3) << endl;
}