#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

ll power(ll a, ll b, ll m) {
    ll res = 1;
    while(b) {
        if (b & 1) res *= a;

        a *= a;
        b /= 2;

        a %= m;
        res %= m;
    }
    return res % m;
}

ll f(ll n, ll mod) {
    if (mod == 1) return 0;
    if (n == 1) return 1;
    if (n <= 4) {
        ll b = f(n - 1, LLONG_MAX);
        return power(n, b, mod);
    }  
    ll b = phi(mod) + f(n - 1, phi(mod));
    return power(n, b, mod);
}


int main() {
    ll n, m;
    cin >> n >> m;
    cout << f(n, m) << endl;
}