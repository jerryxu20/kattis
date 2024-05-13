#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int &x: arr) cin >> x;

    int ans = -1;
    for (int i = 0; i < n; i++) {
        int prev = arr[i];
        int l = i - 1;
        int r = i + 1;

        while(l >= 0 && r < n && arr[l] == arr[r] && arr[l] < arr[l + 1]) {
            ans = max(ans, r - l + 1);
            l--;
            r++;
        } 
    }

    cout << ans << endl;

}