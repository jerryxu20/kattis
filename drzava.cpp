#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 50000;
const int B = 50;

ll X[MAXN], Y[MAXN], POP[MAXN];
int col[MAXN];
vector<int> id[MAXN], x;
vector<ll> pts[MAXN];

int n, k;

struct UF {
    vi rank, id;
    vector<ll> mod;
    int good = 0;
    UF(int n) : rank(n, 1), id(n), mod(n) {
        iota(id.begin(), id.end(), 0);
        for (int i = 0; i < n; i++) {
            mod[i] |= (1 << (POP[i] % k));
        }
    }
    int find(int a) {
        if (id[a] == a) return a;
        id[a] = find(id[a]);
        return id[a];
    }
    void join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (rank[a] < rank[b]) swap(a, b);
        rank[a] += rank[b];
        id[b] = a;

        ll newmod = mod[a] | mod[b];
        for (int i = 0; i < k; i++) if(mod[a] & (1 << i)) {
            newmod |= (mod[b] << i); 
        }
        newmod |= (newmod >> k);

        mod[a] = newmod;
        if (mod[a] & 1) good = 1;
    }
};

struct DSU {
    vi id, rank;
    int mx = 1;
    DSU(int n) : id(n), rank(n, 1) {
        iota(id.begin(), id.end(), 0);
    }
    int find(int a) {
        if (id[a] == a) return a;
        id[a] = find(id[a]);
        return id[a];
    }
    void join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;

        if (rank[a] < rank[b]) swap(a, b);
        id[b] = a;
        rank[a] += rank[b];
        mx = max(mx, rank[a]);
    }
};

int valid(ll d2) {
    // cout << "checking neighbors" << endl;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = col[i]; j >= max(0, col[i] - B); j--) {
            ll dx = X[i] - x[j];
            ll rem = d2 - dx * dx;
            if (rem < 0) continue;

            ll dy = sqrt(rem);
            
            ll mxy = Y[i] + dy;
            ll mny = Y[i] - dy;

            ll low = lower_bound(pts[j].begin(), pts[j].end(), mny) - pts[j].begin();
            ll high = upper_bound(pts[j].begin(), pts[j].end(), mxy) - pts[j].begin();
            // assert(high >= low);
            cnt += high - low;
            if (cnt >= B) return 1;
        }
    }

    UF uf(n);
    DSU dsu(n);

    vector<pair<int, int>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = col[i]; j >= max(0, col[i] - B); j--) {
            ll dx = X[i] - x[j];
            ll rem = d2 - dx * dx;
            if (rem < 0) continue;

            ll dy = sqrt(rem);
            
            ll mxy = Y[i] + dy;
            ll mny = Y[i] - dy;

            ll low = lower_bound(pts[j].begin(), pts[j].end(), mny) - pts[j].begin();
            ll high = upper_bound(pts[j].begin(), pts[j].end(), mxy) - pts[j].begin();

            while(low < high) {
                edges.push_back({i, id[j][low]});
                low++;
            }
        }
    }

    for (auto &[a, b]: edges) {
        dsu.join(a, b);
        if (dsu.mx > B) return 1;
    }

    for (auto &[a, b]: edges) {
        uf.join(a, b);
    }

    return uf.good;
}

int main() {
    cin >> n >> k;

    set<int> Xset;
    for (int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i] >> POP[i];
        Xset.insert(X[i]);
    }

    x = vector<int>(Xset.begin(), Xset.end());
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (auto &a, auto &b) {
        return Y[a] < Y[b];
    });

    for (auto &i: idx) {
        int xx = lower_bound(x.begin(), x.end(), X[i]) - x.begin();
        id[xx].push_back(i);
        pts[xx].push_back(Y[i]);
        col[i] = xx;
    }
    


    ll low = 1;
    ll high = 1e18;
    ll ans = -1;
    while(low <= high) {
        ll mid = (low + high)/2;
        // cout << mid << endl;
        if (valid(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    assert(ans != -1);

    cout << setprecision(15) << fixed << sqrt(ans) << "\n";
}