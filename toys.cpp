#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = (res + k) % i;
    }
    cout << res << endl;
}