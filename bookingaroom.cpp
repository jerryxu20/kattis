#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, r;
    cin >> n >> r;
    vector<int> avail(n);
    iota(avail.begin(), avail.end(), 1);
    set<int> st(avail.begin(), avail.end());
    while(r--) {
        cin >> n;
        st.erase(n);
    }
    if (st.size() == 0) {
        cout << "too late\n";
    } else {
        cout << *st.begin() << endl;
    }
    return 0;
}