#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    vector<long long> ans;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i - 1);
            if (n/i != i) ans.push_back(n/i - 1);
        }
    }

    sort(ans.begin(), ans.end());
    for (auto &x: ans) {
        cout << x << " ";
    }
    cout << endl;
}