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
        string s, cur;
        getline(cin, s);
        s.pb(']');
        deque<string> q;
        bool front = true;
        for (auto &c: s) {
            if (c == '[' || c == ']') {
                if (sz(cur)) {
                    if (!front) q.pb(cur);
                    else q.push_front(cur);
                }
                cur = "";
                front = sz(q) == 0 || c == '['; 
                continue;
            }
            if (front && c == '<') {
                if (sz(cur)) cur.pop_back();
                continue;
            }
            cur += c;
        }
        string ans = "";
        for (auto &piece: q) {
            // cout << piece;
            for (auto c: piece) {
                if (c == '<') {
                    if (sz(ans)) ans.pop_back();
                } else {
                    ans += c;
                }
            }
        }
        // cout << endl;
        cout << ans << endl;
        tcase++;
        return 0;
    }
    
    int main() {
        cin.tie(0)->sync_with_stdio(0);
        cin.exceptions(cin.failbit);
        int testcase = 1;
        cin >> testcase;
        string s;
        getline(cin, s);
        for (int i = 1; i <= testcase; i++) {
            solve(i);
        }
        // for (int i = 1; ; i++) {
        //     if (solve(i)) break;
        // }
        testcase++;
        return 0;
    }