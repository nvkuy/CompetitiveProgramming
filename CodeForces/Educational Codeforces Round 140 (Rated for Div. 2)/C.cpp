#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, mod = 998244353;
    cin >> n;
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            cin >> c[i][j];
    bool no_ans = false;
    for (int l1 = 1; l1 <= n; l1++) {
        for (int l2 = 1; l2 <= l1; l2++) {
            for (int i1 = 0; i1 + l1 - 1 < n; i1++) {
                for (int i2 = 0; i2 + l2 - 1 < n; i2++) {
                    int j1 = i1 + l1 - 1, j2 = i2 + l2 - 1;
                    if (c[i1][j1] == 1 && c[i2][j2] == 2)
                        no_ans = true;
                }
            }
        }
    }
    if (no_ans) {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<int>> f(n, vector<int>(2, 0));
    f[0][0] = f[0][1] = 1;
    for (int i = 1; i < n; i++) {

    }

    return 0;
}
