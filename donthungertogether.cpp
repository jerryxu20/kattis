#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

int n, k;
bool valid(double amount, vector<pi> &food) {
    priority_queue<int, vi, greater<int>> pq;
    vector<double> night(n);
    for (int i = 0; i < n; i++) {
        auto [add, expire] = food[i];
        pq.push(expire - 1);
        night[expire - 1] += add;

        double hunger = amount * k;
        while(sz(pq) && hunger > 0) {
            int d = pq.top();
            if (d < i) {
                pq.pop();
                continue;
            }
            double eat = min(night[d], hunger);
            hunger -= eat;
            night[d] -= eat;
            if (night[d] == 0) {
                pq.pop();
            }
        }
        if (hunger > 0) return false;
    }
    return true;
}

double EPS = 1e-12;
int solve(int tc) {
    cin >> n >> k;
    vector<pi> food(n);
    double high = 0;
    for (auto &[a, b]: food) {
        cin >> a >> b;
        high += a;
    }
    double ans = -1;
    double low = 0;
    int m = 250;
    while(abs(high - low) > EPS && m--) {
        double mid = (low + high) / 2;
        if (valid(mid, food)) {
            ans = mid;
            low = mid;
        } else {
            high = mid;
        }
    }
    if (ans <= 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << fixed << setprecision(20) << ans << endl;

    return 0;
}

int main() {
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        if (solve(i)) break;
    }
    return 0;
}