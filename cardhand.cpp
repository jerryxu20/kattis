#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int suit(char &c) {
    if (c == 's') return 0;
    if (c == 'h') return 1;
    if (c == 'd') return 2;
    return 3;
}

int weight(char &c) {
    if (c >= '2' && c <= '9') return c - '0';
    if (c == 'T') return 10;
    if (c == 'J') return 11;
    if (c == 'Q') return 12;
    if (c == 'K') return 13;
    return 20;
}

int lis(vector<pi> &arr) {
    vector<pi> seq;
    for (auto &p: arr) {
        if (seq.empty() || p > seq.back()) {
            seq.push_back(p);
            continue;
        }

        int idx = lower_bound(seq.begin(), seq.end(), p) - seq.begin();
        seq[idx] = p;
    }

    return seq.size();
}


int main() {
    int n; cin >> n;

    vector<pi> cards(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        cards[i] = {suit(s[1]), weight(s[0]), };
    }

    vector<int> v(4);
    iota(v.begin(), v.end(), 0);

    int ans = n;
    do {
        for (int mask = 0; mask < (1 << 4); mask++) {
            vector<pi> arr;
            for (auto &[s, w]: cards) {
                int ns = v[s];
                int nw = (mask & (1 << s)) ? w : -w;

                arr.push_back({ns, nw});
            }

            int cand = n - lis(arr);
            ans = min(ans, cand);
        }
    } while(next_permutation(v.begin(), v.end()));
    cout << ans << endl;
}