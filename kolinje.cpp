#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Frac {
    ll x, y;
    Frac(ll x = 0, ll y = 0): x(x), y(y) {
        if (x == 0) {
            y = 1;
            return;
        }

        ll g = __gcd(x, y);
        this->x /= g;
        this->y /= g;
    }

    Frac operator+(Frac rhs) {
        return Frac(x * rhs.y + rhs.x * y, y * rhs.y);
    }
    Frac operator-(Frac rhs) {
        return Frac(x * rhs.y - rhs.x * y, y * rhs.y);
    }
    Frac operator*(Frac rhs) {
        return Frac(x * rhs.x, y * rhs.y);
    }
    Frac operator/(Frac rhs) {
        return Frac(x * rhs.y, y * rhs.x);
    }
    bool operator<(Frac rhs) {
        return x * rhs.y < y * rhs.x;
    }
    bool operator>(Frac rhs) {
        return x * rhs.y > y * rhs.x;
    }
    bool operator<=(Frac rhs) {
        return x * rhs.y <= y * rhs.x;
    }
    bool operator>=(Frac rhs) {
        return x * rhs.y >= y * rhs.x;
    }
};

const int MAXN = 1000;
Frac cur[MAXN];
int b[MAXN];
Frac weight[MAXN];

int main() {
    int n; cin >> n;
    int sm = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cin >> b[i];
        sm += b[i];
        cur[i] = Frac(x, 1);
    }
    for (int i = 0; i < n; i++) {
        weight[i] = Frac(b[i], sm);
    }

    for (int i = 1; i < n; i++) {
        if (cur[i] > cur[i - 1] && weight[i] > weight[i - 1]) {
            cout << -1 << endl;
            return 0;
        }
    }

    Frac low(0, 1), high(1e7, 1);

    for (int i = 1; i < n; i++) {
        if (cur[i] <= cur[i - 1] && weight[i] <= weight[i - 1]) continue;
        Frac x = (cur[i - 1] - cur[i])/(weight[i] - weight[i - 1]);
        if (cur[i] < cur[i - 1]) {
            if (x < high) high = x;
        } else {
            if (x > low) low = x;
        }
    }

    if (low > high) {
        cout << -1 << endl;
        return 0;
    }

    cout << fixed << setprecision(20) << (double)low.x/low.y << endl;
}