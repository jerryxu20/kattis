#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair


int main() {
    int n, d;
    cin >> n >> d;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < n; i++) {
        if (nums[i] <= d) {
            cout << "It hadn't snowed this early in " << i << " years!";
            return 0;
        }
    }
    cout << "It had never snowed this early!";
    return 0;
}