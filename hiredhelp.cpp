#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

bool check(map<int, int> &freq, map<int, int> &psum, int n, int k) {
    // n people making k shoes?
    int overextend = 0;
    for (int i = 1; i <= k; i++) {
        auto it = psum.lower_bound(i);
        int consumed = min(n, it->second - overextend);
        if (consumed < n) return false; 
        overextend += consumed;
        overextend -= min(overextend, freq[i]);
    }
    return true;
}


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> deadlines(n);
    for (auto &d: deadlines) {
        cin >> d;
    }
    sort(all(deadlines), greater<int>());
    map<int, int> freq;
    map<int, int> psum;
    for (int i = 0; i < n; i++) {
        freq[deadlines[i]]++;
    }
    int sm = 0;
    for (auto it = freq.rbegin(); it != freq.rend(); it++) {
        sm += it->second;
        psum[it->first] = sm;
    }
    int high = n;
    int low = 0;
    int ans = 0;
    while (high >= low) {
        int mid = (low + high) / 2;
        if (check(freq, psum, mid, k)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}