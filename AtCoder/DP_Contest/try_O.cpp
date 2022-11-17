#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, mod = 1e9 + 7;
    cin >> n;
    vector<int> f(1 << n, 0);
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j];
    f[0] = 1;
    for (int mask = 1; mask < (1 << n); mask++) {
        bitset<22> matched(mask);
        int i = matched.count() - 1;
        for (int j = 0; j < n; j++) {
            if (c[i][j] == 1 && matched[j] == 1) {
                int sub_mask = mask ^ (1 << j);
                f[mask] += f[sub_mask];
                f[mask] %= mod;
            }
        }
    }
    cout << f[(1 << n) - 1] << endl;

    return 0;
}