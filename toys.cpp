#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
signed main(){
    int n, k;
    cin >> n >> k;
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res = (res + k) % (i);
    cout << res << endl;
}