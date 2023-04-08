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

int main() {
    int n;
    cin >> n;
    string c, name;
    set<string> inside;
    while(n--) {
        cin >> c >> name;
        if (c == "entry") {
            cout << name << " entered";
            if (inside.count(name)) {
                cout << " (ANOMALY)";
            }
            inside.insert(name);
            cout << endl;
        } else {
            cout << name << " exited";
            if (!inside.count(name)) {
                cout << " (ANOMALY)";
            }
            inside.erase(name);
            cout << endl;
        }
    }
    return 0;
}