#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5;
ll within[MAXN], ump[MAXN], player[MAXN];
int main() {
    ll ans = 0;

    ll sm = 0;
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> player[i] >> ump[i];

        sm += player[i];
    }

    ll smbad = 0;
    for (int i = 0; i < n; i++) {
        within[i] = player[i]*(player[i] - 1)/2;
        smbad += within[i];
    }

    for (int i = 0; i < n; i++) {
        ll p = sm - player[i];

        ll pairs = p * (p - 1)/2 - smbad + within[i];        
        ll cont = ump[i] * pairs;
        ans += cont;
    }

    cout << ans << endl;







}