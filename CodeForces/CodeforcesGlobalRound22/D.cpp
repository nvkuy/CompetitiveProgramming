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

vector<vector<int>> c;

bool cmp(int u, int v) {
    return c[u].size() < c[v].size();
}

void dfs(int u) {
    cout << u << ' ';
    sort(c[u].begin(), c[u].end(), cmp);
    for (int v : c[u])
        dfs(v);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        c.clear();
        c.resize(n + 1);
        vector<int> a(n + 1);
        int k = 0;
        stack<int> r1;
        queue<int> r2;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            k = max(k, min(i, a[i]));
            if (a[i] > 0 && a[i] <= n)
                c[a[i]].push_back(i);
            if (a[i] == 0)
                r1.push(i);
            if (a[i] > n)
                r2.push(i);
        }
        vector<int> tmp;
        while (r1.size() > 0 || r2.size() > 0) {
            if (r1.size() > 0) {
                tmp.push_back(r1.top());
                r1.pop();
            } else {
                tmp.push_back(r2.front());
                r2.pop();
            }
        }
        sort(tmp.begin(), tmp.end(), cmp);
        cout << k << endl;
        for (int u : tmp)
            dfs(u);
        cout << endl;
    }

    return 0;
}