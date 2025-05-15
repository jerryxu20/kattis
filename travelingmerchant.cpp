#include <bits/stdc++.h>
using namespace std;

int n; 
const int B = 300;
const int MAXN = 1e5;
typedef pair<int, int> pi;
int init[MAXN];
int delta[MAXN];
vector<int> mod[7];
vector<int> r_mod[7];
int cost[MAXN];
vector<int> MX, MN, BEST, BESTR;

void build() {
    MX.assign(n, 0);
    MN.assign(n, 1e9);
    BEST.assign(n, 0);
    BESTR.assign(n, 0);

    for (int i = 0; i < n; i++) {
        MN[i/B] = min(MN[i/B], cost[i]); 
        MX[i/B] = max(MX[i/B], cost[i]);

        BEST[i/B] = max(BEST[i/B], cost[i] - MN[i/B]);
        BESTR[i/B] = max(BESTR[i/B], MX[i/B] - cost[i]);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> init[i] >> delta[i];
    }

    int q; cin >> q;

    vector<pi> queries(q);
    for (auto &[s, t]: queries) {
        cin >> s >> t;
        s--; t--;
    }
    for (int i = 0; i < q; i++) {
        if (queries[i].first < queries[i].second) {
            mod[queries[i].first % 7].push_back(i);
        } else {
            int d = queries[i].first - queries[i].second;
            r_mod[((queries[i].first + 1) % 7)].push_back(i);
        }
    }    

    vector<int> mult = {0, 1, 2, 3, 2, 1, 0};
    vector<int> res(q);

    for (int m = 0; m < 7; m++) {
        vector<int> val(n);
        for (int d = 0; d < 7; d++) {
            for (int i = ((m + d) % 7); i < n; i += 7) {
                cost[i] = init[i] + mult[d] * delta[i];
                val[i] = d;
            }
        }


        build();

        for (int &idx: mod[m]) {
            auto &[l, r] = queries[idx];
            int mx = 0;
            int mn = 1e9;

            int a = l/B;
            int b = r/B;

            int ans = 0;

            for (int i = l; i <= min(r, ((a + 1) * B) - 1); i++) {
                ans = max(ans, cost[i] - mn);
                mn = min(mn, cost[i]);
                mx = max(mx, cost[i]);
            }

            if (a == b) {

                res[idx] = ans; 
                continue;
            }
            
            for (int bucket = a + 1; bucket < b; bucket++) {
                ans = max({ans, MX[bucket] - mn, BEST[bucket]});
                mx = max(MX[bucket], mx);
                mn = min(MN[bucket], mn);
            }

            for (int i = b * B; i <= r; i++) {
                ans = max(ans, cost[i] - mn);
                mn = min(mn, cost[i]);
                mx = max(mx, cost[i]);
            }
            res[idx] = ans;
        }

        for (int &idx: r_mod[m]) {

            auto &[l, r] = queries[idx];

            swap(l, r);
            

            int mx = 0;
            int mn = 1e9;

            int a = l/B;
            int b = r/B;


            int ans = 0;

            for (int i = l; i <= min(r, ((a + 1) * B) - 1); i++) {
                ans = max(ans, mx - cost[i]);
                mn = min(mn, cost[i]);
                mx = max(mx, cost[i]);
            }

            if (a == b) {
                res[idx] = ans; 
                continue;
            }
            
            for (int bucket = a + 1; bucket < b; bucket++) {
                ans = max({ans, mx - MN[bucket], BESTR[bucket]});
                mx = max(MX[bucket], mx);
                mn = min(MN[bucket], mn);
            }

            for (int i = b * B; i <= r; i++) {
                ans = max(ans, mx - cost[i]);
                mn = min(mn, cost[i]);
                mx = max(mx, cost[i]);
            }
            
            res[idx] = ans;
        }
    }

    for (int &x: res) {
        cout << x << "\n";
    }   
}