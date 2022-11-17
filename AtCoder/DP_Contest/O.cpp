#include <bits/stdc++.h>
using namespace std;

const int max_mask = 2097152;
int f[max_mask], pf[max_mask];

int main() {

    int n, mod = 1e9 + 7;
    cin >> n;
    // vector<int> f(1 << n, 0), pf;
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j];
    f[0] = 1;
    // int max_ans = 0;
    for (int i = 0; i < n; i++) {
        // pf = f;
        // fill(f.begin(), f.end(), 0);
        for (int j = 0; j < (1 << n); j++) {
            pf[j] = f[j];
            // cout << pf[j] << ' ';
            f[j] = 0;
        }
        // cout << endl;
        for (int mask = 0; mask < (1 << n); mask++) {
            bitset<22> matched(mask);
            if (matched.count() != i + 1)
                continue;
            for (int j = 0; j < n; j++) {
                if (c[i][j] == 1 && matched[j] == 1) {
                    int pre_mask = mask ^ (1 << j);
                    f[mask] = (f[mask] + pf[pre_mask]) % mod;
                }
            }
            // max_ans = max(max_ans, f[mask]);
        }
    }
    // cout << max_ans << endl;
    cout << f[(1 << n) - 1] << endl;

    return 0;
}