#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

deque<int> build(int l, int r) {
    deque<int> q;
    for (int i = 0; i <= 13; i++) {
        if (l & (1 << i)) q.push_back(i);
    }

    for (int i = 13; i >= 0; i--) {
        if (r & (1 << i)) q.push_back(i);
    }
    return q;
}

pair<int, int> placeleft(int l, int r, int x) {
    deque<int> q = build(l, r);
    while(q.size() && q.front() == x) {
        q.pop_front();
        x++;
    }

    q.push_front(x);

    vector<int> v(all(q));

    int idx = 0;
    int ll = (1 << v[0]);
    int rr = 0;
    for (int i = 0; i < (int) v.size(); i++) {
        if (v[i] > v[idx]) idx = i;
    }

    for (int i = 1; i <= idx; i++) {
        if (v[i - 1] >= v[i]) return {-1, -1};
        ll |= (1 << v[i]);
    }

    for (int i = idx + 1; i < (int) v.size(); i++) {
        if (v[i] >= v[i - 1]) return {-1, -1};
        rr |= (1 << v[i]);
    }

    return {ll, rr};
}

pair<int, int> placeright(int l, int r, int x) {
    deque<int> q = build(l, r);
    while(q.size() && q.back() == x) {
        q.pop_back();
        x++;
    }

    q.push_back(x);

    vector<int> v(all(q));

    int idx = 0;
    int ll = (1 << v[0]);
    int rr = 0;
    for (int i = 0; i < (int) v.size(); i++) {
        if (v[i] > v[idx]) idx = i;
    }

    for (int i = 1; i <= idx; i++) {
        if (v[i - 1] >= v[i]) return {-1, -1};
        ll |= (1 << v[i]);
    }

    for (int i = idx + 1; i < (int) v.size(); i++) {
        if (v[i] >= v[i - 1]) return {-1, -1};
        rr |= (1 << v[i]);
    }

    return {ll, rr};
}

constexpr int MAXN = (1 << 13) + 1;
int seen[MAXN][MAXN];
int id = 0;

int solve() {
    int n; cin >> n;
    id++;
    vector<int> arr(n);
    for (int &x: arr) {
        cin >> x;
        x = __builtin_ctz(x);
    }

    if (n == 1) {
        cout << "r\n";
        return 0;
    }

    queue <tuple<int, int, string>> q;

    int L = (1 << arr[0]);
    int R = (1 << arr[1]);

    if (L == R) {
        L = 0;
        R += R;
    }
    

    q.push({L, R, "rr"});

    for (int i = 2; i < n; i++) {
        int z = q.size();
        if (z == 0) break;
        while(z--) {
            auto [l, r, ans] = q.front();
            q.pop();

            auto [ll, rr] = placeleft(l, r, arr[i]);
            auto [lll, rrr] = placeright(l, r, arr[i]);
            
            if (ll != -1 && seen[ll][rr] != id) {
                seen[ll][rr] = id;
                q.push({ll, rr, ans + "l"});
            }
            if (lll != -1 && seen[lll][rrr] != id) {
                seen[lll][rrr] = id;
                q.push({lll, rrr, ans + "r"});
            }

        }
    }

    while(q.size()) {
        auto [l, r, ans] = q.front();
        q.pop();
        if (__builtin_popcount(l) + __builtin_popcount(r) == 1) {
            cout << ans << endl;
            return 0;
        }
    }

    cout << "no\n";




    return 0;
}


int32_t main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}