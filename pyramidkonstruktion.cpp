#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, N, M; cin >> H >> N >> M;

    // I can always tile a layer with 2 x 4
    // just keep track of the number of 2 x 4s needed

    int a = 0;
    int b = 0;
    if (N == 0) {
        a++;
    } else {
        N--;
    }

    vector<int> arr;
    for (int h = 2; h <= H; h++) {
        int need = 4 + (h - 2) * 4;
        arr.push_back(need);
    }
    
    for (int &x: arr) {
        int cap = min(x/2, M);
        M -= cap;
        x -= 2 * cap;
    }

    int extra = 0;
    for (int &x: arr) {
        extra += x;
    }

    if (extra > N) {
        extra -= N;
        N = 0;
    } else {
        extra = 0;
    }
    if (extra % 2 == 1) {
        a++;
        extra--;
    }
    b += extra/2;

    cout << a << " " << b << endl;


}