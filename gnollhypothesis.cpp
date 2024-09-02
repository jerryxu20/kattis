#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500;
double odds[MAXN];
double ans[MAXN];

int main() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> odds[i];
    
    cout << fixed << setprecision(15);
    if (n == k) {
        for (int i = 0; i < n; i++) {
            cout << odds[i] << " ";
        }
        cout << endl;
        return 0;
    }

    if (k == 1) {
        for (int i = 0; i < n; i++) {
            cout << 100.0/n << " ";
        }
        cout << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int feeders = 0;

        double weight = (double)k * (k - 1)/(n * (n - 1));
        double sm = 0;
        for (int j = i; ; j = (j - 1 + n) % n) {
            sm += odds[j];
            int rem = n - feeders - 2;
            if (rem < k - 2) break;

            ans[i] += weight * sm;
            if (rem) weight /= rem;
            weight *= (rem - k + 2);
            feeders++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}