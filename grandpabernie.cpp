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
    int n, y;
    string s;
    cin >> n;
    map<string, vi> vac;
    while(n--) {
        cin >> s >> y;
        vac[s].pb(y);
    }
    for (auto &[place, years]: vac) {
        sort(all(years));
    }
    cin >> n;
    while(n--) {
        cin >> s >> y;
        cout << vac[s][y - 1] << endl;
    }
    return 0;
}