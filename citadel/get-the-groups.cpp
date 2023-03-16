#include <bits/stdc++.h>
using namespace std;

const int Mx = 1e5 + 5;
int par[Mx], cnt[Mx];

void ini(int n) {
    for(int i = 1; i <= n; ++i) {
        par[i] = i;
        cnt[i] = 1;
    }
}

int root(int a) {
    if(a == par[a]) {
        return a;
    }
    return par[a] = root(par[a]);
}

void Union(int a, int b) {
    a = root(a);
    b = root(b);
    if(a == b) {
        return;
    }
    if(cnt[a] > cnt[b]) {
        swap(a, b);
    }
    par[a] = b;
    cnt[b] += cnt[a];
}

int* getTheGroups(int n, int q, int sz, string queryTypes[], int student1[], int student2[], int* ans) {
    ini(n);
    int current = 0;
    for(int i = 0; i < q; ++i) {
        if(queryTypes[i] == "Friend") {
            Union(student1[i], student2[i]);
        } else {
            int x = root(student1[i]), y = root(student2[i]);
            if(x == y) {
                ans[current++] = cnt[x];
            } else {
                ans[current++] = cnt[x] + cnt[y];
            }
        }
    }
    return ans;
}

int main() {
    int n = 3, q = 2, sz = 0;
    string queryTypes[] = {"Friend", "Total"};
    int student1[] = {1, 2};
    int student2[] = {2, 3};

    for (int i = 0; i < q; ++i) {
        if (queryTypes[i] == "Total") {
            ++sz;
        }
    }

    int ans[sz];
    int* ptr = getTheGroups(n, q, sz, queryTypes, student1, student2, ans);
    for(int i = 0; i < sz; ++i) {
        cout << ptr[i] << endl;
    }
    return 0;
}