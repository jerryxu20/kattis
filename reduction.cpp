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

vs split(string &s) {
    vs ans;
    string cur;
    s += ':';
    for (char &c: s) {
        if (c == ':' || c == ',') {
            ans.pb(cur);
            cur = "";
            continue;
        }
        cur += c;
    }
    return ans;
}
int n, m, l;

int calc(int a, int b, int mid) {
    int ans = mid * b; 
    int rem = n / (1 << mid);
    if (rem < m) return 1e9 + mid;
    ans += (rem - m) * a;
    return ans;
}


int solve(int tcase) {
    string s;
    cin >> n >> m >> l;
    vector<pair<string, int>> res;
    while(l--) {
        cin >> s;
        vs S = split(s);
        string name = S[0];
        int a = stoi(S[1]);
        int b = stoi(S[2]);
        int ans = INT_MAX;
        int low = 0;
        int high = 17;
        while(low <= high) {
            int mid = (low + high) / 2;
            int cost1 = calc(a, b, mid);
            int cost2 = calc(a, b, mid + 1);
            ans = min({ans, cost1, cost2});
            if (cost1 >= cost2) {
                low = mid + 2;
            } else {
                high = mid - 1;
            }
        }
        res.pb(mp(name, ans));
    }
    sort(all(res), [] (auto &a, auto &b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    cout << "Case " << tcase << endl;
    for (auto &[agency, cost]: res) {
        cout << agency << " " << cost << "\n";
    }
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