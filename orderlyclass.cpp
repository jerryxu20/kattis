#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair


int main() {
    string a, b;
    cin >> a >> b;
    // lowest bad
    int n = sz(a);
    int low = -1;
    int high = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;
        low = i;
        break;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == b[i]) continue;
        high = i;
        break;
    }
    int left = low;
    int right = high;
    while (left <= right) {
        if (a[left] != b[right] || a[right] != b[left]) {
            cout << 0 << endl;
            return 0;
        }
        left++;
        right--;
    }
    int ans = 1;
    left = low - 1;
    right = high + 1;
    while (left >= 0 && right < n) {
        if (a[left] != b[right] || a[right] != b[left]) break;
        ans++;
        left--;
        right++;
    }
    cout << ans << endl;
    return 0;
}