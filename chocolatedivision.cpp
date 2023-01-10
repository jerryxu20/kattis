#include <bits/stdc++.h>
using namespace std;

int numberoffactors(int a) {
    int d = 2;
    int ans = 0;
    while (d * d <= a) {
        while (a % d == 0) {
            a /= d;
            ans += d;
        }
        d++;
    }
    if (a > 1) {
        ans += a;
    } 
    return ans;
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 4) {
            break;
        }
        int ans = 1;
        while (true) {
            int b = numberoffactors(n);
            if (b == n) {
                break;
            }
            ans++;
            n = b;
        }
        cout << n << ' ' << ans << '\n';

    } 
    return 0;
}