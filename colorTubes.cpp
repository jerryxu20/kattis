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


int main() {
    int n, a, b, c;
    cin >> n;
    vector<vi> tubes (n + 1;)
    vector<pair<int, int>> empty;
    for (auto &tube: tubes) {
        cin >> a >> b >> c;
        tube = {a, b, c};
    }
    vector<int> size(n + 1);
    vector<int> lacking;
    for (int i = 0; i <= n; i++) {
        while(tubes[i].back() == 0) {
            tubes[i].pop_back();
        }
        size[i] = sz(tubes[i]);
        if (size[i] < 3 && i > 0) lacking.pb(i);
    }
    vector<pair<int, int>> moves;
    while(sz(tubes) > 1) {
        // empty first tube
        while(sz(tubes[0]) > 0) {
            moves.pb(mp(0, lacking.back()));
            tubes[lacking.back()].pb(tubes[0].back());
            tubes[0].pop_back();
            if (sz(tubes[lacking.back()]) == 3) {
                lacking.pop_back();
            }
        }
        // solve last bucket
    }
    // the first tube should be empty

    return 0;
}