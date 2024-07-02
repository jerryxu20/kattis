#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
int price[MAXN];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    sort(price, price + n, greater<int>());

    long long ans = 0;
    for (int i = 2; i < n; i += 3) {
        ans += price[i];
    }
    cout << ans << endl;
    
}