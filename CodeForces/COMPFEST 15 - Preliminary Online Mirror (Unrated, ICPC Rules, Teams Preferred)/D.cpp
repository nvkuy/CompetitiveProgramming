#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    vector<pair<int, int>> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            b.push_back({j + 1, a[i][j]});
        }
    }

    sort(b.begin(), b.end());
    vector<long long> f(m + 1, 0);
    for (auto p : b) {
        for (int pos = min(p.first, m - k + 1); pos >= max(1, p.first - k + 1); pos--)
            f[pos] = max(f[pos], f[pos - 1] + p.second);
    }

    long long ans = 0;
    for (int i = 0; i <= m; i++)
        ans = max(ans, f[i]);
    cout << ans << endl;

    return 0;
}
