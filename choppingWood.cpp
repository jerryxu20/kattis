#include <bits/stdc++.h>
using namespace std;


int largest_unused(vector<bool> &used, int &idx) {
    while (idx >= 0) {
        if (!used[idx]) return idx;
        idx--;
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> v (n);
    vector<bool> used (n + 2);
    vector<int> ans;
    int idx = n + 1;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (v.back() != n + 1) {
        cout << "Error";
        return 0;
    }
    used[v.back()] = true;
    for (int i = n - 1; i >= 0; i--) {
        if (i > 0 && v[i - 1] != v[i] && !used[v[i - 1]]) {
            ans.push_back(v[i - 1]);
            used[v[i - 1]] = true;
        } else {
            int a = largest_unused(used, idx);
            if (a == 0) {
                cout << "Error";
                return 0;
            }
            ans.push_back(a);
            used[a] = true;
            
        }
    }
    if (largest_unused(used, idx) != 0) {
        cout << "Error";
        return 0;
    }
    int len = ans.size();
    for (int i = len - 1; i >= 0; i--) {
        cout << ans[i] << "\n";
    }
    return 0;
}