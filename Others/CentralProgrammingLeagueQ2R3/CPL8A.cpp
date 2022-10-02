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

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first > p2.first;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, m;
    cin >> n >> m;
    vector<vector<int>> c(n + 1, vector<int>(m + 1, 0));
    vector<int> cnt(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
            cnt[j] += c[i][j];
        }
    }
    vector<pair<int, int>> ans;
    for (int i = 1; i <= m; i++) 
        ans.push_back({cnt[i], i});
    sort(ans.begin(), ans.end(), cmp);
    for (auto t : ans)
        cout << t.second << ' ';
    cout << endl;

    return 0;
}
