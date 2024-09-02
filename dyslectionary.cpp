#include <bits/stdc++.h>
using namespace std;

int N = 0;
void solve(vector<string> &arr) {
    if (N) cout << "\n";
    vector<string> rev(arr.begin(), arr.end());
    for (auto &s: rev) reverse(s.begin(), s.end());

    vector<int> idx(arr.size());
    iota(idx.begin(), idx.end(), 0);

    sort(idx.begin(), idx.end(), [&] (auto &a, auto &b) {
        return rev[a] < rev[b];
    });

    int mx = 0;
    for (auto &s: arr) mx = max(mx, (int) s.size());

    for (int i = 0; i < (int) arr.size(); i++) {
        int x = mx - arr[idx[i]].size();

        if (x) cout << string(x, ' ');
        cout << arr[idx[i]] << "\n";
    }
    N++;
}


int main() {
    string s;
    vector<string> arr;
    while(getline(cin, s)) {
        if (s == "") {
            solve(arr);
            arr.clear();
        } else {
            arr.push_back(s);
        }
    }
    solve(arr);
}