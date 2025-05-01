#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(x) (x).begin(), (x).end()


struct SuffixArray {
    vi sa, lcp;
    SuffixArray(vector<int> s, int lim=301) { // or vector<int>
        s.push_back(0); int n = sz(s), k = 0, a, b;
        vi x(all(s)), y(n), ws(max(n, lim));
        sa = lcp = y, iota(all(sa), 0);
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(all(y), n - j);
            rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
            fill(all(ws), 0);
            rep(i,0,n) ws[x[i]]++;
            rep(i,1,lim) ws[i] += ws[i - 1];
            for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
                (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }
        for (int i = 0, j; i < n - 1; lcp[x[i++]] = k)
            for (k && k--, j = sa[x[i] - 1];
                    s[i + k] == s[j + k]; k++);
    }
};
template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V): jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j, 0, sz(jmp[k])) {
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
            }
        }
    }

    T query(int a, int b) {
        assert(a < b);
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

void solve() {
    int n;

    while(cin >> n) {
        string t;
        getline(cin, t);
        vector<string> arr(n);
        for (auto &s: arr) getline(cin, s);
        getline(cin, t);
        int l = sz(t);
        vector<int> start;

        vector<int> str(all(t));
        for (auto &s: arr) {
            str.push_back(300);
            start.push_back(sz(str));

            for (auto &c: s) {
                str.push_back(int(c));
            }
        }
        
        SuffixArray sa(str);
        RMQ<int> q(sa.lcp);
        vector<int> at(sz(str));
        for (int i = 1; i < sz(sa.sa); i++) {
            at[sa.sa[i]] = i;
        }
        auto lower = [&] (int idx, int len) {
            int low = 1;
            int high = idx - 1;
            int ans = idx;

            while(low <= high) {
                int mid = (low + high)/2;
                int x = q.query(mid + 1, idx + 1);
                if (x >= len) {
                    high = mid - 1;
                    ans = mid;
                } else {
                    low = mid + 1;
                }
            }
            return ans;
        };

        auto upper = [&] (int idx, int len) {
            int low = idx + 1;
            int high = sz(sa.lcp) - 1;
            int ans = idx;

            while(low <= high) {
                int mid = (low + high)/2;
                int x = q.query(idx + 1, mid + 1);
                if (x >= len) {
                    low = mid + 1;
                    ans = mid;
                } else {
                    high = mid - 1;
                }
            }
            return ans;
        };
    

        for (int i = 0; i < n; i++) {
            int idx = at[start[i]];
            int left = lower(idx, sz(arr[i]));
            int r = upper(idx, sz(arr[i]));
            vector<int> ans;
            for (int j = left; j <= r; j++) {
                if (sa.sa[j] < l) {
                    ans.push_back(sa.sa[j]);
                }
            }
            sort(all(ans));
            for (int &x: ans) {
                cout << x << " ";
            }
            cout << "\n";
        }
    }
}


int main() {
    solve();
}