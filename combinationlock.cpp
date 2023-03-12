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

int distance(int a, int b, int inc) {
    int ans = 0;
    // cout << a << " " << b << " " << inc;
    while(a != b) {
        a += inc;
        a += 40;
        a %= 40;
        ans++;
    }
    // cout << " " << ans << endl;
    return ans;
    
}

int main() {
    int a, b, c, init;
    while(true){
        cin >> init >> a >> b >> c;
        if ((a + b + c + init) == 0) return 0;
        int ans = 3 * 360;
        ans += 9 * distance(init, a, -1);
        ans += 9 * distance(a, b, 1);
        ans += 9 * distance(b, c, -1);
        cout << ans << endl;
    }
    return 0;
}