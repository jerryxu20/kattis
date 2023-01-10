#include <bits/stdc++.h>
using namespace std;


int main() {
    int low = 1;
    int high = 1000;
    while (true) {
        int mid = (low + high) / 2;
        cout << mid << endl;
        string s;
        cin >> s;
        if (s == "lower") {
            high = mid - 1;
        } else if (s == "higher") {
            low = mid + 1;
        } else {
            break;
        }
    }
    return 0;
}