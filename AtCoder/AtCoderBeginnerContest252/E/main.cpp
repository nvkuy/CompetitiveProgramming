#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct Edge {
    int st, fi, id;
    long long cost;
    Edge(int s, int f, int idx, int cc) {
        st = s, fi = f;
        id = idx, cost = cc;
    }
};

bool cmpEdge(Edge e1, Edge e2) {
    return e1.cost < e2.cost;
}

vector<int> par;
vector<Edge> edges;

int root(int v) {
    return par[v] < 0 ? v : (par[v] = root(par[v]));
}

void mergeSet(int x, int y) {
    if ((x = root(x)) == (y = root(y)))
        return ;
    if (par[y] < par[x])
        swap(x, y);
    par[x] += par[y];
    par[y] = x;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, u, v, cost;
    cin >> n >> m;
    par.assign(n + 1, -1);
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> cost;
        edges.push_back(Edge(u, v, i, cost));
    }
    sort(edges.begin(), edges.end(), cmpEdge);
    long long MstCost = 0;
    for (int i = 0; i < edges.size(); i++) {
        Edge e = edges[i];
        if (root(e.st) != root(e.fi)) {
            mergeSet(e.st, e.fi);
            cout << e.id << ' ';
            //MstCost += e.cost;
        }
    }
    //cout << MstCost;

    return 0;
}
