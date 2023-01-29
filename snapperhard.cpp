#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair

void solve(int t) {
    int n, k;
    cin >> n >> k;
    ll state = 1;
    state += k;
    state--;
    // cout << bitset<32>(state).to_string() << endl;
    for (int i = 0; i < n; i++) {
        if ((state & (1 << i)) == 0) {
            cout << "Case #" << t << ": OFF" << endl;
            return; 
        } 
    }
    cout << "Case #" << t << ": ON" << endl;
    return;

}


int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}