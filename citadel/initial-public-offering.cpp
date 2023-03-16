# include <bits/stdc++.h>

using namespace std;

struct comparison{
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[2] == b[2]? a[3] > b[3] : a[2] < b[2]; // min - first greater | max - first smaller
    }
};

vector<int> get_unallotted_users(vector<vector<int>> bids, int totalShares) {
    vector<int> ans;
    priority_queue<vector<int>, vector<vector<int>>, comparison> pq (bids.begin(), bids.end());

    while (!pq.empty()) {
        auto t = pq.top(); pq.pop(); // Get the highest bid from the priority queue
        if (totalShares > 0) { // If there are still shares to be allocated
            if (!pq.empty() && pq.top()[2] == t[2] && pq.top()[3] == t[3]) {
                // distribute equally
                queue<int> temp;
                temp.push(t[2]);
                int total = 0;
                // pop all bids with the same price and timestamp from the priority queue
                while (!pq.empty() && pq.top()[2] == t[2] && pq.top()[3] == t[3]) {
                    auto t = pq.top(); pq.pop(); 
                    temp.push(t[2]);
                    total += t[1]; // add the number of shares in the bid to the current total
                }
                if (total > totalShares) { // not enough shares to allocate
                    if (totalShares > temp.size()) {
                        // distribute shares round-robin style
                        while (!temp.empty()) {
                            auto t2 = temp.front(); temp.pop();
                            totalShares--;
                            if (totalShares == 0) break;
                            if (t2 - 1 > 0) temp.push(t2 - 1);
                        }
                    } else {
                        // allocate shares to the first bids
                        while (totalShares) {
                            temp.pop();
                            totalShares--;
                        }
                        // add IDs to the answer vector if we run out shares
                        while (!temp.empty()) {
                            ans.push_back(temp.front());
                            temp.pop();
                        }
                        totalShares = 0; // reset total shares
                    }
                } else totalShares -= total; // allocate all bid shares 
            } else totalShares -= std::min(t[1], totalShares); // allocate all shares to the highest bud
        } else ans.push_back(t[0]); // if there are no more shares to allocate, add the ID of the bid to the answer vector
    }
    return ans;
}

// passes 14/15 test cases based on assumption that ONLY 2 USERS can have same price 
// vector<int> get_unallotted_users_for_2(vector<vector<int>> bids, int total){
//     int n = bids.size();
//     vector<int> res;
//     if (n == 0 || total == 0) return res;
//     priority_queue<vector<int>, vector<vector<int>>, comparison> pq;
//     for (auto e: bids) pq.push(e);

//     while (!pq.empty() && total > 0){
//         vector<int> b1 = pq.top();
//         vector<int> b2;
//         pq.pop();
//         int numSharesB1 = b1[1];
//         int numSharesB2 = 0;
//         if (!pq.empty()){
//             b2 = pq.top();
//             numSharesB2 = b2[1];
//         }
//         // allocating shares round robin style
//         if (numSharesB1 == numSharesB2){
//             pq.pop();
//             while (numSharesB1 > 0 && numSharesB2 > 0){
//                 if (numSharesB1 > 0 && numSharesB2 > 0) total -= 2;
//                 else total -= 1;
//                 if (total <= 0) {
//                     total = 0;
//                     break;
//                 }
//             }
//         } else total -= numSharesB1;
//     }

//     while (!pq.empty()){
//         vector<int> bid = pq.top();
//         res.push_back(bid[0]);
//         pq.pop();
//     }
//     return res;
// }

int main(){
    vector<vector<int>> a {{1,5,5,0},{2,7,8,1},{3,7,5,1},{4,10,3,3}};
    vector<int> res = get_unallotted_users(a, 18);
    for (auto e: res) cout << e << " ";
    cout << endl;
    a ={{1,2,5,0},{2,1,4,0},{3,5,4,6}};
    res = get_unallotted_users(a, 3);
    for (auto e: res) cout << e << " ";
}