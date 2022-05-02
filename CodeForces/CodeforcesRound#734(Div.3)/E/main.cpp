#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<vector<int>> f(n + 1, vector<int>(k + 1, 1e9));
        a[0] = 0, f[0][0] = 0;
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {

            }
        }

    }

    return 0;
}
