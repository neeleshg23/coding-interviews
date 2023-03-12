#include <bits/stdc++.h>

using namespace std;

int dp(unsigned i, string& s, vector<int>& mem){
    if(mem[i] > -1) return mem[i];
    if(s[i] == '0') {
        mem[i] = 0;
        return mem[i];
    }
    int res = dp(i+1,s,mem);
    if(i<s.size()-1 && (s[i]=='1'||s[i]=='2') && s[i+1]<'7'){
        res += dp(i+2,s,mem);
    }
    mem[i] = res;
    return mem[i];
}

int numDecodingsDpRecursion(string s){
    int n = s.length();
    vector<int> mem(n+1, -1);
    mem[n] = 1;
    return s.empty() ? 0 : dp(0,s,mem);
}

int numDecodings(string s){
    int n = s.size();
    vector<int> dp(n+1);
    dp[n] = 1;
    for(int i=n-1; i>=0; i--){
        if(s[i]=='0'}{
            dp[i]=0;        
        }
else {
                dp[i] = dp[i+1];
                if(i<n-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')) dp[i]+=dp[i+2];
            }
    }

int main(){
    string s="12";
    cout << numDecodings(s) << endl;
    s = "226";
    cout << numDecodings(s) << endl;
    return 0;
}
