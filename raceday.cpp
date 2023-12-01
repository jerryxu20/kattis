#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<bool> vb;
typedef tuple<int,int,int> ti;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vi> vii;
typedef vector<vii> viii;

template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, a, b) for (int i=a; i<(b); i++)
#define FOR(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(x,A) for (auto& x : A)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ins insert

const int MOD = 1000000007;
const char nl = '\n';

string pad(string s, int len, bool left = false) {
    string space = string(len - sz(s), ' ');
    if (left) return s + space;
    return space + s;
}

string HEAD = "NAME                       BIB    SPLIT1      RANK    SPLIT2      RANK    FINISH      RANK";

int solve(int tt) {
    int n; cin >> n;
    if (n == 0) return 1;
    vector<vs> runners(n);
    string first, last, bib;
    trav(v, runners) {
        cin >> first >> last >> bib;
        v = {last, first, bib};
    }
    map<string, int> split1_cnt, split2_cnt, finish_cnt;
    map<string, string> split1, split2, finish;

    string mark, time;
    rep(i, 0, 3 * n) {
        cin >> bib >> mark >> time;
        if (mark == "S1") {
            split1_cnt[time]++;
            split1[bib] = time;
        } else if (mark == "S2") {
            split2_cnt[time]++; 
            split2[bib] = time;
        } else {
            finish_cnt[time]++;
            finish[bib] = time;
        }
    }

    map<string, int> rank1, rank2, rank_finish;
    int cnt = 1;
    for (auto &[time, freq]: split1_cnt) {
        rank1[time] = cnt;
        cnt += freq; 
    }
    cnt = 1;
    for (auto &[time, freq]: split2_cnt) {
        rank2[time] = cnt;
        cnt += freq; 
    }
    cnt = 1;
    for (auto &[time, freq]: finish_cnt) {
        rank_finish[time] = cnt;
        cnt += freq; 
    }

    sort(all(runners), [&](auto &a, auto &b) {
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
    });

    cout << HEAD << nl;
    trav(v, runners) {
        string NAME = pad(v[0] + ", " + v[1], 20, true);
        string BIB = pad(v[2], 10);
        string SPLIT1 = pad(split1[v[2]], 10);
        string SPLIT2 = pad(split2[v[2]], 10);
        string FINISH = pad(finish[v[2]], 10);
        string RANK1 = pad(to_string(rank1[split1[v[2]]]), 10);
        string RANK2 = pad(to_string(rank2[split2[v[2]]]), 10);
        string RANK_FINISH = pad(to_string(rank_finish[finish[v[2]]]), 10);
        cout << NAME << BIB << SPLIT1 << RANK1 << SPLIT2 << RANK2 << FINISH << RANK_FINISH << nl;
    }
    cout << nl;
    tt++;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    // cin >> T;
    for (int i = 1; ; i++) {
        if (solve(i)) break;
    }
    T++;
    return 0;
}