#include <bits/stdc++.h>
using namespace std;

vector<int> prime_factors(int num){
    int i = 2;
    vector<int> factors;
    while (i*i <= num){
        if (num % i){
            i++;
        }
        else{
            num /= i;
            factors.push_back(i);
        }
    }
    if (num > 1) factors.push_back(num);
    set<int> s(factors.begin(), factors.end());
    factors.assign(s.begin(), s.end());
    return factors;
}

vector<int> flip(vector<int>& states, vector<int>& numbers){
    vector<int> factors;
    for (auto num: numbers){
        vector<int> cur = prime_factors(num);
        factors.insert(factors.end(), cur.begin(), cur.end());
    }
    map<int,int> freq;
    for(auto factor: factors){
        freq[factor]++;
    }

    for (auto it = freq.begin(); it != freq.end(); ++it){
        if (it->second % 2){
            int factor = it->first;
            cout << "Flipping bulbs for prime factor " << factor << endl;
            for (int i = 0; i < states.size(); i++){
                if ((i + 1) % factor == 0){
                    if (states[i] == 1) states[i] = 0;
                    else states[i] = 1;
                }
            }
        }
    }
    return states;
}

vector<int> sieve(size_t maxN){
    vector<int> sf(maxN + 1);
    for (size_t i = 0; i <= maxN; ++i) {
        sf[i] = i;
    }
    for (size_t i = 4; i <= maxN; i += 2) {
        sf[i] = 2;
    }
    size_t limit = sqrt(maxN);
    for (size_t p = 3; p <= limit; p += 2) {
        if (sf[p] == p) {
            for (int i = p * p; i <= maxN; i += 2*p) {
                if (sf[i] == i) {
                    sf[i] = p;
                }
            }
        }
    }
    return sf;
}

/**
 * @brief Unique Prime Factors
 * 
 * @param n - number for which we're finding unique prime factors of
 * @param sf - output from sieve which has smallest prime factor of every i
 * @return vector<int> - list of unique prime factors
 */
vector<int> upf(int n, vector<int>& sf){
    vector<int> res;
    res.reserve(log2(n) + 1);
    while (n > 1){
        int p = sf[n];
        res.push_back(p);
        n /= p;
        while (n % p == 0){
            n /= p;
        }
    }
    return res;
}

vector<int> light_bulbs(vector<int>& states, vector<int>& nums){
    size_t maxN = 2*pow(10,5);
    vector<int> sf = sieve(maxN);
    unordered_map<int,int> pCount;
    for (const auto& e: nums){
        vector<int> u = upf(e, sf);
        for (const auto& p: u){
            pCount[p]++;
        }
    }
    for (auto it = pCount.begin(); it != pCount.end(); ++it){
        if (it->second & 1){
            for (int i = it->first-1; i < states.size(); i += it->first){
                states[i] = 1 - states[i];
            }
        }
    }
    return states;
}

int main()
{
    vector<int> st{1,1,0,0,1,1,0,1,1,1};
    vector<int> n{3,4,15};
    vector<int> res = light_bulbs(st, n);
    for (auto e: res) cout << e << " ";
    cout << endl;
    return 0;
}