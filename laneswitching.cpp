#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> gap;
#define sz(x) (int)x.size()

const int MAXN = 100;
vector<gap> lane[MAXN];
vector<int> id[MAXN];
int s, n, car;
int N = 0;
struct UF {
    vector<int> rank, id;
    UF(int n) {
        rank.resize(n, 1);
        id.resize(n);
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
        if (rank[b] > rank[a]) swap(a, b);
        id[b] = a;
        rank[a] += rank[b];
    }
};

double inter(const gap &a, const gap &b) {
    if (a.first >= a.second) return 0;
    if (b.first >= b.second) return 0;

    double l = max(a.first, b.first);
    double r = min(a.second, b.second);

    if (l >= r) return 0;
    return r - l;
}

bool valid(double x) {
    UF uf(N);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < sz(lane[i]); j++) {
            for (int k = 0; k < sz(lane[i - 1]); k++) {
                gap a = lane[i][j];
                gap b = lane[i - 1][k];

                a.first += x;
                a.second -= x;
                b.first += x;
                b.second -= x;

                if (inter(a, b) >= car) {
                    uf.join(id[i][j], id[i - 1][k]);
                }
            }
        }
    }
    
    for (int i = 0; i < sz(lane[n - 1]); i++) {
        if (uf.find(s) == uf.find(id[n - 1][i])) return true;
    }
    return false;
}



int main() {
    int m, r; cin >> n >> m >> r;

    
    vector<pair<int, int>> cars;
    vector<vector<int>> idx(n);
    for(int i = 0; i < m; i++) {
        int l, len, d;
        cin >> l >> len >> d;
        cars.push_back({len, d});
        idx[l].push_back(i);
    }

    double mx = r;
    for (int i = 0; i < n; i++) {
        sort(idx[i].begin(), idx[i].end(), [&] (auto &a, auto &b) {
            return cars[a].second < cars[b].second;
        });

        int low = 0;
        
        bool start = false;
        for (auto &c: idx[i]) {
            if (c == 0) {
                start = 1;
                continue;
            }
            
            if (cars[c].second > low) {
                lane[i].push_back({low, cars[c].second});
                if (start) {
                    s = N;
                    mx = min(cars[0].second - low, cars[c].second - (cars[0].second + cars[0].first));
                    start = 0;
                }
                id[i].push_back(N++);
            }
            low = cars[c].second + cars[c].first;
        }
        if (start) {
            s = N;
            mx = min(cars[0].second - low, r - (cars[0].second + cars[0].first));
            start = 0;
        }
        lane[i].push_back({low, r});
        id[i].push_back(N++);
    }

    car = cars[0].first;


    double low = 0;
    double high = mx;
    double ans = -1;
    int iters = 100;
    while(iters--) {
        double mid = (low + high)/2;
        if (valid(mid)) {
            ans = mid;
            low = mid;
        } else {
            high = mid;
        }
    }

    if (ans < 0) {
        cout << "Impossible\n";
    } else {
        cout << setprecision(10) << fixed << ans << endl;
    }

    return 0;
}