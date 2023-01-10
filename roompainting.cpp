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
    int n, m;
    cin >> n >> m;
    vector<int> cans(n);
    for (int &can: cans) {
        cin >> can;
    }
    sort(all(cans));
    ll waste = 0;
    while (m--) {
        int v;
        cin >> v;
        auto it = lower_bound(all(cans), v);
        int idx = it - cans.begin();
        waste += cans[idx] - v; 
    }
    cout << waste << endl;

    return 0;
}