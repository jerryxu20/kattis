#include <bits/stdc++.h>
using namespace std;


int solve(int c) {
    int n; cin >> n;

    vector<int> pts(n);
    for (int &x: pts) cin >> x;

    int sm = accumulate(pts.begin(), pts.end(), 0);

    cout << setprecision(10) << fixed << "Case #" << c << ": "; 
    for (int i = 0; i < n; i++) {
        double low = 0;
        double high = 1;
        double ans = 1;

        int iter = 50;
        while(iter--) {
            double mid = (low + high)/2;

            double weights = 0;
            double targ = pts[i] + sm * mid;

            for (int j = 0; j < n; j++) {
                if (pts[j] >= targ) continue;
                weights += (targ - pts[j])/(double)sm;
            }
            
            
            if (weights >= 1) {
                ans = mid;
                high = mid;
            } else {
                low = mid;
            }
        }
        cout << ans * 100 << " ";
    } 
    cout << endl;
    return 0;
}

int main() {
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(i);
    }
}