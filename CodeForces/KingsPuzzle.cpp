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


    int n, k, cur;
    cin >> n >> k;

    if (k == 1) {
        cout << "YES" << endl;
        cout << n - (n <= 2) << endl;
        for (int i = 1; i < n; i++)
            cout << i << ' ' << i + 1 << endl;
        if (n > 2)
            cout << n << ' ' << 1 << endl;
        return 0;
    }

    vector<vector<int>> c(n + 1, vector<int>(n + 1, 0));
    vector<int> cntEdge(n + 1, 1);

    for (int i = 2; i + 1 <= n; i++) {
        c[i][i - 1] = c[i - 1][i] = 1;
        c[i][i + 1] = c[i + 1][i] = 1;
        cntEdge[i]++;
    }

    set<int> degree;
    for (int i = 2; i <= n; i++) {
        cur = k - degree.size();
        if (cur <= 0) break;
        for (int j = i + 2; j <= n; j++) {
            if (cntEdge[i] >= cur) break;
            c[i][j] = c[j][i] = 1;
            cntEdge[i]++, cntEdge[j]++;
        }
        degree.insert(cntEdge[i]);
        if (i + 2 <= n && cntEdge[i + 2] == cur - 1)
            degree.insert(cntEdge[i + 2]);
    }
    degree.insert(cntEdge[1]);

    if (k != degree.size()) {
        cout << "NO" << endl;
        return 0;
    }

    vector<pair<int, int>> edges;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (c[i][j])
                edges.push_back({i, j});
        }
    }

    cout << "YES" << endl;
    cout << edges.size() << endl;
    for (auto e : edges)
        cout << e.first << ' ' << e.second << endl;

    return 0;
}
