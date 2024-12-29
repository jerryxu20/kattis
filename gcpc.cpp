#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef array<int, 3> ent;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

int main() {
    int n, m; cin >> n >> m;

    Tree<ent> leaderboard;
    vector<ent> score(n + 1);

    for (int i = 1; i <= n; i++) {
        score[i][0] = score[i][1] = 0;
        score[i][2] = i;

        leaderboard.insert(score[i]);
    }

    while(m--) {
        int t, p; cin >> t >> p;

        leaderboard.erase(score[t]);

        score[t][0] --;
        score[t][1] += p;

        leaderboard.insert(score[t]);

        ent s = score[1];

        s[2] = -1;
        int x = leaderboard.order_of_key(s);
        cout << x + 1 << endl;
    }
}