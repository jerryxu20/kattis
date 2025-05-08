#include <bits/stdc++.h>
using namespace std;

const int MAXN = 60;
vector<string> pref[MAXN];
vector<string> team[MAXN];
int at[MAXN];

int main() {
    int n, k; cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int q; cin >> q;
        pref[i].resize(q);
        for (auto &x: pref[i]) cin >> x;
    }

    int p; cin >> p;
    vector<string> ranking(p);
    for (auto &x: ranking) cin >> x;

    set<string> taken;
    int j = 0;
    while(k--) {
        for (int i = 0; i < n; i++) {
            while(at[i] < pref[i].size() && taken.count(pref[i][at[i]])) {
                at[i]++;
            }
            while(j < p && taken.count(ranking[j])) {
                j++;
            } 

            string choice;
            if (at[i] < pref[i].size()) {
                choice = pref[i][at[i]];
            } else {
                choice = ranking[j];
            }
            team[i].push_back(choice);
            taken.insert(choice);
        }
    }
    for (int i = 0; i < n; i++) {
        for (auto &s: team[i]) {
            cout << s << " ";
        }
        cout << "\n";
    }   
}