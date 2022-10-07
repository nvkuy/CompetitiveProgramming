#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

vector<vector<int>> mm;
vector<int> bestRank;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, m;
    cin >> n >> m;
    mm.assign(m, vector<int>(n));
    bestRank.assign(n, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mm[i][j];
            mm[i][j]--;
        }
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            bestRank[mm[i][j]] = min(j + 1, bestRank[mm[i][j]]);
    int zz = 5;
    for (int zzz = 0; zzz < zz; zzz++)
        for (int i = 0; i < m; i++)
            for (int j = n - 1; j > 0; j--)
                bestRank[mm[i][j - 1]] = min(bestRank[mm[i][j - 1]], bestRank[mm[i][j]]);
    for (int i = 0; i < n; i++)
        cout << n - bestRank[i] << ' ';
    cout << endl;

    return 0;
}
