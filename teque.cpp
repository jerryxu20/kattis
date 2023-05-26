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

deque<int> qleft;
deque<int> qright;

int get(int i) {
    if (i < sz(qleft)) return qleft[i];
    return qright[i - sz(qleft)];
}

void balance() {
    while (sz(qleft) > sz(qright) + 1) {
        qright.push_front(qleft.back());
        qleft.pop_back();
    }
    
    while (sz(qright) > sz(qleft)) {
        qleft.push_back(qright.front());
        qright.pop_front();
    }

    return;
}


int solve(int tcase) {
    int n, a; cin >> n;
    string s;
    while(n--) {
        cin >> s >> a;
        if (s == "push_front") {
            qleft.push_front(a);
        } else if (s == "push_back") {
            qright.push_back(a);
        } else if (s == "push_middle") {
            qleft.push_back(a);
        } else {
            cout << get(a) << "\n";
        }
        balance();
    }
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