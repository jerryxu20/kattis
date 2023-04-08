#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define pb push_back
#define mp make_pair

double L, K, T1, T2, H;

// finds largest possible rain
bool check1(double rain) {
    if (rain <= L) return rain <= H;
    double over = rain - L;
    double time = T1 + T2 - L / (rain / T1);
    // over drains for t
    over = max(0.0, over - time * K);
    return over + L <= H;
}

// finds smallest possible rain
bool check2(double rain) {
    if (rain <= L) return rain >= H;
    double over = rain - L;
    double time = T1 + T2 - L / (rain / T1);
    // over drains for t
    over = max(0.0, over - time * K);
    return over + L >= H;
}

int solve(int tcase) {
    double e = 1e-6;
    cin >> L >> K >> T1 >> T2 >> H;
    // output F1, F2, F1 is smallest rainfall to get obs and F2 is largest rainfall to get obs
    double low = 0;
    double high = 1e9;
    double F1 = high;
    double F2 = high;
    while (high - low > e) {
        double mid = (high + low) / 2;
        if (check1(mid)) {
            F1 = mid;
            low = mid;
        } else {
            high = mid;
        }
    }
    low = 0;
    high = 1e9;
    while (high - low > e) {
        double mid = (high + low) / 2;
        if (check2(mid)) {
            high = mid;
            F2 = mid;
        } else {
            low = mid;
        }
    }
    cout << setprecision(12) << F2 << " " << F1 << endl;
    tcase++;
    return 0;
}

int main() {
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; i++) {
        solve(i);
    }
    // for (int i = 1; ; i++) {
    //     if (solve(i)) break;
    // }
    testcase++;
    return 0;
}