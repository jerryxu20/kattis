#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair


int main() {
    // out of the least filled possibilities what is the max
    int n;
    cin >> n;
    vector<int> gas(n);
    vector<int> can(n);
    // ballons are from 1 to n
    double mn = 1;
    for (int &c: can) {
        cin >> c;
    }
    sort(all(can));
    double filled;
    for (int i = 1; i <= n; i++) {
        filled = can[i - 1] / (double) i;
        if (filled > 1) {
            cout << "impossible" << endl;
            return 0;
        }
        mn = min(mn, filled);
    }
    cout << setprecision(10) << mn << endl;
    return 0;
    // I can binary search the answer, by pairing the smallest balloon if the most appropriate canister
    // 
    
    return 0;
}