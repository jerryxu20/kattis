#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;

#define pb push_back
#define mp make_pair

class uf {
private:
    vi rank;
    vi id;
public:
    uf(int n) {
        rank = vi(n, 1);
        id = vi(n);
        iota(all(id), 0);
    }

    bool join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rank[b] > rank[a]) swap(a, b);
        rank[a] += rank[b];
        rank[b] = 0;
        id[b] = a;
        return true; 
    }

    int size(int a) {
        return rank[find(a)];
    }

    int find(int a) {
        if (id[a] == a) {
            return a;
        }
        id[a] = find(id[a]);
        return id[a];
    }
};

int solve() {
    int n, ID = 0;
    string a, b;
    cin >> n;
    uf UF(100000);
    map<string, int> ids;
    while(n--) {
        cin >> a >> b;
        if (!ids.count(a)) ids[a] = ID++;
        if (!ids.count(b)) ids[b] = ID++;
        UF.join(ids[a], ids[b]);
        cout << UF.size(ids[a]) << endl;
    }

    return 0;
}

int main() {
    int tcase = 1;
    cin >> tcase;
    for (int i = 1; i <= tcase; i++) {
        // cout << "Case #" << i << " : ";
        solve();
    }
    return 0;
}