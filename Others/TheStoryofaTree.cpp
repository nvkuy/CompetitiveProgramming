#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> c;
vector<int> st, ed, par;

void dfs(int &ti, int u, int parent) {
    par[u] = parent;
    ti++;
    st[u] = ti;
    for (int v : c[u]) {
        if (v == parent)
            continue;
        dfs(ti, v, u);
    }
    ed[u] = ti;
}

int main() {

    int t, n, g, k, u, v;
    cin >> t;
    while (t--) {
        cin >> n;
        c.clear();
        st.clear();
        ed.clear();
        par.clear();
        par.assign(n + 1, -1);
        c.resize(n + 1);
        st.resize(n + 1);
        ed.resize(n + 1);
        for (int i = 1; i < n; i++) {
            cin >> u >> v;
            c[u].push_back(v);
            c[v].push_back(u);
        }
        int ti = 0;
        dfs(ti, 1, 0);
        // for (int i = 1; i <= n; i++)
        //     cout << st[i] << ' ' << ed[i] << endl;
        vector<pair<int, int>> guess;
        cin >> g >> k;
        while (g--) {
            cin >> u >> v;
            guess.push_back({u, v});
        }
        vector<int> sgt(n + 2, 0);
        for (auto gg : guess) {
            if (par[gg.first] == gg.second) {
                sgt[st[gg.first]]++;
                sgt[ed[gg.first] + 1]--;
            } else {
                sgt[1]++;
                sgt[st[gg.second]]--;
                sgt[ed[gg.second] + 1]++;
            }
        }
        int valid_root = 0;
        for (int i = 1; i <= n; i++) {
            sgt[i] += sgt[i - 1];
            if (sgt[i] >= k) {
                valid_root++;
                // cout << i << endl;
            }
        }
        if (valid_root == 0) {
            cout << "0/1" << endl;
            continue;
        }
        int tmp = gcd(valid_root, n);
        cout << valid_root / tmp << '/' << n / tmp << endl;
    }

    return 0;
}