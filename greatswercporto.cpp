#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()

vector<long long> weight(10);
vector<int> lead(10);
int N = 0;

int backtrack(int idx, int mask, long long balance) {
    if (idx == N && balance == 0) return 1;
    if (idx == N) return 0;
    long long mx = 0;
    long long mn = 0;

    vector<int> avail;
    for (int i = 0; i < 10; i++) if (mask & (1 << i)) {
        avail.push_back(i);
    }
    
    int ans = 0;    
    for (int i = 0; i < 10; i++) if (mask & (1 << i)) {
        if (i == 0 && lead[idx]) continue;
        long long nbal = balance + weight[idx] * i;
        int nmask = mask & ~(1 << i);
        ans += backtrack(idx + 1, nmask, nbal);
    }
    return ans;
}

map<char, int> ID;
int id(char &c) {
    if (ID.count(c)) return ID[c];
    ID[c] = N++;
    return ID[c];
}

int main() {
    int n; cin >> n;
    vector<int> leading(10);
    for (int _ = 0; _ < n - 1; _++) {
        string s; cin >> s;
        long long mag = 1;
        for (int i = sz(s) - 1; i >= 0; i--) {
            int idx = id(s[i]);
            weight[idx] += mag;
            mag *= 10;

            if (i == 0) {
                leading[idx] = 1;
            }
        }
    }

    string s; cin >> s;
    long long mag = 1;
    for (int i = sz(s) - 1; i >= 0; i--) {
        int idx = id(s[i]);
        weight[idx] -= mag;
        mag *= 10;

        if (i == 0) {
            leading[idx] = 1;
        }
    }
    

    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);

    sort(idx.begin(), idx.end(), [&] (auto &a, auto &b) {
        return weight[a] < weight[b];
    });

    sort(weight.begin(), weight.begin() + N);
    for (int i = 0; i < N; i++) {
        lead[i] = leading[idx[i]]; 
    }
    cout << backtrack(0, (1 << 11) - 1, 0) << endl;
    return 0;
}