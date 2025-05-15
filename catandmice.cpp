#include <bits/stdc++.h>
using namespace std;
const int MAXN = 15;

int n;
double m;
pair<int, int> pos[MAXN + 1];
int duck[MAXN];


bool valid(double is) {
    typedef tuple<double, int, int> ti;
    vector<double> speeds(n, is);
    
    for (int i = 1; i < n; i++) {
        speeds[i] = speeds[i - 1] * m;
    }
    
    priority_queue<ti, vector<ti> , greater<ti>> pq; 
    pq.push({0, (1 << n) - 1, n});

    vector<vector<double>> best(1 << n, vector<double>(n + 1, 1e9));
    best[(1 << n) - 1][n] = 0;

    while(pq.size()) {
        auto [t, bs, prev] = pq.top();
        pq.pop();
        
        if (bs == 0) {
            return true;
        }

        if (t > best[bs][prev]) continue;
        
        auto [x, y] = pos[prev];        

        for (int i = 0; i < n; i++) if (bs & (1 << i)) {
            auto [xx, yy] = pos[i];

            int dx = x - xx;
            int dy = y - yy;
            double dis = sqrt(dx * dx + dy * dy);

            double delta = dis/speeds[n - __builtin_popcount(bs)];
            double nt = t + delta;

            if (nt <= duck[i]) {
                int nbs = bs & ~(1 << i);
                int nprev = i;
                
                if (nt < best[nbs][nprev]) {
                    best[nbs][nprev] = nt;
                    pq.push({nt, nbs, nprev});
                }
            }
        }
    }
    
    return false;
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pos[i].first >> pos[i].second >> duck[i];
    }
    cin >> m;

    double low = 1e-9;
    double high = 1e6;
    double ans = high;
    int k = 30;
    while(k--) {
        double mid = (low + high)/2;
        if (valid(mid)) {
            ans = mid;
            high = mid;
        } else {
            low = mid;
        }
    } 
    

    cout << setprecision(20) << fixed << ans << endl;
}