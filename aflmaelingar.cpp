#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, q; cin >> k >> q;
    int n = 300;
    vector<int> ans(n);
    if (k == 2) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    cout << 0 << " ";
                } else {
                    cout << 1 << " ";
                }
            }
            cout << endl;
            cin >> ans[i];
        }


    } else if (k == 4) {
        for (int i = 0; i + 1 < n; i += 2) {
            for (int j = 0; j < i; j++) {
                cout << 0 << " ";
            }
            cout << 1 << " " << 100 << " ";
            for (int j = i + 2; j < n; j++) {
                cout << 0 << " ";
            }
            cout << endl;
            
            int x; cin >> x;
            ans[i] = x % 100;
            ans[i + 1] = x/100;
        }
    } else if (k == 3) {
        for (int i = 0; i + 2 < n; i += 3) {
            for (int j = 0; j < i; j++) {
                cout << 0 << " ";
            }
            cout << 1 << " " << 100 << " ";
            for (int j = i + 2; j < n; j++) {
                cout << 0 << " ";
            }
            cout << endl;
            int a; cin >> a;
            ans[i] = a % 100;
            ans[i + 1] = a/100;

            for (int j = 0; j < i + 1; j++) {
                cout << 0 << " ";
            }
            cout << 10 << " " << 1 << " ";
            for (int j = i + 3; j < n; j++) {
                cout << 0 << " ";
            }
            cout << endl;

            int b; cin >> b;
            // if (b < 100) b += 1000;

            b -= 10 * ans[i + 1];
            if (b < 0) b += 1000;
            ans[i + 1] += b/100 * 10;
            ans[i + 2] = b % 100;
        }
    }


    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
}