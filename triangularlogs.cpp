#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef pair<int, int> pi;

struct Seg {
    Seg *left = nullptr, *right = nullptr;
    vector<pi> a;
    int low, high;

    Seg(int low, int high, vector<vector<pi>> &arr): low(low), high(high) {
        if (low == high) {
            a = arr[low];
            return;
        }
        
        int mid = (low + high)/2;
        left = new Seg(low, mid, arr);
        right = new Seg(mid + 1, high, arr);
        recalc();
    }

    vector<pi> comb(const vector<pi> &A, const vector<pi> &B) {
        vector<pi> ans;
        int i = 0, j = 0;
        while(i < sz(A) && j < sz(B)) {
            if (A[i] < B[j]) {
                ans.push_back(A[i++]);
            } else {
                ans.push_back(B[j++]);
            }
        }

        while(i < sz(A)) ans.push_back(A[i++]);
        while(j < sz(B)) ans.push_back(B[j++]);

        return ans;
    }

    void recalc() {
        if (low == high) return;
        a = comb(left->a, right->a);
        return;
    }

    int count(int ax, int bx, int ay, int by) {
        if (ax > high || bx < low) return 0;
        if (ax <= low && high <= bx) {
            int lb = lower_bound(all(a), pi(ay, 0)) - a.begin();
            int ub = upper_bound(all(a), pi(by, INT_MAX)) - a.begin();

            if (lb >= ub) return 0;
            return ub - lb;
        }
        
        int l = left->count(ax, bx, ay, by);
        int r = right->count(ax, bx, ay, by);
        return l + r; 
    }

    vector<pi> query(int ax, int bx, int ay, int by) {
        if (ax > high || bx < low) return {};
        if (ax <= low && high <= bx) {
            vector<pi> ans;
            int idx = lower_bound(all(a), pi(ay, 0)) - a.begin();

            for (int i = idx; i < sz(a); i++) {
                if (a[i] > pi{by, INT_MAX}) break;
                ans.push_back(a[i]); 
            }

            return ans;
        }

        vector<pi> l = left->query(ax, bx, ay, by);
        vector<pi> r = right->query(ax, bx, ay, by);

        return comb(l, r);
    }

    ~Seg() {
        if (left) delete left;
        if (right) delete right;
    }
};

int main() {

    int n, q; cin >> n >> q;

    vector<int> X;


    vector<tuple<int, int, int>> pts(n);

    for (auto &[x, y, h]: pts) {
        cin >> x >> y >> h;
        X.push_back(x);
    }
    sort(all(X));
    X.push_back(INT_MAX);

    int N = sz(X);
    vector<vector<pi>> arr(N);
    for (auto &[x, y, h]: pts) {
        x = lower_bound(all(X), x) - X.begin();
        arr[x].push_back({y, h});
    }

    for (int i = 0; i < N; i++) {
        sort(all(arr[i]));
    }

    Seg tree(0, N - 1, arr);

    while(q--) {
        int ax, bx, ay, by;

        cin >> ax >> ay >> bx >> by;

        ax = lower_bound(all(X), ax) - X.begin();
        bx = upper_bound(all(X), bx) - X.begin() - 1;

        int cnt = tree.count(ax, bx, ay, by);
        if (cnt > 64) {
            cout << 1 << "\n";
            continue;
        }

        vector<pi> region = tree.query(ax, bx, ay, by);
        sort(all(region), [] (auto &a, auto &b) {
            return a.second < b.second;
        });

        int found = 0;
        for (int i = 0; i + 2 < sz(region); i++) {
            if (region[i].second + region[i + 1].second > region[i + 2].second) {
                found = 1;
                break;
            }
        }
        cout << found << "\n";
    }
    


    return 0;
}