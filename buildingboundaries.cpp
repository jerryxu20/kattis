#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
int main() {
    int t; cin >> t;

    while(t--) {
        pi A, B, C;
        cin >> A.first >> A.second >> B.first >> B.second >> C.first >> C.second;
        ll ans = 5e18;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    // they are all in a line
                    ll w = (A.first + B.first + C.first);
                    ll h = max({A.second, B.second, C.second});
                    ans = min(ans, w * h);

                    w = A.first + max(B.first, C.first);
                    h = max(A.second, B.second + C.second);
                    ans = min(ans, w * h);

                    w = B.first + max(A.first, C.first);
                    h = max(B.second, A.second + C.second);
                    ans = min(ans, w * h);

                    w = C.first + max(A.first, B.first);
                    h = max(C.second, A.second + B.second);
                    ans = min(ans, w * h);

                    swap(C.first, C.second);
                }
                swap(B.first, B.second);
            }
            swap(A.first, A.second);
        }

        cout << ans << endl;


    }
}