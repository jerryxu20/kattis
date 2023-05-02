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
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef vector<string> vs;

#define pb push_back
#define mp make_pair

// vii delta4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int solve(int tcase) {
    int n;
    cin >> n;
    // i is how many numbers I'm taking
    int i, extra = 1;
    for (i = 2; ;i++) {
        if (i * (i + 1) / 2 > n) break; 
        if ((n - extra) % i == 0) break;
        extra += i;
    }
    if (i * (i + 1) / 2 > n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    int start = (n - extra) / i;
    cout << n << " = ";
    cout << start ;
    i--;
    while(i--) {
        cout << " + " << ++start;
    }
    cout << endl;
    tcase++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; i++) {
        solve(i);
    }
    // for (int i = 1; ; i++) {
    //     if (solve(i)) break;
    // }
    testcase++;
    return 0;
}