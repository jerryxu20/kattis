#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef tuple<int, int, int> tii;
typedef vector<pii> vpii;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

#define pb push_back
#define mp make_pair

// vii delta4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

// USE LONG LONG!
int solve(int tcase) {
    int n, k;

    cin >> n >> k;
    vector<vi> mons(n, vi(4));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mons[i][j];
        }
        mons[i][3] = i;    
    }
    set<int> team;
    for (int i = 0; i < 3; i++) {
        sort(all(mons), [&] (auto &a, auto &b) {
            return a[i] > b[i];
        });
        for (int i = 0; i < min(n, k); i++) {
            team.insert(mons[i][3]);
        }  
    }
    cout << sz(team) << endl;

    tcase++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; i++) {
        solve(i);
    }
    // for (int i = 1; ; i++) {
    //     if (solve(i)) break;
    // }
    testcase++;
    return 0;
}