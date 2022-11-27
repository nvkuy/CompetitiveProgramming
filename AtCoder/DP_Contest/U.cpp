#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    vector<long long> cost(1 << n, 0), f = cost;
    for (int i = 0; i < (1 << n); i++) {
        for (int u = 0; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                if (((1 << u) & i) != 0 && ((1 << v) & i) != 0)
                    cost[i] += a[u][v];
            }
        }
        // cout << cost[i] << endl;
    }
    // cout << cost[(1 << n) - 1] << endl;
    for (int i = 0; i < (1 << n); i++) {
        int j = ((1 << n) - 1) ^ i;
        for (int k = j; k; k = ((k - 1) & j)) {
            f[i ^ k] = max(f[i ^ k], f[i] + cost[k]);
        }
    }
    cout << f[(1 << n) - 1] << endl;

    return 0;
}