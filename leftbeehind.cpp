#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a = -1;
    int b = -1;
    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0) {
            break;
        }
        if (a + b == 13) {
            cout << "Never speak again.";
        } else if (a == b) {
            cout << "Undecided.";
        } else if (a > b) {
            cout << "To the convention.";
        } else {
            cout << "Left beehind.";
        }
        cout << '\n';
    }   
    return 0;
}