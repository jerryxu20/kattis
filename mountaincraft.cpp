#include <bits/stdc++.h>
using namespace std;

struct Seg {
    Seg *left = nullptr, *right = nullptr;
    int low, high;
    int ans = 1;
    int delta = 0;

    Seg(int l, int h) {
        low = l;
        high = h;
        ans = size();
    }

    int query(int l, int r) {
        if (l <= low && high <= r) {
            return ans;
        }

        if (high < l || r < low) {
            return 0;
        }
    
        push();
        return left->query(l, r) + right->query(l, r);
    }

    void add(int l, int r, int x) {
        if (high < l || r < low) {
            return;
        }

        if (l <= low && high <= r) {
            // this is bad
            if (delta + x < 0) {
                push();
                left->add(l, r, x);
                right->add(l, r, x);
                ans = left->ans + right->ans;
                assert(ans <= size());
                return;
            }

            delta += x;
            assert(delta >= 0);
            if (delta == 0) {
                if (left) {
                    ans = left->ans + right->ans;
                } else {
                    ans = size();
                }
            }

            if (delta > 0) {
                ans = 0;
            }

            return;
        }  

        push();
        left->add(l, r, x);
        right->add(l, r, x);

        ans = left->ans + right->ans;
    }

    void push() {
        if (left == nullptr) {
            int mid = (low + high)/2;
            left = new Seg(low, mid);
            right = new Seg(mid + 1, high);
        }

        left->add(low, high, delta);
        right->add(low, high, delta);
        delta = 0;

        ans = left->ans + right->ans;
    }

    int size() {
        return high - low + 1;
    }
};

int main() {
    int q, w; cin >> q >> w;


    Seg seg(0, w - 1);
    map<pair<int, int>, int> state; 
    while(q--) {
        int x, y;
        cin >> x >> y;
        int l = x - y;
        int r = x + y - 1;
        r = min(r, w - 1);
        if (state[{x, y}] == 1) {
            seg.add(l, r, -1);
        } else {
            seg.add(l, r, 1);
        }
        state[{x, y}] ^= 1;
        long long vis = w - seg.query(0, w - 1);

        double ans = 2 * sqrt(0.5 * vis * vis);
        cout << setprecision(15) << fixed << ans << endl;
    }

}
