#include <bits/stdc++.h>

using namespace std;

struct node {
    priority_queue<int, vector<int>, greater<int>> pq;
    void add(int xi) {
        pq.push(xi);
        if (pq.size() > 20)
            pq.pop();
    }
    void mergeN(priority_queue<int, vector<int>, greater<int>> pqc) {
        priority_queue<int, vector<int>, greater<int>> tmp = pqc;
        while (!tmp.empty()) {
            add(tmp.top());
            tmp.pop();
        }
    }
    int getK(int k) {
        priority_queue<int, vector<int>, greater<int>> tmp = pq;
        int ck = pq.size();
        while (tmp.size() > k)
            tmp.pop();
        return tmp.top();
    }
};

vector<int> x;
vector<vector<int>> c;
vector<node> a;
vector<bool> dd;

void dfs(int u) {
    dd[u] = true;
    a[u].add(x[u]);
    for (int i = 0; i < c[u].size(); i++) {
        if (!dd[c[u][i]]) {
            dfs(c[u][i]);
            a[u].mergeN(a[c[u][i]].pq);
        }
    }
}

int main()
{
    int n, q, u, v, k;
    cin >> n >> q;
    x.resize(n + 1);
    dd.assign(n + 1, false);
    c.resize(n + 1);
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    dfs(1);
    while (q--) {
        cin >> v >> k;
        cout << a[v].getK(k) << endl;
    }

    return 0;
}
