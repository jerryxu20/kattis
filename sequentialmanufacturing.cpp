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

void merge(vector<ll> &machines, int &changes) {
    changes = 0;
    machines.pb(LLONG_MAX);
    ll sm = machines[0];
    int idx = 0;
    for (int i = 1; i < sz(machines); i++) {
        if (machines[i] <= machines[i - 1]) {
            sm += machines[i];
            changes++;
            continue;
        } else {
            machines[idx++] = sm;
            sm = machines[i];
        }
    }
    while(sz(machines) != idx) {
        machines.pop_back();
    }
    return;
}

int main() {
    int n, p;
    cin >> n >> p;
    vector<ll> machines(n);
    for (auto &x: machines) cin >> x;
    ll slowest = 0;
    ll sm = 0;
    for (auto &x: machines) {
        slowest = max(x, slowest);
        sm += x;
    }
    cout << sm + slowest * (p - 1) << endl;
    return 0;
}