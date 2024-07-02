#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p, d; cin >> n >> p >> d;
    string s; cin >> s;
    s += s;

    int cur = 0;
    int low = 0;
    int ans = 0;
    for (int i = 0; i < n + n; i++) {
        if (s[i] == 'Z') cur++;

        while(low < i - p + 1) {
            if (s[low] == 'Z') cur--;
            low++;
        }

        if (i >= n && cur < d) ans++; 
    }
    cout << ans << endl;



}