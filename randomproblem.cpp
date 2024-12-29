#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
int arr[MAXN], nums[MAXN];


int ab[1000][1000], bc[1000][1000], ac[1000][1000], cnt[1000][1000];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> nums[i];

    int start = -1;
    int g1 = -1;
    int g2 = -1;

    int thres = (n + 39)/40 + 1;

    map<int, int> id;
    int N = 0;
    for (int i = 0; i < n; i++) {
        if (!id.count(nums[i])) {
            id[nums[i]] = ++N;
        }
        arr[i] = id[nums[i]];
    }
    
    for (int d1 = 1; d1 < n; d1++) {
        for (int d2 = 1; d2 < n; d2++) {
            for (int i = 0, j = d1, k = d1 + d2; k < n; i++, j++, k++) {
                int a = arr[i];
                int b = arr[j];
                int c = arr[k];
                if (ab[a][b] == 0) ab[a][b] = c;
                if (ac[a][c] == 0) ac[a][c] = b;
                if (bc[b][c] == 0) bc[b][c] = a;

                int valid = 1;
                if (ab[a][b] != c) {
                    ab[a][b] = -1;
                    valid = 0;
                } 
                if (ac[a][c] != b) {
                    ac[a][c] = -1;
                    valid = 0;
                }
                if (bc[b][c] != a) {
                    bc[b][c] = -1;
                    valid = 0;
                }
                if (valid) {
                    cnt[a][b]++;
                }
            }

            for (int i = 0, j = d1, k = d1 + d2; k < n; i++, j++, k++) {
                int a = arr[i];
                int b = arr[j];
                int c = arr[k];

                if (ab[a][b] != c || ac[a][c] != b || bc[b][c] != a) {
                    continue;
                } 
                if (cnt[a][b] < thres) continue;

                if (start == -1 || i < start) {
                    start = i;
                    g1 = d1;
                    g2 = d2;
                    break;
                }   
            }

            for (int i = 0, j = d1, k = d1 + d2; k < n; i++, j++, k++) {
                int a = arr[i];
                int b = arr[j];
                int c = arr[k];
                ab[a][b] = 0;
                ac[a][c] = 0;
                bc[b][c] = 0;
                cnt[a][b] = 0;
            }
            
        }
    }

    if (start == -1) {
        cout << "random sequence\n";
        return 0;
    }
    
    cout << "triple correlation " << nums[start] << "(" << g1 << ")" << nums[start + g1] << "(" << g2 << ")" << nums[start + g1 + g2] << " found\n";  
}