#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair


int main() {
    // I want the differences to increase
    int n;
    cin >> n;
    vector<int> pools(n);
    for (auto &pool: pools) {
        cin >> pool;
    }
    sort(all(pools));
    vector<int> ans;
    int high = n - 1;
    int low = 1;
    ans.push_back(pools[0]);
    int l, r;
    while (low < high) {
        l = abs(pools[low] - ans.back());
        r = abs(pools[high] - ans.back());
        if (l > r) {
            ans.push_back(pools[low]);
            low++;
        } else {
            ans.push_back(pools[high]);
            high--;
        }
    }
    if (low == high) {
        ans.push_back(pools[low]);
    }
    reverse(all(ans));
    for (int i = 1; i + 1 < n; i++) {
        if (abs(ans[i - 1] - ans[i]) > abs(ans[i] - ans[i + 1])) {
            cout << "impossible" << endl;
            return 0;
        }
    }
    for (int num: ans) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}