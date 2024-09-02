#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int LOG = 60;
const ll MOD = 1e9 + 7;

struct Point {
    ll x, y;
    Point(ll x = 0, ll y = 0): x(x % MOD), y(y % MOD) {};

    ll dot(const Point &p) {
        return (x * p.x + y * p.y) % MOD;
    }

    ll cross(const Point &p) {
        return (x * p.y - p.x * y) % MOD;
    }

    Point rotate(ll SIN, ll COS) {
        return Point(x * COS - y * SIN, x * SIN + y * COS);
    }
};

Point trans[LOG];


ll power(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while(b) {
        if (b & 1) res *= a;
        a *= a;
        b /= 2;
        res %= MOD;
        a %= MOD;
    }
    return ((res % MOD) + MOD) % MOD;
}


ll inv(ll x) {
    return power(x, MOD - 2);
}

// Point bounce(Point &a, int idx) {
//     Point t = trans[idx];
//     // t is assuming that we started at (-1, 0), but we actually started at a and the angle is off too

//     ll COS = a.dot(Point(-1, 0)) * inv(a.x * a.x + a.y * a.y);
//     ll SIN = a.cross(Point(-1, 0)) * inv(a.x * a.x + a.y * a.y);

//     COS %= MOD;
//     SIN %= MOD;
//     // ll sgn = a.cross(Point(-1, 0));
//     // if (sgn < 0) {
//     //     COS *= -1;
//     // }
    
// }


ll SIN[LOG], COS[LOG];
int main() {
    ll a, b, n; cin >> a >> b >> n;

    n++;
    // ll x = ((a * a - b * b) % MOD) * inv(a * a + b * b);
    // ll y = ((2 * a * b) % MOD) * inv(a * a + b * b);

    SIN[0] = ((2 * a * b) % MOD) * inv(a * a + b * b);
    COS[0] = ((b * b - a * a) % MOD) * inv(a * a + b * b);
    
    SIN[0] %= MOD;
    COS[0] *= -1;
    COS[0] %= MOD;

    for (int i = 1; i < LOG; i++) {
        SIN[i] = 2 * SIN[i - 1] * COS[i - 1];
        SIN[i] %= MOD;
        SIN[i] += MOD;
        SIN[i] %= MOD;

        COS[i] = (COS[i - 1] * COS[i - 1]) % MOD - (SIN[i - 1] * SIN[i - 1]) % MOD;
        COS[i] %= MOD;
        COS[i] += MOD;
        COS[i] %= MOD;
    }

    Point cur(MOD - 1, 0);

    ll s = 0;
    ll c = 1;
    ll ss, cc;
    for (int i = 0; i < LOG; i++) if (n & (1LL << i)) {
        ss = SIN[i] * c + s * COS[i];
        cc = c * COS[i] - s * SIN[i];
        ss %= MOD;
        cc %= MOD;
        s = ss;
        c = cc;
    }

    cout << ((MOD - c) % MOD + MOD) % MOD << endl;
}