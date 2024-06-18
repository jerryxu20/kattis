#include <bits/stdc++.h>
using namespace std;

struct Seg {
    int ans = 0;
    Seg *left = nullptr, *right = nullptr;
    int low, high;

    Seg(int l, int h): low(l), high(h) {
        if (low == high) return;
        int mid = (low + high)/2;
        left = new Seg(low, mid);
        right = new Seg(mid + 1, high);
        ans = left->ans + right->ans;
        return;
    }

    int query(int a, int b) {
        if (a <= low && high <= b) return ans;
        if (high < a || low > b) return 0;
        return left->query(a, b) + right->query(a, b);
    }

    void set(int a, int x) {
        if (a == low && a == high) {
            ans = x;
            return;
        }
        if (a < low || a > high) return;
        left->set(a, x);
        right->set(a, x);
        ans = left->ans + right->ans;
        return;
    }
};

const int MAXN = 2e5;
int a[MAXN], b[MAXN];

int main() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    for (int i = 0; i < n; i++) {
        int x; cin >> x; x--;
        b[x] = i;
    }

    Seg tree(0, n);

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int j = b[a[i]];
        ans += tree.query(j + 1, n);
        tree.set(j, 1);
    }
    
    cout << ans << endl;
}