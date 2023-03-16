# include <bits/stdc++.h>
using namespace std;

int unitDigitOfPower(int x, int y) {
    int ones = x % 10;
    if (y != 0) {
        y = y % 4 + 4;
    }
    int res = pow(ones, y);
    return res % 10;
}

string solve(int m, vector<string>& s) {
    // Create a lookup table for lowercase English letters (a to z)
    vector<int> lookup(26);
    for (char c = 'a'; c <= 'z'; ++c) {
        lookup[c - 'a'] = unitDigitOfPower(c, m);
    }

    int sum = 0;
    for (auto& str : s) {
        int val = 1;
        for (auto c : str) {
            val *= lookup[c - 'a']; // Use the lookup table with the appropriate index
            val %= 10;
        }
        sum += val;
    }
    return sum % 2 == 0 ? "EVEN" : "ODD";
}

int main(){
    vector<string> v{"abc", "abcd"};
    cout << solve(2, v) << endl;
    v = {"aceace", "ceceaa", "abdbdbdbakjkljhkjh"};
    cout << solve(50,v) << endl;
    v = {"azbde", "abcher", "acegk"};
    cout << solve(47,v) << endl;
    v = {"austin", "houston", "dallas"};
    cout << solve(6,v) << endl;
    return 0;
}