#include <bits/stdc++.h>
using namespace std;

struct edge {
    int from, to, weight;
    edge(int f, int t, int w) {
        from = f;
        to = t;
        weight = w;
    }
};

bool cmp(edge &e1, edge &e2) {
    return e1.weight > e2.weight;
}

vector<vector<int>> c;
vector<int> cc, dd;

void dfs(int u) {
    dd[u] = 1;
    cc.push_back(u);
    for (int v : c[u]) {
        if (dd[v] == 0)
            dfs(v);
    }
}

int main() {

    if (fopen("wormsort.in", "r")) {
        freopen("wormsort.in", "r", stdin);
        freopen("wormsort.out", "w", stdout);
    }
    
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<edge> edges;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edges.push_back(edge(a, b, c));
    }

    bool need_swap = false;
    for (int i = 0; i < n; i++) {
        if (p[i] != i) {
            need_swap = true;
            break;
        }
    }
    if (!need_swap) {
        cout << -1 << endl;
        return 0;
    }

    sort(edges.begin(), edges.end(), cmp);
    int ll = 0, rr = m - 1, mm;
    while (ll < rr) {
        mm = (ll + rr) / 2;
        c.clear();
        c.resize(n);
        dd.assign(n, 0);
        for (int i = 0; i <= mm; i++) {
            c[edges[i].from].push_back(edges[i].to);
            c[edges[i].to].push_back(edges[i].from);
        }
        bool iok = true;
        for (int i = 0; i < n; i++) {
            if (!dd[i]) {
                cc.clear();
                dfs(i);
                vector<int> pos;
                sort(cc.begin(), cc.end());
                for (int j : cc)
                    pos.push_back(p[j]);
                sort(pos.begin(), pos.end());
                for (int j = 0; j < pos.size(); j++) {
                    if (pos[j] != cc[j]) {
                        iok = false;
                        break;
                    }
                }
                if (!iok)
                    break;
            }
        }
        if (iok)
            rr = mm;
        else
            ll = mm + 1;
    }
    cout << edges[rr].weight << endl;

    return 0;
}