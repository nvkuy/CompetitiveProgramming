#include <bits/stdc++.h>

using namespace std;

int sum_deg, num_node, self_loop;
vector<int> dd;
vector<vector<int>> c;

void dfs(int u) {
    num_node++;
    sum_deg += c[u].size();
    dd[u] = 1;
    for (int v : c[u]) {
        if (u == v)
            self_loop = 1;
        if (dd[v] == -1)
            dfs(v);
    }
}

int main()
{

    long long maxN = 1e5 + 3, mod = 998244353;
    vector<long long> per(maxN);
    per[0] = 1;
    for (int i = 1; i < maxN; i++)
        per[i] = (per[i - 1] * i) % mod;

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        c.clear();
        c.resize(n + 1);
        dd.assign(n + 1, - 1);
        bool no_ans = false;
        long long ans = 1;
        for (int i = 0; i < n; i++) {
            c[a[i]].push_back(b[i]);
            c[b[i]].push_back(a[i]);
        }
        for (int i = 1; i <= n; i++) {
            if (no_ans) break;
            if (dd[i] != -1) continue;
            num_node = sum_deg = self_loop = 0;
            dfs(i);
            if (num_node * 2 != sum_deg)
                no_ans = true;
            else {
                if (self_loop)
                    ans = (ans * n) % mod;
                else
                    ans = (ans * 2) % mod;
            }
        }
        if (no_ans) {
            cout << 0 << endl;
            continue;
        }
        cout << ans << endl;
    }

    return 0;
}
