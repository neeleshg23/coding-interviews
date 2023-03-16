# include <bits/stdc++.h>
using namespace std;

int dropped_requests(const vector<int>& request_time) {
    unordered_map<int, int> counter;
    for (int time : request_time) {
        counter[time]++;
    }

    vector<pair<int, int>> pairs;
    for (const auto& entry : counter) {
        pairs.emplace_back(entry);
    }
    sort(pairs.begin(), pairs.end());

    int res = 0;
    int l10 = 0;
    int l60 = 0;
    int c10 = 0;
    int c60 = 0;
    
    for (const auto& [time, total] : pairs) {
        c10 += total;
        c60 += total;
        while (pairs[l10].first < time - 9) {
            c10 -= pairs[l10].second;
            l10++;
        }
        while (pairs[l60].first < time - 59) {
            c60 -= pairs[l60].second;
            l60++;
        }
        res += max({total - 3, c10 - 20, c60 - 60, 0});
    }
    return res;
}

/** EXPECT:
* 7
* 1
* 0
*/
int main(){
    vector<int> v{1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 11, 11, 11, 11};
    cout << dropped_requests(v) << endl;
    v = {1,1,1,1,2};
    cout << dropped_requests(v) << endl;
    v = {1,2,3,5};
    cout << dropped_requests(v) << endl;
}