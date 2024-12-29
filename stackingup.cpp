#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
void dfs(vector<int> &arr) {
    if (sz(arr) == 0) return;
    int x = arr.back();
    if (x == 1) {
        arr.pop_back();
        dfs(arr);
        cout << 1;
        return;
    }
    if (x % 2 == 0) {
        arr.back() /= 2;
        for (int i = 0; i < sz(arr) - 1; i ++) {
            arr[i]++;
        }
        dfs(arr);
        cout << "d";
        cout << "+";
        return;
    }

    arr.back() /= 2;
    for (int i = 0; i < sz(arr) - 1; i++) {
        arr[i] += 2;
    }
    dfs(arr);
    cout << "d";
    cout << "+";
    cout << 1;
    cout << "+";
    return;
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int &x: arr) cin >> x;
    dfs(arr);
}