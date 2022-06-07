#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n;
vector<vector<int>> c;

long long bfs(int st, int k) {
    long long ans = st;
    set<int> dd;
    queue<pair<int, int>> q;
    dd.insert(st);
    q.push({st, 0});
    while (!q.empty()) {
        pair<int, int> tmp = q.front(); q.pop();
        int u = tmp.first, dis = tmp.second;
        if (dis >= k)
            continue;
        for (int i = 0; i < c[u].size(); i++) {
            int v = c[u][i];
            if (dd.find(v) == dd.end()) {
                dd.insert(v);
                ans += v;
                q.push({v, dis + 1});
            }
        }
    }
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m, a, b, q;
    cin >> n >> m;
    c.resize(n + 1);
    while (m--) {
        cin >> a >> b;
        c[a].push_back(b);
        c[b].push_back(a);
    }
    cin >> q;
    while (q--) {
        cin >> a >> b;
        long long ans = bfs(a, b);
        cout << ans << endl;
    }

    return 0;
}
