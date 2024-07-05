#include <bits/stdc++.h>
using namespace std;

double a[30], b[30];


int main() {
    int n; cin >> n;
    vector<int> arr(n - 1);
    for (int &x: arr) cin >> x;


    a[0] = pow(2.0, -5/4.0);
    b[0] = pow(2.0, -3/4.0);

    for (int i = 1; i < n - 1; i++) {
        b[i] = a[i - 1];
        a[i] = b[i - 1]/2;
    }

    int need = 1;
 
    double ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (need == 0) break;

        ans += need * b[i];

        need *= 2;
        int cap = min(arr[i], need);
        
        need -= cap;
    }

    if (need) {
        cout << "impossible\n";
        return 0;
    }
    cout << fixed << setprecision(15) << ans << endl;

}